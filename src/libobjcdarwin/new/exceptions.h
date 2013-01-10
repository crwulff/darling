#ifndef OBJC_EXCEPTIONS_H
#define OBJC_EXCEPTIONS_H
#include "../visibility.h"

extern "C" {

typedef void* (*objc_exception_preprocessor)(void* exception);

DARLING_VISIBLE void objc_exception_rethrow();
DARLING_VISIBLE void* objc_begin_catch(void*);
DARLING_VISIBLE void objc_end_catch();

DARLING_VISIBLE objc_exception_preprocessor objc_setExceptionPreprocessor(objc_exception_preprocessor fn);

}

#endif

