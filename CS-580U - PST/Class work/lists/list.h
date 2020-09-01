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
	struct List *(* join)(struct List * one, struct List * second );
	struct List *(*split)(struct List * list);
} List;

List * newList();

void insertList(struct List * list, int index, Data data);

Data * readList(struct List * list, int index);

List * join(struct List * one, struct List * second );

List * split(struct List * list);

#endif