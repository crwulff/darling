#include "CFPreferences.h"
#include <util/debug.h>
#import <Foundation/NSUserDefaults.h>
#import <CoreFoundation/CFNumber.h>

#ifndef CONST_STRING_DECL
#	define CONST_STRING_DECL(name, value) const CFStringRef name = CFSTR(value);
#endif

CONST_STRING_DECL(kCFPreferencesAnyApplication,
  "kCFPreferencesAnyApplication");
CONST_STRING_DECL(kCFPreferencesCurrentApplication,
  "kCFPreferencesCurrentApplication");
CONST_STRING_DECL(kCFPreferencesAnyHost,
  "kCFPreferencesAnyHost");
CONST_STRING_DECL(kCFPreferencesCurrentHost,
  "kCFPreferencesCurrentHost");
CONST_STRING_DECL(kCFPreferencesAnyUser,
  "kCFPreferencesAnyUser");
CONST_STRING_DECL(kCFPreferencesCurrentUser,
  "kCFPreferencesCurrentUser");

/* CFPreferences Private? */
CONST_STRING_DECL(kCFManagedPreferencesMCXObjectName,
  "CFManagedPreferencesMCXObjectName");
CONST_STRING_DECL(kCFManagedPreferencesMCXNotificationName,
  "CFManagedPreferencesMCXNotificationName");
CONST_STRING_DECL(kCFPreferencesDidChangeNotificationName,
  "CFPreferencesDidChangeNotificationName");
CONST_STRING_DECL(kCFPreferencesWebServicesProviderTypeMap,
  "CFPreferencesWebServicesProviderTypeMap");
CONST_STRING_DECL(kCFPreferencesWebServicesProviderTypeWebSearch,
  "CFPreferencesWebServicesProviderTypeWebSearch");
CONST_STRING_DECL(kCFPreferencesDidChangeObject,
  "CFPreferencesDidChangeObject");

CFPropertyListRef CFPreferencesCopyAppValue(CFStringRef key, CFStringRef applicationID)
{
	if (applicationID == kCFPreferencesCurrentApplication)
	{
		return [[NSUserDefaults standardUserDefaults] objectForKey: (NSString*) key];
	}
	else
	{
		STUB();
		return NULL;
	}
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
	STUB();
}

void CFPreferencesRemoveSuitePreferencesFromApp(CFStringRef applicationID, CFStringRef suiteID)
{
	STUB();
}

Boolean CFPreferencesAppSynchronize(CFStringRef applicationID)
{
	STUB();
	return 0;
}

CFPropertyListRef CFPreferencesCopyValue(CFStringRef key, CFStringRef applicationID, CFStringRef userName, CFStringRef hostName)
{
	// TODO: this ignores the applicationID, userName and hostName and searches more than just the application domain

	return [[NSUserDefaults standardUserDefaults] objectForKey: key];
}

CFDictionaryRef CFPreferencesCopyMultiple(CFArrayRef keysToFetch, CFStringRef applicationID, CFStringRef userName, CFStringRef hostName)
{
	STUB();
	return NULL;
}

void CFPreferencesSetValue(CFStringRef key, CFPropertyListRef value, CFStringRef applicationID, CFStringRef userName, CFStringRef hostName)
{
	// TODO: this ignores the applicationID, userName and hostName

	[[NSUserDefaults standardUserDefaults] setObject: (id)value forKey: key];
}

void CFPreferencesSetMultiple(CFDictionaryRef keysToSet, CFArrayRef keysToRemove, CFStringRef applicationID, CFStringRef userName, CFStringRef hostName)
{
	STUB();
}

Boolean CFPreferencesSynchronize(CFStringRef applicationID, CFStringRef userName, CFStringRef hostName)
{
	STUB();
	return 0;
}

CFArrayRef CFPreferencesCopyApplicationList(CFStringRef userName, CFStringRef hostName)
{
	STUB();
	return NULL;
}

CFArrayRef CFPreferencesCopyKeyList(CFStringRef applicationID, CFStringRef userName, CFStringRef hostName)
{
	STUB();
	return NULL;
}

Boolean CFPreferencesAppValueIsForced(CFStringRef key, CFStringRef applicationID)
{
	STUB();
	return 0;
}

