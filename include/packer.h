#ifndef _PACKER_H_
#define _PACKER_H_

#include "types.h"

/*
 * The parameter buf is a struct, i might a struct of 
 * location info or certification info, function will
 * get the real type of struct by flag.
 */
void  unpack(byte *bytes, void *info);
byte * packetgene(int type);
char typeof_packet(byte *bytes);

#endif /* _PACKER_H_ */
