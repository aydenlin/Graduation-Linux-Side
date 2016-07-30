/*
 * You need to provide an action 
 * for children terminate signal.
 * Also,need daemonize function.
 * Finally, List username and password
 * here is unsafe, need an alternative
 * solution.
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
#define _PASSWORD_ ""
#define _DB_NAME_ ""
#define _PORT_NUM_  0
#define _SOCKET_NAME_  NULL
#define _FLAGS_  0

#define _SERVER_PORT_NUM_ XXXXX

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
