###########################################################################
## Makefile generated for component 'rtwshared'. 
## 
## Makefile     : rtwshared.mk
## Generated on : Sat Apr 09 14:35:06 2022
## Final product: .\rtwshared.lib
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
MATLAB_ROOT               = C:\PROGRA~1\MATLAB\R2022a
MATLAB_BIN                = C:\PROGRA~1\MATLAB\R2022a\bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)\win64
START_DIR                 = C:\Users\oscar\Documents\GitHub\AMS-model\Batteri256\Code
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = ISO_C
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ..\..\..\..
COMPILER_COMMAND_FILE     = rtwshared_comp.rsp
CMD_FILE                  = rtwshared.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
NODEBUG                   = 1
MODELLIB                  = rtwshared.lib

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

PRODUCT = .\rtwshared.lib
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

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)\slprj\ert\_sharedutils\look1_binlxpw.c $(START_DIR)\slprj\ert\_sharedutils\merge_SqkScL3b.c $(START_DIR)\slprj\ert\_sharedutils\rtGetInf.c $(START_DIR)\slprj\ert\_sharedutils\rtGetNaN.c $(START_DIR)\slprj\ert\_sharedutils\rt_nonfinite.c $(START_DIR)\slprj\ert\_sharedutils\sort_iw8mDS81.c $(START_DIR)\slprj\ert\_sharedutils\UTMeanCovSqrt_C2vgLQ4W.c $(START_DIR)\slprj\ert\_sharedutils\UTMeanCovSqrt_C6QfB9Td.c $(START_DIR)\slprj\ert\_sharedutils\cholUpdateFactor_HBMX5a5h.c $(START_DIR)\slprj\ert\_sharedutils\qr_5a2P8Gh6.c $(START_DIR)\slprj\ert\_sharedutils\qr_DvOBrgQi.c $(START_DIR)\slprj\ert\_sharedutils\rotate_LZ7ctbe0.c $(START_DIR)\slprj\ert\_sharedutils\rt_hypotd_snf.c $(START_DIR)\slprj\ert\_sharedutils\svd_u3DvUgOe.c $(START_DIR)\slprj\ert\_sharedutils\trisolve_BC1XmAGq.c $(START_DIR)\slprj\ert\_sharedutils\xaxpy_OQ28XA21.c $(START_DIR)\slprj\ert\_sharedutils\xaxpy_Wxch84Fl.c $(START_DIR)\slprj\ert\_sharedutils\xaxpy_guu0hJif.c $(START_DIR)\slprj\ert\_sharedutils\xdotc_mznw4aLl.c $(START_DIR)\slprj\ert\_sharedutils\xgemv_NQlWbt2i.c $(START_DIR)\slprj\ert\_sharedutils\xgemv_fRiR1I1O.c $(START_DIR)\slprj\ert\_sharedutils\xgerc_R09LiDgJ.c $(START_DIR)\slprj\ert\_sharedutils\xgerc_tNNiazQU.c $(START_DIR)\slprj\ert\_sharedutils\xnrm2_7bm34mDQ.c $(START_DIR)\slprj\ert\_sharedutils\xnrm2_Mnmxg9YT.c $(START_DIR)\slprj\ert\_sharedutils\xnrm2_Rlk0oxWw.c $(START_DIR)\slprj\ert\_sharedutils\xnrm2_nLdASVZH.c $(START_DIR)\slprj\ert\_sharedutils\xnrm2_xDOlDEtw.c $(START_DIR)\slprj\ert\_sharedutils\xrot_i7f01JoJ.c $(START_DIR)\slprj\ert\_sharedutils\xrotg_XzIjz1eG.c $(START_DIR)\slprj\ert\_sharedutils\xscal_59GtRAwv.c $(START_DIR)\slprj\ert\_sharedutils\xscal_PLmmUlD2.c $(START_DIR)\slprj\ert\_sharedutils\xscal_eaAxXsvQ.c $(START_DIR)\slprj\ert\_sharedutils\xswap_JoAqPjUv.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = look1_binlxpw.obj merge_SqkScL3b.obj rtGetInf.obj rtGetNaN.obj rt_nonfinite.obj sort_iw8mDS81.obj UTMeanCovSqrt_C2vgLQ4W.obj UTMeanCovSqrt_C6QfB9Td.obj cholUpdateFactor_HBMX5a5h.obj qr_5a2P8Gh6.obj qr_DvOBrgQi.obj rotate_LZ7ctbe0.obj rt_hypotd_snf.obj svd_u3DvUgOe.obj trisolve_BC1XmAGq.obj xaxpy_OQ28XA21.obj xaxpy_Wxch84Fl.obj xaxpy_guu0hJif.obj xdotc_mznw4aLl.obj xgemv_NQlWbt2i.obj xgemv_fRiR1I1O.obj xgerc_R09LiDgJ.obj xgerc_tNNiazQU.obj xnrm2_7bm34mDQ.obj xnrm2_Mnmxg9YT.obj xnrm2_Rlk0oxWw.obj xnrm2_nLdASVZH.obj xnrm2_xDOlDEtw.obj xrot_i7f01JoJ.obj xrotg_XzIjz1eG.obj xscal_59GtRAwv.obj xscal_PLmmUlD2.obj xscal_eaAxXsvQ.obj xswap_JoAqPjUv.obj

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

