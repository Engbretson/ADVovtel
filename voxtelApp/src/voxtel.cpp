
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>

#include <epicsTime.h>
#include <epicsThread.h>
#include <epicsEvent.h>
#include <epicsTimer.h>
#include <epicsMutex.h>
#include <epicsStdlib.h>
#include <epicsString.h>
#include <epicsStdio.h>
#include <epicsMutex.h>
#include <cantProceed.h>
#include <iocsh.h>
#include <asynOctetSyncIO.h>

#include "ADDriver.h"
#define _VOXTELIOC_


#ifndef _WIN32
#define FALSE false
#define TRUE true
#endif

#include <epicsExport.h>
#include "voxtel.h"
#include "com_functions.h"
#include "matrox_functions.h"

static const char *driverName = "voxtel";

/**
* runs on thread for seding and receiving serial port message.
* @param drvPvt    Pointer to pco object, and ADDriver.
*/


void voxtel::do_Initialize()
{
	printf("Performing Voxtal Initialize To Defaults\n");

//	printme = 0;

//	Do_Write_Read("Disable_Pattern_Generation", m_portHandle, Disable_Pattern_Generation);
//	setIntegerParam(voxtel_disable_test_pattern_generation, 1);
//	callParamCallbacks();

	Do_Write_Read("Frame_Stop", m_portHandle, Frame_Stop);
	Do_Write_Read("Program_ADC", m_portHandle, Program_ADC);
	Do_Write_Read("Initialize_DACTable", m_portHandle, Initialize_DACTable);
	Do_Write_Read("Program_DAC", m_portHandle, Program_DAC_0);
	Do_Write_Read("Write_DSI__1", m_portHandle, Write_DSI__1);
	Do_Write_Read("Counter_Mode_8", m_portHandle, Counter_Mode_8);
	Do_Write_Read("Write_DSI__2", m_portHandle, Write_DSI__2);
	Do_Write_Read("Write_DSI__3", m_portHandle, Write_DSI__3);

	setIntegerParam(voxtel_initialize, 1);
	setIntegerParam(voxtel_frame_stop, 1);
	setIntegerParam(voxtel_counter_mode_select, 8);
	callParamCallbacks();


	Do_Write_Integration_Time(m_portHandle, 100.0);
	setDoubleParam(voxtel_integration_time, 100.0);
//	Do_Write_Integration_Time(m_portHandle, 4.0);
//	setDoubleParam(voxtel_integration_time, 4.0);

	callParamCallbacks();

	Do_Write_Threshold1(m_portHandle, 2.5);
	setDoubleParam(voxtel_threashold_1, 2.5);
	callParamCallbacks();

	Do_Write_Threshold2(m_portHandle, 2.5);
	setDoubleParam(voxtel_threashold_2, 2.5);
	callParamCallbacks();

	setIntegerParam(voxtel_pixel_test_inject_location_col, 255);
	setIntegerParam(voxtel_pixel_test_inject_location_row, 255);
	callParamCallbacks();

//	printme = 1;

	printf("End Of  Voxtal Initialize All\n");
}

static void voxtelTaskC(void *drvPvt) {
	voxtel *pPvt = (voxtel *)drvPvt;
	pPvt->voxtelTask();
}

