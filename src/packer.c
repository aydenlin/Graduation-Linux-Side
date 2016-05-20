#include "packer.h"
#include <malloc.h>
#include <errno.h>
#include "types.h"
extern int errno;

void * unpack(byte *bytes) {
	int flag = bytes[0];
	Certifi_struct *certifi_info_ret;
	Location_struct *location_info_ret;
	switch(flag) {
		case _CERTIFICATION_PACKET_:
			certifi_info_ret =
				(Certifi_struct *)malloc(sizeof(Certifi_struct));
			certifi_info_ret->type = bytes[_PACKET_TYPE_POS_];;
			certifi_info_ret->username = &bytes[_PACKET_CERTIFI_USER_POS_];
			certifi_info_ret->password = &bytes[_PACKET_CERTIFI_PASS_POS_];
			certifi_info_ret->imei = &bytes[_PACKET_CERTIFI_IMEI_POS_];
			return (void *)certifi_info_ret;
			break;
		case _LOCATION_PACKET_:
			location_info_ret = 
				(Location_struct *)malloc(sizeof(Location_struct));
			location_info_ret->type = bytes[_PACKET_TYPE_POS_];
			location_info_ret->longtitude = 
				*(double *)(bytes + _PACKET_LOCAT_LONG_POS_);
			location_info_ret->latitude = 
				*(double *)(bytes + _PACKET_LOCAT_LATI_POS_);
			return (void *)location_info_ret;
			break;
		default:
		errno = 1;
	}
	return NULL;
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

int typeof_packet(byte *bytes) {
	return bytes[_PACKET_TYPE_POS_];
}
