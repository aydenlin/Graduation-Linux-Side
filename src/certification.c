#include "certification.h"

void setuser(Certification_info *C, char *user) {
	C->username = user;
}

void getuser(Certification_info *C) {
	return C->username;
}

void setpass(Certification_info *C, char *pass) {
	C->password = pass;
}

char * getpass(Certification_info) {
	return C->password;
}

void setimei(Certification_info *C, char *imei) {
	C->imei = imei;
}

char * getimei(Certification_info *C) {
	return C->imei;
}