void voxtel::voxtelTask()
{
	NDDataType_t dataType;
	int arrayCallbacks = 1;
	int imageCounter = 0;
	size_t dims[2];
	epicsTimeStamp startTime, endTime;
	double elapsedTime;
	uint32_t size;

	int astatus = asynSuccess;
	int acquire;
	int iMode, numImages, numImagesCounter;
	const char *functionName = "voxtelTask";
	dims[0] = 0;
	dims[1] = 0;

	this->lock();
 //  printf("Initializing voxtelTask() \n");

	// Loop forever
	while (1) {
		// Is acquisition active?
		getIntegerParam(ADAcquire, &acquire);
		callParamCallbacks();
		// If we are not acquiring then wait for a semaphore that is given when acquisition is started
		if (!acquire) {
			// Release the lock while we wait for an event that says acquire has started, then lock again
			asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW,
				"%s:%s: waiting for acquire to start\n", driverName, functionName);
			setIntegerParam(ADNumImagesCounter, 0);
			callParamCallbacks();
			this->unlock();
			astatus = epicsEventWait(this->startEventId);
			this->lock();
		}

//		if (printme) printf("Starting Acquire \n");


	// start acq
		getIntegerParam(ADImageMode, &iMode);
		getIntegerParam(ADNumImages, &numImages);
		getIntegerParam(ADNumImagesCounter, &numImagesCounter);
		getIntegerParam(NDArrayCounter, &imageCounter);
		setIntegerParam(ADStatus, ADStatusInitializing);
		callParamCallbacks();
//		imageCounter++;
//		numImagesCounter++;

//		setIntegerParam(NDArrayCounter, imageCounter);
//		setIntegerParam(ADNumImagesCounter, numImagesCounter);

//		callParamCallbacks();


		////
#ifdef BIG_COMMENT
		Ok, what is requested is that by this point, we have preallocated as much memory as we can so then when the buffer comes back to use a filled,
			we just copy the contents and the timestamp to memory and repeat until the number of images has expired.
			Then we hit the following code using our cached memory values, not fresh values from the camera.
			we do this from the image count which, I guess, is validated from available memory

#endif
			////

			while (1) {
				setIntegerParam(ADStatus, ADStatusAcquire);
				callParamCallbacks();
				this->unlock();
				try
				{
	try
	{
//					MbufClear(MilImage, M_WHITE);
					MbufClear(MilImage, 0);
					MdigGrab(MilDigitizer, MilImage);
					MbufGet(MilImage, buffer);

	}
	catch (...) {
		 printf("Acquire Error of some sort\n");
	}

				}
				catch (...)
				{
					if (printme) printf("Error in acquire from digitizer\n");
				}
				epicsTimeGetCurrent(&startTime);

				this->lock();
				setIntegerParam(ADStatus, ADStatusReadout);
				callParamCallbacks();

				getIntegerParam(NDDataType, (int *)&dataType);
				getIntegerParam(NDArrayCallbacks, &arrayCallbacks);

				// playing with empty databuffers seem to have little real life use
				if (arrayCallbacks) {
					getIntegerParam(ADMaxSizeX, (int *)&dims[0]);
					getIntegerParam(ADMaxSizeY, (int *)&dims[1]);

				}

				////				dataType = NDUInt8;

				switch (dataType) {
				case 0:
					size = dims[0] * dims[1] * sizeof(int8_t);
					break;
				case 1:
					size = dims[0] * dims[1] * sizeof(uint8_t);
					break;
				case 2:
					size = dims[0] * dims[1] * sizeof(int16_t);
					break;
				case 3:
					size = dims[0] * dims[1] * sizeof(uint16_t);  
					break;
				case 4:
					size = dims[0] * dims[1] * sizeof(int32_t);
					break;
				case 5:
					size = dims[0] * dims[1] * sizeof(uint32_t);
					break;
				default:
					size = dims[0] * dims[1] * sizeof(uint8_t);
				}

//				if (printme) printf("arrayCallbacks %d \n", arrayCallbacks);
//				if (printme) printf("dataType %d \n", dataType);
//				if (printme) printf("dims 0 X %d \n", dims[0]);
//				if (printme) printf("dims 1 y %d \n", dims[1]);
//				if (printme) printf("size %d \n", size);

				//			dataType = NDUInt16;
				//			dims[0] = 4096;
				//			dims[1] = 3072;
				//			arrayCallbacks = 1;

				this->pImage = this->pNDArrayPool->alloc(2, dims, dataType, 0, NULL);
				//							this->pImage = this->pNDArrayPool->alloc(2, dims, dataType, 2, NULL);

				if (!this->pImage) {
					asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR,
						"%s:%s: error allocating image buffer\n",
						driverName, functionName);
					break;

				}

				// Put the frame number and time stamp into the buffer
				// Set the the start time

				pImage->uniqueId = imageCounter;
				pImage->timeStamp = startTime.secPastEpoch + startTime.nsec / 1.e9;

//				if (printme) printf("Before Copy1 \n");
				try
				{
					memcpy(pImage->pData, buffer, size);
				}
				catch (...)
				{
					if (printme) printf("Error copying data from digitizer\n");
				}

//				if (printme) printf("After Copy \n");

				// Get any attributes that have been defined for this driver        
				this->getAttributes(pImage->pAttributeList);

				// Call the NDArray callback
				asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW,
					"%s:%s: calling NDArray callback\n", driverName, functionName);

				this->unlock();
				doCallbacksGenericPointer(pImage, NDArrayData, 0);
				this->lock();

				getIntegerParam(ADNumImagesCounter, &numImagesCounter);
				getIntegerParam(NDArrayCounter, &imageCounter);

				imageCounter++;
				numImagesCounter++;

				setIntegerParam(NDArrayCounter, imageCounter);
				setIntegerParam(ADNumImagesCounter, numImagesCounter);

				callParamCallbacks();


				pImage->release();

				this->unlock();
				astatus = epicsEventWaitWithTimeout(this->stopEventId, 0.0);
				this->lock();

				if (astatus == epicsEventWaitOK) break;
				if ((numImagesCounter >= numImages) && (iMode == ADImageMultiple)) break;
				if ((numImagesCounter >= 1) && (iMode == ADImageSingle)) break;
			}

		// finish acq
		setIntegerParam(ADAcquire, 0);
		callParamCallbacks();
		setIntegerParam(ADStatus, ADStatusIdle);
		callParamCallbacks();

	}
}

