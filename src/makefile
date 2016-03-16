include ../makefile
PROCESSOR=processor
MAIN=footprint
MODULES=certification.o network.o database_manager.o location.o	\		$(PROCESSOR)/executor.o $(PROCESSOR)/packer.o \
		$(PROCESSOR)/processor.o
SRCS=certification.c network.c database_manager.c location.c \
	 $(PROCESSOR)/executor.c $(PROCESSOR)/packer.c \
	 $(PROCESSOR)/processor.c footprint.c
		
all:$(MODULES) $(MAIN)

$(MAIN) $(MODULES):$(SRCS)
	
