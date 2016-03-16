#include "packer.h"
#include <malloc.h>
#include <errno.h>

extern int errno;

void unpack(byte *bytes, void *buf, int flag) {
	switch(flag) {
		case _CERTIFICATION_PACKET_:
			break;
		case _LOCATION_PAKET_:
			break;
		default:
		errno = 1;
	}
}

byte *packetgene(int type) {
	byte *pack = (byte *)malloc(byte);
	switch(type) {
		case _EXISTS_:
			*pack = 3;
			break;
		case _PASS_ERROR_:
			*pack = 4;
			break;
		case _CONFIRMES_:
			*pack = 5;
			break;
		default:
			errno = 1;
	}
	return pack;
}