/**
* Override from super class to handle detector specific parameters.
* If the parameter is from one of the super classes and is not handled
* here, then pass along to ADDriver (direct super class)
*/
asynStatus voxtel::writeOctet(asynUser* pasynUser, const char *value,
	size_t nChars, size_t *nActual) {
	int status = asynSuccess;
	int function = pasynUser->reason;

//	if (printme) printf("I am in the write Octet routine %d %s\n", function, value);

	if (function < FIRST_voxtel_PARAM) {
		status = ADDriver::writeOctet(pasynUser, value, nChars, nActual);
	}

	callParamCallbacks();

	return (asynStatus)status;
}

asynStatus voxtel::writeInt32(asynUser *pasynUser, epicsInt32 value) {
	int function = pasynUser->reason;
	int adstatus;
	int acquiring;
	int imageMode;

	asynStatus status = asynSuccess;
	char mesx2[256];
//	char *mesx2;

	status = setIntegerParam(function, value);
//	getParamName(function, (const char **)&mesx2);
 printf("in writeInt32 function %d value %d \n", function, value);

///	sprintf(mesx, "voxtel::writeInt32, param=%s, value=%d", mesx2, value);
///	lf.log(mesx);

// don't do any of these at the moment
/*
 if (
	 (function == 54) |
	 (function == 55) |
	 (function == 56) |
	 (function == 57) |
	 (function == 58) |
	 (function == 59) |
	 (function == 62) |
	 (function == 63) |
	 (function == 9) |
	 (function == 10)
	 ) return (status);
*/

/* Ensure that ADStatus is set correctly before we set ADAcquire.*/
	getIntegerParam(ADStatus, &adstatus);
	getIntegerParam(ADAcquire, &acquiring);
	getIntegerParam(ADImageMode, &imageMode);

	if (function == ADAcquire) {
		if (value && !acquiring) {
			setStringParam(ADStatusMessage, "Acquiring data");
		}
		if (!value && acquiring) {
			setStringParam(ADStatusMessage, "Acquisition stopped");
			if (imageMode == ADImageContinuous) {
				setIntegerParam(ADStatus, ADStatusIdle);
			}
			else {
				setIntegerParam(ADStatus, ADStatusAborted);
			}
			setIntegerParam(ADStatus, ADStatusAcquire);
		}
	}
	callParamCallbacks();


	if (function == voxtel_initialize) {
		do_Initialize();
	}
	if(function == voxtel_frame_stop) {
		Do_Write_Read("Frame_Stop", m_portHandle, Frame_Stop);
		setIntegerParam(voxtel_frame_start, 0);
		callParamCallbacks();
	}
	if(function == voxtel_frame_start) {
		Do_Write_Read("Frame_Start", m_portHandle, Frame_Start);
		setIntegerParam(voxtel_frame_stop, 0);
		callParamCallbacks();
	}

	if (function == voxtel_counter_mode_select) {
		switch (value)
		{
		case 1:
			break;
		case 2:
			Do_Write_Read("Counter_Mode_2", m_portHandle, Counter_Mode_2);
			Do_Write_Read("Write_DSI__3", m_portHandle, Write_DSI__3);
			break;
		case 3:
			Do_Write_Read("Counter_Mode_3", m_portHandle, Counter_Mode_3);
			Do_Write_Read("Write_DSI__3", m_portHandle, Write_DSI__3);
			break;
		case 4:
			break;
		case 5:
			Do_Write_Read("Counter_Mode_5", m_portHandle, Counter_Mode_5);
			Do_Write_Read("Write_DSI__3", m_portHandle, Write_DSI__3);
			break;
		case 6:
			break;
		case 7:
			Do_Write_Read("Counter_Mode_7", m_portHandle, Counter_Mode_7);
			Do_Write_Read("Write_DSI__3", m_portHandle, Write_DSI__3);
			break;
		case 8:
			Do_Write_Read("Counter_Mode_8", m_portHandle, Counter_Mode_8);
			Do_Write_Read("Write_DSI__3", m_portHandle, Write_DSI__3);
			break;
		}
	}

	if (function == voxtel_pixel_test_inject_location_row) {
		if (printme) printf("Pixel test injection row %d\n", value);
	}

	if (function == voxtel_pixel_test_inject_location_col) {
		if (printme) printf("Pixel test injection col %d\n", value);
	}

	if (function == voxtel_pixel_test_inject_location) {
		int row, col;
		getIntegerParam(voxtel_pixel_test_inject_location_col, &col);
		getIntegerParam(voxtel_pixel_test_inject_location_row, &row);
		Do_Write_Pixel_Test_Inject_Location(m_portHandle, col, row);
	}

	if (function == voxtel_enable_test_pattern_generation) {
		Do_Write_Read("Enable_Pattern_Generation", m_portHandle, Enable_Pattern_Generation);
		setIntegerParam(voxtel_disable_test_pattern_generation, 0);
		callParamCallbacks();
	}
	if (function == voxtel_disable_test_pattern_generation) {
		Do_Write_Read("Disable_Pattern_Generation", m_portHandle, Disable_Pattern_Generation);
		setIntegerParam(voxtel_enable_test_pattern_generation, 0);
		callParamCallbacks();
	}
	if (function == voxtel_print_dactable) {
		Do_Write_Read("Print_DAC_Table", m_portHandle, "t0000");
	}

	if ((function == ADAcquire) & (value == 1)) {
		epicsEventSignal(this->startEventId);
	}
	if ((function == ADAcquire) & (value == 0)) {
		epicsEventSignal(this->stopEventId);
	}

/* If this parameter belongs to a base class call its method */
	
	callParamCallbacks();

	if (function < FIRST_voxtel_PARAM) 
		status = ADDriver::writeInt32(pasynUser, value);

	callParamCallbacks();

	status = asynSuccess;
	return (status);
}

