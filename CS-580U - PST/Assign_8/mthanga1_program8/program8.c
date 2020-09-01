#include "map.h"
#include "list.h"
#include<stdio.h>


List * shortestPath(Map * map, City * start, City * dest);
void * deleteMap(Map *map);
void printShortestPathList(List *list);



int main(){

	Map *map = createMap("townlist.txt");
	printMap(map);

	char city1[256], city2[256];
	printf("\nEnter origin city name : ");
	scanf("%200s", city1);

	printf("Enter destination city name : ");
	scanf("%200s", city2);

	City *cityFrom = findByName(map, city1);
	City *cityTo = findByName(map, city2);
	List *shortestPathList = NULL;
	shortestPathList = shortestPath(map, cityFrom, cityTo);
	printShortestPathList(shortestPathList);


	shortestPathList =deleteList(shortestPathList);
	map = deleteMap(map);

	return 0;
}
