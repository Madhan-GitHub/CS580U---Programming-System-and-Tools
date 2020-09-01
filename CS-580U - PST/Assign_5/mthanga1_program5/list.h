#ifndef LIST_H
#define LIST_H

#include"data.h"

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

List * newList();

void insertList(struct List * list, int index, Data data);

void removeList(struct List * list, int index);

Data * readList(struct List * list, int index);

void deleteList(struct List * list);

#endif