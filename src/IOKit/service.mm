#include "service.h"
#include "constants.h"
#include "bsd.h"
#include <Foundation/NSString.h>
#include <CoreFoundation/CFString.h>
#include <libudev.h>
#include <stdlib.h>
#include <list>
#include <string>
#include <fstream>
#include <sys/types.h>
#include <dirent.h>
#include <cstdlib>
#include "../util/stlutils.h"
#include "../util/log.h"
#include "io_device.h"
#include "io_device_iterator.h"
#include "cfutil.h"

const void* kIOMasterPortDefault = 0;

static void filterByBSDName(struct udev_enumerate* uenum, CFStringRef str);
static void filterByClass(struct udev_enumerate* uenum, CFStringRef str);
static void filterByDriver(struct udev_enumerate* uenum, CFStringRef str);
static void filterByProperties(struct udev_enumerate* uenum, CFDictionaryRef dict);

static CFMutableDictionaryRef createMatchingDictionary(CFStringRef key, CFStringRef value)
{
	CFMutableDictionaryRef dict = CFDictionaryCreateMutable(kCFAllocatorDefault, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
	CFDictionarySetValue(dict, key, value);
	return dict;
}

int IOMasterPort(void* bootstrapPort, void** masterPort)
{
	*masterPort = (void*) kIOMasterPortDefault;
	return 0;
}

CFMutableDictionaryRef IOServiceMatching(const char* service)
{
	static CFStringRef str = CFSTR(kIOProviderClassKey);
	return createMatchingDictionary(str, strToCF(service));
}

CFMutableDictionaryRef IOServiceNameMatching(const char* name)
{
	static CFStringRef str = CFSTR(kIONameMatchKey);
	return createMatchingDictionary(str, strToCF(name));
}

CFMutableDictionaryRef IOBSDNameMatching(void* iokitPort, unsigned int options, const char* bsdName)
{
	static CFStringRef str = CFSTR(kIOBSDNameKey);
	return createMatchingDictionary(str, strToCF(bsdName));
}

int IOServiceGetMatchingServices(void* port, CFDictionaryRef rules, io_device_iterator_t* iter)
{
	//size_t size = CFDictionaryGetCount(rules);
	//std::unique_ptr<CFStringRef[]> keys (new CFStringRef[size]);
	//CFDictionaryGetKeysAndValues(rules, (const void **) keys, nullptr);
	struct udev* udev;
	struct udev_enumerate* uenum;
	struct udev_list_entry* list;
	const void* value;

	udev = udev_new();
	uenum = udev_enumerate_new(udev);

	if ((value = CFDictionaryGetValue(rules, CFSTR(kIOProviderClassKey))))
		filterByClass(uenum, (CFStringRef) value);

	if ((value = CFDictionaryGetValue(rules, CFSTR(kIOBSDNameKey))))
		filterByBSDName(uenum, (CFStringRef) value);

	if ((value = CFDictionaryGetValue(rules, CFSTR(kIOPropertyMatchKey))))
		filterByProperties(uenum, (CFDictionaryRef) value);

	udev_enumerate_scan_devices(uenum);
	*iter = new io_device_iterator(uenum);

	return 0;
}

int IORegistryEntryCreateCFProperties(io_object_t obj, CFMutableDictionaryRef* props, CFAllocatorRef allocator, int opts)
{
	io_device* dev = dynamic_cast<io_device*>(obj);

	if (!dev)
	{
		*props = nullptr;
		return -4;
	}
	else
	{
		*props = CFDictionaryCreateMutable(allocator, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
		dev->properties(*props, allocator);
		return 0;
	}
}

CFTypeRef IORegistryEntryCreateCFProperty(io_object_t obj, CFStringRef key, CFAllocatorRef allocator, int opts)
{
	io_device* dev = dynamic_cast<io_device*>(obj);

	if (!dev)
		return nullptr;
	else
		return dev->property(key, allocator);
}

int IORegistryEntryGetParentEntry(io_object_t obj, void* planeName /* TODO */, io_object_t* parent)
{
	io_device* dev = dynamic_cast<io_device*>(obj);
	if (!dev)
	{
		*parent = nullptr;
		return -1;
	}
	else
	{
		*parent = dev->parent();
		return 0;
	}
}

void filterByClass(struct udev_enumerate* uenum, CFStringRef str)
{
	if (strCFEqual(str, kIOEthernetInterfaceClass))
		udev_enumerate_add_match_subsystem(uenum, "net");
	else if (strCFEqual(str, kIOSerialBSDServiceValue))
		udev_enumerate_add_match_subsystem(uenum, "tty");
	else if (strCFEqual(str, kIOUSBDeviceClassName))
		udev_enumerate_add_match_property(uenum, "DEVTYPE", "usb_device");
	else if (strCFEqual(str, kIOUSBInterfaceClassName))
		udev_enumerate_add_match_property(uenum, "DEVTYPE", "usb_interface");
	else if (strCFEqual(str, kIOHIDDeviceKey))
		udev_enumerate_add_match_subsystem(uenum, "hidraw");
}

void filterByBSDName(struct udev_enumerate* uenum, CFStringRef str)
{
	std::string translated = DarlingTranslateBSDName([(NSString*) str UTF8String]);
	udev_enumerate_add_match_sysname(uenum, translated.c_str());
}

void filterByDriver(struct udev_enumerate* uenum, CFStringRef str)
{
	const char* driver = nullptr;

	// TODO: USB interface vs. device
	if (strCFEqual(str, "AppleUSBEHCI"))
		driver = "ehci_hcd";
	else if (strCFEqual(str, "AppleUSBOHCI"))
		driver = "ohci_hcd";
	else if (strCFEqual(str, "AppleUSBUHCI"))
		driver = "uhci_hcd";
	else if (strCFEqual(str, "AppleUSBCDC"))
		driver = "cdc_acm";
	else if (strCFEqual(str, "processor"))
		driver = "processor";
	else
		driver = [(NSString*) str UTF8String];
	
	udev_enumerate_add_match_property(uenum, "driver", driver);
}

static std::string detectPrimaryInterface()
{
	std::ifstream routes;
	
	if (const char* iface = getenv("IOKIT_PRIMARY_IFACE"))
		return iface;
	
	routes.open("/proc/net/route");
	
	if (routes.is_open())
	{
		std::string ifaceName, destination;
		
		while (!routes.eof())
		{
			routes >> ifaceName >> destination;
			
			if (destination == "00000000")
			{
				LOG << "Primary network interface detected to be " << ifaceName << std::endl;
				return ifaceName;
			}
			
			std::getline(routes, ifaceName); // drop the rest of the line
		}
	}
	
	return std::string();
}

void filterByProperties(struct udev_enumerate* uenum, CFDictionaryRef dict)
{
	size_t size = CFDictionaryGetCount(dict);
	CFStringRef* keys = new CFStringRef[size];
	CFDictionaryGetKeysAndValues(dict, (const void **) keys, nullptr);

	for (size_t i = 0; i < size; i++)
	{
		const void* value = CFDictionaryGetValue(dict, keys[i]);
		const char* key = nullptr;
		CFStringRef str = keys[i];
		std::string svalue;

		if (strCFEqual(str, "VendorID"))
		{
			key = "ID_VENDOR_ID";
			svalue = [(NSString*)value UTF8String];
		}
		else if (strCFEqual(str, "ProductID"))
		{
			key = "ID_MODEL_ID";
			svalue = [(NSString*)value UTF8String];
		}
		else if (strCFEqual(str, "IOPrimaryInterface"))
		{
			svalue = detectPrimaryInterface();
			if (!svalue.empty())
				key = "INTERFACE";
			//svalue = "eth0";
		}

		if (key != nullptr)
			udev_enumerate_add_match_property(uenum, key, svalue.c_str());
		else
			LOG << "Ignoring property " << [(NSString*) str UTF8String] << " in IOKit filterByProperties\n";
	}

	delete [] keys;
}



