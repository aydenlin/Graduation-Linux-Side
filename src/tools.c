#include "tools.h"
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <string.h>

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
	len += num;

	va_start(parg, num);
	result = malloc(len);
	count = num;
	
	while (count--) {
		item = (char *)va_arg(parg, char *);	
		item_len = strlen(item);

		strncpy(result, item, item_len);
		offset += item_len;
	}	
	return result;
}

char * single_quotes(char *str) {
	return strgen(3, "'", str, "'");
}

char * space_append(char *str) {
	return strgen(2, str, " ");
}

char *num2str(double num) {
	char *ret = (char *)malloc(_LOC_STR_MAX_);
	sprintf(ret, "%f", num);
	return ret;
}
