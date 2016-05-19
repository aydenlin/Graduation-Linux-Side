#ifndef _LOCATION_H_
#define _LOCATION_H_

#include <malloc.h>

#define _INIT_LOCATION_MALLOC_(L, LONG, LAT) do { \
	L = (Location *)malloc(sizeof(Location)); \
	init_location(L, LONG, LAT); \
} while(0)

#define _INIT_LOCATION_(L, LONG, LAT) do { \
	init_location(L, LONG, LAT); \
} while(0)

typedef struct location {
	double longtitude;
	double latitude;
	void (*setloc)(Location *L, double lon, double lat);
	double (*getlong)(Location *L);
	double (*getlat)(Location *L);
	void (*saving)(Database_manager *d_manager, Location *L);
	Location * (*loading)(Database_manager *d_manager, Location *L);
} Location;

void init_location(Location *L, double lon, double lat);
void setloc(Location *L,double longtitude, double latitude);
double getlong(Location *L);
double getlat(Location *L);
void saving(Database_manager *d_manager, Location *L);
Location * loading(Database_manager *d_manager, Location *L);

#endif /* _LOCATION_H_ */
