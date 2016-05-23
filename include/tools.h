#ifndef _TOOLS_H_
#define _TOOLS_H_

#include <stdarg.h>

#define _LOC_STR_MAX_ 100

char * strgen(int num, ...);
char * num2str(double num);
char * single_quotes(char *str);

#endif /* _TOOLS_H_ */
