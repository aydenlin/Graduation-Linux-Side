#include "packer.h"
#include "certification.h"
#include "location.h"
#include <malloc.h>
#include <errno.h>
#include "types.h"
#include <string.h>

extern int errno;

void unpack(byte *packet, void *info) {
	byte type = typeof_packet(packet);
	Certification_info *cerinfo;
	Location *locinfo;
	
	char *imei;
	// Certification related variable
	char *username;
	char *password;
	// Location related variable
	char *longtitude;
	char *latitude;

	switch (type) {
	case _CERTIFICATION_PACKET_:
		cerinfo = (Certification_info *)info;
		username = (char *)malloc(_PACKET_CERTIFI_USER_LENGTH_+1);
		password = (char *)malloc(_PACKET_CERTIFI_PASS_LENGTH_+1);
		imei = (char *)malloc(_PACKET_CERTIFI_IMEI_LENGTH_+1);
		
		strncpy(username, packet+_PACKET_CERTIFI_USER_POS_, 
				_PACKET_CERTIFI_USER_LENGTH_);
		username[_PACKET_CERTIFI_USER_LENGTH_] = '\0';
		strncpy(password, packet+_PACKET_CERTIFI_PASS_POS_,
				_PACKET_CERTIFI_PASS_LENGTH_);
		password[_PACKET_CERTIFI_PASS_LENGTH_] = '\0';
		strncpy(imei, packet+_PACKET_CERTIFI_IMEI_POS_,
				_PACKET_CERTIFI_IMEI_LENGTH_);
		imei[_PACKET_CERTIFI_IMEI_LENGTH_] = '\0';
		
		cerinfo->setimei(cerinfo, imei);
		cerinfo->setuser(cerinfo, username);
		cerinfo->setpass(cerinfo, password);
		break;
	case _LOCATION_PACKET_:
		locinfo = (Location *)info;
		longtitude = (char *)malloc(_LOC_STR_MAX_);
		latitude = (char *)malloc(_LOC_STR_MAX_);

		locinfo->setloc(locinfo, *((double *)(packet+_PACKET_LOCAT_LONG_POS_)),
				*((double *)(packet+_PACKET_LOCAT_LATI_POS_)));		
		break;
	}

}

byte *packetgene(int type) {
	byte *pack = (byte *)malloc(sizeof(byte));
	switch(type) {
		case _EXISTS_:
			*pack = 3;
			break;
		case _PASS_ERROR_:
			*pack = 4;
			break;
		case _CONFIRMED_:
			*pack = 5;
			break;
		default:
			errno = 1;
	}
	return pack;
}

char typeof_packet(byte *bytes) {
	return bytes[_PACKET_TYPE_POS_];
}
