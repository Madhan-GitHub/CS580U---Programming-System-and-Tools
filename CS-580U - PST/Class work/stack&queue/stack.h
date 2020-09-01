#ifndef _STACK_H
#define _STACK_H

#include"data.h"

typedef char stackElementT;
typedef struct {
  stackElementT *contents;
  int maxSize;
  int top;
} stackT;

typedef struct Vector
{
	Data *data;
	unsigned int current_size;
	unsigned int max_size;
	void (*insert)(struct Vector * array, int index, Data value);
	Data * (*read)(struct Vector * array, int index);
	void (*remove)(struct Vector * array, int index);
	void (*delete)(struct Vector * array);

} Vector;

Vector * newVector();

void insertVector(Vector * array, int index, Data value);

void removeVector(Vector * array, int index);

Data * readVector(Vector * array, int index);

void  deleteVector(Vector * array);

void StackInit(stackT *stackP, int maxSize);

void StackDestroy(stackT *stackP);

void StackPush(stackT *stackP, stackElementT element);

stackElementT StackPop(stackT *stackP);

int StackIsEmpty(stackT *stackP);

int StackIsFull(stackT *stackP);

#endif 