/** Called when asyn clients call pasynFloat64->write().
* This function performs actions for some parameters.
* For all parameters it sets the value in the parameter library and calls any
* registered callbacks..
* \param[in] pasynUser pasynUser structure that encodes the reason and
* address.
* \param[in] value Value to write. */
asynStatus voxtel::writeFloat64(asynUser *pasynUser, epicsFloat64 value) {
	int function = pasynUser->reason;
	asynStatus status = asynSuccess;

//	status = setDoubleParam(function, value);

///	char mesx[256];
///	char *mesx2;

///	getParamName(function, (const char **)&mesx2);

///	sprintf(mesx, "voxtel::writeFloat64, param=%s, value=%f", mesx2, value);
///	lf.log(mesx);

	printf("in writeFloat64 function %d value %f \n", function, value);

	// don't do any of these at the moment
	if (
		(function == 53) 
		) return (status);

if (function == voxtel_integration_time) {
	value = max(min(1000.0, value), 1.0);
	Do_Write_Integration_Time(m_portHandle, value);
	}

if (function == voxtel_threashold_1) {
		value = max(min(2.5, value), 1.5);
		Do_Write_Threshold1(m_portHandle, value);
}

if (function == voxtel_threashold_2) {
		value = max(min(2.5, value), 1.5);
		Do_Write_Threshold2(m_portHandle, value);
}

// in the event that we min/maxed the value, after it after the fact


status = setDoubleParam(function, value);
callParamCallbacks();

/* If this parameter belongs to a base class call its method */
if (function < FIRST_voxtel_PARAM)
	status =ADDriver::writeFloat64(pasynUser, value);

	callParamCallbacks();

	return (status);
}

/** Report status of the driver.
* Prints details about the driver if details>0.
* It then calls the ADDriver::report() method.
* \param[in] fp File pointed passed by caller where the output is written to.
* \param[in] details If >0 then driver details are printed.
*/
void voxtel::report(FILE *fp, int details) {
	 fprintf(fp, "VOXTEL detector %s\n", this->portName);
	if (details > 0) {
		int nx, ny;
		getIntegerParam(ADSizeX, &nx);
		getIntegerParam(ADSizeY, &ny);
		fprintf(fp, "  NX, NY:            %d  %d\n", nx, ny);
	}
	/* Invoke the base class method */
	ADDriver::report(fp, details);
}


/** Constructor for voxtel driver; most parameters are simply passed to
* ADDriver::ADDriver.
* After calling the base class constructor this method creates a thread to
* collect the detector data,
* and sets reasonable default values the parameters defined in this class,
* asynNDArrayDriver, and ADDriver.
* \param[in] portName The name of the asyn port driver to be created.
* \param[in] serverPort The name of the asyn port driver previously created
* with drvAsynIPPortConfigure
*            connected to the voxtel_server program.
* \param[in] maxBuffers The maximum number of NDArray buffers that the
* NDArrayPool for this driver is
*            allowed to allocate. Set this to -1 to allow an unlimited number
* of buffers.
* \param[in] maxMemory The maximum amount of memory that the NDArrayPool for
* this driver is
*            allowed to allocate. Set this to -1 to allow an unlimited amount
* of memory.
* \param[in] priority The thread priority for the asyn port driver thread if
* ASYN_CANBLOCK is set in asynFlags.
* \param[in] stackSize The stack size for the asyn port driver thread if
* ASYN_CANBLOCK is set in asynFlags.
*/

///voxtel::voxtel(const char *portName, const char *serverPort, int maxBuffers,
///	size_t maxMemory, int priority, int stackSize)
voxtel::voxtel(const char *portName, int maxSizeX, int maxSizeY, NDDataType_t dataType,
		int maxBuffers, size_t maxMemory, int priority, int stackSize)
	//	: ADCameralink(portName, serverPort, NUM_voxtel_PARAMS, maxBuffers, maxMemory,
