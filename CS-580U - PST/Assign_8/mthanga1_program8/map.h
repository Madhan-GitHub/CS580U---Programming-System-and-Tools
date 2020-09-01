#ifndef MAP_H
#define MAP_H

#include "vector.h"
#include "city.h"

typedef struct map{
	Vector * cityVector;	
	
}Map;

Map * createMap(char * filename);
struct city * findByName(Map * map, char * cityName);
void printMap(Map *);

#endif