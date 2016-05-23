#include <stdio.h>
#include <strings.h>
#include <malloc.h>
#include <string.h>
#include "certification.h"
#include "location.h"
#include "packer.h"

#define MAX_TESTING 10
#define MAX_RESULT  10 * sizeof(int)

#define TITLE() do { \
	printf("Module %s is under testing...\n", __func__); \
} while(0)

#define IS_SUCCESS(X) do { \
	if (X == 1) \
		printf("\tStatus:success\n"); \
	else if (X == 0) \
		break; \
	else \
		printf("\tStatus:failed on line %d of test file\n", X); \
} while(0)

static int terminated;
#define TERMINATED_INIT() (terminated = 0)
#define SUCCESS_RESULT_APPEND(RESULT_BOX) do { \
	RESULT_BOX[terminated] = 1; \
	++terminated; \
} while(0)
#define FAILED_RESULT_APPEND(RESULT_BOX) do { \
	RESULT_BOX[terminated] = __LINE__; \
	++terminated; \
} while(0)

typedef int *UNIT_TEST_MODULE();

// testing function
int * certification_test();
int * location_test();
int * packer_test();

void testing(UNIT_TEST_MODULE **array_func, int size);

UNIT_TEST_MODULE *array_test_func[MAX_TESTING];

int main() {
	array_test_func[0] = certification_test;
	array_test_func[1] = location_test;
	array_test_func[2] = packer_test;
 	testing(array_test_func, 3);
}

void testing(UNIT_TEST_MODULE **array_func, int size) {
 	int i, j, result_holder;;
	int *result;
	for (i=0; i<size; i++) {
 		result = array_func[i]();
	for (j=0; j<MAX_RESULT && j<terminated; j++) {
 			result_holder = result[j];
 			IS_SUCCESS(result_holder);
		}
 		free(result);
 	}
}

int * packer_test() {
	int *result = (int *)malloc(MAX_RESULT);
	Certifi_struct *pcertifi_struct;
	Location_struct *plocation_struct;
	char *certifi_packet =
		(char *)malloc(_PACKET_CERTIFI_LENGTH_);
	char *location_packet =
		(char *)malloc(_PACKET_LOCATE_LENGTH_);

	TITLE();	
	TERMINATED_INIT();
	certifi_packet[_PACKET_TYPE_POS_] = _CERTIFICATION_PACKET_;
	strncpy(certifi_packet+_PACKET_CERTIFI_USER_POS_, "ayden", 
			_PACKET_CERTIFI_USER_LENGTH_);	
	strncpy(certifi_packet+_PACKET_CERTIFI_PASS_POS_, "passo", 
			_PACKET_CERTIFI_PASS_LENGTH_);
	strncpy(certifi_packet+_PACKET_CERTIFI_IMEI_POS_, 
			"123456789012345", _PACKET_CERTIFI_IMEI_LENGTH_);
	pcertifi_struct = unpack(certifi_packet);

	location_packet[_PACKET_TYPE_POS_] = _LOCATION_PACKET_;
	*(double *)(location_packet+_PACKET_LOCATE_LONG_POS_) = 0.001;
	*(double *)(location_packet+_PACKET_LOCATE_LATI_POS_) = 0.002;
	plocation_struct = unpack(location_packet);

	if (pcertifi_struct->type == _CERTIFICATION_PACKET_ &&
			strcmp(pcertifi_struct->username, "ayden") == 0 &&
			strcmp(pcertifi_struct->password, "passo") == 0 &&
			strcmp(pcertifi_struct->imei, "123456789012345") == 0)
		SUCCESS_RESULT_APPEND(result);
	else 
		FAILED_RESULT_APPEND(result);

	if (plocation_struct->type == _LOCATION_PACKET_ &&
			plocation_struct->longtitude == 0.001 &&
			plocation_struct->latitude == 0.002)
		SUCCESS_RESULT_APPEND(result);
	else 
		FAILED_RESULT_APPEND(result);

	return result;
}

int * certification_test() {
 	int *result = (int *)malloc(MAX_RESULT);
	Certification_info certifi_info;
	Certification_info *pcertifi_info;
	
	TITLE();
	bzero(result, MAX_RESULT);
	TERMINATED_INIT();
	_INIT_CERTIFICATION_(certifi_info, "ayden", "gogo", "imei");
	_INIT_CERTIFICATION_MALLOC_(pcertifi_info, "ayden", "gogo", \
			"imei");

	if (certifi_info.username == "ayden" &&
			certifi_info.password == "gogo" &&
			certifi_info.imei == "imei")
		SUCCESS_RESULT_APPEND(result);
	else 
		FAILED_RESULT_APPEND(result);

	if (pcertifi_info->username =="ayden" &&
			pcertifi_info->password == "gogo" &&
			pcertifi_info->imei == "imei")
		SUCCESS_RESULT_APPEND(result);
	else 
		FAILED_RESULT_APPEND(result);
	
	certifi_info.setuser(&certifi_info, "gogo");
	certifi_info.setpass(&certifi_info, "gogo's pass");
	certifi_info.setimei(&certifi_info, "gogo's imei");
	if (certifi_info.getuser(&certifi_info) == "gogo" &&
			certifi_info.getpass(&certifi_info) == "gogo's pass" &&
			certifi_info.getimei(&certifi_info) == "gogo's imei")
		SUCCESS_RESULT_APPEND(result);
	else 
		FAILED_RESULT_APPEND(result);

	return result;
}

int * location_test() {
	Location location;
	int *result = (int *)malloc(MAX_RESULT);
	
	TITLE();
	TERMINATED_INIT();
	_INIT_LOCATION_(&location, 0.001, 0.002);

	if (location.getlong(&location) == 0.001 &&
			location.getlat(&location) == 0.002)
		SUCCESS_RESULT_APPEND(result);
	else 
		FAILED_RESULT_APPEND(result);

	location.setloc(&location, 0.002, 0.001);
	if (location.getlong(&location) == 0.002 &&
			location.getlat(&location) == 0.001) 
		SUCCESS_RESULT_APPEND(result);
	else 
		FAILED_RESULT_APPEND(result);
	return result;
}


