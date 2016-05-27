#include "processor.h"
#include "packer.h"
#include <malloc.h>

static void analyzer(byte *packet);
int packet_deal(void *info_mod,byte *packet, Network *network,
		Database_manager *dbmanager);
static void CONTROL_MESSAGE_SEND(Network *network, int flag);
static int certifi_deal(Certification_info *certifi_info, Network *network,
		Database_manager *dbmanager);
static void loc_deal(Location *loc, Database_manager *dbmanager);

byte * processor_work_obtain(Network *network) {
	return network->obtain(network);
}

int packet_deal(void *info_mod,byte *packet, Network *network,
		Database_manager *dbmanager) {
	int packet_type = typeof_packet(packet);
	Certification_info *cerinfo;
	Location *locinfo;
	int ret;
	
	switch(packet_type) {
	case _CERTIFICATION_PACKET_:
		cerinfo = (Certification_info *)info_mod;
		unpack(packet, cerinfo);
		ret = certifi_deal(cerinfo, network, dbmanager);
		break;
	case _LOCATION_PACKET_:
		locinfo = (Location *)info_mod;
		unpack(packet, locinfo);
		loc_deal(locinfo, dbmanager);
		break;
	}

	return ret;
}

static int certifi_deal(Certification_info *certifi_info, Network *network,
		Database_manager *dbmanager) {
	int ret;
	if ((ret = certifi_info->info_check(certifi_info, dbmanager)) ==  1) /* found */
		CONTROL_MESSAGE_SEND(network, _CONFIRMED_);
	 else if (ret == 0) /* username or password wrong */
		CONTROL_MESSAGE_SEND(network, _PASS_ERROR_);
	else if (ret == 2) {/* no such imei in database */
		certifi_info->saving(certifi_info, dbmanager);
		CONTROL_MESSAGE_SEND(network, _CONFIRMED_);
	}
	return ret;
}

static void loc_deal(Location *loc, Database_manager *dbmanager) {
	loc->saving(dbmanager, loc);	
}

static void CONTROL_MESSAGE_SEND(Network *network, int flag) {
	byte packet = (char)flag;
	network_send(network, &packet);
}


void processing(Network *network, Database_manager *dbmanager, 
		Certification_info *certifi, Location *loc) {
	byte *packet;
	int ret;
	while (0 < 1) {
		if (network->is_work_here(network)) {
			// network->obtain() function should 
			// block, if there is no task.
			packet = network->obtain(network);
		}
		if (typeof_packet(packet) == _CERTIFICATION_PACKET_) {
			ret = packet_deal((void *)certifi, packet, network, dbmanager);
			loc->setimei(loc, certifi->imei);
		}
		else if (typeof_packet(packet) == _LOCATION_PACKET_) 
			packet_deal((void *)loc, packet, network, dbmanager);				
	}

}

static int is_username_exists(Database_manager *d_manager, 
		Certification_info *cerinfo) {
	Stmt_info *stmt_info = (Stmt_info *)malloc(sizeof(Stmt_info));
	stmt_info->field = "name";
	stmt_info->table = "users";
	stmt_info->compare = cerinfo->username;
}
