INC=/home/ayden/project/graduation/include
LIB=/home/ayden/project/graduation/lib

SUBDIRS=$(shell ls -F | grep / | grep -v include | grep -v lib)

#define build
#@for subdir in $(SUBDIRS); do \
#	(cd $$subdir && make $1); \
#done
#endef

#all:build
#build:
#	$(call build, all)
