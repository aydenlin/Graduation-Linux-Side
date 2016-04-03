#ifndef _TYPES_H_
#define _TYPES_H_

/******************
 * Packet defined *							
 ******************/
#define _PACKET_TYPE_POS_ 0
// Certification packet fields 
#define _PACKET_CERTIFI_USER_POS_ 1
#define _PACKET_CERTIFI_PASS_POS_ 7
#define _PACKET_CERTIFI_IMEI_POS_ 13
#define _PACKET_CERTIFI_USER_LENGTH_ 6
#define _PACKET_CERTIFI_PASS_LENGTH_ 6
#define _PACKET_CERTIFI_IMEI_LENGTH_ 16
#define _PACKET_CERTIFI_LENGTH_   29

// Location packet fields
#define _PACKET_LOCATE_LONG_POS_ 1
#define _PACKET_LOCATE_LATI_POS_ 9
#define _PACKET_LOCATE_LONG_LENGTH_ 8
#define _PACKET_LOCATE_LONG_LENGTH_ 8
#define _PACKET_LOCATE_LENGTH_   17

#define _MAX_LENGTH_OF_PACKET_ 17

typedef char byte;

typedef struct certifi_struct {
	int type;
	char *username;
	char *password;
	char *imei;
} Certifi_struct;

typedef struct location_struct {
	int type;
	double longtitude;
	double latitude;
} Location_struct;

#endif /* _TYPES_H_ */
