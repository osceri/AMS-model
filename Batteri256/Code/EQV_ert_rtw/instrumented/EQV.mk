###########################################################################
## Makefile generated for component 'EQV'. 
## 
## Makefile     : EQV.mk
## Generated on : Mon Apr 11 22:46:22 2022
## Final product: $(RELATIVE_PATH_TO_ANCHOR)\EQV.exe
## Product type : executable
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

PRODUCT_NAME              = EQV
MAKEFILE                  = EQV.mk
MATLAB_ROOT               = C:\PROGRA~1\MATLAB\R2022a
MATLAB_BIN                = C:\PROGRA~1\MATLAB\R2022a\bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)\win64
START_DIR                 = C:\Users\oscar\Documents\GitHub\AMS-model\Batteri256\Code
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = ISO_C
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..\..
COMPILER_COMMAND_FILE     = EQV_comp.rsp
CMD_FILE                  = EQV.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
NODEBUG                   = 1
LIBSSC_SLI_ERT_VCX64_OBJS = 
LIBSSC_CORE_ERT_VCX64_OBJS = 
LIBSSC_ST_ERT_VCX64_OBJS  = 
LIBMC_ERT_VCX64_OBJS      = 
LIBEX_ERT_VCX64_OBJS      = 
LIBPM_ERT_VCX64_OBJS      = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Microsoft Visual C++ 2022 v17.0 | nmake (64-bit Windows)
# Supported Version(s):    17.0
# ToolchainInfo Version:   2022a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# NODEBUG
# cvarsdll
# cvarsmt
# conlibsmt
# ldebug
# conflags
# cflags

#-----------
# MACROS
#-----------

MW_EXTERNLIB_DIR    = $(MATLAB_ROOT)\extern\lib\win64\microsoft
MW_LIB_DIR          = $(MATLAB_ROOT)\lib\win64
CPU                 = AMD64
APPVER              = 5.02
CVARSFLAG           = $(cvarsmt)
CFLAGS_ADDITIONAL   = -D_CRT_SECURE_NO_WARNINGS
CPPFLAGS_ADDITIONAL = -EHs -D_CRT_SECURE_NO_WARNINGS /wd4251 /Zc:__cplusplus
LIBS_TOOLCHAIN      = $(conlibs)

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Microsoft Visual C Compiler
CC = cl

# Linker: Microsoft Visual C Linker
LD = link

# C++ Compiler: Microsoft Visual C++ Compiler
CPP = cl

# C++ Linker: Microsoft Visual C++ Linker
CPP_LD = link

# Archiver: Microsoft Visual C/C++ Archiver
AR = lib

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)\mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: NMAKE Utility
MAKE = nmake


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -Zi
C_OUTPUT_FLAG       = -Fo
LDDEBUG             = /DEBUG
OUTPUT_FLAG         = -out:
CPPDEBUG            = -Zi
CPP_OUTPUT_FLAG     = -Fo
CPPLDDEBUG          = /DEBUG
OUTPUT_FLAG         = -out:
ARDEBUG             =
STATICLIB_OUTPUT_FLAG = -out:
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @ren
RUN                 = @cmd /C

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = /nologo
CFLAGS               = $(cflags) $(CVARSFLAG) $(CFLAGS_ADDITIONAL) \
                       /Od /Oy-
CPPFLAGS             = /TP $(cflags) $(CVARSFLAG) $(CPPFLAGS_ADDITIONAL) \
                       /Od /Oy-
