#include "vector.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>

Vector * createVector(){
	Vector *vector = malloc(sizeof(Vector));	
	(*vector).data = NULL;
	(*vector).current_size = 0;
	(*vector).capacity = 0;
	return vector;
}
Data* vectorRead(Vector *vector, int index){
	if(index < 0) 
		fprintf(stderr, "Invalid Index\n");
	if(index > (*vector).current_size){	//remove >=
		return NULL;
	}
	return (*vector).data;
}

void vectorRemove(Vector *vector, int index){
	if(index >= (*vector).current_size){
		return;
	}else if(index == (*vector).current_size){

	}

	int i = 0;
	for ( i = index ; i< (*vector).current_size-1;  i++){
		vector->data[i] = vector->data[i+1];
#if DEBUG_1
		printf("\n%d\n", v->data[i]);
#endif
	}
#if DEBUG_1
	printf(" current size\n %d\n", (*v).current_size);
#endif
	((*vector).current_size)--;
#if DEBUG_1
	printf(" current size\n %d\n", (*v).current_size);
#endif
}

void * deleteVector(Vector *vector){
	vector->data = deleteData(vector->data);
	free(vector);
	return NULL;
}

void vectorInsert3(Vector *vector, int index, Data dataIn){
	if(index >= (*vector).capacity){
		if((*vector).capacity == 0){
			(*vector).capacity = 1;
		}
		while(index >= (*vector).capacity){
			vector->capacity = (vector->capacity * 3)/2 + 1;
		}
		Data *newData = malloc(sizeof(Data) *(*vector).capacity);
		memcpy( newData, (*vector).data, sizeof(Data) * (*vector).current_size);
		free((*vector).data);
		(*vector).data =  newData;
    
	}
  else if( index < (*vector).current_size)
  {

	}
  else{
	}
  
	(*vector).data[index] = *(initData(dataIn.city));
	(*vector).current_size = index+  1; 
  
}

void printVector(Vector *v){
	int i = 0;
	for( i =0 ; i< (v->current_size) ; i++)
		printf("Name:%s, X=%d, Y=%d\n", v->data[i].city->name, v->data[i].city->x, v->data[i].city->y);
}