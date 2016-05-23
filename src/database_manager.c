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

MYSQL_RES * read_from_db(Database_manager *D, Stmt_info *info) {
	char *stmt = stmt_generate(info, _READ_STMT_);
	return MYSQL_STMT_PROCESS(D->connection, stmt);
}

static char * stmt_generate(Stmt_info *info, int flag) {
	switch (flag) {
		// Read operation is temporary undefined.
		case _READ_STMT_:
			return strgen(10, space_append("SELECT"), space_append(info->field), 
					space_append("FROM"), space_append(info->table), space_append("WHERE"),
					"users.imei", "=", info->imei, ";", "\0");
			break;
		case _WRITE_STMT_:
			return strgen(5, space_append("INSERT INTO"), space_append(info->table), 
					info->values, ";", "\0");
			break;
	}
	return NULL;
}


