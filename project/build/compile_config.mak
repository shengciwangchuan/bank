
VSS_CFLAGS += -fno-aggressive-loop-optimizations
VSS_CFLAGS += -ffunction-sections -fdata-sections -funwind-tables
VSS_CFLAGS += -Wall -Warray-bounds -Werror -Wfatal-errors
VSS_CFLAGS += -Wno-error=strict-prototypes
VSS_CFLAGS += -fPIC -fPIE -pie
VSS_CFLAGS += --param ssp-buffer-size=4
VSS_CFLAGS += -D_GNU_SOURCE

CC      = $(CROSS)gcc
CXX     = $(CROSS)gcc
CCDEP   = $(CROSS)gcc
AR      = $(CROSS)ar
LINK    = $(CROSS)gcc

STRIP   = $(CROSS)strip
OBJCOPY = $(CROSS)objcopy
OBJDUMP = $(CROSS)objdump
RANLIB  = true
ARFLAGS = rcv
