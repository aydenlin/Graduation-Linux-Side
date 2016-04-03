INC=../include
TEST_UNITS=certification.o location.o packer.o
TEST_SRC=unit_test.c
TEST_TARGET=unit_test

all:$(TEST_TARGET)

$(TEST_TARGET):$(TEST_SRC) $(TEST_UNITS)
	gcc -gstabs -o unit_test unit_test.c \
		$(TEST_UNITS) -I$(INC)

clean:
	-rm $(TEST_UNITS)
