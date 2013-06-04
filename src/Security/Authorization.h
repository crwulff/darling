
#include <CoreFoundation/CFString.h>
#include <CoreFoundation/CFBundle.h>

extern "C" {

typedef const char *AuthorizationString;
typedef struct {
	AuthorizationString name;
	size_t valueLength;
	void *value;
	UInt32 flags;
} AuthorizationItem;


typedef struct {
	UInt32 count;
	AuthorizationItem *items;
} AuthorizationItemSet;

typedef UInt32 AuthorizationFlags;
typedef AuthorizationItemSet AuthorizationRights;
typedef AuthorizationItemSet AuthorizationEnvironment;
typedef const struct AuthorizationOpaqueRef *AuthorizationRef;

OSStatus AuthorizationCreate(const AuthorizationRights *rights,
			     const AuthorizationEnvironment *environment,
			     AuthorizationFlags flags,
			     AuthorizationRef *authorization);

OSStatus AuthorizationFree(AuthorizationRef authorization, AuthorizationFlags flags);

OSStatus AuthorizationCopyRights(AuthorizationRef authorization,
				 const AuthorizationRights *rights,
				 const AuthorizationEnvironment *environment,
				 AuthorizationFlags flags,
				 AuthorizationRights **authorizedRights);

OSStatus AuthorizationRightSet(AuthorizationRef authRef,
			       const char *rightName,
			       CFTypeRef rightDefinition,
			       CFStringRef descriptionKey,
			       CFBundleRef bundle,
			       CFStringRef localeTableName);
} // extern "C"

