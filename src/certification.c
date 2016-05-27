#include "certification.h"
#include "tools.h"
#include <malloc.h>

static int info_check(Certification_info *C, Database_manager *D);

void init_certification_info(Certification_info *C, char *username, 
		char *pass, char *imei) {
	C->username = username;
	C->password = pass;
	C->imei = imei;
	C->setuser = setuser;
	C->getuser = getuser;
	C->setpass = set_userpass;
	C->getpass = get_userpass;
	C->setimei = setimei;
	C->getimei = getimei;
	C->saving = certifi_saving;
	C->info_check = info_check;
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

static void  certifi_saving(Certification_info *C, Database_manager *d_manager) {
	char *values = strgen("VALUES(", S_QUOTES(C->imei),",", S_QUOTES(C->username), 
			",", S_QUOTES(C->password), ")", "\0");
	
	char *stmt = strgen(SP_APP("INSERT INTO"), SP_APP("users"), values, ";", "\0");
	d_manager->database_action(d_manager, stmt);
}

static int info_check(Certification_info *C, Database_manager *d_manager) {
	MYSQL_RES *res;
	MYSQL_ROW row;
	MYSQL *conn;
	char *stmt = strgen(SP_APP("SELECT"), SP_APP("name,pass"),
			SP_APP("FROM"), SP_APP("users"), SP_APP("WHERE"),
			"users.imei", "=", S_QUOTES(C->imei), ";", "\0");
	res = d_manager->database_action(d_manager, stmt);	
	
	if ((row = mysql_fetch_row(res)) != NULL) {
		if (strcmp(row[0], C->username) == 0 &&
				strcmp(row[1], C->password) == 0)
			return 1;
		else 
			return 0;
	} else {
		return 2;
	}
}

