#ifndef _CERTIFICATION_H_
#define _CERTIFICATION_H_

#include <malloc.h>

#define _INIT_CERTIFICATION_(C, u, p, i) do { \
	C = (Certification_info *)malloc(sizeof(Certification_info); \
	C->username = u; \
	C->password = p; \
	C->imei     = i; \
} while(0)

typedef struct certification_info {
	char *username;
	char *password;
	char *imei;
} Certification_info;

void setuser(Certification_info *C, char *user);
char * getuser(Certification_info *C);
void setpass(Certification_info *C, char *pass);
char * getpass(Certification_info *C);
void setimei(Certification_info *C, char *imei);
char * getimei(Certification_info *C);

#endif /* _CERTIFICATION_H_ */
