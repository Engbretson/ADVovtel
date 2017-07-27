TOP=../..
include $(TOP)/configure/CONFIG

#----------------------------------------
#  
#
# Voxtell
#
#
#=============================

ifeq (windows-x64, $(findstring windows-x64, $(T_A)))
  LIBRARY_IOC_WIN32 = Mil
endif
LIBRARY_IOC_Linux = Mil



LIB_SRCS    += voxtel.cpp

LIB_LIBS += Mil

INC += voxtel.h

#when we build debug.. we need this line?
#!! for debvug only
PROD_LDFLAGS_WIN32 = /NODEFAULTLIB:LIBCMT.lib

PROD_LDFLAGS_WIN32 += /NODEFAULTLIB:msvcrt.lib

PROD_LDFLAGS_WIN32 += /VERBOSE:LIB

DBD += voxtelSupport.dbd

include $(ADCORE)/ADApp/commonLibraryMakefile

include $(TOP)/configure/RULES

#----------------------------------------
#  ADD RULES AFTER THIS LINE
