#include "tools.h"
#include "database_manager.h"
#include <strings.h>
#include <malloc.h>

#define _READ_STMT_ 0
#define _WRITE_STMT_ 1

static char * stmt_generate(Stmt_info *info, int flag);

void database_init(Database_manager *database, MYSQL *conn) {
	database->connection = conn;
	database->init = MYSQL_INIT;
	database->connecting = MYSQL_CONN;
	database->disconnecting = MYSQL_DISCONNECT;
	database->write_to_db = write_to_db;
	database->read_from_db = read_from_db;
}

void write_to_db(Database_manager *D, Stmt_info *info) {
	char *stmt = stmt_generate(info, _WRITE_STMT_);
	MYSQL_STMT_PROCESS(D->connection, stmt);
}


static char * stmt_generate(Stmt_info *info, int flag) {
	char *opt;

	switch (flag) {
		// Read operation is temporary undefined.
		case _READ_STMT_:
			break;
		case _WRITE_STMT_:
			opt = "INSERT INTO";
			break;
	}
	return strgen(3, opt, info->table, info->values);
}


