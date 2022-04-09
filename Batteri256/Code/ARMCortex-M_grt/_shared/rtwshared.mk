###########################################################################
## Makefile generated for component 'rtwshared'. 
## 
## Makefile     : rtwshared.mk
## Generated on : Sat Apr 09 03:16:07 2022
## Final product: ./rtwshared.lib
## Product type : static library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file
# MODELLIB                Static library target

PRODUCT_NAME              = rtwshared
MAKEFILE                  = rtwshared.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2021a
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2021a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/oscar/Documents/GitHub/AMS-model/Batteri256/Code
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = ISO_C
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../..
COMPILER_COMMAND_FILE     = rtwshared_comp.rsp
CMD_FILE                  = rtwshared.rsp
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
MODELLIB                  = rtwshared.lib

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          MinGW64 | gmake (64-bit Windows)
# Supported Version(s):    6.x
# ToolchainInfo Version:   2021a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS
# MINGW_ROOT
# MINGW_C_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS            = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align
WARN_FLAGS_MAX        = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS        = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align
CPP_WARN_FLAGS_MAX    = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow
MW_EXTERNLIB_DIR      = $(MATLAB_ROOT)/extern/lib/win64/mingw64
SHELL                 = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lws2_32

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC_PATH = $(MINGW_ROOT)
CC = "$(CC_PATH)/gcc"

# Linker: GNU Linker
LD_PATH = $(MINGW_ROOT)
LD = "$(LD_PATH)/g++"

# C++ Compiler: GNU C++ Compiler
CPP_PATH = $(MINGW_ROOT)
CPP = "$(CPP_PATH)/g++"

# C++ Linker: GNU C++ Linker
CPP_LD_PATH = $(MINGW_ROOT)
CPP_LD = "$(CPP_LD_PATH)/g++"

# Archiver: GNU Archiver
AR_PATH = $(MINGW_ROOT)
AR = "$(AR_PATH)/ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(MINGW_C_STANDARD_OPTS) -m64 \
                       -O0
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -m64 \
                       -O0
