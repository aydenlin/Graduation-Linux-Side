#ifndef _TOOLS_H_
#define _TOOLS_H_

#include <stdarg.h>


#define message(x) printf("Message : %s\n", x); 

#define END "\0"
#define SP_APP(X) X, " "
#define S_QUOTES(X) "'", X, "'"

char * strgen(char *begin, ...);
char * num2str(double num);
void release(void **ptr);

#endif /* _TOOLS_H_ */
