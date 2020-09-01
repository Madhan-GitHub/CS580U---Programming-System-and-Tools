#ifndef QUEUE_H
#define QUEUE_H

#include"data.h"

#define ERROR_QUEUE   2
#define ERROR_MEMORY  3

typedef struct Node
{
	struct Node *prev, *next;
    Data data;

} Node;

typedef struct  List
{
	Node *head, *tail;
	void (*insert)(struct List * list, int index, Data data);
	Data * (*read)(struct List * list, int index);
	void (*remove)(struct List * list, int index);
	void (*delete)(struct List * list);

} List;

typedef char queueElementT;

typedef struct queueCDT *queueADT;	

List * newList();

void insertList(struct List * list, int index, Data data);

void removeList(struct List * list, int index);

Data * readList(struct List * list, int index);

void deleteList(struct List * list);

queueADT QueueCreate(void);

void QueueDestroy(queueADT queue);

void QueueEnter(queueADT queue, queueElementT element);

queueElementT QueueDelete(queueADT queue);

int QueueIsEmpty(queueADT queue);

int QueueIsFull(queueADT queue);

#endif