#include "location.h"
#include "tools.h"

void init_location(Location *L) {
	L->imei = NULL;
	L->longtitude = 0;
	L->latitude   = 0;
	L->setimei	  = loc_setimei;
	L->getimei    = loc_getimei;
	L->setloc     = setloc;
	L->getlong    = getlong;
	L->getlat     = getlat;
	L->saving	  = location_saving;
	L->loading = NULL;
}

void loc_setimei(Location *L, char *imei) {
	L->imei = imei;
}

char * loc_getimei(Location *L) {
	return L->imei;
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
static void location_saving(Database_manager *d_manager, Location *L) {
	char *values = strgen("VALUES(", S_QUOTES(L->imei), ",", S_QUOTES(num2str(L->longtitude)),
			",", S_QUOTES(num2str(L->latitude)), ")", "\0");
	char *stmt = strgen(SP_APP("INSERT INTO"), SP_APP("location"), 
			values, "\0");
	d_manager->database_action(d_manager, stmt);
	release(values);
	release(stmt);
}

// loading is temporary no need.
static Location * location_loading(Database_manager *d_manager, Location *L) {}
