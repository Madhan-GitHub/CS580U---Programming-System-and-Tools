#ifndef heap_h
#define heap_h

#include"data.h"

typedef struct Heap
{
	Data * data;
	int current_size;
	int maximum_capacity;
    struct Heap * (*initHeap)(Data * d);
    void (*siftDown)(struct Heap * h, int index);
    void * (*heapify)(struct Heap * h);
    void (*push)(struct Heap * heap, Data v);
    Data (*pop)(struct Heap * heap);
    Data (*peek)(struct Heap * heap);
}Heap;

Heap * initHeap(Data * d);

void siftDown(Heap * h, int index);

void * heapify(Heap * h);

void push (Heap * heap, Data v);

Data pop (Heap * heap);

Data peek (Heap * heap);

void deleteHeap(Heap *);

#endif