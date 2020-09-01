#include <stdio.h>
#include <stdlib.h> 
#include "stack.h"  

// Function to create the constructor.
Vector * newVector()
{
	Vector *vector = malloc(sizeof(Vector));
	vector->data = NULL;
	vector->current_size = 0;
	vector->max_size = 0;

	//Init function pointers
	vector->insert = insertVector;
	vector->read = readVector;
	vector->remove = removeVector;
	vector->delete = deleteVector;
	return vector;
}

// Function to insert element at specific index in an array.
void insertVector(Vector * array, int index, Data value)
{
	//To check if the index is within the bounds.
	if(index >= array->max_size)
	{
		
		array->max_size = ((2 * index) + 1); //Set the max size using the formula '2n + 1'.

		array->data = realloc(array->data, array->max_size * sizeof(Data)); //Reallocate the array using the size of 'Data' and the formula.

		//Set unused location to '-1'.
		for(int i = array->current_size; i < array->max_size; i++)
        	{
                	array->data[i].value = -1;
        	}
	}

	//Update the current size if the index at which data is to be inserted is greater than the current size.
	if(index >= array->current_size)
	{
		array->current_size = index + 1;
	}

	array->data[index].value = value.value; //Inserting data in the array.
}

// Function to remove the element at specific index in an array.
void removeVector(Vector * array, int index)
{
	//Check whether the data to be removed from the list is less than the index passed.
	if(index < array->max_size)
	{
		//Allocating a new array of size 'max_size - 1' and copying of data.
		Data *tempData = malloc(array->max_size * sizeof(Data) - 1);
		for(int i = 0; i < array->max_size - 1; i++)
		{
			if(i < index)
			{
				tempData[i].value = array->data[i].value;
			}
			else
			{
				tempData[i].value = array->data[i + 1].value;
			}
		}
		free(array->data);
		array->data = tempData;
		array->max_size -= 1;
		int newCurrentSize = 0;
		//Updating the current size.
		for(int index = (array->max_size - 1); index >= 0; index--)
		{
			if(array->data[index].value != -1)
			{
				newCurrentSize = index + 1;
				break;
			}
		}
		array->current_size = newCurrentSize;
	}
}

// Fuction to read data in array.
Data * readVector(Vector * array, int index)
{
	Data *data = NULL;
	//Return null if the index is greater than the max size.
	if(index >= array->max_size)
	{
		return data;
	}
	else//Return the data at the required index.
	{
		data = &(array->data[index]);
	}

	return data;
}

// Function to delete, pointing to destructor.
void  deleteVector(Vector * array)
{
	free(array->data);
	free(array);
}

/************************ Function Definitions of Stack **********************/

void StackInit(stackT *stackP, int maxSize)
{
  stackElementT *newContents;
  newContents = (stackElementT *)malloc(sizeof(stackElementT) * maxSize);

  if (newContents == NULL) {
    fprintf(stderr, "Insufficient memory to initialize stack.\n");
    exit(1);  /* Exit, returning error code. */
  }
  stackP->contents = newContents;
  stackP->maxSize = maxSize;
  stackP->top = -1;  /* I.e., empty */
}

void StackDestroy(stackT *stackP)
{
  /* Get rid of array. */
  free(stackP->contents);

  stackP->contents = NULL;
  stackP->maxSize = 0;
  stackP->top = -1;  /* I.e., empty */
}

void StackPush(stackT *stackP, stackElementT element)
{
  if (StackIsFull(stackP)) {
    fprintf(stderr, "Can't push element on stack: stack is full.\n");
    exit(1);  /* Exit, returning error code. */
  }
  stackP->contents[++stackP->top] = element;
}

stackElementT StackPop(stackT *stackP)
{
  if (StackIsEmpty(stackP)) {
    fprintf(stderr, "Can't pop element from stack: stack is empty.\n");
    exit(1);  /* Exit, returning error code. */
  }
  return stackP->contents[stackP->top--];
}

int StackIsEmpty(stackT *stackP)
{
  return stackP->top < 0;
}

int StackIsFull(stackT *stackP)
{
  return stackP->top >= stackP->maxSize - 1;
}