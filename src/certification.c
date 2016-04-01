#include "certification.h"

void init_certification_info(Certification_info *C, char *username,
		char *pass, char *imei) {
	C->username = username;
	C->password = pass;
	C->imei = imei;
	C->setuser = setuser;
	C->getuser = getuser;
	C->setpass = setpass;
	C->getpass = getpass;
	C->setimei = setimei;
	C->getimei = getimei;
}

void setuser(Certification_info *C, char *user) {
	C->username = user;
}

char * getuser(Certification_info *C) {
	return C->username;
}

void setpass(Certification_info *C, char *pass) {
	C->password = pass;
}

char * getpass(Certification_info *C) {
	return C->password;
}

void setimei(Certification_info *C, char *imei) {
	C->imei = imei;
}

char * getimei(Certification_info *C) {
	return C->imei;
}
