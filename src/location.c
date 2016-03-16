#include "location.h"

void setloc(Location *L, double longtitude, double latitude) {
	L->longtitude = longtitude;
	L->latitude = latitude;
}

void getlong(Location *L) {
	return L->longtitude;
}

void getlat(Location *L) {
	return L->latitude;
}
