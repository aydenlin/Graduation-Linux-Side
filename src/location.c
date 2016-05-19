#include "location.h"

void init_location(Location *L, double lon, double lat) {
	L->longtitude = lon;
	L->latitude   = lat;
	L->setloc     = setloc;
	L->getlong    = getlong;
	L->getlat     = getlat;
	L->saving = saving;
	L->loading = NULL;
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
		
}

// loading is temporary no need.
Location *loading(Database_manager *d_manager, Location *L) {}