CPP_LDFLAGS          = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN)
CPP_SHAREDLIB_LDFLAGS  = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN) \
                         -dll -def:$(DEF_FILE)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN) \
                       -dll -def:$(DEF_FILE)



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)\EQV.exe
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=0 -DPROFILING_DEFINE_UINT64_TIMER_TYPE
DEFINES_STANDARD = -DMODEL=EQV -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds.c $(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_zc.c $(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_obs_il.c $(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_obs_all.c $(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_obs_act.c $(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_log.c $(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_tdxf_p.c $(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_dxf_p.c $(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_dxf.c $(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_mode.c $(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_f.c $(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_assert.c $(START_DIR)\EQV_ert_rtw\EQV_627956e1_1.c $(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_gateway.c $(START_DIR)\EQV_ert_rtw\EQV.c $(START_DIR)\EQV_ert_rtw\EQV_data.c

MAIN_SRC = $(START_DIR)\EQV_ert_rtw\ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = EQV_627956e1_1_ds.obj EQV_627956e1_1_ds_zc.obj EQV_627956e1_1_ds_obs_il.obj EQV_627956e1_1_ds_obs_all.obj EQV_627956e1_1_ds_obs_act.obj EQV_627956e1_1_ds_log.obj EQV_627956e1_1_ds_tdxf_p.obj EQV_627956e1_1_ds_dxf_p.obj EQV_627956e1_1_ds_dxf.obj EQV_627956e1_1_ds_mode.obj EQV_627956e1_1_ds_f.obj EQV_627956e1_1_ds_assert.obj EQV_627956e1_1.obj EQV_627956e1_1_gateway.obj EQV.obj EQV_data.obj

MAIN_OBJ = ert_main.obj

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = $(MATLAB_ROOT)\toolbox\physmod\simscape\engine\sli\lib\win64\ssc_sli_ert_vcx64.lib $(MATLAB_ROOT)\toolbox\physmod\simscape\engine\core\lib\win64\ssc_core_ert_vcx64.lib $(MATLAB_ROOT)\toolbox\physmod\simscape\simtypes\core\lib\win64\ssc_st_ert_vcx64.lib $(MATLAB_ROOT)\toolbox\physmod\common\math\core\lib\win64\mc_ert_vcx64.lib $(MATLAB_ROOT)\toolbox\physmod\common\external\library\lib\win64\ex_ert_vcx64.lib $(MATLAB_ROOT)\toolbox\physmod\common\foundation\core\lib\win64\pm_ert_vcx64.lib $(START_DIR)\slprj\ert\_sharedutils\instrumented\rtwshared.lib

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

CFLAGS_BASIC = $(DEFINES) @$(COMPILER_COMMAND_FILE)

CFLAGS = $(CFLAGS) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS = $(CPPFLAGS) $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


!include $(MATLAB_ROOT)\rtw\c\tools\vcdefs.mak


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute set_environment_variables


all : build
	@cmd /C "@echo ### Successfully generated all binary outputs."


build : set_environment_variables prebuild $(PRODUCT)


buildobj : set_environment_variables prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@cmd /C "@echo ### Successfully generated all binary outputs."


prebuild : 


download : $(PRODUCT)


execute : download
	@cmd /C "@echo ### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@cmd /C "@echo ### Done invoking postbuild tool."


set_environment_variables : 
	@set INCLUDE=$(INCLUDES);$(INCLUDE)
	@set LIB=$(LIB)


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	@cmd /C "@echo ### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -out:$(PRODUCT) @$(CMD_FILE) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@cmd /C "@echo ### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\sli\c\win64}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\sli\c\win64}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\core\c\win64}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\core\c\win64}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\simscape\compiler\core\c\win64}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\simscape\compiler\core\c\win64}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\simscape\ds\core\c\win64}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\simscape\ds\core\c\win64}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\simscape\simtypes\core\c\win64}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\simscape\simtypes\core\c\win64}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\common\math\core\c\win64}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\common\math\core\c\win64}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\common\logging\core\c\win64}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\common\logging\core\c\win64}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\common\lang\core\c\win64}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\common\lang\core\c\win64}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\common\external\library\c\win64}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\common\external\library\c\win64}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\common\foundation\core\c\win64}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\common\foundation\core\c\win64}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)\EQV_ert_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\EQV_ert_rtw}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\rtw\c\src}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\simulink\src}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\simulink\src}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{..}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{..}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


EQV_627956e1_1_ds.obj : "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds.c"


EQV_627956e1_1_ds_zc.obj : "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_zc.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_zc.c"


EQV_627956e1_1_ds_obs_il.obj : "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_obs_il.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_obs_il.c"


EQV_627956e1_1_ds_obs_all.obj : "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_obs_all.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_obs_all.c"


EQV_627956e1_1_ds_obs_act.obj : "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_obs_act.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_obs_act.c"


EQV_627956e1_1_ds_log.obj : "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_log.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_log.c"


EQV_627956e1_1_ds_tdxf_p.obj : "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_tdxf_p.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_tdxf_p.c"


EQV_627956e1_1_ds_dxf_p.obj : "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_dxf_p.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_dxf_p.c"


EQV_627956e1_1_ds_dxf.obj : "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_dxf.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_dxf.c"


EQV_627956e1_1_ds_mode.obj : "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_mode.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_mode.c"


EQV_627956e1_1_ds_f.obj : "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_f.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_f.c"


EQV_627956e1_1_ds_assert.obj : "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_assert.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_ds_assert.c"


EQV_627956e1_1.obj : "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1.c"


EQV_627956e1_1_gateway.obj : "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_gateway.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\EQV_ert_rtw\EQV_627956e1_1_gateway.c"


EQV.obj : "$(START_DIR)\EQV_ert_rtw\EQV.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\EQV_ert_rtw\EQV.c"


EQV_data.obj : "$(START_DIR)\EQV_ert_rtw\EQV_data.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\EQV_ert_rtw\EQV_data.c"


ert_main.obj : "$(START_DIR)\EQV_ert_rtw\ert_main.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\EQV_ert_rtw\ert_main.c"


#------------------------
# BUILDABLE LIBRARIES
#------------------------

$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\sli\lib\win64\ssc_sli_ert_vcx64.lib : $(LIBSSC_SLI_ERT_VCX64_OBJS)
	@cmd /C "@echo ### Creating static library $@ ..."
	$(AR) $(ARFLAGS) -out:$@ $(LIBSSC_SLI_ERT_VCX64_OBJS)


$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\core\lib\win64\ssc_core_ert_vcx64.lib : $(LIBSSC_CORE_ERT_VCX64_OBJS)
	@cmd /C "@echo ### Creating static library $@ ..."
	$(AR) $(ARFLAGS) -out:$@ $(LIBSSC_CORE_ERT_VCX64_OBJS)


$(MATLAB_ROOT)\toolbox\physmod\simscape\simtypes\core\lib\win64\ssc_st_ert_vcx64.lib : $(LIBSSC_ST_ERT_VCX64_OBJS)
	@cmd /C "@echo ### Creating static library $@ ..."
	$(AR) $(ARFLAGS) -out:$@ $(LIBSSC_ST_ERT_VCX64_OBJS)


$(MATLAB_ROOT)\toolbox\physmod\common\math\core\lib\win64\mc_ert_vcx64.lib : $(LIBMC_ERT_VCX64_OBJS)
	@cmd /C "@echo ### Creating static library $@ ..."
	$(AR) $(ARFLAGS) -out:$@ $(LIBMC_ERT_VCX64_OBJS)


$(MATLAB_ROOT)\toolbox\physmod\common\external\library\lib\win64\ex_ert_vcx64.lib : $(LIBEX_ERT_VCX64_OBJS)
	@cmd /C "@echo ### Creating static library $@ ..."
	$(AR) $(ARFLAGS) -out:$@ $(LIBEX_ERT_VCX64_OBJS)


$(MATLAB_ROOT)\toolbox\physmod\common\foundation\core\lib\win64\pm_ert_vcx64.lib : $(LIBPM_ERT_VCX64_OBJS)
	@cmd /C "@echo ### Creating static library $@ ..."
	$(AR) $(ARFLAGS) -out:$@ $(LIBPM_ERT_VCX64_OBJS)


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@cmd /C "@echo ### PRODUCT = $(PRODUCT)"
	@cmd /C "@echo ### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@cmd /C "@echo ### BUILD_TYPE = $(BUILD_TYPE)"
	@cmd /C "@echo ### INCLUDES = $(INCLUDES)"
	@cmd /C "@echo ### DEFINES = $(DEFINES)"
	@cmd /C "@echo ### ALL_SRCS = $(ALL_SRCS)"
	@cmd /C "@echo ### ALL_OBJS = $(ALL_OBJS)"
	@cmd /C "@echo ### LIBS = $(LIBS)"
	@cmd /C "@echo ### MODELREF_LIBS = $(MODELREF_LIBS)"
	@cmd /C "@echo ### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@cmd /C "@echo ### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@cmd /C "@echo ### CFLAGS = $(CFLAGS)"
	@cmd /C "@echo ### LDFLAGS = $(LDFLAGS)"
	@cmd /C "@echo ### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ### CPPFLAGS = $(CPPFLAGS)"
	@cmd /C "@echo ### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@cmd /C "@echo ### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ### ARFLAGS = $(ARFLAGS)"
	@cmd /C "@echo ### MEX_CFLAGS = $(MEX_CFLAGS)"
	@cmd /C "@echo ### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@cmd /C "@echo ### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@cmd /C "@echo ### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@cmd /C "@echo ### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@cmd /C "@echo ### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@cmd /C "@echo ### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	@if exist $(PRODUCT) $(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


