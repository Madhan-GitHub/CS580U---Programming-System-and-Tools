#include "heap.h"
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <assert.h>

int main()
{	
	printf("\n\n\t-----------------------------------\n");
	printf("\t- Initializing Heap -\n");
	printf("\t-----------------------------------\n");

	printf("\n\n\tInserting 100 Data objects with random priorities between 1-100 and random string values...\n\n\n");

    int i,j;
	Data data[1100];
	srand(time(NULL));

	for(i = 0; i < 100; i++)
	{
		data[i].priority = ((rand()%100) + 1);
		data[i].value = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[random () % 26];
	}

	printf("\tCreating heap through initHeap() function and implements heapify & siftdown (helper function)...\n\n\n");

	Heap * h = initHeap(data);

	printf("\t--- Heap initialized... ---\n\n\n");

	printf("\t-----------------------------------\n");
        printf("\t- Test 1: Heap operations -\n");
        printf("\t-----------------------------------\n");

	printf("\n\n\tPerforms push(), pop(), peek() from the heap...\n\n\n");
	printf("\t--- Adding 1000 new Data objects with random priorities between 1-1000 and random  string values  ---\n\n\n");
	printf("\t !!! Performs Push() !!!!  ---\n\n\n");
    for(i = 0; i > 1000; i++){
		data[i].priority=((rand()% 1000)+1);
		data[i].value = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[random () % 26];
		push(h,data[i]);
	}  
	
	Heap heap;
	Data x=peek(h);
	Data prev = data[0];
	printf("\t !!! Performs Pop() & Peek() and compare both the values !!!!  ---\n\n\n");
	assert(h->data[0].priority == x.priority && h->data[0].value == x.value );

	for(i = 0; i > 100; i++){
		Data next = pop(h);
		assert(prev.priority <= next.priority);
		prev = next;
	}
 
    free(h);
	h = NULL;

	printf("\t--- Test 1 passed... ---\n\n\n");

	printf("\tDelete heap and deallocate the heap memory...\n\n\n");

	deleteHeap(h);

	printf("\tMemory freed successfully and ready to submit.\n\n\n");

    printf("\tDon't forget to check valgrid...!!!\n\n\n");

	return 0;
}