//		priority, stackSize)
:ADDriver(portName, 1, NUM_voxtel_PARAMS, maxBuffers, maxMemory,
	0, 0, /* No interfaces beyond those set in ADDriver.cpp */
	0, 1, /* ASYN_CANBLOCK=0, ASYN_MULTIDEVICE=0, autoConnect=1 */
	priority, stackSize)
		{
	int status;
	const char *functionName = "voxtelDetector";

//	printf("Starting voxtel::voxtel constructor\n");

	/* Create the epicsEvents for signaling to the acquire task when acquisition starts and stops */
	startEventId = epicsEventCreate(epicsEventEmpty);
	if (!startEventId) {
		if (printme) printf("%s:%s epicsEventCreate failure for start event\n",
			driverName, functionName);
		return;
	}
	stopEventId = epicsEventCreate(epicsEventEmpty);
	if (!stopEventId) {
		if (printme) printf("%s:%s epicsEventCreate failure for stop event\n",
			driverName, functionName);
		return;
	}

//	printf("after event creations\n");

//	createParam("voxtel_initialize", asynParamOctet, &voxtel_initialize);
	createParam("voxtel_initialize", asynParamInt32, &voxtel_initialize);
	createParam("voxtel_counter_mode_select", asynParamInt32, &voxtel_counter_mode_select);
	createParam("voxtel_integration_time", asynParamFloat64, &voxtel_integration_time);
//	createParam("voxtel_frame_start", asynParamOctet, &voxtel_frame_start);
//	createParam("voxtel_frame_stop", asynParamOctet, &voxtel_frame_stop);
	createParam("voxtel_frame_start", asynParamInt32, &voxtel_frame_start);
	createParam("voxtel_frame_stop", asynParamInt32, &voxtel_frame_stop);
	createParam("voxtel_threashold_1", asynParamFloat64, &voxtel_threashold_1);
	createParam("voxtel_threashold_2", asynParamFloat64, &voxtel_threashold_2);
	createParam("voxtel_pixel_test_inject_location_row", asynParamInt32, &voxtel_pixel_test_inject_location_row);
	createParam("voxtel_pixel_test_inject_location_col", asynParamInt32, &voxtel_pixel_test_inject_location_col);
//	createParam("voxtel_pixel_test_inject_location", asynParamOctet, &voxtel_pixel_test_inject_location);
	createParam("voxtel_pixel_test_inject_location", asynParamInt32, &voxtel_pixel_test_inject_location);
	createParam("voxtel_enable_test_pattern_generation", asynParamInt32, &voxtel_enable_test_pattern_generation);
	createParam("voxtel_disable_test_pattern_generation", asynParamInt32, &voxtel_disable_test_pattern_generation);
	createParam("voxtel_print_dactable", asynParamInt32, &voxtel_print_dactable);

	createParam("voxtel_VP01", asynParamInt32, &voxtel_VP01);
	createParam("voxtel_VP02", asynParamInt32, &voxtel_VP02);
	createParam("voxtel_VP03", asynParamInt32, &voxtel_VP03);
	createParam("voxtel_VP04", asynParamInt32, &voxtel_VP04);
	createParam("voxtel_VP05", asynParamInt32, &voxtel_VP05);
	createParam("voxtel_VP06", asynParamInt32, &voxtel_VP06);

/*
	createParam("voxtel_VP01", asynParamFloat64, &voxtel_VP01);
	createParam("voxtel_VP02", asynParamFloat64, &voxtel_VP02);
	createParam("voxtel_VP03", asynParamFloat64, &voxtel_VP03);
	createParam("voxtel_VP04", asynParamFloat64, &voxtel_VP04);
	createParam("voxtel_VP05", asynParamFloat64, &voxtel_VP05);
	createParam("voxtel_VP06", asynParamFloat64, &voxtel_VP06);
*/

	createParam("voxtel_CC01", asynParamInt32, &voxtel_CC01);
	createParam("voxtel_CC02", asynParamInt32, &voxtel_CC02);
	createParam("voxtel_CC03", asynParamInt32, &voxtel_CC03);
	createParam("voxtel_CC04", asynParamInt32, &voxtel_CC04);
	createParam("voxtel_CC05", asynParamInt32, &voxtel_CC05);
	createParam("voxtel_CC06", asynParamInt32, &voxtel_CC06);
	createParam("voxtel_CC07", asynParamInt32, &voxtel_CC07);
	createParam("voxtel_CC08", asynParamInt32, &voxtel_CC08);
	createParam("voxtel_CC09", asynParamInt32, &voxtel_CC09);
	createParam("voxtel_CC10", asynParamInt32, &voxtel_CC10);
	createParam("voxtel_CC11", asynParamInt32, &voxtel_CC11);
	createParam("voxtel_CC12", asynParamInt32, &voxtel_CC12);

/*
	createParam("voxtel_CC01", asynParamFloat64, &voxtel_CC01);
	createParam("voxtel_CC02", asynParamFloat64, &voxtel_CC02);
	createParam("voxtel_CC03", asynParamFloat64, &voxtel_CC03);
	createParam("voxtel_CC04", asynParamFloat64, &voxtel_CC04);
	createParam("voxtel_CC05", asynParamFloat64, &voxtel_CC05);
	createParam("voxtel_CC06", asynParamFloat64, &voxtel_CC06);
	createParam("voxtel_CC07", asynParamFloat64, &voxtel_CC07);
	createParam("voxtel_CC08", asynParamFloat64, &voxtel_CC08);
	createParam("voxtel_CC09", asynParamFloat64, &voxtel_CC09);
	createParam("voxtel_CC10", asynParamFloat64, &voxtel_CC10);
	createParam("voxtel_CC11", asynParamFloat64, &voxtel_CC11);
	createParam("voxtel_CC12", asynParamFloat64, &voxtel_CC12);
*/

	createParam("voxtel_IREF", asynParamInt32, &voxtel_IREF);
//	createParam("voxtel_IREF", asynParamFloat64, &voxtel_IREF);

	createParam("voxtel_VV01", asynParamInt32, &voxtel_VV01);
	createParam("voxtel_VV02", asynParamInt32, &voxtel_VV02);
	createParam("voxtel_VV03", asynParamInt32, &voxtel_VV03);
	createParam("voxtel_VV04", asynParamInt32, &voxtel_VV04);
	createParam("voxtel_VV05", asynParamInt32, &voxtel_VV05);
	createParam("voxtel_VV06", asynParamInt32, &voxtel_VV06);
	createParam("voxtel_VV07", asynParamInt32, &voxtel_VV07);
	createParam("voxtel_VV08", asynParamInt32, &voxtel_VV08);
	createParam("voxtel_VV09", asynParamInt32, &voxtel_VV09);
	createParam("voxtel_VV10", asynParamInt32, &voxtel_VV10);

/*
	createParam("voxtel_VV01", asynParamFloat, &voxtel_VV01);
	createParam("voxtel_VV02", asynParamFloat, &voxtel_VV02);
	createParam("voxtel_VV03", asynParamFloat, &voxtel_VV03);
	createParam("voxtel_VV04", asynParamFloat, &voxtel_VV04);
	createParam("voxtel_VV05", asynParamFloat, &voxtel_VV05);
	createParam("voxtel_VV06", asynParamFloat, &voxtel_VV06);
	createParam("voxtel_VV07", asynParamFloat, &voxtel_VV07);
	createParam("voxtel_VV08", asynParamFloat, &voxtel_VV08);
	createParam("voxtel_VV09", asynParamFloat, &voxtel_VV09);
	createParam("voxtel_VV10", asynParamFloat, &voxtel_VV10);

*/

//	printf("After createParams \n");

// Skip this, I have to initial EVERYTHING to a known state anyway.

//	printf("Starting voxtel set params \n");

	setIntegerParam(voxtel_initialize, 1);	
	setIntegerParam(voxtel_counter_mode_select, 8);
	setIntegerParam(voxtel_pixel_test_inject_location_col, 255);
	setIntegerParam(voxtel_pixel_test_inject_location_row, 255);

	setDoubleParam(voxtel_integration_time, 100.0);
	setDoubleParam(voxtel_threashold_1, 2.5);
	setDoubleParam(voxtel_threashold_2, 2.5);

	setIntegerParam(voxtel_frame_stop, 1);
	setIntegerParam(voxtel_disable_test_pattern_generation, 1);

	setIntegerParam(voxtel_VP01, 0x828E);
	setIntegerParam(voxtel_VP02, 0x828E);
	setIntegerParam(voxtel_VP03, 0x0A34);
	setIntegerParam(voxtel_VP04, 0x0A34);
	setIntegerParam(voxtel_VP05, 0x0A34);
	setIntegerParam(voxtel_VP06, 0x828E);

	setIntegerParam(voxtel_CC01, 0x411A);
	setIntegerParam(voxtel_CC02, 0x6CC2);
	setIntegerParam(voxtel_CC03, 0x6CC2);
	setIntegerParam(voxtel_CC04, 0x4D93);
	setIntegerParam(voxtel_CC05, 0x4D93);
	setIntegerParam(voxtel_CC06, 0x4D93);
	setIntegerParam(voxtel_CC07, 0x4D93);
	setIntegerParam(voxtel_CC08, 0x4D93);
	setIntegerParam(voxtel_CC09, 0x4D93);
	setIntegerParam(voxtel_CC10, 0x4D93);
	setIntegerParam(voxtel_CC11, 0x4D93);
	setIntegerParam(voxtel_CC12, 0x4D93);

	setIntegerParam(voxtel_IREF, 0x4D93);

	setIntegerParam(voxtel_VV01, 0xC1F0);
	setIntegerParam(voxtel_VV02, 0xC1F0);
	setIntegerParam(voxtel_VV03, 0x07C1);
	setIntegerParam(voxtel_VV04, 0x0000);
	setIntegerParam(voxtel_VV05, 0x0000);
	setIntegerParam(voxtel_VV06, 0x0000);
	setIntegerParam(voxtel_VV07, 0x0000);
	setIntegerParam(voxtel_VV08, 0x0000);
	setIntegerParam(voxtel_VV09, 0x0000);
	setIntegerParam(voxtel_VV10, 0x0000);

	setIntegerParam(voxtel_VP01, 0x828E);
	setIntegerParam(voxtel_VP02, 0x828E);
	setIntegerParam(voxtel_VP03, 0x0A34);
	setIntegerParam(voxtel_VP04, 0x0A34);
	setIntegerParam(voxtel_VP05, 0x0A34);
	setIntegerParam(voxtel_VP06, 0x828E);

	/*
	setDoubleParam(voxtel_CC01, 0x411A);
	setDoubleParam(voxtel_CC02, 0x6CC2);
	setDoubleParam(voxtel_CC03, 0x6CC2);
	setDoubleParam(voxtel_CC04, 0x4D93);
	setDoubleParam(voxtel_CC05, 0x4D93);
	setDoubleParam(voxtel_CC06, 0x4D93);
	setDoubleParam(voxtel_CC07, 0x4D93);
	setDoubleParam(voxtel_CC08, 0x4D93);
	setDoubleParam(voxtel_CC09, 0x4D93);
	setDoubleParam(voxtel_CC10, 0x4D93);
	setDoubleParam(voxtel_CC11, 0x4D93);
	setDoubleParam(voxtel_CC12, 0x4D93);

	setDoubleParam(voxtel_IREF, 0x4D93);

	setDoubleParam(voxtel_VV01, 0xC1F0);
	setDoubleParam(voxtel_VV02, 0xC1F0);
	setDoubleParam(voxtel_VV03, 0x07C1);
	setDoubleParam(voxtel_VV04, 0x0000);
	setDoubleParam(voxtel_VV05, 0x0000);
	setDoubleParam(voxtel_VV06, 0x0000);
	setDoubleParam(voxtel_VV07, 0x0000);
	setDoubleParam(voxtel_VV08, 0x0000);
	setDoubleParam(voxtel_VV09, 0x0000);
	setDoubleParam(voxtel_VV10, 0x0000);
*/

//	printf("Done with voxtel set params \n");


	/* Allocate MIL defaults. */
//	MappAllocDefault(M_DEFAULT, &MilApplication, &MilSystem, &MilDisplay, &MilDigitizer, &MilImage);
/* Allocate application and system. */
	try
	{
		MappAlloc(M_NULL, M_DEFAULT, &MilApplication);
	}
	catch (...) {
		printf("MappAlloc Error \n");
	}
	try
	{
		MsysAlloc(M_DEFAULT, M_SYSTEM_DEFAULT, M_DEFAULT, M_DEFAULT, &MilSystem);
	}
	catch (...) {
		 printf("MsysAlloc Error \n");
	}
	/* Allocate digitizers using the default DCF. */
	try
	{
//		MdigAlloc(MilSystem, M_DEFAULT, MIL_TEXT("M_DEFAULT"), M_DEFAULT, &MilDigitizer);
		MdigAlloc(MilSystem, M_DEFAULT, "C:\\epics\\Vx810.dcf", M_DEFAULT, &MilDigitizer);

	}
	catch (const std::exception &e) {
		 printf("MdigAlloc Error \n");
	}

	/* Allocate the grab buffers for each digitizer and clear them. */
	try
	{
		MappControl(M_DEFAULT, M_ERROR, M_PRINT_DISABLE);
	}
	catch (const std::exception &e) {
		 printf("MappControl Error \n");
	}

	MdigControl(MilDigitizer, M_GRAB_SCALE, 1);

//	do_matrox_diag_1();
//	do_matrox_diag_2();


	/*get width & height of cam*/

//	printf("before some MsysInquires\n");

	MIL_INT width = MdigInquire(MilDigitizer, M_SIZE_X, M_NULL);
	MIL_INT height = MdigInquire(MilDigitizer, M_SIZE_Y, M_NULL);
	MIL_INT bits = MdigInquire(MilDigitizer, M_SIZE_BIT, M_NULL);

	printf(" X %d Y %d Z %d \n", width, height, bits);

	MbufAlloc2d(MilSystem,width,height,16 + M_UNSIGNED, M_IMAGE + M_PROC + M_GRAB, &MilImage);

	/* Allocate a temporary host buffer */
//	MbufAlloc2d(MilSystem,
//		width,
//		height,
//		((MdigInquire(MilDigitizer, M_SIZE_BIT, M_NULL) == 8) ? 8 + M_UNSIGNED : 16 + M_UNSIGNED),
//		M_IMAGE + M_GRAB,
//		&MilImage);

	MbufClear(MilImage, M_BLACK);

	MIL_INT SerialNumberStringSize = 0;
	MIL_INT SerialNumberSize = 0;
	MIL_INT FirmwareRevision = 0;

	MsysInquire(MilSystem, M_FIRMWARE_REVISION, &FirmwareRevision);

	MIL_TEXT_PTR SerialNumberPtr = new MIL_TEXT_CHAR[SerialNumberStringSize];
	MsysInquire(MilSystem, M_SERIAL_NUMBER, SerialNumberPtr);
	setStringParam(ADSerialNumber, (char *)SerialNumberPtr);
	delete[] SerialNumberPtr;

//	printf("before more sets\n");

	setStringParam(ADFirmwareVersion, "Firmware N/A");
//	setStringParam(voxtel_file_template_raw, "%s%s_%3.3d.rawish");

	setIntegerParam(ADSizeY, height);
	setIntegerParam(ADSizeX, width);
	setStringParam(ADManufacturer, "Voxtel");
	setStringParam(ADModel, "Voxtel VX-810");
	setDoubleParam(ADGain, 1.0);
	setIntegerParam(ADBinX, 1);
	setIntegerParam(ADBinY, 1);
	setIntegerParam(ADMinX, 1);
	setIntegerParam(ADMinY, 1);
	setIntegerParam(ADMaxSizeY, height);
	setIntegerParam(ADMaxSizeX, width);
	setIntegerParam(9, 3);

	setIntegerParam(ADStatus, ADStatusIdle);
	callParamCallbacks();

//	printf("before open com port\n");

	opencomport();

//	printf("after open com port\n");


	/* Create the thread that updates the images */
	status = (epicsThreadCreate("VoxtelDetTask",
		epicsThreadPriorityMedium,
		epicsThreadGetStackSize(epicsThreadStackMedium),
		(EPICSTHREADFUNC)voxtelTaskC,
		this) == NULL);

//	printf("after created processing task\n");
	
	if (status) {
		if (printme) printf("%s:%s epicsThreadCreate failure for image task\n",
			driverName, functionName);
		return;
	}
//	printf("Finished create\n");
}

