TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

PROD_NAME = voxtelApp
ifeq (windows-x64, $(findstring windows-x64, $(T_A)))
  PROD_IOC_WIN32 += $(PROD_NAME)
endif
#PROD_IOC_Linux += $(PROD_NAME)


# <name>.dbd will be created from <name>Include.dbd
DBD += $(PROD_NAME).dbd
$(PROD_NAME)_DBD += VOXTELSupport.dbd
#$(PROD_NAME)_DBD  += camLinkSerialSupport.dbd

# <name>_registerRecordDeviceDriver.cpp will be created from <name>.dbd
PROD_SRCS_DEFAULT += $(PROD_NAME)_registerRecordDeviceDriver.cpp $(PROD_NAME)Main.cpp

# Add locally compiled object code
PROD_LIBS += voxtel Mil 
#PROD_LIBS += cameralink Mil
#PROD_LIBS += clsersis display_lib fglib5 gbelib iolibrt

include $(ADCORE)/ADApp/commonDriverMakefile

#=============================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