.PHONY : all build clean info prebuild download execute set_environment_variables


all : build
	@cmd /C "@echo ### Successfully generated all binary outputs."


build : set_environment_variables prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


set_environment_variables : 
	@set INCLUDE=$(INCLUDES);$(INCLUDE)
	@set LIB=$(LIB)


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@cmd /C "@echo ### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS) -out:$(PRODUCT) @$(CMD_FILE)
	@cmd /C "@echo ### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


look1_binlxpw.obj : "$(START_DIR)\slprj\ert\_sharedutils\look1_binlxpw.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\look1_binlxpw.c"


merge_SqkScL3b.obj : "$(START_DIR)\slprj\ert\_sharedutils\merge_SqkScL3b.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\merge_SqkScL3b.c"


rtGetInf.obj : "$(START_DIR)\slprj\ert\_sharedutils\rtGetInf.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\rtGetInf.c"


rtGetNaN.obj : "$(START_DIR)\slprj\ert\_sharedutils\rtGetNaN.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\rtGetNaN.c"


rt_nonfinite.obj : "$(START_DIR)\slprj\ert\_sharedutils\rt_nonfinite.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\rt_nonfinite.c"


sort_iw8mDS81.obj : "$(START_DIR)\slprj\ert\_sharedutils\sort_iw8mDS81.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\sort_iw8mDS81.c"


UTMeanCovSqrt_C2vgLQ4W.obj : "$(START_DIR)\slprj\ert\_sharedutils\UTMeanCovSqrt_C2vgLQ4W.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\UTMeanCovSqrt_C2vgLQ4W.c"


UTMeanCovSqrt_C6QfB9Td.obj : "$(START_DIR)\slprj\ert\_sharedutils\UTMeanCovSqrt_C6QfB9Td.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\UTMeanCovSqrt_C6QfB9Td.c"


cholUpdateFactor_HBMX5a5h.obj : "$(START_DIR)\slprj\ert\_sharedutils\cholUpdateFactor_HBMX5a5h.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\cholUpdateFactor_HBMX5a5h.c"


qr_5a2P8Gh6.obj : "$(START_DIR)\slprj\ert\_sharedutils\qr_5a2P8Gh6.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\qr_5a2P8Gh6.c"


qr_DvOBrgQi.obj : "$(START_DIR)\slprj\ert\_sharedutils\qr_DvOBrgQi.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\qr_DvOBrgQi.c"


rotate_LZ7ctbe0.obj : "$(START_DIR)\slprj\ert\_sharedutils\rotate_LZ7ctbe0.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\rotate_LZ7ctbe0.c"


rt_hypotd_snf.obj : "$(START_DIR)\slprj\ert\_sharedutils\rt_hypotd_snf.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\rt_hypotd_snf.c"


