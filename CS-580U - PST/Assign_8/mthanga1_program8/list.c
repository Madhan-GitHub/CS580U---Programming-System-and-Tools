#include "list.h"
#include "data.h"
#include<stdlib.h>
#include<stdio.h>

Node * createNode(Data data){
	Node * node = malloc(sizeof(Node));
	node->data = initData(data.city);
	node->next = NULL;
	node->prev = NULL;
	return node;
}
List * createList(){
	List * list = malloc(sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	return list;
  free(list);
}
void insertData(List * list, int index, Data data){
	if(list->head == NULL){
		(*list).head = createNode(data);
		(*list).tail= (*list).head;
	}else{
		Node *node = list->head;
		if(index == 1){
			Node *newNode = createNode(data);
			newNode->next = node;
			node->prev = newNode;
			list->head = newNode;
		}else{

			int counter = 1;
			while(node->next!= NULL && counter < index) //index < current index.
      {  
				node = node->next;
				counter++;
			}
			if(index > counter) //out of bounds, add at last pos.
      {
				Node *newNode = createNode(data);
				node->next=newNode;
				newNode->prev = node;
				list->tail = newNode;
			}
      else{
				Node *newNode = createNode(data);
				newNode->next = node;
				newNode->prev = node->prev;
      	node->prev->next = newNode;
        node->prev = newNode;
			}
      
		}
    
	}
  
}

void printList(List *list){
	if(list ==  NULL) return;
	if(list->head==NULL){
		 printf("\t Cannot print empty list\n\n");
		return;
    
	}
	Node * node = list->head;
	//printf("\t Origin");
	int i = 0;
while(node!=NULL){
//printf("[%s]->", *(node->data->city).name));
printf("\n\t\tCity = %-10s, [x,y] = [%d,%d] shortestweight=%d >>> ", node->data->city->name, node->data->city->x, node->data->city->y, node->data->city->edge->weight);
                node = node->next;
		i++;
        }
	printf("\n");
  free(node);   // FREED THIS 
}
void printListReverse(List *list){
	if(list->head==NULL) {
		printf("Cannot print Empty List\n\n");
		return;
	}
        Node * node = list->tail;
        printf("\t tail");
        while(node!=NULL){
                //printf("[%d]->", *(node->data));
                printf("[city=%s, x=%d, y=%d]->", node->data->city->name, node->data->city->x, node->data->city->y);
                node = node->prev;
        }
        printf("Head\n");
       free(node);    // FREED THIS 
}

void * freeList(List *list){
	if(list==NULL)
       	freeNode((*list).head);
	list->head = NULL;
	list->tail = NULL;
        free(list);
        return NULL;
}

void freeNode(Node * node){
	Node *tempNode;
	while(node!=NULL){
		if(node->next != NULL){
			tempNode = node->next;
			deleteData((*node).data);
			free(node);
			node->data = NULL;
			node->next = NULL;
			node->prev = NULL;
			node = NULL;
			node = tempNode;
		}else{
			deleteData((*node).data);
			free(node);
			node->next = NULL;
			node->prev = NULL;
			node = NULL;
     free(tempNode);     // FREED THIS  
		}
	}
}
int removeData(List * list, int index){
	if(list->head==NULL){
		printf("\tList is Empty\n");
		return 0;
	}
	if(index == -1){
		Node *node;
		if(list->head->next == NULL){
			printf("\t Only 1 element in List\n");
			deleteData( (*(*list).head).data );	
                        (*(*list).head).data = NULL;		 
			list->head = NULL;
			list->tail = NULL;
			free(list);				 
			list=NULL;				 
			printf("\tList Emptied\n");
			return 0;
		}else{
			node = list->tail->prev;		
			node->next = NULL;			
			deleteData((*(*list).tail).data);	
			(*(*list).tail).data = NULL;		
			list->tail->next = NULL;		
			list->tail->prev = NULL;		
			list->tail = NULL;			
			list->tail = node;		
      free(node);	 // FREED THIS 
     free((*(*list).tail).data);         // FREED THIS 
			return 0;
		}
	}
	if(list->head->next == NULL){
		printf("\t Only 1 element in List\n");
		deleteData( (*(*list).head).data);  	
		(*(*list).head).data = NULL;		
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
		list=NULL;				 
		printf("\tList Emptied\n");
		return 0;
   free((*(*list).head).data);   /* FREED THIS */ 
	}else{
		Node *node = list->head;
		if(index == 1){
			node->next->prev = NULL;
			list->head = node->next;
			deleteData((*node).data);	  
			(*node).data = NULL;			
			node->next = NULL;
			node->prev = NULL;
			free(node);
			node= NULL;
			return 0;
		}else{
			int count = totalCount(list);
			if(index >= count){
				//printf("\tIndex is out of bound, Deleting last element\n");
				Node * prevNode = list->tail->prev;
				prevNode->next= NULL;
 				deleteData((*(*list).tail).data);	
				(*(*list).tail).data = NULL;		
				list->tail->next = NULL;		
				list->tail->prev = NULL;		

				free(list->tail);
				list->tail=NULL;
				list->tail = prevNode;
				return 0;
        free(prevNode);
			}
      else{
				int counter = 1;
				while(node->next->next != NULL && counter < index){
					node = node->next;
					counter++;
				}
				node->prev->next = node->next;
				node->next->prev = node->prev;

				deleteData((*node).data);	  	
				(*node).data = NULL;			
				node->next = NULL;
				node->prev = NULL;
				free(node);

				node= NULL;
				return 0;
			}
		}
	}
	return 1;
}
int totalCount(List *list){
	if(list->head==NULL){
		printf("\tEmpty List\n");
		return 0;
	}
	int count = 0;
	Node * node = list->head;
	while(node!=NULL){
		count++;
		node = node->next;
	}
	return count;
  free(node);
}
Data * readData(List * list, int index){
	if(list->head==NULL){
		printf("\tEmpty List\n");
		return NULL;
	}
	if(index == 1){
		return list->head->data;
	}
	int count = totalCount(list);
	if(index == count){
		return list->tail->data;
	}else if( index > count){
		printf("\tIndex out of bound\n\tReturning Last element\n");
		return list->tail->data;
	}else{

		count = 1;
		Node * node = list->head;
		while(node->next!= NULL && count < index) {
			count ++;
			node = node->next;
		}
		return node->data;
    free(node);
	}
  
}
int Empty(List * list1){
	int result = -1;
	if(list1->head==NULL){
                printf("\tEmpty List\n");
                return 1;
        }
	printf("\nDeleting List at Random Index\n");
        while(list1!=NULL){
                int index = rand() % 25 + 1;
                printf("\n\tDeleting at index = %d\n", index-1);
                result = removeData(list1, index);
                printList(list1);
                if(list1->head==NULL) break;
        }
	return 0;
}
int searchForward(List * list, int num){
	if(list->head==NULL){
                printf("\tEmpty List\n");
                return 1;
        }
	int index = -1;
	Node *node = list->head;
	while(node->next!=NULL){
		index++;
		node = node->next;
	}
	return -1;
  free(node);
}

int searchBackward(List * list, int num){
        if(list->head==NULL){
                printf("\tEmpty List\n");
                return 1;
        }
        int index = -1;
        Node *node = list->tail;
        while(node->prev!=NULL){
                index++;
                node = node->prev;
        }
        return -1;
}
void * deleteNode(Node * node){
	deleteData(node->data);
	free(node);
	return NULL;
}


void *deleteList(List * list){ // to delete list.
	Node * iterator = list -> head;

	Node * prev = NULL; //deallocate memory of nodes
	while(iterator!= NULL){
		prev = iterator;
		iterator = iterator -> next;
		prev = deleteNode(prev);
	}
	free(list);
  free(prev);
  free(iterator);
	return NULL;
}
void printShortestPathList(List *list){
        if(list ==  NULL) return;
        if(list->head==NULL){
                 printf("\tCant print Empty List!!\n\n");
                return;
        }
        Node * node = list->head;
        printf("\npath for the given origina and city is as follows");
       printf("\n\nPath\t = ");
        int i = 0;
        while(node!=NULL)
        {
                printf("\tcity=%-10s >>>", node->data->city->name);
		node = node->next;
                i++;
        }
        printf("\t= Destination\n\n");
        free(node);
        
}
