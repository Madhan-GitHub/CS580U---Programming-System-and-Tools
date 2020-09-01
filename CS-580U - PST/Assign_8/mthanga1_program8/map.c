#include "data.h"
#include "map.h"
#include "vector.h"
#include "list.h"

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

Map * createMap(char * filename){
	Map *map = malloc(sizeof(Map));
	map->cityVector = createVector();

	int x, y;
	char cityName[255] = {0};
	FILE * fptr = fopen(filename, "r");

	int index = 0;
	while( fscanf(fptr, "%s %d %d", cityName, &x, &y)!= EOF){
		//data.city = city;
		City city;
		strcpy(city.name,cityName);
		city.x = x;
		city.y = y;
		Data data;
		data.city = &city;
		vectorInsert3(map->cityVector, index, data);
		index++;
	}
	setAdjacent(map->cityVector);
	return map;
  free(map);
}
City* findByName(Map * map, char * cityName){
	City *city = findByNameCity(map->cityVector, cityName);
	if(city==NULL){
		printf("\n Entered city name is incorrect\n");
		return NULL;
	}
	return city;
  free(city);
}

void printMap(Map *map){
	printAdjList(map->cityVector);
}

void * deleteMap(Map *map){
	map->cityVector = deleteVector(map->cityVector);
	free(map);
	return NULL;
}