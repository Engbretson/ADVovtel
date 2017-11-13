

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

static const char *driverName = "voxtel";

/**
* runs on thread for seding and receiving serial port message.
* @param drvPvt    Pointer to pco object, and ADDriver.
*/


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
	const char *functionName = "CoaXLinkTask";
	dims[0] = 0;
	dims[1] = 0;

	this->lock();
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

//		printf("Starting Acquire \n");


	// start acq
		getIntegerParam(ADImageMode, &iMode);
		getIntegerParam(ADNumImages, &numImages);
		getIntegerParam(ADNumImagesCounter, &numImagesCounter);
		getIntegerParam(NDArrayCounter, &imageCounter);

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

				this->unlock();
				try
				{
					MdigGrab(MilDigitizer, MilImage);
					MbufGet(MilImage, buffer);
				}
				catch (...)
				{
					printf("Error in acquire from digitizer\n");
				}
				epicsTimeGetCurrent(&startTime);

				this->lock();

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

//				printf("arrayCallbacks %d \n", arrayCallbacks);
//				printf("dataType %d \n", dataType);
//				printf("dims 0 X %d \n", dims[0]);
//				printf("dims 1 y %d \n", dims[1]);
//				printf("size %d \n", size);

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

//				printf("Before Copy1 \n");
				try
				{
					memcpy(pImage->pData, buffer, size);
				}
				catch (...)
				{
					printf("Error copying data from digitizer\n");
				}


				//				pImage->dataType
				////				printf("Before Copy2 \n");
				//				memcpy(&pImage->pData+size, ptr2, size);
				//				memcpy((void *)pImage->pData + size, ptr2, size);

//				printf("After Copy \n");

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

	printf("I am in the write Octet routine %d %s\n", function, value);

if (function == voxtel_file_template_raw)
setStringParam(voxtel_file_template_raw, value);

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
//	printf("in write32 function %d value %d \n", function, value);

///	sprintf(mesx, "voxtel::writeInt32, param=%s, value=%d", mesx2, value);
///	lf.log(mesx);

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
		printf("Performing Voxtal Initialize \n");
		Do_Write_Read("Frame_Stop", m_portHandle, Frame_Stop);
		Do_Write_Read("Program_ADC", m_portHandle, Program_ADC);
		Do_Write_Read("Initialize_DACTable", m_portHandle, Initialize_DACTable);
		Do_Write_Read("Program_DAC", m_portHandle, Program_DAC_0);
	}
	if(function == voxtel_frame_stop) {
		Do_Write_Read("Frame_Stop", m_portHandle, Frame_Stop);
		setIntegerParam(voxtel_frame_start, 0);
	}
	if(function == voxtel_frame_start) {
		Do_Write_Read("Frame_Start", m_portHandle, Frame_Start);
		setIntegerParam(voxtel_frame_stop, 0);
	}
	if (function == voxtel_counter_mode_select) {
		switch (value)
		{
		case 1:
			break;
		case 2:
			Do_Write_Read("Counter_Mode_2", m_portHandle, Counter_Mode_2);
			setStringParam(voxtel_file_template_raw, "mode2");
			break;
		case 3:
			Do_Write_Read("Counter_Mode_3", m_portHandle, Counter_Mode_3);
			setStringParam(voxtel_file_template_raw, "mode3");
			break;
		case 4:
			break;
		case 5:
			Do_Write_Read("Counter_Mode_5", m_portHandle, Counter_Mode_5);
			setStringParam(voxtel_file_template_raw, "mode5");
			break;
		case 6:
			break;
		case 7:
			Do_Write_Read("Counter_Mode_7", m_portHandle, Counter_Mode_7);
			setStringParam(voxtel_file_template_raw, "mode7");
			break;
		case 8:
			Do_Write_Read("Counter_Mode_8", m_portHandle, Counter_Mode_8);
			setStringParam(voxtel_file_template_raw, "mode8");
			break;
		}
	}

	if (function == voxtel_pixel_test_inject_location_row) {
		printf("Pixel test injection row %d\n", value);
	}

	if (function == voxtel_pixel_test_inject_location_col) {
		printf("Pixel test injection row %d\n", value);
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
	}
	if (function == voxtel_disable_test_pattern_generation) {
		Do_Write_Read("Disable_Pattern_Generation", m_portHandle, Disable_Pattern_Generation);
		setIntegerParam(voxtel_enable_test_pattern_generation, 0);
	}
	if (function == voxtel_print_dactable) {
		Do_Write_Read("Print_DAC_Table", m_portHandle, "t0000");
	}

	if ((function == ADAcquire) & (value == 1)) epicsEventSignal(this->startEventId);

	if ((function == ADAcquire) & (value == 0)) epicsEventSignal(this->stopEventId);


