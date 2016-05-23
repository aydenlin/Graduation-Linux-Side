#include "certification.h"
#include "tools.h"
#include <malloc.h>

void init_certification_info(Certification_info *C, char *username, 
		char *pass, char *imei) {
//	C->user_len = userlen;
//	C->pass_len = passlen;
	C->username = username;
	C->password = pass;
	C->imei = imei;
//	C->setuser_len = setuser_len;
//	C->getuser_len = getuser_len;
//	C->setpass_len = setpass_len;
//	C->getpass_len = getpass_len;
	C->setuser = setuser;
	C->getuser = getuser;
	C->setpass = set_userpass;
	C->getpass = get_userpass;
	C->setimei = setimei;
	C->getimei = getimei;
}

/* Temporary no need to use.
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
*/

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
  
char * getimei(Certification_info *C) {
	return C->imei;
}

void  saving(Certification_info *C, Database_manager *d_manager) {
	Stmt_info *info;
	info->table = "\'users\'";
	info->values = strgen(4, "VALUES(", single_quotes(C->imei), 
			single_quotes(C->username), single_quotes(C->password));
	d_manager->write_to_db(d_manager, info);
}

int info_check(Certification_info *C, Database_manager *d_manager, int flag) {
	MYSQL_RES *res = loading(d_manager, C, flag);
	MYSQL_ROW row;

	if ((row = mysql_fetch_row(res)) != NULL) {
		switch (flag) {
			case _USERS_CHECK_:
				return !strcmp(row[0], C->username);
				break;
			case _PASS_CHECK_:
				return !strcmp(row[0], C->password);
				break;
		}
	} else {
		/* error */
	}
	
}

static MYSQL_RES * loading(Database_manager *d_manager, Certification_info *C, int flag) {
	Stmt_info *info;

	switch (flag) {
	case _USERS_CHECK_:
		info->field = "name";
		break;
	case _PASS_CHECK_:
		info->field = "pass";
		break;
	}

	info->table = "users";
	info->imei = C->imei;

	return d_manager->read_from_db(d_manager, info);
}

