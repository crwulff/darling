
#import "NSAnimationContext.h"

#import <QuartzCore/CAMediaTimingFunction.h>
#import <QuartzCore/CATransaction.h>

#import <Foundation/NSThread.h>
#import <Foundation/NSValue.h>

@implementation NSAnimationContext

static NSMutableArray * _NSGetAnimationContextForCurrentThread(void)
{
  NSMutableDictionary *threadDict = [[NSThread currentThread] threadDictionary];
  NSMutableArray *contextStack = [threadDict objectForKey: @"animationContexts"];

  if (contextStack == nil)
    {
      contextStack = [[NSMutableArray alloc] init];
      [threadDict setObject: contextStack forKey: @"animationContexts"];
    }

  return contextStack;
}

+ (void)runAnimationGroup:(void (^)(NSAnimationContext *context))changes completionHandler:(void (^)(void))completionHandler
{
  [NSAnimationContext beginGrouping];
  
  NSAnimationContext *currentContext = [NSAnimationContext currentContext];
  [currentContext setCompletionHandler: completionHandler];
  changes(currentContext);

  [NSAnimationContext endGrouping];
}

+ (void) beginGrouping
{
  NSMutableArray *contextStack = _NSGetAnimationContextForCurrentThread();
  NSAnimationContext *context = nil;

  if ([contextStack count] == 0)
    {
      context = [[NSAnimationContext alloc] init];
    }
  else
    {
      context = [contextStack lastObject];
      context = [context copyWithZone: [context zone]];
    }

  [contextStack addObject: context];
}

+ (void) endGrouping
{
  NSMutableArray *contextStack = _NSGetAnimationContextForCurrentThread();
  if ([contextStack count] > 0)
    {
      [[contextStack lastObject] _flushAnimations];
      [contextStack removeLastObject];
    }
}

+ (NSAnimationContext*) currentContext
{
  NSMutableArray *contextStack = _NSGetAnimationContextForCurrentThread();
  NSAnimationContext *context = nil;

  if ([contextStack count] == 0)
    {
      context = [[NSAnimationContext alloc] init];
    }
  else
    {
      context = [contextStack lastObject];
    }

  return context;
}

- (id) init
{
  _duration = 0.25;
  _animations = [[NSMutableArray alloc] init];
  _completionHandler = nil;
  _timingFunction = nil;
  _allowsImplicitAnimation = false;
  _isImplicitContext = false;

  return self;
}

- (id) copyWithZone: (NSZone*)zone
{
  NSAnimationContext *copy = [[[self class] alloc] init];
  copy->_completionHandler = [_completionHandler retain];
  copy->_timingFunction = [_timingFunction retain];
  return copy;
}

- (void) dealloc
{
  [_animations release];
  [_completionHandler release];
  [_timingFunction release];

  [super dealloc];
}

- (NSTimeInterval) duration
{
  return _duration;
}

- (void) setDuration: (NSTimeInterval)duration
{
  _duration = duration;
  [CATransaction setValue: [NSNumber numberWithDouble: duration] forKey: kCATransactionAnimationDuration];
}

- (CAMediaTimingFunction*) timingFunction
{
  return _timingFunction;
}

- (void) setTimingFunction: (CAMediaTimingFunction*)timingFunction
{
  _timingFunction = timingFunction;
  [CATransaction setAnimationTimingFunction: timingFunction];
}

- (void (^)(void)) completionHandler
{
  return [[_completionHandler retain] autorelease];
}

- (void) setCompletionHandler: (void (^)(void))completionHandler
{
  _completionHandler = completionHandler;
  [CATransaction setCompletionBlock: completionHandler];
}

- (BOOL) allowsImplicitAnimation
{
  return _allowsImplicitAnimation;
}

- (void) setAllowsImplicitAnimation: (BOOL)allowsImplicitAnimation
{
  _allowsImplicitAnimation = allowsImplicitAnimation;
}

@end
