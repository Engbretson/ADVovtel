
set EPICS_CA_MAX_ARRAY_BYTES=10000000
set EPICS_DISPLAY_PATH=C:\epics\synApps_5_8\support\areaDetector-R3-1\ADVoxtel\voxtelApp\op\adl;C:\epics\synApps_5_8\support\areaDetector-R3-1\ADCore\ADApp\op\adl
set CAQTDM_DISPLAY_PATH=C:\epics\synApps_5_8\support\areaDetector-R3-1\ADVoxtel\voxtelApp\op\ui;C:\epics\synApps_5_8\support\areaDetector-R3-1\ADCore\ADApp\op\ui\autoconvert

start medm -x -macro "P=Voxtel1:, R=cam1:" VoxtelDetector.adl 
rem start medm -x -macro "P=Voxtel1:, R=cam1:" Power_Supply.adl 
rem start medm -x -macro "P=Voxtel1:, R=cam1:" Reference_Current.adl 
rem start medm -x -macro "P=Voxtel1:, R=cam1:" Reference_Voltage.adl 

rem start caqtdm -x -macro "P=Voxtel1:, R=cam1:" ad_cam_image.ui
  
rem ..\..\bin\windows-x64-static\voxtelApp.exe st.cmd

rem CleanUp_Voxtel
rem CleanUP_Maxtor

rem  taskkill /IM caqtdm.exe /F
rem  taskkill /IM medm.exe /F

