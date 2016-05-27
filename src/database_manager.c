#include "tools.h"
#include "database_manager.h"
#include <strings.h>
#include <malloc.h>

void database_init(Database_manager *database, char *p_name) {
	database->init = MYSQL_INIT;
	database->connecting = MYSQL_CONN;
	database->disconnecting = MYSQL_DISCONNECT;
	database->database_action = database_action;

	MYSQL_INIT(p_name, &(database->connection));
}

MYSQL_RES * database_action(Database_manager *dbmanager, char *stmt) {
	return MYSQL_STMT_PROCESS(dbmanager->connection, stmt);
}
