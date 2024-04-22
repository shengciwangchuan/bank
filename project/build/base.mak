ifeq ($(PRJ_ROOT_BASECFG),)
PRJ_ROOT_BASECFG = 1

ifeq ($(PRJ_ROOT),)
$(error please specify reference root path)
endif

#++++++++++++++++++++++++++++++++++++++++++++++++++++
#	Common Function Definition
#++++++++++++++++++++++++++++++++++++++++++++++++++++
# Current Directory Name(exclude prefix)
CUR_DIR_NAME = $(shell pwd |sed 's/^\(.*\)[/]//' )

# Current Parent Directory Name(exclude prefix)
CUR_PARENT_DIR_NAME = $(shell cd ./..;pwd|sed 's/^\(.*\)[/]//')

# Make Result Check
MAKE_EXT_FLAG := || exit "$$?"

SVR_LONGBIT   := $(shell getconf LONG_BIT)

#++++++++++++++++++++++++++++++++++++++++++++++++++++
#	Common Configure
#++++++++++++++++++++++++++++++++++++++++++++++++++++
PRJ_ROOT     := $(shell cd $(PRJ_ROOT); pwd)
SDK_ROOT     ?= $(shell cd $(PRJ_ROOT)/..; pwd)
include $(SDK_ROOT)/build/base.mak

#++++++++++++++++++++++++++++++++++++++++++++++++++++
#	Out Path Configure
#++++++++++++++++++++++++++++++++++++++++++++++++++++
PRJ_OUT_ROOT       := $(PRJ_ROOT)/out

PRJ_OUT_COMMON     := $(PRJ_OUT_ROOT)/common
PRJ_OUT_COMMON_OBJ := $(PRJ_OUT_COMMON)/obj
PRJ_OUT_COMMON_LIB := $(PRJ_OUT_COMMON)/lib

PRJ_OUT_MODULE      := $(PRJ_OUT_ROOT)/module
PRJ_OUT_MODULE_OBJ  := $(PRJ_OUT_THIRD)/obj
PRJ_OUT_MODULE_LIB  := $(PRJ_OUT_THIRD)/lib

PRJ_OUT_THIRD      := $(PRJ_OUT_ROOT)/thirdparty
PRJ_OUT_THIRD_OBJ  := $(PRJ_OUT_THIRD)/obj
PRJ_OUT_THIRD_LIB  := $(PRJ_OUT_THIRD)/lib


#++++++++++++++++++++++++++++++++++++++++++++++++++++
#	Compile Configure
#++++++++++++++++++++++++++++++++++++++++++++++++++++
VSS_INC_PATH :=
VSS_CFLAGS   :=
VSS_LDFLAGS  :=
VSS_STLIBS   :=
VSS_SHLIBS   :=

include $(PRJ_ROOT)/build/compile_config.mak

#include $(REF_ROOT)/build/inc.mak
#include $(REF_APPCOMMON_PATH)/inc.mak
#include $(REF_HAL_PATH)/inc.mak
#include $(REF_THIRDPARTY_PATH)/inc.mak

endif # ifndef $(PRJ_ROOT_BASECFG)
