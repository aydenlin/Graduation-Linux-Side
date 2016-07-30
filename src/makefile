include ../makefile

SERVER=Server
MYSQL_INC=/usr/include/mysql
MODULES=location.o certification.o packer.o network.o tools.o\
		database_manager.o datastruct.o processor.o
SRC=certification.c location.c packer.c network.c \
	database_manager.c datastruct/datastruct.c processor.c
DEBUG=-gstabs -D DEBUG
DEBUG_PATH=.

all:MODULES SERVER

SERVER:$(SERVER).c MODULES
	gcc $(DEBUG) -o $(SERVER) $(SERVER).c $(MODULES) -I$(INC) -I$(MYSQL_INC)  \
		-L/usr/lib64 -lmysqlclient -lpthread -lz -lm -lssl -lcrypto -ldl \
		-L/home/ayden/project/graduation/lib -lmy_mysql
	rm ./*.o
MODULES:$(SRC)
	gcc $(DEBUG) -c -o $(DEBUG_PATH)/database_manager.o \
					database_manager.c -I$(INC) -I$(MYSQL_INC) 
	gcc $(DEBUG) -c -o $(DEBUG_PATH)/tools.o \
					tools.c -I$(INC)
	gcc $(DEBUG) -c -o $(DEBUG_PATH)/certification.o \
					certification.c  -I$(INC) -I$(MYSQL_INC) 
	gcc $(DEBUG) -c -o $(DEBUG_PATH)/location.o \
					location.c -I$(INC) -I$(MYSQL_INC)
	gcc $(DEBUG) -c -o $(DEBUG_PATH)/packer.o \
					packer.c -I$(INC) -I$(MYSQL_INC)
	gcc $(DEBUG) -c -o $(DEBUG_PATH)/network.o \
					network.c -I$(INC)
	gcc $(DEBUG) -c -o $(DEBUG_PATH)/datastruct.o \
					datastruct/datastruct.c -I$(INC) -I$(MYSQL_INC)
	gcc $(DEBUG) -c -o $(DEBUG_PATH)/processor.o \
					processor.c -I$(INC) -I$(MYSQL_INC)
	
