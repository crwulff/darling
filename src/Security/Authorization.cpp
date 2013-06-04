
#include "Authorization.h"

OSStatus AuthorizationCreate(const AuthorizationRights *rights,
			     const AuthorizationEnvironment *environment,
			     AuthorizationFlags flags,
			     AuthorizationRef *authorization)
{
	// TODO
	return 0;
}

OSStatus AuthorizationFree(AuthorizationRef authorization, AuthorizationFlags flags)
{
	// TODO
	return 0;
}

OSStatus AuthorizationCopyRights(AuthorizationRef authorization,
				 const AuthorizationRights *rights,
				 const AuthorizationEnvironment *environment,
				 AuthorizationFlags flags,
				 AuthorizationRights **authorizedRights)
{
	// TODO
	return 0;
}

OSStatus AuthorizationRightSet(AuthorizationRef authRef,
			       const char *rightName,
			       CFTypeRef rightDefinition,
			       CFStringRef descriptionKey,
			       CFBundleRef bundle,
			       CFStringRef localeTableName)
{
	// TODO
	return 0;
}
