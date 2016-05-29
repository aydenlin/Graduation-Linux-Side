#ifndef _MY_CERTIFICATION_H_
#define _MY_CERTIFICATION_H_

#include <malloc.h>
#include "database_manager.h"

#define _INIT_CERTIFICATION_(C, u, p, i) do { \
	init_certification_info(&C,u, p, i); \
} while(0)

#define _INIT_CERTIFICATION_MALLOC_(C, u, p, i) do { \
	C = (Certification_info *)malloc(sizeof(Certification_info)); \
	init_certification_info(C, u, p, i); \
} while(0)

typedef struct certification_info Certification_info;
typedef void   Setuser(Certification_info *C, char *user);
typedef char * Getuser(Certification_info *C);
typedef void   Setpass(Certification_info *C, char *pass);
typedef char * Getpass(Certification_info *C);
typedef void   Setimei(Certification_info *C, char *imei);
typedef char * Getimei(Certification_info *C);
typedef void   Saving(Certification_info *C, Database_manager *d_manager);
typedef int	   Info_check(Certification_info *C, Database_manager *d_manager);

void init_certification_info(Certification_info *C);
void setuser(Certification_info *C, char *user);
char * getuser(Certification_info *C);
void set_userpass(Certification_info *C, char *pass);
char * get_userpass(Certification_info *C);
void setimei(Certification_info *C, char *imei);
char * getimei(Certification_info *C);
static void certifi_saving(Certification_info *C, Database_manager *d_manager);
static MYSQL_RES * certifi_loading(Database_manager *d_manager, Certification_info *C, int flag);
static int info_check(Certification_info *C, Database_manager *d_manager);

typedef struct certification_info {
//	int user_len:8;
//	int pass_len:8;
	char *username;
	char *password;
	char *imei;
//	Setuser_len *setuser_len;
//	Getuser_len *getuser_len;
//	Setpass_len *setpass_len;
//	Getpass_len *getpass_len;
	Setuser *setuser;
	Getuser *getuser;
	Setpass *setpass;
	Getpass *getpass;
	Setimei *setimei;
	Getimei *getimei;
	Saving  *saving;
	Info_check *info_check;
} Certification_info;


#endif /* _MY_CERTIFICATION_H_ */
