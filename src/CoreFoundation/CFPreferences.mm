#include "CFPreferences.h"
#include <stdio.h>

#include <Foundation/NSUserDefaults.h>
#include <CoreFoundation/CFString.h>
#include <CoreFoundation/CFNumber.h>

const CFStringRef kCFPreferencesAnyApplication     = CFSTR("CFPreferencesAnyApplication");
const CFStringRef kCFPreferencesCurrentApplication = CFSTR("CFPreferencesCurrentApplication");
const CFStringRef kCFPreferencesAnyHost            = CFSTR("CFPreferencesAnyHost");
const CFStringRef kCFPreferencesCurrentHost        = CFSTR("CFPreferencesCurrentHost");
const CFStringRef kCFPreferencesAnyUser            = CFSTR("CFPreferencesAnyUser");
const CFStringRef kCFPreferencesCurrentUser        = CFSTR("CFPreferencesCurrentUser");

/* CFPreferences Private? */
const CFStringRef kCFManagedPreferencesMCXObjectName             = CFSTR("CFManagedPreferencesMCXObjectName");
const CFStringRef kCFManagedPreferencesMCXNotificationName       = CFSTR("CFManagedPreferencesMCXNotificationName");
const CFStringRef kCFPreferencesDidChangeNotificationName        = CFSTR("CFPreferencesDidChangeNotificationName");
const CFStringRef kCFPreferencesWebServicesProviderTypeMap       = CFSTR("CFPreferencesWebServicesProviderTypeMap");
const CFStringRef kCFPreferencesWebServicesProviderTypeWebSearch = CFSTR("CFPreferencesWebServicesProviderTypeWebSearch");
const CFStringRef kCFPreferencesDidChangeObject                  = CFSTR("CFPreferencesDidChangeObject");

CFPropertyListRef CFPreferencesCopyAppValue(CFStringRef key, CFStringRef applicationID)
{
	// TODO: this ignores the applicationID and searches more than just the application domain

	return [[NSUserDefaults standardUserDefaults] objectForKey: key];
}

Boolean CFPreferencesGetAppBooleanValue(CFStringRef key, CFStringRef applicationID, Boolean *keyExistsAndHasValidFormat)
{
	Boolean result = false;
	Boolean valid = false;

	CFPropertyListRef value = CFPreferencesCopyAppValue(key, applicationID);

	if (value)
	{
		CFTypeID type = CFGetTypeID(value);
		if (type == CFStringGetTypeID())
		{
			if ((kCFCompareEqualTo == CFStringCompare((CFStringRef)value, CFSTR("true"), kCFCompareCaseInsensitive)) ||
			    (kCFCompareEqualTo == CFStringCompare((CFStringRef)value, CFSTR("YES"), kCFCompareCaseInsensitive)))
			{
				valid = true;
				result = true;
			}
			else if ((kCFCompareEqualTo == CFStringCompare((CFStringRef)value, CFSTR("false"), kCFCompareCaseInsensitive)) ||
			         (kCFCompareEqualTo == CFStringCompare((CFStringRef)value, CFSTR("NO"), kCFCompareCaseInsensitive)))
			{
				valid = true;
				result = true;
			}
		}
		else if (type == CFNumberGetTypeID())
		{
			int number = 0;
			CFNumberGetValue((CFNumberRef)value, kCFNumberIntType, &number);
			valid = true;
			result = (number != 0);
		}
		else if (type == CFBooleanGetTypeID())
		{
			valid = true;
			result = (value == kCFBooleanTrue);
		}

		CFRelease(value);
	}

	if (keyExistsAndHasValidFormat)
	{
		*keyExistsAndHasValidFormat = valid;
	}

	return result;
}

CFIndex CFPreferencesGetAppIntegerValue(CFStringRef key, CFStringRef applicationID, Boolean *keyExistsAndHasValidFormat)
{
	CFIndex result = 0;
	Boolean valid = false;

	CFPropertyListRef value = CFPreferencesCopyAppValue(key, applicationID);

	if (value)
	{
		CFTypeID type = CFGetTypeID(value);
		if (type == CFStringGetTypeID())
		{
			// TODO: This doesn't detect invalid strings or deal with larger numbers...
			result = CFStringGetIntValue((CFStringRef)value);
			valid = true;
		}
		else if (type == CFNumberGetTypeID())
		{
			CFNumberGetValue((CFNumberRef)value, kCFNumberCFIndexType, &result);
			valid = true;
		}

		CFRelease(value);
	}

	if (keyExistsAndHasValidFormat)
	{
		*keyExistsAndHasValidFormat = valid;
	}

	return result;
}

void CFPreferencesSetAppValue(CFStringRef key, CFPropertyListRef value, CFStringRef applicationID)
{
	// TODO: this ignores the applicationID

	return [[NSUserDefaults standardUserDefaults] setObject: (id)value forKey: key];
}

void CFPreferencesAddSuitePreferencesToApp(CFStringRef applicationID, CFStringRef suiteID)
{
	printf("%s - Not implemented\n", __FUNCTION__);
	//TODO
}

void CFPreferencesRemoveSuitePreferencesFromApp(CFStringRef applicationID, CFStringRef suiteID)
{
	printf("%s - Not implemented\n", __FUNCTION__);
	//TODO
}

Boolean CFPreferencesAppSynchronize(CFStringRef applicationID)
{
	printf("%s - Not implemented\n", __FUNCTION__);
	return false; // TODO
}

CFPropertyListRef CFPreferencesCopyValue(CFStringRef key, CFStringRef applicationID, CFStringRef userName, CFStringRef hostName)
{
	// TODO: this ignores the applicationID, userName and hostName and searches more than just the application domain

	return [[NSUserDefaults standardUserDefaults] objectForKey: key];
}

CFDictionaryRef CFPreferencesCopyMultiple(CFArrayRef keysToFetch, CFStringRef applicationID, CFStringRef userName, CFStringRef hostName)
{
	printf("%s - Not implemented\n", __FUNCTION__);
	return NULL; // TODO
}

void CFPreferencesSetValue(CFStringRef key, CFPropertyListRef value, CFStringRef applicationID, CFStringRef userName, CFStringRef hostName)
{
	// TODO: this ignores the applicationID, userName and hostName

	[[NSUserDefaults standardUserDefaults] setObject: (id)value forKey: key];
}

void CFPreferencesSetMultiple(CFDictionaryRef keysToSet, CFArrayRef keysToRemove, CFStringRef applicationID, CFStringRef userName, CFStringRef hostName)
{
	printf("%s - Not implemented\n", __FUNCTION__);
	//TODO
}

Boolean CFPreferencesSynchronize(CFStringRef applicationID, CFStringRef userName, CFStringRef hostName)
{
	printf("%s - Not implemented\n", __FUNCTION__);
	return false; // TODO
}

CFArrayRef CFPreferencesCopyApplicationList(CFStringRef userName, CFStringRef hostName)
{
	printf("%s - Not implemented\n", __FUNCTION__);
	return NULL; // TODO
}

CFArrayRef CFPreferencesCopyKeyList(CFStringRef applicationID, CFStringRef userName, CFStringRef hostName)
{
	printf("%s - Not implemented\n", __FUNCTION__);
	return NULL; // TODO
}

Boolean CFPreferencesAppValueIsForced(CFStringRef key, CFStringRef applicationID)
{
	printf("%s - Not implemented\n", __FUNCTION__);
	return false; // TODO
}

