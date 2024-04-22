CUR_ROOT    := $(shell pwd)
PRJ_ROOT    ?= $(CUR_ROOT)/..
include $(PRJ_ROOT)/build/base.mak

.PHONY : all clean


components := $(shell find . -maxdepth 1 -type d)
components := $(basename $(patsubst ./%,%,$(components)))

all:
	for comp in $(components);do make -C $$comp||exit;done

clean: $(components)
	for comp in $(components);do make -C $$comp clean||exit;done
