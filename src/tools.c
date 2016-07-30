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
