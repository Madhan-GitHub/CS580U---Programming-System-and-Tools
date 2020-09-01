#include"heap.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <malloc.h>

Heap * initHeap(Data * d){				//Initializes the heap
	Heap * heap = malloc(sizeof(Heap));	//Allocates the space
	heap->data = NULL;					//Initialize to NULL
    heap->data = d;					    //Initializes with the data  created
	heap->current_size = 100;
	heap->maximum_capacity = 100;
	heapify(heap);
	return heap;
}

void * heapify(Heap * h){	    	  //Converts the array into an Heap
	for(int index = ((h->current_size-2) / 2); index >= 0; index--){	//Gets the last non-leaf node
		siftDown(h,index);
	}
}

void siftDown(Heap * h, int i){		 //Implements the siftdown
	
	int j = 0;
	Data * d =  h->data;
	
	if((i < 0) || (i >= h->current_size)){
		return;
	}

	while(((2 * i) + 2 <= h->current_size)){						
		if((2*i)+1 >= h->current_size){ j=-1; }
		else 
			j = (2*i)+1;
		if(j==-1){
			return;
		}
		if( j+1 < h->current_size && h->data[j+1].priority < h->data[j].priority){
	    j++;
	    }
        if( h->data[j].priority > h->data[i].priority ){
	    return;
	    }
		else{
		    Data temp;
            temp.priority = h->data[i].priority;
            temp.value=h->data[i].value;
			h->data[i].priority = h->data[j].priority;
            h->data[i].value=h->data[j].value;
            h->data[j].priority = temp.priority;
            h->data[j].value=temp.value;
			i = j;	
		}		
	}
}

Data pop (Heap * heap){
    Data temp = heap->data[0];
	heap->data[0] = heap->data[heap->current_size - 1];
	heap->data[heap->current_size - 1] = temp;
	heap->current_size = heap->current_size - 1;
	siftDown(heap, 0);
	return temp;
}

void push (Heap * heap, Data v){
	heap->data[heap->current_size].priority = v.priority;
	heap->data[heap->current_size].value = v.value;
    int x=heap->current_size;
    heap->current_size=x+1;
    heap->maximum_capacity=heap->current_size;
    siftDown(heap, x);
}

Data peek (Heap * heap){
    Data value = heap->data[0];
    return value;      // Returns Minimum value in heap
}

void deleteHeap(Heap * heap){	    //Frees the memory
	free(heap);
	heap = NULL;
}