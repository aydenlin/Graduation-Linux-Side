/*
 * You need to provide an action 
 * for children terminate signal.
 */


#include "processor.h"
#include "database_manager.h"
#include "location.h"
#include "certification.h"
#include "packer.h"
#include "network.h"
#include "tools.h"
#include <stdio.h>
#include <unistd.h>
#include <malloc.h>
#include <pthread.h>

#define _HOST_NAME_ "localhost"
#define _USER_NAME_ "root"
#define _PASSWORD_ "linianyi11"
#define _DB_NAME_ "graduation"
#define _PORT_NUM_  0
#define _SOCKET_NAME_  NULL
#define _FLAGS_  0

#define _SERVER_PORT_NUM_ 1555

int main(int argc, char **argv) {
	// This Network is use for 
	// listening to request.
	Network *network = (Network *)malloc(sizeof(Network));;
	Database_manager *dbm = 
		(Database_manager *)malloc(sizeof(Database_manager));	

	database_init(dbm, argv[0]);
	network_initialize(network, _SERVER_PORT_NUM_);

	dbm->connecting(dbm, _HOST_NAME_, _USER_NAME_, 
			_PASSWORD_,_DB_NAME_, _PORT_NUM_, _SOCKET_NAME_, _FLAGS_);
	network->listen(network);

	while (TRUE) {
		network->accept(network);
		request_processing(network, dbm);
	}
	
	return 0;
}

static void testing(Network *network) {
	int connfd = network->connfd;
	char *buf = (char *)malloc(30);
	while (read(connfd, buf, 30)) {
		buf[30] = '\0';
		printf("%s\n", buf);
	}
	printf("FINISHED\n");
}

static void request_processing(Network *network_, 
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