/* If this parameter belongs to a base class call its method */
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

	status = setDoubleParam(function, value);

///	char mesx[256];
///	char *mesx2;

///	getParamName(function, (const char **)&mesx2);

///	sprintf(mesx, "voxtel::writeFloat64, param=%s, value=%f", mesx2, value);
///	lf.log(mesx);

if (function == voxtel_integration_time) {
	Do_Write_Integration_Time(m_portHandle, value);
	}
if (function == voxtel_threashold_1) {
		Do_Write_Threshold1(m_portHandle, value);
}
if(function == voxtel_threashold_2) {
		Do_Write_Threshold2(m_portHandle, value);
}

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

	/* Create the epicsEvents for signaling to the acquire task when acquisition starts and stops */
	startEventId = epicsEventCreate(epicsEventEmpty);
	if (!startEventId) {
		printf("%s:%s epicsEventCreate failure for start event\n",
			driverName, functionName);
		return;
	}
	stopEventId = epicsEventCreate(epicsEventEmpty);
	if (!stopEventId) {
		printf("%s:%s epicsEventCreate failure for stop event\n",
			driverName, functionName);
		return;
	}

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
	createParam("voxtel_file_template_raw", asynParamOctet, &voxtel_file_template_raw);

	setIntegerParam(voxtel_initialize, 1);	
	setIntegerParam(voxtel_counter_mode_select, 8);
	setIntegerParam(voxtel_pixel_test_inject_location_col, 255);
	setIntegerParam(voxtel_pixel_test_inject_location_row, 255);

	setDoubleParam(voxtel_integration_time, 100.0);
	setDoubleParam(voxtel_threashold_1, 2.5);
	setDoubleParam(voxtel_threashold_2, 2.5);

	setIntegerParam(voxtel_frame_stop, 1);
	setIntegerParam(voxtel_disable_test_pattern_generation, 1);

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
		MdigAlloc(MilSystem, M_DEFAULT, MIL_TEXT("M_DEFAULT"), M_DEFAULT, &MilDigitizer);
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

//	MdigControl(MilDigitizer, M_GRAB_SCALE, GRAB_SCALE);
	/*get width & height of cam*/
	MIL_INT width = MdigInquire(MilDigitizer, M_SIZE_X, M_NULL);
	MIL_INT height = MdigInquire(MilDigitizer, M_SIZE_Y, M_NULL);

	MbufAlloc2d(MilSystem,width,height,8 + M_UNSIGNED,M_IMAGE + M_DISP + M_PROC + M_GRAB, &MilImage);
	MbufClear(MilImage, M_BLACK);

	MIL_INT SerialNumberStringSize = 0;
	MIL_INT SerialNumberSize = 0;
	MIL_INT FirmwareRevision = 0;

	MsysInquire(MilSystem, M_FIRMWARE_REVISION, &FirmwareRevision);

	MIL_TEXT_PTR SerialNumberPtr = new MIL_TEXT_CHAR[SerialNumberStringSize];
	MsysInquire(MilSystem, M_SERIAL_NUMBER, SerialNumberPtr);
	setStringParam(ADSerialNumber, (char *)SerialNumberPtr);
	delete[] SerialNumberPtr;

	setStringParam(ADFirmwareVersion, "Firmware N/A");
	setStringParam(voxtel_file_template_raw, "%s%s_%3.3d.rawish");

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

	setIntegerParam(ADStatus, ADStatusIdle);
	callParamCallbacks();

	opencomport();
//	setIntegerParam(open_com, 0);
	// force baud to fastest rate at startup
