include ~/project/graduation/makefile
MODULES=libdatastruct.so libqueue.so
SRC=datastruct.c queue.c
all:MODULES

MODULES:$(SRC)
	gcc -fPIC -c -o datastruct.o datastruct.c -I$(INC)
	gcc -shared -o $(LIB)/libdatastruct.so datastruct.o
	rm datastruct.o

	gcc -fPIC -c -o queue.o queue.c -I$(INC)
	gcc -shared -o $(LIB)/libqueue.so queue.o
	rm queue.o
	


