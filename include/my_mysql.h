#ifndef _MY_MYSQL_H_
#define _MY_MYSQL_H_

#include <my_global.h>	
#include <my_sys.h>
#include <mysql.h>

int MYSQL_INIT(char *name, MYSQL **conn);
int MYSQL_CONN(MYSQL *conn, char *opt_host_name,
		char *opt_user_name, char *opt_password, char* opt_db_name,
		int opt_port_num, char *opt_socket_name, unsigned int opt_flags);
void MYSQL_DISCONNECT(MYSQL *conn);
MYSQL_RES * MYSQL_STMT_PROCESS(MYSQL *conn, char *stmt);

#endif /* MY_MYSQL_H_ */
