obj-m := char_device.o

KERNELDIR ?= /usr/src/linux-source-3.13.0
PWD := $(shell pwd)

all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	rm -f *.o *.ko modules.order Module.symvers char_device.mod.c

