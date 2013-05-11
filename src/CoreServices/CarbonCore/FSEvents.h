
#include <CoreFoundation/CFArray.h>
#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFDate.h>
#include <dispatch/dispatch.h>

extern "C" {

typedef UInt32                        FSEventStreamCreateFlags;

enum {
	kFSEventStreamCreateFlagNone       = 0x00000000,
	kFSEventStreamCreateFlagUseCFTypes = 0x00000001,
	kFSEventStreamCreateFlagNoDefer    = 0x00000002,
	kFSEventStreamCreateFlagWatchRoot  = 0x00000004,
	kFSEventStreamCreateFlagIgnoreSelf = 0x00000008,
	kFSEventStreamCreateFlagFileEvents = 0x00000010
};

typedef UInt32                        FSEventStreamEventFlags;

enum {
	kFSEventStreamEventFlagNone              = 0x00000000,
	kFSEventStreamEventFlagMustScanSubDirs   = 0x00000001,
	kFSEventStreamEventFlagUserDropped       = 0x00000002,
	kFSEventStreamEventFlagKernelDropped     = 0x00000004,
	kFSEventStreamEventFlagEventIdsWrapped   = 0x00000008,
	kFSEventStreamEventFlagHistoryDone       = 0x00000010,
	kFSEventStreamEventFlagRootChanged       = 0x00000020,
	kFSEventStreamEventFlagMount             = 0x00000040,
	kFSEventStreamEventFlagUnmount           = 0x00000080, /* These flags are only set if you specified the FileEvents*/
	kFSEventStreamEventFlagItemCreated       = 0x00000100,
	kFSEventStreamEventFlagItemRemoved       = 0x00000200,
	kFSEventStreamEventFlagItemInodeMetaMod  = 0x00000400,
	kFSEventStreamEventFlagItemRenamed       = 0x00000800,
	kFSEventStreamEventFlagItemModified      = 0x00001000,
	kFSEventStreamEventFlagItemFinderInfoMod = 0x00002000,
	kFSEventStreamEventFlagItemChangeOwner   = 0x00004000,
	kFSEventStreamEventFlagItemXattrMod      = 0x00008000,
	kFSEventStreamEventFlagItemIsFile        = 0x00010000,
	kFSEventStreamEventFlagItemIsDir         = 0x00020000,
	kFSEventStreamEventFlagItemIsSymlink     = 0x00040000
};

typedef UInt64                        FSEventStreamEventId;

enum {
	kFSEventStreamEventIdSinceNow = 0xFFFFFFFFFFFFFFFFULL
};

typedef struct __FSEventStream       *FSEventStreamRef;
typedef const struct __FSEventStream *ConstFSEventStreamRef;

typedef struct FSEventStreamContext {
	CFIndex                            version;
	void                              *info;
	CFAllocatorRetainCallBack          retain;
	CFAllocatorReleaseCallBack         release;
	CFAllocatorCopyDescriptionCallBack copyDescription;
} FSEventStreamContext;

typedef void (*FSEventStreamCallback)(
	ConstFSEventStreamRef streamRef,
	void *clientCallBackInfo,
	size_t numEvents,
	void *eventPaths,
	const FSEventStreamEventFlags eventFlags[],
	const FSEventStreamEventId eventIds[]);

extern FSEventStreamRef FSEventStreamCreate(
	CFAllocatorRef allocator,
	FSEventStreamCallback callback,
	FSEventStreamContext *context,
	CFArrayRef pathsToWatch,
	FSEventStreamEventId sinceWhen,
	CFTimeInterval latency,
	FSEventStreamCreateFlags flags);

extern CFArrayRef FSEventStreamCopyPathsBeingWatched(ConstFSEventStreamRef streamRef);

extern void FSEventStreamSetDispatchQueue(FSEventStreamRef streamRef, dispatch_queue_t q);

extern Boolean FSEventStreamStart(FSEventStreamRef streamRef);

} // extern "C"