CPP_LDFLAGS          =  -static -m64
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,--no-undefined \
                         -Wl,--out-implib,$(basename $(PRODUCT)).lib
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =  -static -m64
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,--no-undefined \
                       -Wl,--out-implib,$(basename $(PRODUCT)).lib



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./rtwshared.lib
PRODUCT_TYPE = "static library"
BUILD_TYPE = "Model Reference Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DINTEGER_CODE=0
DEFINES_CUSTOM = 
DEFINES_STANDARD = -DNRT -DUSE_RTMODEL

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/ARMCortex-M_grt/_shared/UTMeanCovSqrt_Cre0pFhD.c $(START_DIR)/ARMCortex-M_grt/_shared/UTMeanCovSqrt_XXn7ctVv.c $(START_DIR)/ARMCortex-M_grt/_shared/cholUpdateFactor_2sWnptMU.c $(START_DIR)/ARMCortex-M_grt/_shared/look1_binlxpw.c $(START_DIR)/ARMCortex-M_grt/_shared/qr_EmoCK6PM.c $(START_DIR)/ARMCortex-M_grt/_shared/qr_GmaocXY1.c $(START_DIR)/ARMCortex-M_grt/_shared/rotate_YgpoDwi7.c $(START_DIR)/ARMCortex-M_grt/_shared/rtGetInf.c $(START_DIR)/ARMCortex-M_grt/_shared/rtGetNaN.c $(START_DIR)/ARMCortex-M_grt/_shared/rt_hypotd_snf.c $(START_DIR)/ARMCortex-M_grt/_shared/rt_nonfinite.c $(START_DIR)/ARMCortex-M_grt/_shared/svd_NBhHrtzf.c $(START_DIR)/ARMCortex-M_grt/_shared/trisolve_xiqzX6vu.c $(START_DIR)/ARMCortex-M_grt/_shared/xaxpy_7GI3igQ0.c $(START_DIR)/ARMCortex-M_grt/_shared/xaxpy_mbb9dr0X.c $(START_DIR)/ARMCortex-M_grt/_shared/xaxpy_rrNCryFm.c $(START_DIR)/ARMCortex-M_grt/_shared/xdotc_zr3wrcdj.c $(START_DIR)/ARMCortex-M_grt/_shared/xgemv_Wy0IOmcY.c $(START_DIR)/ARMCortex-M_grt/_shared/xgemv_YUCucuUc.c $(START_DIR)/ARMCortex-M_grt/_shared/xgerc_EXI1TjPL.c $(START_DIR)/ARMCortex-M_grt/_shared/xgerc_gpDDvQUP.c $(START_DIR)/ARMCortex-M_grt/_shared/xnrm2_5iCqcdaj.c $(START_DIR)/ARMCortex-M_grt/_shared/xnrm2_FT4aBNcp.c $(START_DIR)/ARMCortex-M_grt/_shared/xnrm2_hoYimUM0.c $(START_DIR)/ARMCortex-M_grt/_shared/xnrm2_jjztiUbW.c $(START_DIR)/ARMCortex-M_grt/_shared/xnrm2_ok6MIqj4.c $(START_DIR)/ARMCortex-M_grt/_shared/xrot_XJ24Fklz.c $(START_DIR)/ARMCortex-M_grt/_shared/xrotg_3bzOSYJ0.c $(START_DIR)/ARMCortex-M_grt/_shared/xscal_GEvlLaQR.c $(START_DIR)/ARMCortex-M_grt/_shared/xscal_MJdXKQzM.c $(START_DIR)/ARMCortex-M_grt/_shared/xscal_zWOdCWj1.c $(START_DIR)/ARMCortex-M_grt/_shared/xswap_XY2Ve8c9.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = UTMeanCovSqrt_Cre0pFhD.obj UTMeanCovSqrt_XXn7ctVv.obj cholUpdateFactor_2sWnptMU.obj look1_binlxpw.obj qr_EmoCK6PM.obj qr_GmaocXY1.obj rotate_YgpoDwi7.obj rtGetInf.obj rtGetNaN.obj rt_hypotd_snf.obj rt_nonfinite.obj svd_NBhHrtzf.obj trisolve_xiqzX6vu.obj xaxpy_7GI3igQ0.obj xaxpy_mbb9dr0X.obj xaxpy_rrNCryFm.obj xdotc_zr3wrcdj.obj xgemv_Wy0IOmcY.obj xgemv_YUCucuUc.obj xgerc_EXI1TjPL.obj xgerc_gpDDvQUP.obj xnrm2_5iCqcdaj.obj xnrm2_FT4aBNcp.obj xnrm2_hoYimUM0.obj xnrm2_jjztiUbW.obj xnrm2_ok6MIqj4.obj xrot_XJ24Fklz.obj xrotg_3bzOSYJ0.obj xscal_GEvlLaQR.obj xscal_MJdXKQzM.obj xscal_zWOdCWj1.obj xswap_XY2Ve8c9.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_BASIC)

#---------------------
# MEX C++ Compiler
#---------------------

MEX_CPP_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CPPFLAGS += $(MEX_CPP_Compiler_BASIC)

#-----------------
# MEX Compiler
#-----------------

