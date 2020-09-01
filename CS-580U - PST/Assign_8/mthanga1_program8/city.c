#include "city.h"
#include "vector.h"
#include "list.h"
#include "map.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

City * createCity(char * cityNameIn, int xIn, int yIn){
	City *city =  malloc(sizeof(City));
	strcpy(city->name, cityNameIn);
	city->x = xIn;
	city->y = yIn;
	city->adjacents = NULL;
	city->visited = 0;
	city->edge = NULL;
	return city;
}

void createEdge(List *list, int index, Data data, int weight){
	Node * node = list->head;
	int counter = 1;
	while(node->next!=NULL &&  counter<index){
		node = node->next;
		counter++;
	}
	node->data->city->edge = malloc(sizeof(Edge));
	node->data->city->edge->city = data.city;
	node->data->city->edge->weight = weight;
}
//Assumaption : Lit index starts from 1 instead of zero Please notice.

void setAdjacent(Vector *v){
	int i=0, j=0, index=1;
	for(i=0; i < (v->current_size) ; i++){
		int x1flag = -1;
    int x2flag = -1;	
		int y1flag = -1;
    int y2flag = -1;			
		int north=0, south=0, east=0, west=0;
    int northidx=-1, southidx=-1;
	int	westidx=-1, eastidx=-1;
		int southwt=-1, northwt=-1;
		int	eastwt=-1, westwt=-1;


		City *city = v->data[i].city;
		city->adjacents = createList();
		insertData(city->adjacents, index, v->data[i]);
		createEdge(city->adjacents, index, v->data[i], 0);
		//v->data[i].weight = 0;
		index++;

		for(j=0; j < (v->current_size) ; j++){
			//printf("%d%d\n",i,j);
			if(i!=j){
				//Are they in  horizontal or vertical line?
				int Ax = v->data[i].city->x; 	int Bx = v->data[j].city->x;
				int Ay = v->data[i].city->y; 	int By = v->data[j].city->y;
				if(Ax==Bx || Ay==By){ 
					int weight;
					//check if shorted path available
					if(Ax==Bx){
						weight = abs(Ay-By);
						if(Ay>By){// B is South to A
if(south==0){ //if South side not has been added add one edge.
insertData(city->adjacents, index, v->data[j]);
createEdge(city->adjacents, index, v->data[j], weight);
southidx = index; southwt = weight;
index++;
south = 1;
}else if(southwt < weight){ //if old weight is less, do nothing
continue;
}else{//Means new weight is less, remove old.
if(southidx == index){
int result = removeData(city->adjacents, -1);
}else{
int result = removeData(city->adjacents, southidx);
}
index--;
insertData(city->adjacents, southidx, v->data[j]);
createEdge(city->adjacents, southidx, v->data[j], weight);
southidx = index; southwt = weight;
index++;
south = 1;

}
}else{//B is on North of A
if(north==0){ //if North side not has been added add one edge.
insertData(city->adjacents, index, v->data[j]);
createEdge(city->adjacents, index, v->data[j], weight);
northidx = index; northwt = weight;
index++;
north = 1;
}else if(northwt < weight){ //if old weight is less, do nothing
continue;
}else{//Means new weight is less, remove old.
if(southidx == index){
int result = removeData(city->adjacents, -1);
}else{
int result = removeData(city->adjacents, northidx);
}
index--;
insertData(city->adjacents, northidx, v->data[j]);
createEdge(city->adjacents, northidx, v->data[j], weight);
northidx = index; northwt = weight;
index++;
north = 1;

}
}

}else if(Ay==By){
weight = abs(Ax-Bx);
if(Ax>Bx){// B is on West of A
if(west==0){ //if West side not has been added add one edge.
insertData(city->adjacents, index, v->data[j]);
createEdge(city->adjacents, index, v->data[j], weight);
westidx = index; westwt = weight;
index++;
west = 1;
}else if(westwt < weight){ //if old weight is less, do nothing
continue;
}else{//Means new weight is less, remove old.
if(southidx == index){
int result = removeData(city->adjacents, -1);
}else{
int result = removeData(city->adjacents, westidx);
}
index--;
insertData(city->adjacents, westidx, v->data[j]);
createEdge(city->adjacents, westidx, v->data[j], weight);
westidx = index; westwt = weight;
index++;
west = 1;
}
}else{//B is on East of A
if(east==0){ //if West side not has been added add one edge.
insertData(city->adjacents, index, v->data[j]);
createEdge(city->adjacents, index, v->data[j], weight);
eastidx = index; eastwt = weight;
index++;
east = 1;
}else if(eastwt < weight){ //if old weight is less, do nothing
continue;
}{//Means new weight is less, remove old.
if(southidx == index){
int result = removeData(city->adjacents, -1);
}else{
int result = removeData(city->adjacents, eastidx);
}
index--;
insertData(city->adjacents, eastidx, v->data[j]);
createEdge(city->adjacents, eastidx, v->data[j], weight);
eastidx = index; eastwt = weight;
index++;
east = 1;
}
  }
}
}
			}
		}
		y1flag = x1flag = -1;
		y2flag = x2flag = -1;
		index=1;
	}
}

void printAdjList(Vector *v){
	int i = 0;
	for(i =0; i< (v->current_size); i++){
		printf("%i.%s->", i+1,  v->data[i].city->name);

		printList(v->data[i].city->adjacents);

	}
}

struct city * findByNameCity(Vector *v, char *cityName){
	int i = 0;
	for(i=0; i < (v->current_size) ; i++){
		int found = strcmp(cityName, v->data[i].city->name);
		if(found ==0)
			return v->data[i].city;
			//break;
	}
	printf("\n Entered city name is invalid\n");
	return NULL;
}


