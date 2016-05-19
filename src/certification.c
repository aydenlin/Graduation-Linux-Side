#include "certification.h"
#include <malloc.h>

void init_certification_info(Certification_info *C, int userlen,
		int passlen, char *username, char *pass, char *imei) {
	C->user_len = userlen;
	C->pass_len = passlen;
	C->username = username;
	C->password = pass;
	C->imei = imei;
	C->setuser_len = setuser_len;
	C->getuser_len = getuser_len;
	C->setpass_len = setpass_len;
	C->getpass_len = getpass_len;
	C->setuser = setuser;
	C->getuser = getuser;
	C->setpass = set_userpass;
	C->getpass = get_userpass;
	C->setimei = setimei;
	C->getimei = getimei;
}

void setuser_len(Certification_info *C, int len) {
	C->user_len = len;
}

int getuser_len(Certification_info *C) {
	return C->user_len;
}

void setpass_len(Certification_info *C, int len) {
	C->pass_len = len;
}

int getpass_len(Certification_info *C) {
	return C->pass_len;
}

void setuser(Certification_info *C, char *user) {
	C->username = user;
}

char * getuser(Certification_info *C) {
	return C->username;
}

void set_userpass(Certification_info *C, char *pass) {
	C->password = pass;
}

char * get_userpass(Certification_info *C) {
	return C->password;
}

void setimei(Certification_info *C, char *imei) {
	C->imei = imei;
}

char * getimei(Certification_info *C) {
	return C->imei;
}

void  saving(Database_manager *d_manager, Certification_info *C) {
	Stmt_info *stmt_info = malloc(sizeof(Stmt_info));
	char *table = "users";
	char *values = "VALUES(";
}
