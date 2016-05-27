#ifndef _LOCATION_H_
#define _LOCATION_H_

#include <malloc.h>
#include "database_manager.h"

#define _INIT_LOCATION_MALLOC_(L, LONG, LAT) do { \
	L = (Location *)malloc(sizeof(Location)); \
	init_location(L, LONG, LAT); \
} while(0)

#define _INIT_LOCATION_(L, LONG, LAT) do { \
	init_location(L, LONG, LAT); \
} while(0)

typedef struct location {
	char *imei;
	double longtitude;
	double latitude;
	void (*setimei)(struct location *L, char *imei);
	char * (*getimei)(struct location *L);
	void (*setloc)(struct location *L, double lon, double lat);
	double (*getlong)(struct location *L);
	double (*getlat)(struct location *L);
	void (*saving)(Database_manager *d_manager, struct location *L);
	struct location * (*loading)(Database_manager *d_manager, struct location *L);
} Location;

void init_location(Location *L, double lon, double lat);
void loc_setimei(Location *L, char *imei);
char * loc_getimei(Location *L);
void setloc(Location *L,double longtitude, double latitude);
double getlong(Location *L);
double getlat(Location *L);
static void location_saving(Database_manager *d_manager, Location *L);
static Location * location_loading(Database_manager *d_manager, Location *L);

#endif /* _LOCATION_H_ */
