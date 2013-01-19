
#include <Foundation/NSNotification.h>
#include <Foundation/NSOperation.h>

@interface BlockProxy : NSOperation
{
@public
  id                 _object;
  NSOperationQueue * _queue;
  void (^_block)(NSNotification *);
  NSNotification *   _notification;
}

- (BlockProxy*)init: (id)object
	      queue: (NSOperationQueue *)queue
	 usingBlock: (void (^)(NSNotification *))block;

- (void)run: (NSNotification *)notification;

- (void)main;

@end

@implementation BlockProxy
- (BlockProxy*)init: (id)object
	      queue: (NSOperationQueue *)queue
	 usingBlock: (void (^)(NSNotification *))block
{
	self->_object = object;
	self->_queue = queue;
	self->_block = [[block copy] autorelease];
	return self;
}

- (void)run: (NSNotification *)notification
{
	self->_notification = notification;
	[self->_queue addOperation: self];
}

- (void)main
{
	self->_block(self->_notification);
}

@end

@interface NSNotificationCenter (NSNotificationCenter_dyld)

- (id)addObserverForName: (NSString *)name
		  object: (id)obj
		   queue: (NSOperationQueue *)queue
	      usingBlock: (void (^)(NSNotification *))block;

@end

@implementation NSNotificationCenter (NSNotificationCenter_dyld)

- (id)addObserverForName: (NSString *)name
		  object: (id)obj
		   queue: (NSOperationQueue *)queue
	      usingBlock: (void (^)(NSNotification *))block
{
	BlockProxy *proxyObject = [[BlockProxy alloc] init: obj
						     queue: queue
					        usingBlock: block];
	[self addObserver: proxyObject
		 selector: NSSelectorFromString(@"run:")
		     name: name
		   object: obj];

	return (id)proxyObject;
}

@end
