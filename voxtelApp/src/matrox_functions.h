/*
// This is a repository of routines that I might need in the future, but have not implemented now
*/

void voxtel::do_matrox_diag_1()
{

	// For general system settings

	MsysControl(MilSystem, M_ALLOCATION_OVERSCAN, M_ENABLE); // Specifies that image buffers are allocated on the system with an overscan region.
	MsysControl(MilSystem, M_ALLOCATION_OVERSCAN_SIZE, 0);
	MsysControl(MilSystem, M_DEFAULT_PITCH_BYTE_MULTIPLE, 64);
	MsysControl(MilSystem, M_MODIFIED_BUFFER_HOOK_MODE, M_SINGLE_THREAD); // Specifies that only one thread should be created and that all user-defined functions hooked to buffer modifications are run on the same thread.
	MsysControl(MilSystem, M_THREAD_MODE, M_ASYNCHRONOUS); // Specifies that threads allocated on the system can execute in asynchronous mode.
	MsysControl(MilSystem, M_TIMEOUT, 20);

	MIL_INT AllocationOverscan = 0;
	MIL_INT AllocationOverscanSizeInPixels = 0;
	MIL_INT DefaultPitchByteMultipleInBytes = 0;
	MIL_INT ModifiedBufferHookMode = 0;
	MIL_INT ThreadMode = 0;
	MIL_INT TimeoutInSecs = 0;
	MIL_INT AcceleratorPresent = 0;
	MIL_INT AsynchronousCallSupport = 0;
	MIL_INT BoardRevision = 0;
	MIL_INT BoardType = 0;
	MIL_INT CurrentThreadId = 0;
	MIL_INT DcfSupported = 0;
	MIL_INT DigitizerNum = 0;
	MIL_INT DisplayOutputNum = 0;
	MIL_INT64 ExtendedInitFlag = 0;
	MIL_INT FirmwareBuilddate = 0;
	MIL_INT FirmwareBuilddateProcessing = 0;
	MIL_INT FirmwareRevision = 0;
	MIL_INT FirmwareRevisionProcessing = 0;
	MIL_INT Location = 0;
	MIL_INT MemoryFreeInBytes = 0;
	MIL_INT MemoryFreeBank0InBytes = 0;
	MIL_INT MemoryFreeBank1InBytes = 0;
	MIL_INT MemoryFreeBank2InBytes = 0;
	MIL_INT MemorySizeInMbytes = 0;
	MIL_INT MemorySizeBank0InMbytes = 0;
	MIL_INT MemorySizeBank1InMbytes = 0;
	MIL_INT MemorySizeBank2InMbytes = 0;
	MIL_INT Number = 0;
	MIL_INT OwnerApplication = 0;
	MIL_INT PcieNumberOfLanes = 0;
	MIL_INT ProcessorNum = 0;
	MIL_INT SerialNumberStringSize = 0;
	MIL_INT SerialNumberSize = 0;
	MIL_INT SharedMemoryFreeInBytes = 0;
	MIL_INT SharedMemorySizeInMbytes = 0;
	MIL_INT SystemDescriptorStringSize = 0;
	MIL_INT SystemDescriptorSize = 0;
	MIL_INT SystemType = 0;

	MsysInquire(MilSystem, M_ALLOCATION_OVERSCAN, &AllocationOverscan);
	MsysInquire(MilSystem, M_ALLOCATION_OVERSCAN_SIZE, &AllocationOverscanSizeInPixels);
	MsysInquire(MilSystem, M_DEFAULT_PITCH_BYTE_MULTIPLE, &DefaultPitchByteMultipleInBytes);
	MsysInquire(MilSystem, M_MODIFIED_BUFFER_HOOK_MODE, &ModifiedBufferHookMode);
	MsysInquire(MilSystem, M_THREAD_MODE, &ThreadMode);
	MsysInquire(MilSystem, M_TIMEOUT, &TimeoutInSecs);
	MsysInquire(MilSystem, M_ACCELERATOR_PRESENT, &AcceleratorPresent);
	MsysInquire(MilSystem, M_ASYNCHRONOUS_CALL_SUPPORT, &AsynchronousCallSupport);
	MsysInquire(MilSystem, M_BOARD_REVISION, &BoardRevision);
	MsysInquire(MilSystem, M_BOARD_TYPE, &BoardType);
	MsysInquire(MilSystem, M_CURRENT_THREAD_ID, &CurrentThreadId);
	MsysInquire(MilSystem, M_DCF_SUPPORTED, &DcfSupported);
	MsysInquire(MilSystem, M_DIGITIZER_NUM, &DigitizerNum);
	MsysInquire(MilSystem, M_DISPLAY_OUTPUT_NUM, &DisplayOutputNum);
	MsysInquire(MilSystem, M_EXTENDED_INIT_FLAG, &ExtendedInitFlag);
	MsysInquire(MilSystem, M_FIRMWARE_BUILDDATE, &FirmwareBuilddate);
	MsysInquire(MilSystem, M_FIRMWARE_BUILDDATE_PROCESSING, &FirmwareBuilddateProcessing);
	MsysInquire(MilSystem, M_FIRMWARE_REVISION, &FirmwareRevision);
	MsysInquire(MilSystem, M_FIRMWARE_REVISION_PROCESSING, &FirmwareRevisionProcessing);
	MsysInquire(MilSystem, M_LOCATION, &Location);
	MsysInquire(MilSystem, M_MEMORY_FREE, &MemoryFreeInBytes);
	MsysInquire(MilSystem, M_MEMORY_FREE_BANK_0, &MemoryFreeBank0InBytes);
	MsysInquire(MilSystem, M_MEMORY_FREE_BANK_1, &MemoryFreeBank1InBytes);
	MsysInquire(MilSystem, M_MEMORY_FREE_BANK_2, &MemoryFreeBank2InBytes);
	MsysInquire(MilSystem, M_MEMORY_SIZE, &MemorySizeInMbytes);
	MsysInquire(MilSystem, M_MEMORY_SIZE_BANK_0, &MemorySizeBank0InMbytes);
	MsysInquire(MilSystem, M_MEMORY_SIZE_BANK_1, &MemorySizeBank1InMbytes);
	MsysInquire(MilSystem, M_MEMORY_SIZE_BANK_2, &MemorySizeBank2InMbytes);
	MsysInquire(MilSystem, M_NUMBER, &Number);
	MsysInquire(MilSystem, M_OWNER_APPLICATION, &OwnerApplication);
	MsysInquire(MilSystem, M_PCIE_NUMBER_OF_LANES, &PcieNumberOfLanes);
	MsysInquire(MilSystem, M_PROCESSOR_NUM, &ProcessorNum);
	MsysInquire(MilSystem, M_SERIAL_NUMBER_SIZE, &SerialNumberStringSize);
	MIL_TEXT_PTR SerialNumberPtr = new MIL_TEXT_CHAR[SerialNumberStringSize];
	MsysInquire(MilSystem, M_SERIAL_NUMBER, SerialNumberPtr);
	delete[] SerialNumberPtr;
	MsysInquire(MilSystem, M_SERIAL_NUMBER_SIZE, &SerialNumberSize);
	MsysInquire(MilSystem, M_SHARED_MEMORY_FREE, &SharedMemoryFreeInBytes);
	MsysInquire(MilSystem, M_SHARED_MEMORY_SIZE, &SharedMemorySizeInMbytes);
	MsysInquire(MilSystem, M_SYSTEM_DESCRIPTOR_SIZE, &SystemDescriptorStringSize);
	MIL_TEXT_PTR SystemDescriptorPtr = new MIL_TEXT_CHAR[SystemDescriptorStringSize];
	MsysInquire(MilSystem, M_SYSTEM_DESCRIPTOR, SystemDescriptorPtr);
	delete[] SystemDescriptorPtr;
	MsysInquire(MilSystem, M_SYSTEM_DESCRIPTOR_SIZE, &SystemDescriptorSize);
	MsysInquire(MilSystem, M_SYSTEM_TYPE, &SystemType);
}

