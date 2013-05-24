
#include "AEDataModel.h"

#include <CoreServices/MacTypes.h>

extern "C" {

extern OSErr
AEGetEventHandler(
	AEEventClass       theAEEventClass,
	AEEventID          theAEEventID,
	AEEventHandlerUPP *handler,
	SRefCon *          handlerRefcon,
	Boolean            isSysHandler);

extern OSErr
AEInstallEventHandler(
	AEEventClass theAEEventClass,
	AEEventID theAEEventID,
	AEEventHandlerUPP handler,
	SRefCon handlerRefcon,
	Boolean isSysHandler);

};
