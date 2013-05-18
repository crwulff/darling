#include "CFPreferences.h"
#include <stdio.h>

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
	printf("%s - Not implemented\n", __FUNCTION__);
	return NULL; // TODO
}

Boolean CFPreferencesGetAppBooleanValue(CFStringRef key, CFStringRef applicationID, Boolean *keyExistsAndHasValidFormat)
{
	printf("%s - Not implemented\n", __FUNCTION__);
	return false; // TODO
}

CFIndex CFPreferencesGetAppIntegerValue(CFStringRef key, CFStringRef applicationID, Boolean *keyExistsAndHasValidFormat)
{
	printf("%s - Not implemented\n", __FUNCTION__);
	return 0; // TODO
}

void CFPreferencesSetAppValue(CFStringRef key, CFPropertyListRef value, CFStringRef applicationID)
{
	printf("%s - Not implemented\n", __FUNCTION__);
	//TODO
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
	printf("%s - Not implemented\n", __FUNCTION__);
	return NULL; // TODO
}

CFDictionaryRef CFPreferencesCopyMultiple(CFArrayRef keysToFetch, CFStringRef applicationID, CFStringRef userName, CFStringRef hostName)
{
	printf("%s - Not implemented\n", __FUNCTION__);
	return NULL; // TODO
}

void CFPreferencesSetValue(CFStringRef key, CFPropertyListRef value, CFStringRef applicationID, CFStringRef userName, CFStringRef hostName)
{
	printf("%s - Not implemented\n", __FUNCTION__);
	//TODO
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

