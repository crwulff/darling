
#include "AppleEvents.h"

OSErr
AEGetEventHandler(
	AEEventClass       theAEEventClass,
	AEEventID          theAEEventID,
	AEEventHandlerUPP *handler,
	SRefCon *          handlerRefcon,
	Boolean            isSysHandler)
{
	// TODO
	return 0;
}

OSErr
AEInstallEventHandler(
	AEEventClass theAEEventClass,
	AEEventID theAEEventID,
	AEEventHandlerUPP handler,
	SRefCon handlerRefcon,
	Boolean isSysHandler)
{
	// TODO
	return 0;
}

