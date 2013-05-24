
#include <CoreServices/MacErrors.h>

typedef const struct __NSAppleEventManagerSuspension *NSAppleEventManagerSuspensionID;

typedef char *Ptr;

typedef FourCharCode AEEventClass;
typedef FourCharCode AEEventID;
typedef FourCharCode ResType;
typedef void* SRefCon;

typedef ResType                         DescType;
typedef Ptr                             AEDataStorageType;
typedef AEDataStorageType *             AEDataStorage;

typedef struct AEDesc
{
  DescType            descriptorType;
  AEDataStorage       dataHandle;
} AEDesc, *AEDescPtr;

typedef AEDesc                          AEDescList;
typedef AEDescList                      AERecord;
typedef AERecord                        AppleEvent;

typedef OSErr (*AEEventHandlerProcPtr)(const AppleEvent *theAppleEvent, AppleEvent *reply, SRefCon handlerRefcon);
typedef AEEventHandlerProcPtr AEEventHandlerUPP;

