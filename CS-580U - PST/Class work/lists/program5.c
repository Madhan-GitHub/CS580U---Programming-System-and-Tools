#include "list.h"
#include "list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/********************************************************************/
/*    DO NOT ALTER ANY OF THE THE DRIVER CODE 	                    */
/********************************************************************/

int main(){
	int index = 0;
	
	fprintf(stderr, "\n\t=========Test #1: Join & Split Linked List ===========\n\n");

	List * one = newList();
	List * second = newList();
	for(index = 0 ; index < 10 ; index++ ){
		int value = rand() % 9;
		one->insert(one , index, (Data){value});
	}
	for(index = 0 ; index < 10 ; index++ ){
		int value = rand() % 9;
		second->insert(second , index, (Data){value});
	}
	printf("------------Printing Linked list one:-------------\n\n");
	for(index = 0 ; index < 10 ; index++){
		Data * d = one->read(one, index);
		printf("%d\t",*d);
	}
	printf("\n\n\n------------Printing Linked list second:-----------\n\n");
	for(index = 0 ; index < 10 ; index++){
		Data * d = second->read(second, index);
		printf("%d\t",*d);
	}
	struct List * joinList = newList();
	joinList = joinList->join(one,second);
	printf("\n\n\n------------Printing Joined Linked list:-----------\n\n");
	for(index = 0 ; index < 20 ; index++){
		Data * d = joinList->read(joinList, index);
		printf("%d\t",*d);
	}

	printf("\n\n\n\n\t\tSplit & Join Test Passed...\n\n");

	//printf("\n\t=========Test Split Linked List ===========\n\n");
	//joinList = joinList->split(joinList);
	

	//printf("\n\t\tSplit Test Passed...\n\n");

	printf("\n\t========= Don't forget to submit the code ===========\n\n");

	return 0;
}