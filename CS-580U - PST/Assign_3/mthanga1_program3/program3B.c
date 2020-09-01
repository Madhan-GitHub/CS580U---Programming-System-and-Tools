#include <stdlib.h>
#include <stdio.h>
#pragma GCC diagnostic ignored "-Wreturn-local-addr"
#pragma GCC diagnostic ignored "-Wfree-nonheap-object"

void f1(){
  int *a = malloc(sizeof(int) * 8);  //modified
  for (int i = 0; i < sizeof(a); i++){
    a[i] = i;
  }
  free(a);  //added
}

int * f2(){
  int a[10];
  for (int i = 0; i < 10; i++){  //modified the array index to print values 0-9
    a[i] = i;
  }
  for (int i = 0; i < 10; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
  return a;
}

int f3(){
  char * cptr = malloc(sizeof(char)*10);
  cptr[1] = 'a';  //changed the index
  int junk = 0;  //Initialized to Integer from char to avoid segmentation fault
  if(junk == 0){
      printf("Junk is zero.");
  }
  //free(&junk);  //commented to avoid warning
  free(cptr);  //added
}

/** DO NOT ALTER THE MAIN FUNCTION **/

int main()
{
  f1();
  f2();
  f3();
}
