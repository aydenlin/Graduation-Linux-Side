#ifndef _TYPES_H_
#define _TYPES_H_

/************
 * Boolean  *
 ************/
#define TRUE (1)
#define FALSE (0)

/******************
 * Packet defined *							
 ******************/
#define _PACKET_TYPE_POS_ 0
#define _PACKET_TYPE_LENGTH_ 1

/*****************************************************
 * Note : such #define that comment out is temporary *
 * unuse it may in use in future.					 *
 ****************************************************/
// Certification field len
//#define _PACKET_CERTIFI_USER_LEN_LENGTH_ 1
//#define _PACKET_CERTIFI_PASS_LEN_LENGTH_ 1
#define _PACKET_CERTIFI_USER_LENGTH_ 6
#define _PACKET_CERTIFI_PASS_LENGTH_ 6
#define _PACKET_CERTIFI_IMEI_LENGTH_ 15
#define _PACKET_CERTIFI_LENGTH_ (_PACKET_TYPE_LENGTH_ + _PACKET_CERTIFI_USER_LENGTH_  \
	+ _PACKET_CERTIFI_PASS_LENGTH_ +  _PACKET_CERTIFI_IMEI_LENGTH_)

// Certification packet fields 
//#define _PACKET_CERTIFI_USER_LEN_	_PACKET_TYPE_ + _PACKET_TYPE_LENGTH_
//#define _PACKET_CERTIFI_PASS_LEN_   _PACKET_CERTIFI_USER_LEN_ + _PACKET_CERTIFI_USER_LEN_LENGTH_
#define _PACKET_CERTIFI_USER_POS_ _PACKET_TYPE_LENGTH_ 
#define _PACKET_CERTIFI_PASS_POS_ (_PACKET_CERTIFI_USER_POS_ + _PACKET_CERTIFI_USER_LENGTH_)
#define _PACKET_CERTIFI_IMEI_POS_ (_PACKET_CERTIFI_PASS_POS_ + _PACKET_CERTIFI_PASS_LENGTH_)


// Location field len
#define _PACKET_LOCAT_LONG_LENGTH_ 8
#define _PACKET_LOCAT_LATI_LENGTH_ 8
#define _PACKET_LOCAT_LENGTH_ (_PACKET_TYPE_LENGTH_ + _PACKET_LOCAT_LONG_LENGTH_ \
	+ _PACKET_LOCAT_LATI_LENGTH_)
// Location packet fields
#define _PACKET_LOCAT_LONG_POS_ _PACKET_TYPE_LENGTH_
#define _PACKET_LOCAT_LATI_POS_	(_PACKET_LOCAT_LONG_POS_ + _PACKET_LOCAT_LONG_LENGTH_)
#define _PACKET_LOCAT_LENGTH_ (_PACKET_TYPE_LENGTH_ + _PACKET_LOCAT_LONG_LENGTH_ \
	+ _PACKET_LOCAT_LATI_LENGTH_)


#define _MAX_LENGTH_OF_PACKET_ 30
#define _CONTROL_MESSAGE_LEN_ 1

// Encode of packet
#define _CERTIFICATION_PACKET_ 1
#define _LOCATION_PACKET_ 2
#define _EXISTS_ 3
#define _PASS_ERROR_ 4
#define _CONFIRMED_ 5

#define _LOC_STR_MAX_ 30

typedef char byte;

#endif /* _TYPES_H_ */
