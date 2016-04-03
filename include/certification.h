#ifndef _CERTIFICATION_H_
#define _CERTIFICATION_H_

#include <malloc.h>

#define _INIT_CERTIFICATION_(C, u, p, i) do { \
	init_certification_info(&C, u, p, i); \
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


void init_certification_info(Certification_info *C, 
	char *username, char *pass, char *imei);
void setuser(Certification_info *C, char *user);
char * getuser(Certification_info *C);
void setpass(Certification_info *C, char *pass);
char * getpass(Certification_info *C);
void setimei(Certification_info *C, char *imei);
char * getimei(Certification_info *C);

typedef struct certification_info {
	char *username;
	char *password;
	char *imei;
	Setuser *setuser;
	Getuser *getuser;
	Setpass *setpass;
	Getpass *getpass;
	Setimei *setimei;
	Getimei *getimei;
} Certification_info;



#endif /* _CERTIFICATION_H_ */
