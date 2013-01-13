#include "exceptions.h"
#include "return.h"
#include <stdio.h>

extern "C" void __cxa_rethrow();
extern "C" void* __cxa_begin_catch(void*);
extern "C" void __cxa_end_catch();

static __thread bool m_cxx = false;

void objc_exception_rethrow()
{
	__cxa_rethrow();
}

void* objc_begin_catch(void* p)
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

void objc_end_catch()
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
