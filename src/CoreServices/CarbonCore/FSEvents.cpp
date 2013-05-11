
#include "FSEvents.h"
#include <stdio.h>

typedef struct __FSEventStream
{
	CFAllocatorRef           allocator;
	FSEventStreamCallback    callback;
	FSEventStreamContext    *context;
	CFArrayRef               pathsToWatch;
	FSEventStreamEventId     sinceWhen;
	CFTimeInterval           latency;
	FSEventStreamCreateFlags flags;
} FSEventStream;

FSEventStreamRef FSEventStreamCreate(
	CFAllocatorRef allocator,
	FSEventStreamCallback callback,
	FSEventStreamContext *context,
	CFArrayRef pathsToWatch,
	FSEventStreamEventId sinceWhen,
	CFTimeInterval latency,
	FSEventStreamCreateFlags flags)
{
	if (NULL == allocator)
	{
		allocator = CFAllocatorGetDefault();
	}

	FSEventStream *newStream = (FSEventStream*)CFAllocatorAllocate(allocator, sizeof(FSEventStream), 0);

	if (NULL == newStream)
	{
		fprintf(stderr, "Unable to create FSEventStream (OOM)\n");
		return NULL;
	}

	newStream->allocator = allocator;
	newStream->callback = callback;
	newStream->context = context;
	newStream->pathsToWatch = CFArrayCreateCopy(allocator, pathsToWatch);
	newStream->sinceWhen = sinceWhen;
	newStream->latency = latency;
	newStream->flags = flags;

	// TODO: Actually set up watches for the supplied paths

	return newStream;
}

CFArrayRef FSEventStreamCopyPathsBeingWatched(ConstFSEventStreamRef streamRef)
{
	return CFArrayCreateCopy(streamRef->allocator, streamRef->pathsToWatch);
}

void FSEventStreamSetDispatchQueue(FSEventStreamRef streamRef, dispatch_queue_t q)
{
	// TODO
}

Boolean FSEventStreamStart(FSEventStreamRef streamRef)
{
	// TODO
	return true;
}
