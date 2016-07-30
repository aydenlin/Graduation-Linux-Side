#include "certification.h"
#include "tools.h"
#include <malloc.h>

static int info_check(Certification_info *C, Database_manager *D);

void init_certification_info(Certification_info *C) {
	C->username = NULL;
	C->password = NULL;
	C->imei = NULL;
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
	char *stmt;
	char *values;
	MYSQL_ROW row;	
	// Is username already exists ?
	stmt = strgen("SELECT count(", C->username, ") FROM users;", END);	
	if ((row = mysql_fetch_row(d_manager->database_action(d_manager, stmt))) == NULL) {
		release((void **)&stmt);
		printf("mysql error in certifi_saving()\n");
		exit;
	}	
	release((void **)&stmt);
	if (strcmp(row[0], "0"))
		exit(0);
	// Account Register
	values = strgen("VALUES(", S_QUOTES(C->imei),",", S_QUOTES(C->username), 
			",", S_QUOTES(C->password), ")", "\0");
	stmt = strgen(SP_APP("INSERT INTO"), SP_APP("users"), values, ";", END);
	d_manager->database_action(d_manager, stmt);
	
	release((void **)&values);
	release((void **)&stmt);
}

static int info_check(Certification_info *C, Database_manager *d_manager) {
	MYSQL_RES *res;
	MYSQL_ROW row;
	MYSQL *conn;
	char *stmt = strgen(SP_APP("SELECT"), SP_APP("name,pass"),
			SP_APP("FROM"), SP_APP("users"), SP_APP("WHERE"),
			"users.imei", "=", S_QUOTES(C->imei), ";", "\0");
	res = d_manager->database_action(d_manager, stmt);	
	release((void **)&stmt);

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

