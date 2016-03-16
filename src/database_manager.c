#include "database_manager.h"

void database_init(Database *database, MYSQL *conn) {
	database->conn = conn;
	database->init = MYSQL_INIT;
	database->connect = MYSQL_CONN;
	database->disconnect = MYSQL_DISCONNECT;
	databse->write_to_db = write_to_db;
}

void write_to_db(Database *D, void *data, int flag) {
	
}
