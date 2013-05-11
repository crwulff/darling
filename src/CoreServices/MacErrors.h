#ifndef MACERRORS_H
#define MACERRORS_H
#include <CoreFoundation/CFBase.h>

inline OSStatus makeOSStatus(int errNo) { return 100000 + errNo; }

#define noErr		0
#define unimpErr	-4
#define fnfErr		-43 // file not found
#define paramErr	-50
#define handlerNotFoundErr -1856
#define kLocalesBufferTooSmallErr -30001
#define kUCOutputBufferTooSmall -25340

// Gestalt errors
#define gestaltUnknownErr       (-5550)
#define gestaltUndefSelectorErr (-5551)
#define gestaltDupSelectorErr   (-5552)
#define gestaltLocationErr      (-5553)

#endif
