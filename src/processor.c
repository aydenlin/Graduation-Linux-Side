#include "processor.h"
#include "packer.h"
#include <malloc.h>

static void analyzer(byte *packet);
static void packet_deal(byte *packet);
static void valid_check(byte *packet, int type);
static void CONTROL_MESSAGE_SEND(Network *network, List *work,
		int flag);

byte * processor_work_obtain(Network *network) {
	return network->obtain(network);
}

void certification_info_saving(Certification_info *C, 
		Certifi_struct *cs) {
	C->setuser(C, cs->username);
	C->setpass(C, cs->password);
	C->setimei(C, cs->imei);
}

void location_info_saving(Location *L, Location_struct *ls) {
	L->setloc(L, ls->longtitude, ls->latitude);
} 

void control_message_gene(Network *network, int flag) {
	switch(flag) {
	case _EXISTS_ :
		CONTROL_MESSAGE_SEND(network, _EXISTS_);
		break;
	case _PASS_ERROR_ :
		CONTROL_MESSAGE_SEND(netowrk, _PASS_ERROR_);
		brea;
	case _CONFIRMED_ :
		CONTROL_MESSAGE_SEND(network, _CONFIRMED_);
		break;
	}
}

static void packet_deal(byte *packet) {
	int packet_type = typeof_packet(packet);
	switch(packet_type) {
	case _CERTIFICATION_PACKET_:
		break;
	case _LOCATION_PACKET_:
		break;
	}
}

static void CONTROL_MESSAGE_SEND(Network *network, int flag) {
	byte *packet = (byte
	network_send(network, packet);
}


void processing(Network *network) {
	byte *packet;

	if (network->is_work_here(network)) {
		packet = network->obtain(network);
		packet_deal(packet);
	}
}
