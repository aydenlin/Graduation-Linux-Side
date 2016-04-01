INC=../include
TEST_UNITS=
all:unit_test
unit_test:unit_test.c
	gcc -gstabs -o unit_test unit_test.c \
		$(TEST_UNITS) -I$(INC)
