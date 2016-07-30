#include "tools.h"
#include "types.h"
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>

char * strgen(char *begin, ...) {
	int len = 0;
	int offset = 0;
	char *item;
	int item_len = 0;
	char *result;
	va_list parg;
	char *holder = begin;

	va_start(parg, begin);
	
	while (1) {
		if (strcmp(holder, "\0")==0) {
			len += 1;
			break;
		} else 
			len += strlen(holder);
		holder = va_arg(parg, char *);
	}
	
	va_start(parg, begin);
	result = (char *)malloc(len);
	item = begin;

	while (1) {
		if (strcmp(item, "\0") == 0) 
			item_len =1;
		else
			item_len = strlen(item);

		strncpy(result+offset, item, item_len);
		offset += item_len;
		if (!strcmp(item, "\0"))
			break;
		item = (char *)va_arg(parg, char *);	
	}
	va_end(parg);
	return result;
}

char *num2str(double num) {
	char *ret = (char *)malloc(_LOC_STR_MAX_);
	sprintf(ret, "%f", num);
	return ret;
}

char * spRem(char *str) {
	char *begin = str;
	while (*str != ' ') str++;
	*str = '\0';
	return begin;
}

void request_processing(Network *network_, 
		Database_manager *dbm_) {
	
	if (fork() == 0) {
		message("request_processing");
		pthread_t tid;
		Network *network = network_;
		Processor *processor = (Processor *)malloc(sizeof(Processor));
		Database_manager *dbm = dbm_;
		Certification_info *cerinfo = 
			(Certification_info *)malloc(sizeof(Certification_info));
		Location *locinfo = 
			(Location *)malloc(sizeof(Location));
		
		initialize(cerinfo, processor, locinfo);
		pthread_create(&tid, NULL, waiting_for, (void *)network);
		processor->processing(network, dbm, cerinfo, locinfo);
	} else {
		printf("fork() error in MAIN->request_processing");
		return;
	}
}

static void initialize(Certification_info *cerinfo, 
		Processor *processor, Location *locinfo)  {
	init_certification_info(cerinfo);
	init_location(locinfo);	
	processor_init(processor);
}

static void * waiting_for(void *arg) {
	Network *network = (Network *)arg;
	network->read_from(network);
}
