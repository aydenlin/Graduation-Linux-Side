#ifndef _DATABASE_MANAGER_H_
#define _DATABASE_MANAGER_H_

#include "my_mysql.h"

typedef int Init(char *name, MYSQL **conn);
typedef int Conn(MYSQL *conn, char *opt_host_name,
			char *opt_user_name, char *opt_password,
			char *opt_db_name, int opt_port_num, 
			char *opt_socket_name, unsigned int opt_flags);
typedef void Disconn(MYSQL *conn);
typedef void Write_to_db(Database *D, void *data, int flag);
typedef struct database {
	MYSQL *conn;
	Init *init;
	Conn *connect;
	Disconn *disconnect;
	Write_to_db *write_to_db;
} Database;


void database_init(Database *database, MYSQL *conn_,
		Init init_, Conn conn_, Disconn disconn, 
		Process process_);
void write_to_db(Database *D, void *data, int flag);

#endif /* _DATABASE_MANAGER_H_ */
