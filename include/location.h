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

typedef struct location Location;
typedef void Setloc(Location *L, double lon, double lat);
typedef double Getlong(Location *L);
typedef double Getlat(Location *L); 

void init_location(Location *L, double lon, double lat);
void setloc(Location *L,double longtitude, double latitude);
double getlong(Location *L);
double getlat(Location *L);

typedef struct location {
	double longtitude;
	double latitude;
	Setloc *setloc;
	Getlong *getlong;
	Getlat *getlat;
	
} Location;

#endif /* _LOCATION_H_ */
