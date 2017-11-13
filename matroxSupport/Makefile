TOP=..
include $(TOP)/configure/CONFIG
 
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

# Note, the files in this directory were manually copied from the Andor SDK directories 
# for Linux and Windows.  The soft links for Linux were manually created.

#copied from win32 version... assume win64 is same h files.

INC += mbasictypes.h
INC += MdispD3D.h
INC += mil.h
INC += mildec.h
INC += MilDyn.h
INC += Milerr.h
INC += milfpga.h
INC += milfunc.h
INC += milfuncll.h
INC += milfunctioncode.h
INC += milos.h
INC += milproto.h
INC += milsetup.h

INC += MILDyn/mil3dmap.h
INC += MILDyn/milbead.h
INC += MILDyn/milblob.h
INC += MILDyn/milcal.h
INC += MILDyn/milcode.h
INC += MILDyn/milcolor.h
INC += MILDyn/mildisplay.h
INC += MILDyn/miledge.h
INC += MILDyn/milim.h
INC += MILDyn/milmeas.h
INC += MILDyn/milmetrol.h
INC += MILDyn/milmod.h
INC += MILDyn/milocr.h
INC += MILDyn/milpat.h
INC += MILDyn/milreg.h
INC += MILDyn/milstr.h



ifeq (windows-x64, $(findstring windows-x64, $(T_A)))
LIB_INSTALLS_WIN32    += ../os/windows-x64/Mil.lib
#else ifeq (linux-x86_64, $(findstring linux-x86_64, $(T_A)))

#else ifeq (linux-x86, $(findstring linux-x86, $(T_A)))

endif

#=============================

include $(TOP)/configure/RULES

#----------------------------------------
#  ADD RULES AFTER THIS LINE

