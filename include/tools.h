#ifndef _TOOLS_H_
#define _TOOLS_H_

#include <stdarg.h>
#include "packer.h"
#include "network.h"
#include "certification.h"
#include "database_manager.h"
#include "location.h"
#include "processor.h"

#ifdef DEBUG
	#define message(msg) printf("In function %s at line %d\n : %s", \
			__func__, __LINE__, msg); 
#else
	#define message(msg) 
#endif

#define release(ptr) ({ \
	free(ptr); \
	ptr = NULL; \
})

#define END "\0"
#define SP_APP(X) X, " "
#define S_QUOTES(X) "'", X, "'"

#define IS_CERTIFI_PACKET(packet) (typeof_packet(packet) == _CERTIFICATION_PACKET_)
#define IS_LOCAT_PACKET(packet) (typeof_packet(packet) == _LOCATION_PACKET_)

char * strgen(char *begin, ...);
char * num2str(double num);

// Tools for Top level of Server
void request_processing(Network *network, Database_manager *dbm);
static void * waiting_for(void *arg);
static void initialize(Certification_info *cerinfo, Processor *processor,
		Location *locinfo);

#endif /* _TOOLS_H_ */
