include ~/Project/graduation/makefile

all:libdatastruct.so
libdatastruct.so:
	gcc -fPIC -c -o datastruct.o datastruct.c -I$(INC)
	gcc -shared -o $(LIB)/libdatastruct.so datastruct.o
	rm datastruct.o

