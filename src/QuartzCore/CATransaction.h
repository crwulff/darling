
#import <Foundation/NSString.h>

#include "mutex.h"
#include <CoreFoundation/CFBase.h>

namespace CA {

class Transaction : public ::Darling::Mutex
{

	public:
		static Transaction* ensure(void);

		static void cf_release(CFTypeRef object);

	private:

		Transaction(void);

		static void create(void);

		static void init(void);

	private:

		static Transaction *_transaction;
};

} // namespace CA

@interface CATransaction : NSObject
@end

extern "C" {

extern NSString * const kCATransactionAnimationDuration;
extern NSString * const kCATransactionDisableActions;
extern NSString * const kCATransactionAnimationTimingFunction;
extern NSString * const kCATransactionCompletionBlock;

} // extern "C"
