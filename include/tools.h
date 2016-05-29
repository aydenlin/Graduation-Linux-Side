#ifndef _TOOLS_H_
#define _TOOLS_H_

#include <stdarg.h>

#define message(x) printf("Message : %s\n", x)
#define SP_APP(X) X, " "
#define S_QUOTES(X) "'", X, "'"

char * strgen(char *begin, ...);
char * num2str(double num);

#endif /* _TOOLS_H_ */