//	setIntegerParam(voxtel_baudrate, 115200);


	/* Create the thread that updates the images */
	status = (epicsThreadCreate("VoxtelDetTask",
		epicsThreadPriorityMedium,
		epicsThreadGetStackSize(epicsThreadStackMedium),
		(EPICSTHREADFUNC)voxtelTaskC,
		this) == NULL);

	if (status) {
		printf("%s:%s epicsThreadCreate failure for image task\n",
			driverName, functionName);
		return;
	}


}

voxtel::~voxtel(void)
		{
	printf("I am in the voxtel destructor \n");

	Do_Write_Read("Disable_Pattern_Generation", m_portHandle, Disable_Pattern_Generation);

	closecomport();
	/* Free MIL defaults. */
//	MappFreeDefault(MilApplication, MilSystem, MilDisplay, MilDigitizer, MilImage);
	MdigFree(MilDigitizer);
	MbufFree(MilImage);
	MsysFree(MilSystem);
	MappFree(MilApplication);
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


void voxtel::opencomport(void)
{

	m_portHandle = CreateFile("COM4",       // Specify port device: default "COM1"
		GENERIC_READ | GENERIC_WRITE,       // Specify mode that open device.
		0,                                  // the devide isn't shared.
		NULL,                               // the object gets a default security.
		OPEN_EXISTING,                      // Specify which action to take on file. 
		0,                                  // default.
		NULL);                              // default.


											// Get current configuration of serial communication port.
	if (GetCommState(m_portHandle, &m_portConfig) == 0)
	{
		printf("Get configuration port has problem.\n");
//		return FALSE;
	}
	// Assign user parameter.
	m_portConfig.BaudRate = CBR_115200;    // Specify buad rate of communicaiton.
	m_portConfig.StopBits = ONESTOPBIT;    // Specify stopbit of communication.
	m_portConfig.Parity = NOPARITY;        // Specify parity of communication.
	m_portConfig.ByteSize = DATABITS_8;    // Specify  byte of size of communication.


										   // Set current configuration of serial communication port.
	if (SetCommState(m_portHandle, &m_portConfig) == 0)
	{
		printf("Set configuration port has problem.\n");
//		return FALSE;
	}

	// instance an object of COMMTIMEOUTS.
	COMMTIMEOUTS comTimeOut;
	comTimeOut.ReadIntervalTimeout = 3;
	comTimeOut.ReadTotalTimeoutMultiplier = 3;
	comTimeOut.ReadTotalTimeoutConstant = 2;
	comTimeOut.WriteTotalTimeoutMultiplier = 3;
	comTimeOut.WriteTotalTimeoutConstant = 2;
	SetCommTimeouts(m_portHandle, &comTimeOut);		// set the time-out parameter into device control.


//	Do_Read("Perform an inital read to clear all buffers.", m_portHandle, inputData);
}

void voxtel::closecomport(void)
{

	if (CloseHandle(m_portHandle) == 0)    // Call this function to close port.
	{
		printf("Port Closeing isn't successed.");
//		return FALSE;
	}


}
BOOLEAN voxtel::Do_Write_Read(const char *command, HANDLE m_portHandle, const char *outputData)
{
	DWORD length1 = 0;
	DWORD length2 = 0;
	int packets = 0;
	div_t divresult;

	divresult = div(int(_tcslen(outputData)), 5);

	packets = divresult.quot;

	printf("Writing %s\n", command);

	for (int i = 0; i < packets; i++)
	{

		char inputData1[1024] = {};
		char tempData[1024] = {};

		if (WriteFile(m_portHandle,    // handle to file to write to
			&outputData[i * 5],               // pointer to data to write to file
			5, // number of bytes to write
			&length1, NULL) == 0)       // pointer to number of bytes written
		{
			printf(". . . Writing of serial communication has problem.");
			return FALSE;
		}

		if (ReadFile(m_portHandle,     // handle of file to read
			inputData1,                // handle of file to read
			1024,                       // number of bytes to read
			&length2,                   // pointer to number of bytes read
			NULL) == 0)                // pointer to structure for data
		{
			printf(". . . Reading of serial communication has problem.\n");
			return FALSE;
		}

		if (length2 > 0) {
			memcpy(tempData, inputData1, length2);

			printf(". . . Wrote %d bytes, Got %d bytes. %.5s %s \n", length1, length2, &outputData[i * 5], tempData);

			//		for (int j = 0; j < length2; j++) printf("%d %d \n", j, inputData1[(i*5)+j]);
		}
		//	Sleep(50);

	}
	printf("\n");

	return TRUE;

}


BOOLEAN voxtel::Do_Read(const char *command, HANDLE m_portHandle, char *inputData)
{
	DWORD length = 0;
	char inputData1[1024] = {};

	printf("Reading %s\n", command);


	if (ReadFile(m_portHandle,  // handle of file to read
		inputData1,               // handle of file to read
		1024,      // number of bytes to read
		&length,                 // pointer to number of bytes read
		NULL) == 0)              // pointer to structure for data
	{
		printf("Reading of serial communication has problem.\n");
		return FALSE;
	}


	if (length > 0) {
		inputData1[length] = NULL; // Assign end flag of message.

		printf(" Got %d bytes. %s\n", length, inputData1);

	}
	printf("\n");
	return TRUE;
}
BOOLEAN voxtel::Do_Write_Register(const char *command, HANDLE m_portHandle, const char *reg, const char *lower, const char *upper)
{
	printf("Performing %s\n", command);
	Do_Write_Read("Upper_16_Bits_Data", m_portHandle, upper);
	Do_Write_Read("Register_Address_Location", m_portHandle, reg);
	Do_Write_Read("Lower_16_Bits_Data", m_portHandle, lower);

	return true;

}

BOOLEAN voxtel::Do_Read_Register(const char *command, HANDLE m_portHandle, const char *reg)
{
	Do_Write_Read(command, m_portHandle, reg);
	return TRUE;
}
//void Compute_Integration_Time(int ms, int *lower, int *upper) {

void voxtel::Do_Write_Integration_Time(HANDLE m_portHandle, double ms) {
	double temp;
	int lower, upper;
	char clower[6], cupper[6];


	temp = round(ms * 7500.0);
	lower = int(temp) & 0xffff;
	upper = (int(temp) & 0xffffffff) >> 16;

	//	printf(" %f %d %d %8.8X %4.4X %4.4X \n", ms, lower, upper, int(temp), lower, upper);

	sprintf_s(clower, 6, "w%4.4X", lower);
	sprintf_s(cupper, 6, "l%4.4X", upper);

	Do_Write_Read("Frame_Stop", m_portHandle, Frame_Stop);
	Do_Write_Register("Write_Integration_Time_To_Register_0x0003", m_portHandle, "a0003", clower, cupper);
	Do_Write_Read("Frame_Start", m_portHandle, Frame_Start);

}

void voxtel::Do_Write_Threshold1(HANDLE m_portHandle, double value) {
	int temp;
	int lower;
	char clower[6];


	temp = (unsigned short int)((value * 65535.0) / 3.3 + 0.5);
	if (temp > 65535)
		temp = 65535;
	else if (temp < 0)
		temp = 0;

	lower = int(temp) & 0xffff;

	sprintf_s(clower, 6, "p%4.4X", lower);

	Do_Write_Register("Write_Threshold1", m_portHandle, clower, "sFF01", "s0A00");



}
void voxtel::Do_Write_Threshold2(HANDLE m_portHandle, double value) {
	int temp;
	int lower;
	char clower[6];


	temp = (unsigned short int)((value * 65535.0) / 3.3 + 0.5);
	if (temp > 65535)
		temp = 65535;
	else if (temp < 0)
		temp = 0;

	lower = int(temp) & 0xffff;

	sprintf_s(clower, 6, "p%4.4X", lower);

	Do_Write_Register("Write_Threshold2", m_portHandle, clower, "sFF02", "s1A00");


}

void voxtel::Do_Write_Pixel_Test_Inject_Location(HANDLE m_portHandle, int col, int row)
{
	char clower[6];

	col = col & 0xFF;
	row = row & 0xFF;

	sprintf_s(clower, 6, "w%2.2X%2.2X", col, row);

	Do_Write_Register("Pixel_Test_Inject_Location", m_portHandle, "a0020", clower, "lFF00");

	Do_Write_Read("Write_DSI_3", m_portHandle, Write_DSI_3);

}


