include ../makefile

MYSQL_INC=/usr/include/mysql
MODULES=certification.o location.o packer.o network.o \
		database_manager.o
SRC=certification.c location.c packer.c network.c \
	database_manager.c
DEBUG=-gstabs
DEBUG_PATH=../test

all:MODULES

MODULES:$(SRC)
	gcc $(DEBUG) -c -o $(DEBUG_PATH)/certification.o \
					certification.c -I$(INC) -I$(MYSQL_INC)
	gcc $(DEBUG) -c -o $(DEBUG_PATH)/location.o \
					location.c -I$(INC) -I$(MYSQL_INC)
	gcc $(DEBUG) -c -o $(DEBUG_PATH)/packer.o \
					packer.c -I$(INC)
	gcc $(DEBUG) -c -o $(DEBUG_PATH)/network.o \
					network.c -I$(INC)
	gcc $(DEBUG) -c -o $(DEBUG_PATH)/database_manager.o \
					database_manager.c -I$(INC) -I$(MYSQL_INC)
