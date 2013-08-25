#include "exceptions.h"
#include "return.h"
#include <stdio.h>

extern "C" void __cxa_rethrow();
extern "C" void* __cxa_begin_catch(void*);
extern "C" void __cxa_end_catch();

#define thread_local __thread

static thread_local bool m_cxx = false;

void __darwin_objc_exception_rethrow()
{
	__cxa_rethrow();
}

void* __darwin_objc_begin_catch(void* p)
{
	void *rv = returnReturn();
	void* cpp = __cxa_begin_catch(p);
	if (cpp)
	{
		m_cxx = true;
		return cpp;
	}
	else
	{
		m_cxx = false;
		return rv;
	}
}

void __darwin_objc_end_catch()
{
	if (m_cxx)
		__cxa_end_catch();
}

void* default_exception_preprocessor(void* exception)
{
	fprintf(stderr, "default_exception_preprocessor: exception %p\n", exception);
	return exception;
}

objc_exception_preprocessor exceptionPreprocessor = &default_exception_preprocessor;

objc_exception_preprocessor objc_setExceptionPreprocessor(objc_exception_preprocessor fn)
{
	fprintf(stderr, "objc_setExceptionPreprocessor %p\n", fn);
	objc_exception_preprocessor oldExceptionPreprocessor = exceptionPreprocessor;
	exceptionPreprocessor = fn;
	return oldExceptionPreprocessor;
}
