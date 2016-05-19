#ifndef _TYPES_H_
#define _TYPES_H_

/******************
 * Packet defined *							
 ******************/
#define _PACKET_TYPE_ 0
#define _PACKET_TYPE_LENGTH_ 1

// Certification field len
#define _PACKET_CERTIFI_USER_LEN_LENGTH_ 1
#define _PACKET_CERTIFI_PASS_LEN_LENGTH_ 1
#define _PACKET_CERTIFI_USER_LENGTH_ 6
#define _PACKET_CERTIFI_PASS_LENGTH_ 6
#define _PACKET_CERTIFI_IMEI_LENGTH_ 15
#define _PACKET_CERTIFI_LENGTH_   \
	_PACKET_TYPE_LENGTH_ + _PACKET_CERTIFI_USER_LEN_LENGTH_ \
	+ _PACKET_CERTIFI_PASS_LEN_LENGTH + _PACKET_CERTIFI_USER_LENGTH_  \
	+ _PACKET_CERTIFI_PASS_LENGTH_ +  _PACKET_CERTIFI_IMEI_LENGTH_

// Certification packet fields 
#define _PACKET_CERTIFI_USER_LEN_	_PACKET_TYPE_ + _PACKET_TYPE_LENGTH_
#define _PACKET_CERTIFI_PASS_LEN_   _PACKET_CERTIFI_USER_LEN_ + _PACKET_CERTIFI_USER_LEN_LENGTH_
#define _PACKET_CERTIFI_USER_		_PACKET_CERTIFI_PASS_LEN_ + _PACKET_CERTIFI_PASS_LEN_LENGTH_      
#define _PACKET_CERTIFI_PASS_		_PACKET_CERTIFI_USER_ + _PACKET_CERTIFI_USER_LENGTH_
#define _PACKET_CERTIFI_IMEI_		_PACKET_CERTIFI_PASS_ + _PACKET_CERTIFI_PASS_LENGTH_


// Location field len
#define _PACKET_LOCAT_LONG_LENGTH_ 8
#define _PACKET_LOCAT_LATI_LENGTH_ 8
// Location packet fields
#define _PACKET_LOCAT_LONG_ 	_PACKET_TYPE_ + _PACKET_TYPE_LENGTH_
#define _PACKET_LOCAT_LATI_	_PACKET_LOCAT_LONG_ + _PACKET_LOCAT_LONG_LENGTH_	
#define _PACKET_LOCAT_LENGTH_ _PACKET_TYPE_LENGTH_ + _PACKET_LOCAT_LONG_LENGTH_ \
	+ _PACKET_LOCAT_LATI_LENGTH_

#define _MAX_LENGTH_OF_PACKET_ 50

// Encode of packet
#define _CERTIFICATION_PACKET_ 1
#define _LOCATION_PACKET_ 2
#define _EXISTS_ 3
#define _PASS_ERROR_ 4
#define _CONFIRMED_ 5

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
