#ifndef _LOCATION_H_
#define _LOCATION_H_

#include <malloc.h>

typedef struct location {
	double longtitude;
	double latitude;
} Location;

#define _INIT_LOCATION_(LOC, LONG, LAT) do { \
	LOC = (Location *)malloc(sizeof(Location)); \
	LOC->longtitude = LONG; \
	LOC->latitude = LAT; \
} while(0)

void setloc(Location *L,double longtitude, double latitude);
void getlong(Location *L);
void getlat(Location *L);

#endif /* _LOCATION_H_ */
