#ifndef _DATABASE_MANAGER_H_
#define _DATABASE_MANAGER_H_

#include "my_mysql.h"

typedef struct stmt_info {
	char *table;
	char *values;
	char *field;
	char *field2;
	char *compare;
} Stmt_info;

typedef struct database_manager {
	MYSQL *connection;
	int (*init)(char *name, MYSQL **conn);
	void (*connecting)(struct database_manager* dbm, char *opt_host_name,
			char *opt_user_name, char *opt_password,
			char *opt_db_name, unsigned int opt_port_num,
			char *opt_socket_name, unsigned int opt_flags);
	void (*disconnecting)(MYSQL *conn);
	MYSQL_RES * (*database_action)(struct database_manager *dbmanager, char *stmt);
} Database_manager;

void database_init(Database_manager *database, char *p_name);
MYSQL_RES * database_action(Database_manager *dbmanager, char *stmt);
void database_connecting(Database_manager *database, char *host, char *user,
		char *pass, char *db, unsigned int port, char *socket, unsigned int flag);

#endif /* _DATABASE_MANAGER_H_ */

