#include"list.h"
#include<stdio.h>
#include<stdlib.h>

// Function to create the constructor.
List * newList()
{
	List *list = malloc(sizeof(List));
	list->head = list->tail = NULL;

	//Init functin pointers
	list->insert = insertList;
	list->read = readList;
	list->join = join;
	list->split = split;
	return list;
}

// Function to insert elements at a specific index in a list.
void insertList(struct List * list, int index, Data value)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->data=value;
	node->prev=NULL;
	node->next=NULL;

	int length=0;
	Node *temp=list->head;
	while(temp!=NULL)
	{
		length=length+1;
		temp=temp->next;
	}
	if(length==0)
	{
		list->head=node;
		list->tail=node;
		return;
	}
	if(index>=length)
	{
		list->tail->next=node;
		node->prev=list->tail;
		list->tail=node;
		return;
	}
	if(index==0)
	{
		node->next=list->head;
		list->head->prev=node;
		list->head=node;
		return;
	}
	int ctr=0;
	temp=list->head;
	while(ctr!=index)
	{
		ctr++;
		temp=temp->next;
	}
	node->next=temp;
	node->prev=temp->prev;
	temp->prev->next=node;
	temp->prev=node;
}

// Function to read elements in a list.
Data * readList(struct List * list, int index)
{
	Data *data = NULL;
	Node *temp=list->head;
	int i = 0;
	while(temp != NULL)
	{
		if(i == index)
		{
			data = &temp->data;
			return data;
		}
		temp = temp->next;
		i++;
	}
	return data;
}

List * join(struct List * one, struct List * second ){
	
	List *temp;
	// If first linked list is empty 
    if (!one) 
        return second; 
  
    // If second linked list is empty 
    if (!second) 
        return one; 
	// If both are empty
	if ( !one && !second)
		return 0;
  
    // Merge if the list has data 
    if (one && second){ 
        one->tail->next = second->head;
        second->head->prev = one->tail; 
		temp->head = one->head;
		temp->tail = second->head; 
    } 
    return temp;
}

List * split(List * list){
	printf("List 1\n");
	for(int i=0;i<9;i++){
    	if(i%2){
        	printf("%d\n",list->head->data);
        	list->head = list->head->next->next;
    	}
		else{
        	//printf("%d\n",list->head->next->data);
    	}
    }
	printf("List 2\n");
	for(int j=10;j<19;j++){
    	if(j%2){
        	list->head = list->head->next->next;
    	}
		else{
        	printf("%d\n",list->head->next->data);
    	}
    }
}