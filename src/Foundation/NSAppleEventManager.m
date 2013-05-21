
#import	<Foundation/NSObject.h>
#import <Foundation/NSException.h>
#import <Foundation/NSLock.h>

#include <CoreServices/MacErrors.h>

typedef const struct __NSAppleEventManagerSuspension *NSAppleEventManagerSuspensionID;

typedef char *Ptr;

typedef FourCharCode AEEventClass;
typedef FourCharCode AEEventID;
typedef FourCharCode ResType;

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

@interface NSAppleEventDescriptor : NSObject
// TODO
@end

@interface NSAppleEventManager : NSObject

+ (NSAppleEventManager*) sharedAppleEventManager;

- (void) setEventHandler: (id)handler
	     andSelector: (SEL)handleEventSelector
	   forEventClass: (AEEventClass)eventClass
	      andEventID: (AEEventID)eventID;

- (void) removeEventHandlerForEventClass: (AEEventClass)eventClass
			      andEventID: (AEEventID)eventID;

- (OSErr) dispatchRawAppleEvent: (const AppleEvent*)theAppleEvent
		   withRawReply: (AppleEvent*)theReply
		  handlerRefCon: (UInt32)handlerRefcon;

- (NSAppleEventDescriptor*) currentAppleEvent;

- (NSAppleEventDescriptor*) currentReplyAppleEvent;

- (NSAppleEventDescriptor*) appleEventForSuspensionID: (NSAppleEventManagerSuspensionID)suspensionID;

- (NSAppleEventDescriptor*) replyAppleEventForSuspensionID: (NSAppleEventManagerSuspensionID)suspensionID;

- (void) resumeWithSuspensionID: (NSAppleEventManagerSuspensionID)suspensionID;

- (void) setCurrentAppleEventAndReplyEventWithSuspensionID: (NSAppleEventManagerSuspensionID)suspensionID;

- (NSAppleEventManagerSuspensionID) suspendCurrentAppleEvent;

@end

@implementation NSAppleEventManager

static NSAppleEventManager* sharedManager = nil;

+ (NSAppleEventManager*) sharedAppleEventManager;
{
  if (sharedManager == nil)
    {
      NS_DURING
	{
	  [gnustep_global_lock lock];
	  if (sharedManager == nil)
	    {
	      sharedManager = [[self alloc] init];
	    }
	  [gnustep_global_lock unlock];
	}
      NS_HANDLER
	{
	  // unlock then re-raise the exception
	  [gnustep_global_lock unlock];
	  [localException raise];
	}
      NS_ENDHANDLER
    }
  return sharedManager;
}

- (void) setEventHandler: (id)handler
	     andSelector: (SEL)handleEventSelector
	   forEventClass: (AEEventClass)eventClass
	      andEventID: (AEEventID)eventID
{
  // TODO
}

- (void) removeEventHandlerForEventClass: (AEEventClass)eventClass
			      andEventID: (AEEventID)eventID
{
  // TODO
}

- (OSErr) dispatchRawAppleEvent: (const AppleEvent*)theAppleEvent
		   withRawReply: (AppleEvent*)theReply
		  handlerRefCon: (UInt32)handlerRefcon
{
  // TODO
  return 0;
}

- (NSAppleEventDescriptor*) currentAppleEvent
{
  // TODO
  return nil;
}

- (NSAppleEventDescriptor*) currentReplyAppleEvent
{
  // TODO
  return nil;
}

- (NSAppleEventDescriptor*) appleEventForSuspensionID: (NSAppleEventManagerSuspensionID)suspensionID
{
  // TODO
  return nil;
}

- (NSAppleEventDescriptor*) replyAppleEventForSuspensionID: (NSAppleEventManagerSuspensionID)suspensionID
{
  // TODO
  return nil;
}

- (void) resumeWithSuspensionID: (NSAppleEventManagerSuspensionID)suspensionID
{
  // TODO
}

- (void) setCurrentAppleEventAndReplyEventWithSuspensionID: (NSAppleEventManagerSuspensionID)suspensionID
{
  // TODO
}

- (NSAppleEventManagerSuspensionID) suspendCurrentAppleEvent
{
  // TODO
  return 0;
}

@end