void deleteEdge(struct edge *edge){
	if(edge!=NULL)
		free(edge);
	//edge->city = NULL;
	edge = NULL;
}
void * deleteCity(City * city){
	deleteEdge(city->edge);
	if(city->adjacents !=NULL){
		if(city->adjacents->head != NULL){
				deleteList(city->adjacents);
		}
	}
	if(city!=NULL)
		free(city);
	//city->edge= NULL;
	return NULL;

}
int findIndexOfCityInVector(Vector * v, City *start){
	int i=0,index = -1;
	for(i=0; i< (v->current_size); i++){
		index++;
		int result = strcmp(start->name, v->data[i].city->name);
		//if(start == v->data[i].city)
		if(result ==0)
		break;
	}
	return index;
}

int findMinDistance(int *distance, int *visited){
	int min = INT_MAX;
	int index = -1, i=0;
	//for(i = 0; i< (sizeof(distance)/sizeof(int)); i++){
	for(i = 0; i< 11; i++){
		if(visited[i]==0){	
			if(distance[i] < min){
				min = distance[i];
				index = i;
			}
		}
	}
	return index;
}
void copyPreviousDistance(int *distance, int * visited){
	int i=0;
	for(i=0; i<11; i++){
		if(visited[i] ==0)   //keep the value
    {
			distance[i] = INT_MAX;
		}
	}
}

City * findClosestCity(Map *map,int *visited,int *distance, int *parent, City *start, int indexOfStart, int visitedIndexCount, int sourceastwt, int indexOfDest){
	Vector * v = map->cityVector;
	Data *data = map->cityVector->data;
	int i = 0;
	int destFound = 0;

	List *adjList = data[indexOfStart].city->adjacents;
	int sizeofAdjList = totalCount(adjList);
	for (i=2; i <= sizeofAdjList; i++){
		data = readData(adjList, i);
		int index =  findIndexOfCityInVector(v, data->city);
		int Edgeastwt = data->city->edge->weight;
		if(visited[index] == 0){
			if( sourceastwt + Edgeastwt < distance[index]){
				distance[index] = sourceastwt + Edgeastwt;
				parent[index] = findIndexOfCityInVector(v, start);
				if(index == indexOfDest){
					 destFound=1;
					 break;
		}
			}
      free(data);
	}

	}
	if( destFound == 1){
		int minCityIndex = indexOfDest;
		visited[minCityIndex] = visitedIndexCount;
    		return (map->cityVector->data[minCityIndex].city);
	}
	int minCityIndex = findMinDistance(distance, visited);
	visited[minCityIndex] = visitedIndexCount;

	return (map->cityVector->data[minCityIndex].city);
   free(adjList);
}

List * shortestPath(Map * map, City * start, City * dest){
	List * listPath = createList();
	int max = INT_MAX, vertexCount = 0;
	vertexCount = map->cityVector->current_size;
	int i=0, distance[vertexCount], visited[vertexCount], parent[vertexCount];
	static int visitedIndexCount = 0;

	for(i=0;i<vertexCount; i++){
		distance[i]=INT_MAX;
		visited[i]=0;
		parent[i] = -1;
	}

	int indexOfStart = findIndexOfCityInVector(map->cityVector, start);
	int indexOfDest = findIndexOfCityInVector(map->cityVector, dest);
	int currentStart = indexOfStart;
	int totalDistance = 0, sourceastwt = 0;

	distance[indexOfStart]= 0;
	visited[indexOfStart] = ++visitedIndexCount;

	City *city = NULL;
	Data data;
	data.city = start;
	int listIndex=1;
	insertData(listPath, listIndex++, data);
	city = start;
	int Count = 0;
	while(city!= dest){
		if(Count >=9){
    // printf("%d \n", nullCheckCount);
      printf("\nPath is infinite");
		printf("\nPath to the destination is not available\n");
		//	return NULL;
			exit(0);
		}
		City *closestCity =  findClosestCity(map, visited, distance, parent, city, currentStart, ++visitedIndexCount, sourceastwt, indexOfDest);
		currentStart = findIndexOfCityInVector(map->cityVector, closestCity);
		sourceastwt = distance[currentStart];
		data.city = closestCity;
		insertData(listPath, listIndex++, data);
		city = closestCity;
		Count++;
	}

bubbleSort(distance, visited, map->cityVector, vertexCount);
	return listPath;	
  free(listPath);
  free(city);
}


void bubbleSort(int * distance, int * visited, Vector *v, int vertexCount){
	int i = 0 , j = 0, n = 0, swap=0, swap1=0, swap2=0;
	Data data;
	for (i=0; i<(vertexCount-1); i++){
	    for (j=0 ; j<(vertexCount-i-1); j++){
	      if (visited[j] > visited[j+1]){ // For decreasing order use 
			swap = visited[j];
			swap1 = distance[j];
			data = v->data[j];
		        visited[j]   = visited[j+1];
		        distance[j]   = distance[j+1];
		        v->data[j]   = v->data[j+1];

		        visited[j+1] = swap;
		        distance[j+1] = swap1;
		        v->data[j+1] = data;
	      }
	    }
	}
	//printf("\n\n\tPrinting detials\n");
	int flag =0;
	for(i=0; i<vertexCount;i++){
		if(visited[i]!=0){
			if(flag == 0){
				//printf("\tVisited  Distance    Parent\n");
				printf("\n**Visited** |   **City**   |**Distance**\n");
				flag = 1;
			}
			printf("\t%-12d%-14s%-4d\n", visited[i], v->data[i].city->name, distance[i]);
		}
	}
  
}