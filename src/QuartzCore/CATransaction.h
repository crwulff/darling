
#ifndef _CATransaction_H_
#define _CATransaction_H_

#import <Foundation/NSString.h>

#include "mutex.h"
#include <CoreFoundation/CFBase.h>

#include "CAAtoms.h"
#include "CAAttrList.h"
#include "CAMediaTimingFunction.h"

namespace CA {

class Transaction : public ::Darling::Mutex
{

	public:
		void push(void);

		void pop(void);

		bool get_value(CAAtom atom, CAValueType valueType, void *value);

		void set_value(CAAtom atom, CAValueType valueType, void *value);

	public:
		static Transaction* ensure(void);

		static void cf_release(CFTypeRef object);

	private:

		Transaction(void);

		static void create(void);

		static void init(void);

	private:

		class AttrListNode
		{
			public:
				AttrListNode *next;
				AttrList      attributes;
		};

	private:

		static Transaction *_transaction;

		AttrListNode *_attrStack;
};

} // namespace CA

@interface CATransaction : NSObject

+ (void) begin;

+ (void) commit;

+ (void) flush;

+ (void) lock;
+ (void) unlock;

+ (CFTimeInterval) animationDuration;
+ (void) setAnimationDuration: (CFTimeInterval)duration;

+ (CAMediaTimingFunction*) animationTimingFunction;
+ (void) setAnimationTimingFunction: (CAMediaTimingFunction*)function;

+ (BOOL) disableActions;
+ (void) setDisableActions: (BOOL)flag;

#if __BLOCKS__
+ (void (^)(void)) completionBlock;
+ (void) setCompletionBlock: (void (^)(void))block;
#endif

+ (id) valueForKey: (NSString *)key;
+ (void) setValue: (id)anObject
           forKey: (NSString*)key;

@end

extern "C" {

extern NSString * const kCATransactionAnimationDuration;
extern NSString * const kCATransactionDisableActions;
extern NSString * const kCATransactionAnimationTimingFunction;
extern NSString * const kCATransactionCompletionBlock;

} // extern "C"

#endif
