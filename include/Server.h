#ifndef _SERVER_H_
#define _SERVER_H_

#include "network.h"
#include "certification.h"
#include "database_manager.h"
#include "location.h"
#include "processor.h"

static void request_processing(Network *network, 
		Database_manager *dbm);
static void * waiting_for(void *arg);
static void testing(Network *network);
static void initialize(Certification_info *cerinfo, 
		Processor *processor, Location *locinfo);
#endif /* _SERVER_H_ */