void voxtel::do_matrox_diag_2()
{
//	The following control types allow you to control various digitizer settings.

	MdigControl(MilDigitizer, M_BAYER_COEFFICIENTS_ID, 0);
	MdigControl(MilDigitizer, M_BAYER_CONVERSION, M_DISABLE); // Specifies to not perform Bayer conversion on the grabbed image.
	MdigControl(MilDigitizer, M_COMMAND_QUEUE_MODE, M_QUEUED); // Specifies that, if you change the setting of a control type of a digitizer currently being used in a grab, the change does not affect the current grab.
	MdigControl(MilDigitizer, M_GC_CLPROTOCOL, M_DISABLE); // Specifies that the GenICam CLProtocol module is disabled.
	MdigControl(MilDigitizer, M_GC_FEATURE_POLLING, M_DISABLE); // Specifies that specific camera features will not be polled.
	MdigControl(MilDigitizer, M_GRAB_ABORT, M_DEFAULT);
	MdigControl(MilDigitizer, M_GRAB_DIRECTION_X, M_FORWARD); // Specifies to grab from left to right, in the horizontal direction.
	MdigControl(MilDigitizer, M_GRAB_DIRECTION_Y, M_FORWARD); // Specifies to grab from top to bottom, in the vertical direction.
	MdigControl(MilDigitizer, M_GRAB_FIELD_NUM, 1);
	MdigControl(MilDigitizer, M_GRAB_LINE_COUNTER, M_DISABLE); // Specifies that the hooked function cannot inquire the number of lines grabbed.
	MdigControl(MilDigitizer, M_GRAB_MODE, M_SYNCHRONOUS); // Specifies that your application is synchronized with the end of a grab operation (that is, your application waits for the grab to finish before returning from the grab function).
	MdigControl(MilDigitizer, M_GRAB_SCALE_X, 1);
	MdigControl(MilDigitizer, M_GRAB_SCALE_Y, 1);
	MdigControl(MilDigitizer, M_GRAB_START_MODE, M_FIELD_START_EVEN); // Specifies that the grab starts on an even field.
	MdigControl(MilDigitizer, M_GRAB_TIMEOUT, 5000);
	MdigControl(MilDigitizer, M_LAST_GRAB_IN_TRUE_BUFFER, M_ENABLE); // Specifies that a monoshot grab is performed.
	MdigControl(MilDigitizer, M_LUT_ID, 8388609);
	MdigControl(MilDigitizer, M_POWER_OVER_CABLE, M_ON); // Specifies to enable PoCL/PoCXP.
	MdigControl(MilDigitizer, M_PROCESS_GRAB_MONITOR, M_ENABLE); // Specifies to create a grab monitoring thread.
	MdigControl(MilDigitizer, M_PROCESS_TIMEOUT, -1);
	MdigControl(MilDigitizer, M_SOURCE_OFFSET_X, 0);
	MdigControl(MilDigitizer, M_SOURCE_OFFSET_Y, 0);
	MdigControl(MilDigitizer, M_SOURCE_SIZE_X, 384);
	MdigControl(MilDigitizer, M_SOURCE_SIZE_Y, 192);
	MdigControl(MilDigitizer, M_WHITE_BALANCE, M_DISABLE); // Specifies that white balancing is disabled.

	MIL_INT BayerCoefficientsId = 0;
	MIL_INT BayerConversion = 0;
	MIL_INT CommandQueueMode = 0;
	MIL_INT GcClprotocol = 0;
	MIL_INT GcClprotocolDeviceIdStringSize = 0;
	MIL_INT GcFeaturePolling = 0;
	MIL_INT GrabDirectionX = 0;
	MIL_INT GrabDirectionY = 0;
	MIL_INT GrabFieldNum = 0;
	MIL_INT GrabLineCounter = 0;
	MIL_INT GrabMode = 0;
	MIL_DOUBLE GrabScaleX = 0.0;
	MIL_DOUBLE GrabScaleY = 0.0;
	MIL_INT GrabStartMode = 0;
	MIL_INT GrabTimeoutInMsecs = 0;
	MIL_INT LastGrabInTrueBuffer = 0;
	MIL_INT LutId = 0;
	MIL_INT PowerOverCable = 0;
	MIL_INT ProcessGrabMonitor = 0;
	MIL_INT ProcessTimeoutInMsecs = 0;
	MIL_INT SourceOffsetXInPixels = 0;
	MIL_INT SourceOffsetYInPixels = 0;
	MIL_INT SourceSizeXInPixels = 0;
	MIL_INT SourceSizeYInPixels = 0;
	MIL_INT WhiteBalance = 0;
	MIL_INT BayerPattern = 0;
	MIL_INT CameraPresent = 0;
	MIL_INT ChannelNum = 0;
	MIL_INT DigProcessInProgress = 0;
	MIL_INT64 ExtendedInitFlag = 0;
	MIL_INT FormatStringSize = 0;
	MIL_INT FormatSize = 0;
	MIL_INT GcClprotocolDeviceIdDefaultStringSize = 0;
	MIL_INT GcClprotocolDeviceIdNum = 0;
	MIL_INT GcClprotocolDeviceIdSizeMax = 0;
	MIL_INT GcXmlPathStringSize = 0;
	MIL_INT GcXmlPathSize = 0;
	MIL_INT GrabInProgress = 0;
	MIL_INT GrabPeriodInMsec = 0;
	MIL_INT InputMode = 0;
	MIL_INT Number = 0;
	MIL_INT OwnerSystem = 0;
	MIL_INT ProcessFrameCountInFrames = 0;
	MIL_INT ProcessFrameMissedInFrames = 0;
	MIL_DOUBLE ProcessFrameRateInFrames = 0.0;
	MIL_INT ProcessPendingGrabNum = 0;
	MIL_INT ProcessTotalBufferNum = 0;
	MIL_INT ScanMode = 0;
	MIL_DOUBLE SelectedFrameRate = 0.0;
	MIL_INT Sign = 0;
	MIL_INT SizeBand = 0;
	MIL_INT SizeBandLut = 0;
	MIL_INT SizeBit = 0;
	MIL_INT SizeXInPixels = 0;
	MIL_INT SizeYInPixels = 0;
	MIL_INT Type = 0;

	MdigInquire(MilDigitizer, M_BAYER_COEFFICIENTS_ID, &BayerCoefficientsId);
	MdigInquire(MilDigitizer, M_BAYER_CONVERSION, &BayerConversion);
	MdigInquire(MilDigitizer, M_COMMAND_QUEUE_MODE, &CommandQueueMode);
	MdigInquire(MilDigitizer, M_GC_CLPROTOCOL, &GcClprotocol);
	MdigInquire(MilDigitizer, M_GC_CLPROTOCOL_DEVICE_ID_SIZE, &GcClprotocolDeviceIdStringSize);
	MIL_TEXT_PTR GcClprotocolDeviceIdPtr = new MIL_TEXT_CHAR[GcClprotocolDeviceIdStringSize];
	MdigInquire(MilDigitizer, M_DEV0 + M_GC_CLPROTOCOL_DEVICE_ID, GcClprotocolDeviceIdPtr);
	delete[] GcClprotocolDeviceIdPtr;
	MdigInquire(MilDigitizer, M_GC_FEATURE_POLLING, &GcFeaturePolling);
	MdigInquire(MilDigitizer, M_GRAB_DIRECTION_X, &GrabDirectionX);
	MdigInquire(MilDigitizer, M_GRAB_DIRECTION_Y, &GrabDirectionY);
	MdigInquire(MilDigitizer, M_GRAB_FIELD_NUM, &GrabFieldNum);
	MdigInquire(MilDigitizer, M_GRAB_LINE_COUNTER, &GrabLineCounter);
	MdigInquire(MilDigitizer, M_GRAB_MODE, &GrabMode);
	MdigInquire(MilDigitizer, M_GRAB_SCALE_X, &GrabScaleX);
	MdigInquire(MilDigitizer, M_GRAB_SCALE_Y, &GrabScaleY);
	MdigInquire(MilDigitizer, M_GRAB_START_MODE, &GrabStartMode);
	MdigInquire(MilDigitizer, M_GRAB_TIMEOUT, &GrabTimeoutInMsecs);
	MdigInquire(MilDigitizer, M_LAST_GRAB_IN_TRUE_BUFFER, &LastGrabInTrueBuffer);
	MdigInquire(MilDigitizer, M_LUT_ID, &LutId);
	MdigInquire(MilDigitizer, M_POWER_OVER_CABLE, &PowerOverCable);
	MdigInquire(MilDigitizer, M_PROCESS_GRAB_MONITOR, &ProcessGrabMonitor);
	MdigInquire(MilDigitizer, M_PROCESS_TIMEOUT, &ProcessTimeoutInMsecs);
	MdigInquire(MilDigitizer, M_SOURCE_OFFSET_X, &SourceOffsetXInPixels);
	MdigInquire(MilDigitizer, M_SOURCE_OFFSET_Y, &SourceOffsetYInPixels);
	MdigInquire(MilDigitizer, M_SOURCE_SIZE_X, &SourceSizeXInPixels);
	MdigInquire(MilDigitizer, M_SOURCE_SIZE_Y, &SourceSizeYInPixels);
	MdigInquire(MilDigitizer, M_WHITE_BALANCE, &WhiteBalance);
	MdigInquire(MilDigitizer, M_BAYER_PATTERN, &BayerPattern);
	MdigInquire(MilDigitizer, M_CAMERA_PRESENT, &CameraPresent);
	printf("Camera Present %d \n", CameraPresent);
	MdigInquire(MilDigitizer, M_CHANNEL_NUM, &ChannelNum);
	MdigInquire(MilDigitizer, M_DIG_PROCESS_IN_PROGRESS, &DigProcessInProgress);
	MdigInquire(MilDigitizer, M_EXTENDED_INIT_FLAG, &ExtendedInitFlag);
	MdigInquire(MilDigitizer, M_FORMAT_SIZE, &FormatStringSize);
	MIL_TEXT_PTR FormatPtr = new MIL_TEXT_CHAR[FormatStringSize];
	MdigInquire(MilDigitizer, M_FORMAT, FormatPtr);
	delete[] FormatPtr;
	MdigInquire(MilDigitizer, M_FORMAT_SIZE, &FormatSize);
	// MdigInquire(MilDigitizer, M_GC_CLPROTOCOL_DEVICE_ID_DEFAULT_SIZE, &GcClprotocolDeviceIdDefaultStringSize);
	MIL_TEXT_PTR GcClprotocolDeviceIdDefaultPtr = new MIL_TEXT_CHAR[GcClprotocolDeviceIdDefaultStringSize];
	MdigInquire(MilDigitizer, M_DEV0 + M_GC_CLPROTOCOL_DEVICE_ID_DEFAULT, GcClprotocolDeviceIdDefaultPtr);
	delete[] GcClprotocolDeviceIdDefaultPtr;
	MdigInquire(MilDigitizer, M_GC_CLPROTOCOL_DEVICE_ID_NUM, &GcClprotocolDeviceIdNum);
	MdigInquire(MilDigitizer, M_GC_CLPROTOCOL_DEVICE_ID_SIZE_MAX, &GcClprotocolDeviceIdSizeMax);
	MdigInquire(MilDigitizer, M_GC_XML_PATH_SIZE, &GcXmlPathStringSize);
	MIL_TEXT_PTR GcXmlPathPtr = new MIL_TEXT_CHAR[GcXmlPathStringSize];
	MdigInquire(MilDigitizer, M_GC_XML_PATH, GcXmlPathPtr);
	delete[] GcXmlPathPtr;
	MdigInquire(MilDigitizer, M_GC_XML_PATH_SIZE, &GcXmlPathSize);
	MdigInquire(MilDigitizer, M_GRAB_IN_PROGRESS, &GrabInProgress);
	MdigInquire(MilDigitizer, M_GRAB_PERIOD, &GrabPeriodInMsec);
	MdigInquire(MilDigitizer, M_INPUT_MODE, &InputMode);
	MdigInquire(MilDigitizer, M_NUMBER, &Number);
	MdigInquire(MilDigitizer, M_OWNER_SYSTEM, &OwnerSystem);
	MdigInquire(MilDigitizer, M_PROCESS_FRAME_COUNT, &ProcessFrameCountInFrames);
	MdigInquire(MilDigitizer, M_PROCESS_FRAME_MISSED, &ProcessFrameMissedInFrames);
	MdigInquire(MilDigitizer, M_PROCESS_FRAME_RATE, &ProcessFrameRateInFrames);
	printf("Frame Count %d Frame Missed %d Frame Rate %d\n", ProcessFrameCountInFrames, ProcessFrameMissedInFrames, ProcessFrameRateInFrames);
	MdigInquire(MilDigitizer, M_PROCESS_PENDING_GRAB_NUM, &ProcessPendingGrabNum);
	MdigInquire(MilDigitizer, M_PROCESS_TOTAL_BUFFER_NUM, &ProcessTotalBufferNum);
	printf("Pending Grab Number %d Total Buffer Num %d\n", ProcessPendingGrabNum, ProcessTotalBufferNum);
	MdigInquire(MilDigitizer, M_SCAN_MODE, &ScanMode);
	MdigInquire(MilDigitizer, M_SELECTED_FRAME_RATE, &SelectedFrameRate);
	MdigInquire(MilDigitizer, M_SIGN, &Sign);
	MdigInquire(MilDigitizer, M_SIZE_BAND, &SizeBand);
	MdigInquire(MilDigitizer, M_SIZE_BAND_LUT, &SizeBandLut);
	MdigInquire(MilDigitizer, M_SIZE_BIT, &SizeBit);
	printf("Size Bit %d \n", SizeBit);
	MdigInquire(MilDigitizer, M_SIZE_X, &SizeXInPixels);
	MdigInquire(MilDigitizer, M_SIZE_Y, &SizeYInPixels);
	MdigInquire(MilDigitizer, M_TYPE, &Type);
	printf("Type %d \n", Type);
}