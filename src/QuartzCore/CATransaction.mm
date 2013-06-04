
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

} // Namespace CA

@implementation CATransaction
@end

NSString * const kCATransactionAnimationDuration       = @"animationDuration";
NSString * const kCATransactionDisableActions          = @"disableActions";
NSString * const kCATransactionAnimationTimingFunction = @"timingFunction";
NSString * const kCATransactionCompletionBlock         = @"completionBlock";
