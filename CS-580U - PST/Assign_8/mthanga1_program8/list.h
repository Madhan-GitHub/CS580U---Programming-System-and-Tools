#ifndef LIST_H
#define LIST_H

#include "data.h"

#define PART_A 1
#define INSERT 1
#define READ 1
#define DELETE 1
#define DELETE_1 0
#define DELETE_2 0
#define PART_B 0

typedef struct list{
	struct node *head;
	struct node *tail;
}List;

typedef struct node{
	struct data * data;
	struct node * next;
	struct node * prev;
}Node;

Node * createNode(struct data);
List * createList();
void insertData(List * list, int index, struct data value);
int removeData(List * list, int index);
struct data * readData(List * list, int index);
int Empty(List * list);
void printList(List *list);
void printListReverse(List *list);
void * freeList(List *list);
void freeNode(Node * node);
int totalCount(List *list);
int searchForward(List *list, int num);
int searchBackward(List *list, int num);
void *deleteNode(Node * node);
void *deleteList(List * list);

#endif