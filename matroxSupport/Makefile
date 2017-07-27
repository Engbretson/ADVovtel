TOP=..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

# Note, the files in this directory were manually copied from the Maxtro MIL directories 

ifeq (windows-x64, $(findstring windows-x64, $(T_A)))

INC += ./os/windows-x64/includes/mbasictypes.h
INC += ./os/windows-x64/includes/MdispD3D.h
INC += ./os/windows-x64/includes/mil.h
INC += ./os/windows-x64/includes/mildec.h
INC += ./os/windows-x64/includes/MilDyn.h
INC += ./os/windows-x64/includes/Milerr.h
INC += ./os/windows-x64/includes/milfpga.h
INC += ./os/windows-x64/includes/milfunc.h
INC += ./os/windows-x64/includes/milfuncll.h
INC += ./os/windows-x64/includes/milfunctioncode.h
INC += ./os/windows-x64/includes/milos.h
INC += ./os/windows-x64/includes/milproto.h
INC += ./os/windows-x64/includes/milsetup.h

INC += ./os/windows-x64/includes/MILDyn/mil3dmap.h
INC += ./os/windows-x64/includes/MILDyn/milbead.h
INC += ./os/windows-x64/includes/MILDyn/milblob.h
INC += ./os/windows-x64/includes/MILDyn/milcal.h
INC += ./os/windows-x64/includes/MILDyn/milcode.h
INC += ./os/windows-x64/includes/MILDyn/milcolor.h
INC += ./os/windows-x64/includes/MILDyn/mildisplay.h
INC += ./os/windows-x64/includes/MILDyn/miledge.h
INC += ./os/windows-x64/includes/MILDyn/milim.h
INC += ./os/windows-x64/includes/MILDyn/milmeas.h
INC += ./os/windows-x64/includes/MILDyn/milmetrol.h
INC += ./os/windows-x64/includes/MILDyn/milmod.h
INC += ./os/windows-x64/includes/MILDyn/milocr.h
INC += ./os/windows-x64/includes/MILDyn/milpat.h
INC += ./os/windows-x64/includes/MILDyn/milreg.h
INC += ./os/windows-x64/includes/MILDyn/milstr.h
endif

ifeq (windows-x64, $(findstring windows-x64, $(T_A)))
LIB_INSTALLS_WIN32    += ../os/windows-x64/libs/Mil.lib
endif


#=============================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

