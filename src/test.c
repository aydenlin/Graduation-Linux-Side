#include <stdio.h>
#include <malloc.h>
#include <pthread.h>
#include "processor.h"
#include "certification.h"
#include "location.h"
#include "database_manager.h"
#include "types.h"
#include "network.h"
#include "tools.h"
#include "string.h"

#define _DATABASE_NAME_ "graduation"
#define _DATABASE_HOST_ "localhost"
#define _DATABASE_USER_ "root"
#define _DATABASE_PASS_ "linianyi11"
#define _DATABASE_DB_NAME_ "graduation"
#define _DATABASE_DB_PORT_NUM_ 0
#define _DATABASE_SOCKET_NUM_ NULL
#define _DATABASE_OPT_FLAG_ 0

void list_test();
void * lock_test(void *arg);

int main(int argc, char **argv) {
	byte *packet;
/*
	Network *network = (Network *)malloc(sizeof(Network));
	Database_manager *dbmanager = (Database_manager *)malloc(sizeof(Database_manager));
	Certification_info *certifi = (Certification_info *)malloc(sizeof(Certification_info));
	Location *loc = (Location *)malloc(sizeof(Location));
	
	init_certification_info(certifi, NULL, NULL, NULL);
	init_location(loc, 0.00, 0.00);
	database_init(dbmanager, argv[0]);
	dbmanager->connecting(dbmanager->connection, _DATABASE_HOST_, _DATABASE_USER_,
			_DATABASE_PASS_, _DATABASE_DB_NAME_, _DATABASE_DB_PORT_NUM_,
			_DATABASE_SOCKET_NUM_, _DATABASE_OPT_FLAG_);
*/
/*	// Location packet testing...
	packet = (byte *)malloc(_PACKET_LOCAT_LENGTH_);
	*packet = _LOCATION_PACKET_;
	*((double *)(packet+_PACKET_LOCAT_LONG_POS_)) = 1.11;
	*((double *)(packet+_PACKET_LOCAT_LATI_POS_)) = 2.22;

	printf("%d, %lf, %lf\n", *packet, *((double *)(packet+_PACKET_LOCAT_LONG_POS_)),
			*((double *)(packet+_PACKET_LOCAT_LATI_POS_)));
	
	loc->setimei(loc, "0123456789abcdef");
	packet_deal(loc, packet, network, dbmanager);
	free(packet);
	packet=NULL;

	// Certification packet testing...
	packet = (byte *) malloc(_PACKET_CERTIFI_LENGTH_);
	*packet = _CERTIFICATION_PACKET_;
	strncpy(packet+_PACKET_CERTIFI_USER_POS_, "Gogo", 6);
	strncpy(packet+_PACKET_CERTIFI_PASS_POS_, "123456", 6);
	strncpy(packet+_PACKET_CERTIFI_IMEI_POS_, "0123456789qwert", 15);
	
//	unpack(packet, certifi);
//	printf("%s,%s,%s\n", certifi->username, certifi->password, certifi->imei);
//	certifi->saving(certifi, dbmanager);
	
	packet_deal(certifi, packet, network, dbmanager);
*/
	list_test();
	return 0;
}

void * lock_test(void *arg) {
	List_head *lh = arg;
	List *ele;
	int i = 0;
	while (0<1) {
		printf("<=========INSERT=========>\n");
		list_insert(lh, INIT_LIST_ELEMENT(ele, "Hello"));
		i++;
	}
}

void list_test() {
	List_head *lh;
	lh_init(&lh);
	byte *ret;
	pthread_t tidp;
	int i = 0;
	pthread_create(&tidp, NULL, lock_test, lh);
	

	while (0<1) {
		printf("<=========OBTAIN=========>\n");
		if ((ret = list_get_obj(list_obtain(lh))) != NULL) {
			printf("%s\n", ret);
			i++;
		}
	}

}

