#ifndef _DATABASE_MANAGER_H_
#define _DATABASE_MANAGER_H_

#include "my_mysql.h"

typedef struct stmt_info {
	char *table;
	char *values;
	char *field;
	char *field2;
	char *imei;
} Stmt_info;

typedef struct database_manager {
	MYSQL *connection;
	int (*init)(char *name, MYSQL **conn);
	int (*connecting)(MYSQL *conn, char *opt_host_name,
			char *opt_user_name, char *opt_password,
			char *opt_db_name, int opt_port_num,
			char *opt_socket_name, unsigned int opt_flags);
	void (*disconnecting)(MYSQL *conn);
	void (*write_to_db)(struct database_manager *D, 
			Stmt_info *info);
	MYSQL_RES * (*read_from_db)(struct database_manager *D, 
			Stmt_info *info);
} Database_manager;

void database_init(Database_manager *database, MYSQL *conn_);
void write_to_db(Database_manager *D, Stmt_info *info);
MYSQL_RES * read_from_db(Database_manager *D, Stmt_info *info);

#endif /* _DATABASE_MANAGER_H_ */

