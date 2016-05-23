#include "location.h"
#include "tools.h"

void init_location(Location *L, double lon, double lat) {
	L->longtitude = lon;
	L->latitude   = lat;
	L->setloc     = setloc;
	L->getlong    = getlong;
	L->getlat     = getlat;
	L->saving	  = saving;
	L->loading	  = NULL;
}

void setloc(Location *L, double longtitude, double latitude) {
	L->longtitude = longtitude;
	L->latitude   = latitude;
}

double getlong(Location *L) {
	return L->longtitude;
}

double getlat(Location *L) {
	return L->latitude;
}
void saving(Database_manager *d_manager, Location *L) {
	Stmt_info *info;
	info->table = "location";
	info->values = strgen(3,"VALUES(", single_quotes(num2str(L->longtitude)),
			single_quotes(num2str(L->latitude)));
	d_manager->write_to_db(d_manager, info);
}

// loading is temporary no need.
Location *loading(Database_manager *d_manager, Location *L) {}
