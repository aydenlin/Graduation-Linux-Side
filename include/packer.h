#ifndef _PACKER_H_
#define _PACKER_H_

#include "types.h"

// Type number of packet
#define _CERTIFICATION_PACKET_ 1
#define _LOCATION_PACKET_ 2
#define _EXISTS_ 3
#define _PASS_ERROR_ 4
#define _CONFIRMED_ 5

/*
 * The parameter buf is a struct, i might a struct of 
 * location info or certification info, function will
 * get the real type of struct by flag.
 */
void unpack(byte *bytes, void *buf, int flag);
byte *packetgene(int type);
int typeof_packet(byte *bytes);

#endif /* _PACKER_H_ */
