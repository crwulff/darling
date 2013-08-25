#ifndef COREVIDEO_H
#define COREVIDEO_H
#include <CoreServices/MacTypes.h>
#include "CVBase.h"
#include <OpenGL/CGLTypes.h>
#include "CVReturn.h"

class CVDisplayLink;

typedef CVDisplayLink* CVDisplayLinkRef;
typedef UInt32 CVOptionFlags;

typedef CVReturn (*CVDisplayLinkOutputCallback)(CVDisplayLinkRef displayLink, const CVTimeStamp *inNow, const CVTimeStamp *inOutputTime, CVOptionFlags flagsIn, CVOptionFlags *flagsOut, void *displayLinkContext);

extern "C" {

CVReturn CVDisplayLinkCreateWithActiveCGDisplays(CVDisplayLinkRef* displayLinkOut);

CVReturn CVDisplayLinkStart(CVDisplayLinkRef displayLink);
CVReturn CVDisplayLinkStop(CVDisplayLinkRef displayLink);
Boolean CVDisplayLinkIsRunning(CVDisplayLinkRef displayLink);

void CVDisplayLinkRelease(CVDisplayLinkRef displayLink);

CVReturn CVDisplayLinkSetOutputCallback(CVDisplayLinkRef displayLink, CVDisplayLinkOutputCallback callback, void *userInfo);
CVReturn CVDisplayLinkSetCurrentCGDisplayFromOpenGLContext(CVDisplayLinkRef displayLink, CGLContextObj cglContext, CGLPixelFormatObj cglPixelFormat);

}

#endif