voxtel::~voxtel(void)
		{
  static const char *functionName = "~voxtel";
	this->lock();

	printf("I am in the voxtel destructor \n");

	Do_Write_Read("Disable_Pattern_Generation", m_portHandle, Disable_Pattern_Generation);

	closecomport();
	/* Free MIL defaults. */
//	MappFreeDefault(MilApplication, MilSystem, MilDisplay, MilDigitizer, MilImage);
	MdigFree(MilDigitizer);
	MbufFree(MilImage);
	MsysFree(MilSystem);
	MappFree(MilApplication);

this->unlock();
}

/** Configuration command, called directly or from iocsh */
extern "C" int voxtelConfig(const char *portName, int maxSizeX, int maxSizeY, int dataType,
	int maxBuffers, int maxMemory, int priority, int stackSize)
{
	new voxtel(portName, maxSizeX, maxSizeY, (NDDataType_t)dataType,
		(maxBuffers < 0) ? 0 : maxBuffers,
		(maxMemory < 0) ? 0 : maxMemory,
		priority, stackSize);
	return(asynSuccess);
}

/** Code for iocsh registration */
static const iocshArg voxtelConfigArg0 = { "Port name", iocshArgString };
static const iocshArg voxtelConfigArg1 = { "Max X size", iocshArgInt };
static const iocshArg voxtelConfigArg2 = { "Max Y size", iocshArgInt };
static const iocshArg voxtelConfigArg3 = { "Data type", iocshArgInt };
static const iocshArg voxtelConfigArg4 = { "maxBuffers", iocshArgInt };
static const iocshArg voxtelConfigArg5 = { "maxMemory", iocshArgInt };
static const iocshArg voxtelConfigArg6 = { "priority", iocshArgInt };
static const iocshArg voxtelConfigArg7 = { "stackSize", iocshArgInt };
static const iocshArg * const voxtelConfigArgs[] = { &voxtelConfigArg0,
&voxtelConfigArg1,
&voxtelConfigArg2,
&voxtelConfigArg3,
&voxtelConfigArg4,
&voxtelConfigArg5,
&voxtelConfigArg6,
&voxtelConfigArg7 };
static const iocshFuncDef configvoxtel = { "voxtelConfig", 8, voxtelConfigArgs };
static void configvoxtelCallFunc(const iocshArgBuf *args)
{
	voxtelConfig(args[0].sval, args[1].ival, args[2].ival, args[3].ival,
		args[4].ival, args[5].ival, args[6].ival, args[7].ival);
}


static void voxtelRegister(void)
{
	iocshRegister(&configvoxtel, configvoxtelCallFunc);
}

extern "C" {
	epicsExportRegistrar(voxtelRegister);
}





