#include <stdio.h>
#include <stdlib.h>

/*
 * To calculate Count to zero using recursion.
 */
int countOf(int n){
    
    int result =0;
    while(n!=0){
        result++;
        if(n>0)
        n--;
        else{
            n++;
        }
        countOf(n);
    }
    return result;
}
/*
 * To calculate Fibonacci using recursion.
 */
int Fibonacci(int n){  
   int result = 0;
   if (n == 0)
    return 0;
   else if (n == 1)
    return 1;
   else
    result = Fibonacci(n-1) + Fibonacci(n-2);
    return (result);
}
/*
 * Struct definition
 */
struct Node
{
    int info;
    struct Node *left, *right;
};
/*
 * To insert values in node
 */
struct Node *insertNode(int key)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return(newNode);
}
/*
 * To find minimum value in tree
 */
struct Node * findMin(struct Node *n)
{
    while(n != NULL && n->left != NULL)
    {
        n = n->left;
    }
    printf("\nSmallest value is:  %d\n\n", n->info);
}
/*
 * To find maximum value in tree
 */
struct Node * findMax(struct Node *n)
{
    while (n != NULL && n->right != NULL)
    {
        n = n->right;
    }
    printf("\nLargest value is: %d\n", n->info);
}
/*
 * Main Function
 */
int main()
{
    int input,n, i = 0;
    printf("Enter the number to find count to zero : ");
    scanf("%d",&input);
    printf("%d",countOf(input));
    printf("\nEnter the number to get Fibonacci series: ");
    scanf("%d",&n);
    printf("\n*********************Fibonacci series*************************\n");
    for ( int index = 1 ; index <= n ; index++ ){
        printf("%d\n", Fibonacci(i));
        i++; 
    }
    printf("\n****************************BST********************************\n");
    printf("The following prints the minimum and maximum value of the tree:\n");
    printf("          25     \n");
    printf("        /    %c\n",'\\');
    printf("       15     35\n ");
    printf("     /  %c   /  %c\n",'\\','\\');
    printf("     10  20 30  40\n");
    /* Creating Binary Search Tree. */
    struct Node *newNode = insertNode(25);
    newNode->left = insertNode(15);
    newNode->right = insertNode(30);
    newNode->left->left = insertNode(10);
    newNode->left->right = insertNode(20);
    newNode->right->left = insertNode(30);
    newNode->right->right = insertNode(40);
    /* Sample Tree 1:
     *               25
     *             /    \
     *            15     35
     *           / \     / \
     *         10  20   30 40
     */
    printf("\nResult of BST:\n");
    findMax(newNode);
    findMin(newNode);
    return 0;
}