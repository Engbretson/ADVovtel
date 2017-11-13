

#ifndef VOXTEL_H_
#define VOXTEL_H_

#include <epicsEvent.h>
#include <epicsTypes.h>
///#include "ADCameralink.h"
///#include "cl_com_port2.h"
///#include "stopWatch.h"
#include "ADDriver.h"
#include <mil.h>

#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include <math.h>

#define DRIVER_VERSION      0
#define DRIVER_REVISION     0
#define DRIVER_MODIFICATION 9


const char *Frame_Stop = "l0000a0001w0000";
const char *Frame_Start = "l0000a0001w0002";
const char *Program_ADC = "y0000";
const char *Program_DAC_0 = "sFF00";
const char *Program_DAC_1 = "sFF01";
const char *Program_DAC_2 = "sFF02";
const char *Print_DAC_Table = "t0000";

const char *Counter_Mode_2 = "lC000a0021w0390";
const char *Counter_Mode_3 = "lC000a0021w03A0";
const char *Counter_Mode_5 = "lC000a0021w03C0";
const char *Counter_Mode_7 = "lC000a0021w03E0";
const char *Counter_Mode_8 = "lC000a0021w03F0";

const char *Enable_Pattern_Generation = "l0000a0004w0003l0000a0001w0002";
const char *Disable_Pattern_Generation = "l0000a0004w0002l0000a0001w0000";

const char *Write_DSI = "lFF00a0020wFFFFlC000a0021w03F0l7A10a0022w9088l0000a0023w213Al0000a0019w0002l0000a0019w0003l0000a0019w0002";
const char *Write_DSI_1 = "lFF00a0020wFFFFlC000a0021w03F0l7A10a0022w9088l0000a0023";
const char *Write_DSI_2 = "w213Al0000a0019w0002l0000a0019w0003l0000a0019w0002";
const char *Write_DSI_3 = "l0000a0019w0002l0000a0019w0003l0000a0019w0002";

const char *Initialize_DACTable = "s0200p828E" "s1200p828E" "s2200p0A34" "s3200p0A34" "s4200p0A34"
"s5200p828E" "s0E00p411A" "s1E00p6CC2" "s2E00p6CC2" "s3E00p4D93"
"s4E00p4D93" "s5E00p4D93" "s6E00p4D93" "s7E00p4D93" "s3600p4D93"
"s4600p4D93" "s5600p4D93" "s6600p4D93" "s7600p4D93" "s0A00pC1F0"
"s1A00pC1F0" "s2A00p07C1" "s3A00p0000" "s4A00p0000" "s5A00p0000"
"s6A00p0000" "s7A00p0000" "s0600p0000" "s1600p0000";



//class epicsShareClass voxtel : public ADCameralink {
class epicsShareClass voxtel : public ADDriver {
public:
///	voxtel(const char *portName, const char *voxtelPort, int maxBuffers,
///		size_t maxMemory, int priority, int stackSize);
	voxtel(const char *portName, int maxSizeX, int maxSizeY, NDDataType_t dataType,
		int maxBuffers, size_t maxMemory, int priority, int stackSize);
	~voxtel(void);
	/* These are the methods that we override from ADDriver */
	virtual asynStatus writeInt32(asynUser *pasynUser, epicsInt32 value);
	virtual asynStatus writeFloat64(asynUser *pasynUser, epicsFloat64 value);
	virtual asynStatus writeOctet(asynUser *pasynUser, const char *value,
		size_t nChars, size_t *nActual);

	virtual void report(FILE *fp, int details);
	void voxtelTask(); /**< This should be private but is called from C, must be public */
	void voxtelTask_(); /**< This should be private but is called from C, must be public */

	int getImage();
	int getImage_();
	epicsEventId stopEventId; /**< This should be private but is accessed from C, must be public */
	epicsEventId startEventId; /**< This should be private but is accessed from C, must be public */

	void opencomport();
	void closecomport();
	BOOLEAN Do_Write_Read(const char *command, HANDLE m_portHandle, const char *outputData);
	BOOLEAN Do_Read(const char *command, HANDLE m_portHandle, char *inputData);
	BOOLEAN Do_Write_Register(const char *command, HANDLE m_portHandle, const char *reg, const char *lower, const char *upper);
	BOOLEAN Do_Read_Register(const char *command, HANDLE m_portHandle, const char *reg);
	void Do_Write_Integration_Time(HANDLE m_portHandle, double ms);
	void Do_Write_Threshold1(HANDLE m_portHandle, double value);
	void Do_Write_Threshold2(HANDLE m_portHandle, double value);
	void Do_Write_Pixel_Test_Inject_Location(HANDLE m_portHandle, int col, int row);

protected:

	int voxtel_initialize;
#define FIRST_voxtel_PARAM voxtel_initialize	
	int voxtel_counter_mode_select;
	int voxtel_integration_time;
	int voxtel_frame_start;
	int voxtel_frame_stop;
	int voxtel_threashold_1;
	int voxtel_threashold_2;
	int voxtel_pixel_test_inject_location_row;
	int voxtel_pixel_test_inject_location_col;
	int voxtel_pixel_test_inject_location;
	int voxtel_enable_test_pattern_generation;
	int voxtel_disable_test_pattern_generation;
	int voxtel_print_dactable;
	int voxtel_file_template_raw;
#define LAST_voxtel_PARAM voxtel_file_template_raw

#ifndef USEASYNSERIAL
///	comportInterface *serial_port;
//	sw_com_port serial_port;
#endif
// asyn user for the serial port
///	asynUser *pasynUserSerial;


	NDArray	*pImage;

	// interface to serial port octet
	asynInterface *paynOctet;
	asynInterface *paynOption;
	char myServerPort[255];
// local com ports

	HANDLE m_portHandle;
	DCB m_portConfig;
	char inputData[1024] = {};
	unsigned int buffer[192][384] = { 0 };


// MIL related 

	MIL_ID MilApplication,  /* Application identifier.  */
		MilSystem,          /* System identifier.       */
		MilDisplay,         /* Display identifier.      */
		MilDigitizer,       /* Digitizer identifier.    */
		MilImage;           /* Image buffer identifier. */

private:
};
#endif

#define NUM_voxtel_PARAMS (&LAST_voxtel_PARAM - &FIRST_voxtel_PARAM + 1)