svd_u3DvUgOe.obj : "$(START_DIR)\slprj\ert\_sharedutils\svd_u3DvUgOe.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\svd_u3DvUgOe.c"


trisolve_BC1XmAGq.obj : "$(START_DIR)\slprj\ert\_sharedutils\trisolve_BC1XmAGq.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\trisolve_BC1XmAGq.c"


xaxpy_OQ28XA21.obj : "$(START_DIR)\slprj\ert\_sharedutils\xaxpy_OQ28XA21.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\xaxpy_OQ28XA21.c"


xaxpy_Wxch84Fl.obj : "$(START_DIR)\slprj\ert\_sharedutils\xaxpy_Wxch84Fl.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\xaxpy_Wxch84Fl.c"


xaxpy_guu0hJif.obj : "$(START_DIR)\slprj\ert\_sharedutils\xaxpy_guu0hJif.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\xaxpy_guu0hJif.c"


xdotc_mznw4aLl.obj : "$(START_DIR)\slprj\ert\_sharedutils\xdotc_mznw4aLl.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\xdotc_mznw4aLl.c"


xgemv_NQlWbt2i.obj : "$(START_DIR)\slprj\ert\_sharedutils\xgemv_NQlWbt2i.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\xgemv_NQlWbt2i.c"


xgemv_fRiR1I1O.obj : "$(START_DIR)\slprj\ert\_sharedutils\xgemv_fRiR1I1O.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\xgemv_fRiR1I1O.c"


xgerc_R09LiDgJ.obj : "$(START_DIR)\slprj\ert\_sharedutils\xgerc_R09LiDgJ.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\xgerc_R09LiDgJ.c"


xgerc_tNNiazQU.obj : "$(START_DIR)\slprj\ert\_sharedutils\xgerc_tNNiazQU.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\xgerc_tNNiazQU.c"


xnrm2_7bm34mDQ.obj : "$(START_DIR)\slprj\ert\_sharedutils\xnrm2_7bm34mDQ.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\xnrm2_7bm34mDQ.c"


xnrm2_Mnmxg9YT.obj : "$(START_DIR)\slprj\ert\_sharedutils\xnrm2_Mnmxg9YT.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\xnrm2_Mnmxg9YT.c"


xnrm2_Rlk0oxWw.obj : "$(START_DIR)\slprj\ert\_sharedutils\xnrm2_Rlk0oxWw.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\xnrm2_Rlk0oxWw.c"


xnrm2_nLdASVZH.obj : "$(START_DIR)\slprj\ert\_sharedutils\xnrm2_nLdASVZH.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\xnrm2_nLdASVZH.c"


xnrm2_xDOlDEtw.obj : "$(START_DIR)\slprj\ert\_sharedutils\xnrm2_xDOlDEtw.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\xnrm2_xDOlDEtw.c"


xrot_i7f01JoJ.obj : "$(START_DIR)\slprj\ert\_sharedutils\xrot_i7f01JoJ.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\xrot_i7f01JoJ.c"


xrotg_XzIjz1eG.obj : "$(START_DIR)\slprj\ert\_sharedutils\xrotg_XzIjz1eG.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\xrotg_XzIjz1eG.c"


xscal_59GtRAwv.obj : "$(START_DIR)\slprj\ert\_sharedutils\xscal_59GtRAwv.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\xscal_59GtRAwv.c"


xscal_PLmmUlD2.obj : "$(START_DIR)\slprj\ert\_sharedutils\xscal_PLmmUlD2.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\xscal_PLmmUlD2.c"


xscal_eaAxXsvQ.obj : "$(START_DIR)\slprj\ert\_sharedutils\xscal_eaAxXsvQ.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\xscal_eaAxXsvQ.c"


xswap_JoAqPjUv.obj : "$(START_DIR)\slprj\ert\_sharedutils\xswap_JoAqPjUv.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\slprj\ert\_sharedutils\xswap_JoAqPjUv.c"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw


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


