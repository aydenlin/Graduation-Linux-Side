include ../makefile

MODULES=certification.o location.o packer.o network.o
SRC=certification.c location.c packer.c network.c
DEBUG=-gstabs
DEBUG_PATH=../test
all:$(MODULES)

$(MODULES):$(SRC)
	gcc $(DEBUG) -c -o $(DEBUG_PATH)/certification.o \
					certification.c -I$(INC)
	gcc $(DEBUG) -c -o $(DEBUG_PATH)/location.o \
					location.c -I$(INC)
	gcc $(DEBUG) -c -o $(DEBUG_PATH)/packer.o \
					packer.c -I$(INC)
	gcc $(DEBUG) -c -o $(DEBUG_PATH)/network.o \
					network.c -I$(INC)
