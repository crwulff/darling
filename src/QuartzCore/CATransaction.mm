
#import "CATransaction.h"

namespace CA {

Transaction *Transaction::_transaction = NULL;

Transaction* Transaction::ensure(void)
{
	if (!_transaction)
	{
		create();
	}

	return _transaction;
}

void Transaction::cf_release(CFTypeRef object)
{
	// TODO: I think this is supposed to queue up to release after the lock is released if it is currently held...
	CFRelease(object);
}

Transaction::Transaction(void)
{
}

void Transaction::create(void)
{
	static pthread_once_t once = PTHREAD_ONCE_INIT;
	pthread_once(&once, init);
}

void Transaction::init(void)
{
	_transaction = new Transaction();
}

void Transaction::push(void)
{
	AttrListNode *newAttributes = new AttrListNode();

	lock();
	newAttributes->next = _attrStack;
	_attrStack = newAttributes;
	unlock();
}

void Transaction::pop(void)
{
	lock();
	if (_attrStack)
	{
		AttrListNode *remove = _attrStack;
		_attrStack = _attrStack->next;
		delete remove;
	}
	unlock();
}

bool Transaction::get_value(CAAtom atom, CAValueType valueType, void *value)
{
	bool found = false;
	AttrListNode *current = _attrStack;
	while (current && !found)
	{
		found = current->attributes.get(atom, valueType, value);
	}

	return found;
}

void Transaction::set_value(CAAtom atom, CAValueType valueType, void *value)
{
	if (_attrStack)
	{
		_attrStack->attributes.set(atom, valueType, value);
	}
}

} // Namespace CA

@implementation CATransaction

+ (void) begin
{
	CA::Transaction::ensure()->push();
}

+ (void) commit
{
	CA::Transaction::ensure()->pop();
}

+ (void) flush
{
	// TODO
}

+ (void) lock
{
	CA::Transaction::ensure()->lock();
}

+ (void) unlock
{
	CA::Transaction::ensure()->unlock();
}

+ (CFTimeInterval) animationDuration
{
	CFTimeInterval duration;
	if (!CA::Transaction::ensure()->get_value(kCAAtom_duration, kCAValueTypeDouble, &duration))
	{
		duration = 0.25;
	}

	return duration;
}

+ (void) setAnimationDuration: (CFTimeInterval)duration
{
	CA::Transaction::ensure()->set_value(kCAAtom_duration, kCAValueTypeDouble, &duration);
}

+ (CAMediaTimingFunction*) animationTimingFunction
{
	CAMediaTimingFunction *timingFunction;

	if (!CA::Transaction::ensure()->get_value(kCAAtom_timingFunction, kCAValueTypeRetainedPointer, &timingFunction))
	{
		timingFunction = nil;
	}

	return timingFunction;
}

+ (void) setAnimationTimingFunction: (CAMediaTimingFunction*)function
{
	CA::Transaction::ensure()->set_value(kCAAtom_timingFunction, kCAValueTypeRetainedPointer, &function);
}

+ (BOOL) disableActions
{
	BOOL disable;

	if (!CA::Transaction::ensure()->get_value(kCAAtom_disableActions, kCAValueTypeBool, &disable))
	{
		disable = false;
	}

	return disable;
}

+ (void) setDisableActions: (BOOL)flag
{
	CA::Transaction::ensure()->set_value(kCAAtom_disableActions, kCAValueTypeBool, &flag);
}

#if __BLOCKS__
+ (void (^)(void)) completionBlock
{
	void (^block)(void);

	if (!CA::Transaction::ensure()->get_value(kCAAtom_completionBlock, kCAValueTypeBlock, &block))
	{
		block = nil;
	}

	return block;
}

+ (void) setCompletionBlock: (void (^)(void))block
{
	CA::Transaction::ensure()->set_value(kCAAtom_completionBlock, kCAValueTypeBlock, &block);
}
#endif

+ (id) valueForKey: (NSString *)key
{
	// TODO: Convert key to atom (creating a new atom if needed) and look up object in the attr list
	return nil;
}

+ (void) setValue: (id)anObject
           forKey: (NSString*)key
{
	// TODO: Convert key to atom (creating a new atom if needed) and set object in the attr list
}

@end

NSString * const kCATransactionAnimationDuration       = @"animationDuration";
NSString * const kCATransactionDisableActions          = @"disableActions";
NSString * const kCATransactionAnimationTimingFunction = @"timingFunction";
NSString * const kCATransactionCompletionBlock         = @"completionBlock";

