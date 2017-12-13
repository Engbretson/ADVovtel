
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
//		if (printme)
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
//		if (printme) 
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
//		if (printme) 
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

//	if (printme) 
	printf("%s ", command);

	for (int i = 0; i < packets; i++)
	{

		char inputData1[1024] = {};
		char tempData[1024] = {};

		if (WriteFile(m_portHandle,    // handle to file to write to
			&outputData[i * 5],               // pointer to data to write to file
			5, // number of bytes to write
			&length1, NULL) == 0)       // pointer to number of bytes written
		{
//			if (printme) 
				printf(". . . Writing of serial communication has problem.");
			return FALSE;
		}

		Sleep(10);
		
			if (ReadFile(m_portHandle,     // handle of file to read
			inputData1,                // handle of file to read
			1024,                       // number of bytes to read
			&length2,                   // pointer to number of bytes read
			NULL) == 0)                // pointer to structure for data
		{
//			if (printme) 
			printf(". . . Reading of serial communication has problem.\n");
			return FALSE;
		}


		if (length2 > 0) {
			memcpy(tempData, inputData1, length2);
//			if (printme) printf(". . . Wrote %d bytes, Got %d bytes. %.5s %s \n", length1, length2, &outputData[i * 5], tempData);
			if (printme) printf("%s ", tempData);

		}
	}
	if (printme) printf("\n");

	return TRUE;

}


BOOLEAN voxtel::Do_Read(const char *command, HANDLE m_portHandle, const char *inputData)
{
	DWORD length = 0;
	char inputData1[1024] = {};

//	if (printme) printf("In Do_Read Reading %s\n", command);

	if (ReadFile(m_portHandle,  // handle of file to read
		inputData1,               // handle of file to read
		1024,      // number of bytes to read
		&length,                 // pointer to number of bytes read
		NULL) == 0)              // pointer to structure for data
	{
//		if (printme) 
		printf("Reading of serial communication has problem.\n");
		return FALSE;
	}

	if (length > 0) {
		inputData1[length] = NULL; // Assign end flag of message.

//		if (printme) printf("Got %d bytes. %s\n", length, inputData1);

	}
	if (printme) printf("\n");
	return TRUE;
}

BOOLEAN voxtel::Do_Write_Register(const char *command, HANDLE m_portHandle, const char *reg, const char *lower, const char *upper)
{
	char reg_temp[6] = {};
	char temp_string[30] = {};

//	if (printme) 
//	printf("%s ", command);
///	Do_Write_Read("Upper_16_Bits_Data", m_portHandle, upper);
///	Do_Write_Read("Register_Address_Location", m_portHandle, reg);
///	Do_Write_Read("Lower_16_Bits_Data", m_portHandle, lower);

//	printf("--> %s %s %s \n", upper, reg, lower);
	sprintf_s(temp_string, 30,  "%s%s%s", upper, reg, lower);

	
//	printf("+++++>%s<+++++\n", temp_string);

	Do_Write_Read(command, m_portHandle, temp_string);
	
    
//	memcpy(reg_temp, reg, 5);
//	reg_temp[0] = 'r';
//	Do_Read_Register("Confirm Register Written", m_portHandle, reg_temp);

	return true;
}

BOOLEAN voxtel::Do_Read_Register(const char *command, HANDLE m_portHandle, const char *reg)
{
	Do_Write_Read(command, m_portHandle, reg);
	return TRUE;
}

void voxtel::Do_Write_Integration_Time(HANDLE m_portHandle, double ms) {
	double temp;
	int lower, upper;
	char clower[6] = {}, cupper[6] = {};

	temp = round((ms /1000.0 * 75E6));
//	temp = ((ms / 1000.0 * 75E6));

	lower = int(temp) & 0xffff;
	upper = (int(temp) >> 16) & 0xffff;

//	if (printme) printf(" %f %f %d %d computed=%8.8X lower=%4.4X upper=%4.4X \n", ms, temp,lower, upper, int(temp), lower, upper);

	sprintf_s(clower, 6, "w%4.4X", lower);
	sprintf_s(cupper, 6, "l%4.4X", upper);

	Do_Write_Read("Frame_Stop", m_portHandle, Frame_Stop);
	Do_Write_Register("Write_Integration_Time", m_portHandle, "a0003", clower, cupper);
	Do_Write_Read("Frame_Start", m_portHandle, Frame_Start);
//	Do_Write_Read("Try dsi_3", m_portHandle, Write_DSI__3);
}

void voxtel::Do_Write_Threshold1(HANDLE m_portHandle, double value) {
	int temp;
	int lower;
	char clower[6] = {};

	temp = (unsigned short int)((value * 65535.0) / 3.3 + 0.5);
	if (temp > 65535)
		temp = 65535;
	else if (temp < 0)
		temp = 0;

	lower = int(temp) & 0xffff;

	sprintf_s(clower, 6, "p%4.4X", lower);

//	WRONG! WRONG! WRONG!

//	Do_Write_Register("Write_Threshold1", m_portHandle, clower, "sFF01", "s0A00");
///	Do_Write_Read("Write_DacTable_a", m_portHandle, "s0A00");
///	Do_Write_Read("Write_DacTable_b", m_portHandle, clower);
///	Do_Write_Read("Program_DAC_1", m_portHandle, Program_DAC_1);

	Do_Write_Register("Write_Threshold1", m_portHandle, clower,Program_DAC_1,"s0A00");



}
void voxtel::Do_Write_Threshold2(HANDLE m_portHandle, double value) {
	int temp;
	int lower;
	char clower[6] = {};

	temp = (unsigned short int)((value * 65535.0) / 3.3 + 0.5);
	if (temp > 65535)
		temp = 65535;
	else if (temp < 0)
		temp = 0;

	lower = int(temp) & 0xffff;

	sprintf_s(clower, 6, "p%4.4X", lower);

//	WRONG!WRONG!WRONG!  should be 2 Do_Write_reads

//	Do_Write_Register("Write_Threshold2", m_portHandle, clower, "sFF02", "s1A00");
///	Do_Write_Read("Write_DacTable_a", m_portHandle, "s1A00");
///	Do_Write_Read("Write_DacTable_b", m_portHandle, clower);
///	Do_Write_Read("Program_DAC_2", m_portHandle, Program_DAC_2);

	Do_Write_Register("Write_Threshold2", m_portHandle, clower, Program_DAC_2, "s1A00");

}

void voxtel::Do_Write_Pixel_Test_Inject_Location(HANDLE m_portHandle, int col, int row)
{
	char clower[6];

	col = col & 0xFF;
	row = row & 0xFF;

	sprintf_s(clower, 6, "w%2.2X%2.2X", col, row);

	Do_Write_Register("Pixel_Test_Inject_Location", m_portHandle, "a0020", clower, "lFF00");
	Do_Write_Read("Write_DSI__3", m_portHandle, Write_DSI__3);

}
