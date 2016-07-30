#ifndef _TOOLS_H_
#define _TOOLS_H_

#include <stdarg.h>
#include "packer.h"

#ifdef DEBUG
	#define message(msg) printf("In function %s at line %d\n : %s", \
			__func__, __LINE__, msg); 
#else
	#define message(msg) 
#endif

#define END "\0"
#define SP_APP(X) X, " "
#define S_QUOTES(X) "'", X, "'"

#define IS_CERTIFI_PACKET(packet) (typeof_packet(packet) == _CERTIFICATION_PACKET_)
#define IS_LOCAT_PACKET(packet) (typeof_packet(packet) == _LOCATION_PACKET_)

char * strgen(char *begin, ...);
char * num2str(double num);
void release(void **ptr);

#endif /* _TOOLS_H_ */
