
rem set EPICS_CA_MAX_ARRAY_BYTES=10000000
rem set EPICS_DISPLAY_PATH=C:\epics\synApps_5_8\support\areaDetector-R3-1\ADVoxtel\voxtelApp\op\adl;C:\epics\synApps_5_8\support\areaDetector-R3-1\ADCore\ADApp\op\adl
rem set CAQTDM_DISPLAY_PATH=C:\epics\synApps_5_8\support\areaDetector-R3-1\ADVoxtel\voxtelApp\op\ui;C:\epics\synApps_5_8\support\areaDetector-R3-1\ADCore\ADApp\op\ui\autoconvert


rem start medm -x -macro "P=Voxtel1:, R=cam1:" VoxtelDetector.adl 
rem start caqtdm -x -macro "P=Voxtel1:, R=cam1:" ad_cam_image.ui
  
 ..\..\bin\windows-x64-static\voxtelApp.exe st.cmd

rem CleanUp_Voxtel
rem CleanUP_Maxtor

rem taskkill /IM caqtdm.exe /F
rem taskkill /IM medm.exe /F