MEX_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CFLAGS += $(MEX_Compiler_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


MINGW_C_STANDARD_OPTS = $(C_STANDARD_OPTS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) @$(CMD_FILE)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


UTMeanCovSqrt_Cre0pFhD.obj : $(START_DIR)/ARMCortex-M_grt/_shared/UTMeanCovSqrt_Cre0pFhD.c
	$(CC) $(CFLAGS) -o "$@" "$<"


UTMeanCovSqrt_XXn7ctVv.obj : $(START_DIR)/ARMCortex-M_grt/_shared/UTMeanCovSqrt_XXn7ctVv.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cholUpdateFactor_2sWnptMU.obj : $(START_DIR)/ARMCortex-M_grt/_shared/cholUpdateFactor_2sWnptMU.c
	$(CC) $(CFLAGS) -o "$@" "$<"


look1_binlxpw.obj : $(START_DIR)/ARMCortex-M_grt/_shared/look1_binlxpw.c
	$(CC) $(CFLAGS) -o "$@" "$<"


qr_EmoCK6PM.obj : $(START_DIR)/ARMCortex-M_grt/_shared/qr_EmoCK6PM.c
	$(CC) $(CFLAGS) -o "$@" "$<"


qr_GmaocXY1.obj : $(START_DIR)/ARMCortex-M_grt/_shared/qr_GmaocXY1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rotate_YgpoDwi7.obj : $(START_DIR)/ARMCortex-M_grt/_shared/rotate_YgpoDwi7.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetInf.obj : $(START_DIR)/ARMCortex-M_grt/_shared/rtGetInf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetNaN.obj : $(START_DIR)/ARMCortex-M_grt/_shared/rtGetNaN.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_hypotd_snf.obj : $(START_DIR)/ARMCortex-M_grt/_shared/rt_hypotd_snf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_nonfinite.obj : $(START_DIR)/ARMCortex-M_grt/_shared/rt_nonfinite.c
	$(CC) $(CFLAGS) -o "$@" "$<"


svd_NBhHrtzf.obj : $(START_DIR)/ARMCortex-M_grt/_shared/svd_NBhHrtzf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


trisolve_xiqzX6vu.obj : $(START_DIR)/ARMCortex-M_grt/_shared/trisolve_xiqzX6vu.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xaxpy_7GI3igQ0.obj : $(START_DIR)/ARMCortex-M_grt/_shared/xaxpy_7GI3igQ0.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xaxpy_mbb9dr0X.obj : $(START_DIR)/ARMCortex-M_grt/_shared/xaxpy_mbb9dr0X.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xaxpy_rrNCryFm.obj : $(START_DIR)/ARMCortex-M_grt/_shared/xaxpy_rrNCryFm.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xdotc_zr3wrcdj.obj : $(START_DIR)/ARMCortex-M_grt/_shared/xdotc_zr3wrcdj.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xgemv_Wy0IOmcY.obj : $(START_DIR)/ARMCortex-M_grt/_shared/xgemv_Wy0IOmcY.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xgemv_YUCucuUc.obj : $(START_DIR)/ARMCortex-M_grt/_shared/xgemv_YUCucuUc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xgerc_EXI1TjPL.obj : $(START_DIR)/ARMCortex-M_grt/_shared/xgerc_EXI1TjPL.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xgerc_gpDDvQUP.obj : $(START_DIR)/ARMCortex-M_grt/_shared/xgerc_gpDDvQUP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xnrm2_5iCqcdaj.obj : $(START_DIR)/ARMCortex-M_grt/_shared/xnrm2_5iCqcdaj.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xnrm2_FT4aBNcp.obj : $(START_DIR)/ARMCortex-M_grt/_shared/xnrm2_FT4aBNcp.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xnrm2_hoYimUM0.obj : $(START_DIR)/ARMCortex-M_grt/_shared/xnrm2_hoYimUM0.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xnrm2_jjztiUbW.obj : $(START_DIR)/ARMCortex-M_grt/_shared/xnrm2_jjztiUbW.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xnrm2_ok6MIqj4.obj : $(START_DIR)/ARMCortex-M_grt/_shared/xnrm2_ok6MIqj4.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xrot_XJ24Fklz.obj : $(START_DIR)/ARMCortex-M_grt/_shared/xrot_XJ24Fklz.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xrotg_3bzOSYJ0.obj : $(START_DIR)/ARMCortex-M_grt/_shared/xrotg_3bzOSYJ0.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xscal_GEvlLaQR.obj : $(START_DIR)/ARMCortex-M_grt/_shared/xscal_GEvlLaQR.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xscal_MJdXKQzM.obj : $(START_DIR)/ARMCortex-M_grt/_shared/xscal_MJdXKQzM.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xscal_zWOdCWj1.obj : $(START_DIR)/ARMCortex-M_grt/_shared/xscal_zWOdCWj1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xswap_XY2Ve8c9.obj : $(START_DIR)/ARMCortex-M_grt/_shared/xswap_XY2Ve8c9.c
	$(CC) $(CFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


