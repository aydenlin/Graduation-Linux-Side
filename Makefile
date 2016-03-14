SRC=./src
INC=./include
VPATH=$(SRC):$(SRC)/processor:test
MODULES=certification.o network.o packer.o database_manager.o \
		executor.o processor.o
MODULES_SRC=certification.c network.c packer.c database_manager.c \
			executor.c processor.c
MAIN=footprint
MAIN_SRC=$(SRC)/$(MAIN).c
UNIT_TEST=unit_test
UNIT_TEST_SRC=$(UNIT_TEST).c	
CLEANER=clean

all:$(MODULES) $(MAIN)

$(MODULES) $(MAIN):$(MODULES_SRC) $(MAIN_SRC) 
	@echo "Compiling..."
	gcc -o $(MAIN) $(MAIN_SRC) -I$(INC)
	gcc -c -o network.o $(SRC)/network.c -I$(INC)
	gcc -c -o certification.o $(SRC)/certification.c -I$(INC)
	gcc -c -o packer.o $(SRC)/processor/packer.c -I$(INC)
	gcc -c -o database_manager.o $(SRC)/database_manager.c -I$(INC)
	gcc -c -o executor.o $(SRC)/processor/executor.c -I$(INC)
	gcc -c -o processor.o $(SRC)/processor/processor.c -I$(INC)
	@echo "Compile finish"
$(UNIT_TEST):$(UNIT_TEST_SRC)
	gcc -o test/$(UNIT_TEST) test/$(UNIT_TEST_SRC) -I$(INC)	

.PHONY:
$(CLEANER):
	rm $(MODULES)
