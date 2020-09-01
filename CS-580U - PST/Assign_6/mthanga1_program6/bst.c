#include"bst.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>

// Function - new tree
Tree * newTree(){
	Tree *bst = malloc(sizeof(Tree));
	bst->root = NULL;
	bst->insert = insert;   
	bst->search = search;
	bst->sort = sort;
	bst->compare = compare;
	bst->clone = clone;
	bst->delete = delete;
	bst->removeData = removeData;
	return bst;
}

// Function to create new node
Node * newNode(Data data, Node * parent){
	Node *node = malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;
	return node;
}

// Recursive function for inserting the node in the tree
Data * insertNode(Node *node, Data data){
	Data *dataPtr = NULL;
	if(node->data.value == data.value){         //Check for the same node is being inserted twice and returns null
		dataPtr = NULL;
	}
	else if(node->data.value > data.value){     //Check for the node to be inserted has a value less than the current node
		if(node->left == NULL){
			node->left = newNode(data, node);
			dataPtr = &(node->left->data);
		}
		else{
			dataPtr = insertNode(node->left, data);
		}
	}
	else if(node->data.value < data.value){
		if(node->right == NULL){
			node->right = newNode(data, node);
			dataPtr = &(node->right->data);
		}
		else{
			dataPtr = insertNode(node->right, data);
		}
	}
	return dataPtr;
}

// Function to call insert node
Data * insert(Tree *bst, Data data){
	Data *dataPtr = NULL;
	if(bst->root == NULL){
		bst->root = newNode(data, NULL);
		dataPtr = &(bst->root->data);
	}
	else{
		dataPtr = insertNode(bst->root, data);
	}
	return dataPtr;
}

// Recursive function for searching the node in the tree
Node * searchNode(Node *node, Data data){
	Node *nodePtr = NULL;
	if(node->data.value == data.value){
		nodePtr = node;
	}
	else if(node->data.value > data.value && node->left != NULL){
		nodePtr = searchNode(node->left, data);
	}
	else if(node->data.value < data.value && node->right != NULL){
		nodePtr = searchNode(node->right, data);
	}
	return nodePtr;
}

// Function to call search function and to find value in tree
Data * search(Tree * bst, Data data){
	Node *nodePtr = NULL;
	if(bst->root == NULL)	{
		return NULL;
	}
	else{
		nodePtr = searchNode(bst->root, data);
		return &(nodePtr->data);
	}
}

// Recursive function for sorting the node in the tree
void sortTree(Node *node, Data *data, int *index){
	if(node != NULL){
		sortTree(node->left, data, index);
		data[*index] = node->data;
		(*index)++;
		sortTree(node->right, data, index);
	}
}

// Function to sort the values in tree - calls sortTree
void sort(Tree *bst, Data *data){
	int index = 0;
	if(bst->root != NULL)	{
		sortTree(bst->root, data, &index);
	}
}

// This function creates a preorder traversed array of the given tree
void performPreorderTraversal(Node *node, Data *data, int *index){
	if(node != NULL){
		data[*index] = node->data;
		(*index)++;
		performPreorderTraversal(node->left, data, index);
		performPreorderTraversal(node->right, data, index);
	}
}

// Function to compare the values in tree
int compare(Tree *tree, Tree *treeCopy){
	int isEqual = 0;
	if(tree != NULL && treeCopy != NULL){
		Data array1[13];
		Data array2[13];
		for(int i = 0; i < 13; i++){
			array1[i] = array2[i] = (Data) {-1};
		}
		int index1, index2;
		index1 = index2 = 0;

		performPreorderTraversal(tree->root, array1, &index1);
		performPreorderTraversal(treeCopy->root, array2, &index2);
		isEqual = 1;
		for(int i = 0; i < 13; i++){
			if(array1[i].value != array2[i].value){
				isEqual = 0;
				break;
			}
		}
	}
	return isEqual;
}

// Recursive function for cloning in the tree
Node * cloneNode(Node *originalNode, Node *cloneNode1, Node *parentNode){
	Node *temp = NULL;
	if(originalNode != NULL)
	{
		temp = newNode(originalNode->data, parentNode);
		if(originalNode->left != NULL){
			temp->left = cloneNode(originalNode->left, temp->left, temp);
		}
		if(originalNode->right != NULL){
			temp->right = cloneNode(originalNode->right, temp->right, temp);
		}
	}
	return temp;
}

// Function to return a clone of a tree
Tree * clone(Tree *tree){
	Tree *clone = newTree();
	clone->root = cloneNode(tree->root, clone->root, NULL);
	return clone;
}

// Function for deleting leaf node
void removeLeaf(Node * leaf){
	if(leaf->parent != NULL){
		if(leaf->parent->right == leaf)
			leaf->parent->right = NULL;
		else
			leaf->parent->left = NULL;
	}
	free(leaf);
}

// Function for deleting a node with single child
void shortCircuit(Node *node){
	if(node->parent->right == node)
	{
		if(node->right == NULL){
			node->parent->right = node->left;
			node->left->parent = node->parent;
		}
		else{
			node->parent->right = node->right;
			node->right->parent = node->parent;
		}
	}
	else if(node->parent->left == node){
		if(node->left == NULL){
			node->parent->left = node->right;
			node->right->parent = node->parent;
		}
		else{
			node->parent->left = node->left;
			node->left->parent = node->parent;
		}
	}
	free(node);
}

// Function for searching the node with minimum value in the right sub tree
Node * searchMin(Node *node){
	while(node->left != NULL)
		node = node->left;
	return node;
}

// Function for deleting a node with two children
void promotion(Node *node){
	Node *tempNode = searchMin(node->right);
	node->data = tempNode->data;
	if(tempNode->left == NULL && tempNode->right == NULL){
		removeLeaf(tempNode);
	}
	else{
		shortCircuit(tempNode);
	}
}

// Function to remove data
void removeData(Tree * bst, Data data){
	Node *node = NULL;
	node = searchNode(bst->root, data);

	if(node != NULL){
		if(node->left == NULL && node->right == NULL){
			if(bst->root == node){
				free(node);
				bst->root = NULL;
			}
			else{
				removeLeaf(node);
			}
		}
		else if((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL))	{
			if(bst->root == node)			{
				if(node->left == NULL)
					bst->root = node->right;
				else
					bst->root = node->left;
					free(node);
			}
			else{
				shortCircuit(node);
			}
		}
		else if(node->left != NULL && node->right != NULL){
			promotion(node);
		}
	}
}

//Recursive function for deleting the node in the tree
void deleteTree(Node *node){
	if(node != NULL){
		deleteTree(node->left);
		deleteTree(node->right);
		removeLeaf(node);
	}
}

// Function to call delete Tree
void delete(Tree * bst){
	if(bst->root != NULL){
		deleteTree(bst->root);
		free(bst);
	}
	else{
		free(bst);
	}
}