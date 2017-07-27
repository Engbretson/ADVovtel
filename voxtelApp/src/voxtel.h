#include <epicsEvent.h>
#include "ADDriver.h"
#include <EGrabber.h>
#include <RGBConverter.h>


class epicsShareClass voxtel : public ADDriver {
public:
    voxtel(const char *portName, int maxSizeX, int maxSizeY, NDDataType_t dataType,
                int maxBuffers, size_t maxMemory,
                int priority, int stackSize);

    /* These are the methods that we override from ADDriver */
    virtual asynStatus writeInt32(asynUser *pasynUser, epicsInt32 value);
    virtual asynStatus writeFloat64(asynUser *pasynUser, epicsFloat64 value);
    virtual void report(FILE *fp, int details);
    void simTask(); /**< Should be private, but gets called from C, so must be public */
	void voxtelHandleReadOnlyParamsTask();

protected:


#define FIRST_voxtel_PARAM voxtel_aaa
#define LAST_voxtel_PARAM voxtel_zzz


private:
    /* These are the methods that are new to this class */

    /* Our data */
    epicsEventId startEventId;
    epicsEventId stopEventId;
	NDArray	*pImage;
};


#define NUM_voxtel_PARAMS ((int)(&LAST_voxtel_PARAM - &FIRST_voxtel_PARAM + 1))

