#include "location.h"

void init_location(Location *L, double lon, double lat) {
	L->longtitude = lon;
	L->latitude   = lat;
	L->setloc     = setloc;
	L->getlong    = getlong;
	L->getlat     = getlat;
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
