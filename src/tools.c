#include "tools.h"
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <string.h>

char * num2char(double num);

char * strgen(int num, ...) {
	int count = num;
	int len;
	int offset = 0;
	char *item;
	int item_len = 0;
	char *result;
	va_list parg;
	
	va_start(parg, num);
	
	while (count--) {
		len += strlen(va_arg(parg, char *));
	}
	len += num+2;

	va_start(parg, num);
	result = malloc(len);
	count = num;
	
	while (count--) {
		item = (char *)va_arg(parg, char *);	
		item_len = strlen(item);

		strcpy(result, item, item_len);
		offset += item_len;
		strncpy(result+offset, " ", 1);
		offset += 1;
	}	
	strncpy(result+offset, ";\0", 2);
	return result;
}

char *num2str(double num) {
	char *ret = (char *)malloc(_LOC_STR_MAX_);
	sprintf(ret, "%f", num);
	return ret;
}

char * num_to_string(int num) {
	int index = 1;
	int tail;
	int char_len = log10(num) + 1 + 1;
	int num_process = num;
	char *result = (char *)malloc(char_len);
	
	*(result + char_len - 1) = '\0';
	
	while (num_process != 0) {
		tail = num_process%10;
		num_process /= 10;
		strncpy(result+char_len-index, num2char(tail), 1);
		index++;
	}
	return result;
}

static char * num2char(int num) {
	char *result = (char *)malloc(2);
	*result = num + 48;
	*(result+1) '\0';
	
	return result;
}
