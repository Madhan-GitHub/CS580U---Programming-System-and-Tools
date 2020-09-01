#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void binaryArray(int n, int array[], int size){
    for(int i= 0; i< size; i++){
        if(n & 1){                //Bit Masking
            array[i] = 1;
        }
        else{
            array[i] = 0;
        }
        n = n>>1;                 //Bit Shifting (right shift)
    }
}   

void binaryPrinter(int array[], int size){
    int i= 0, Temp;
    int j= size-1;
    while (i < j) 
   {
      Temp = array[i];
      array[i] = array[j];         //Reversing the values in array using Temp.
      array[j] = Temp;
      i++;             
      j--; 
   }
    for(int i= 0; i< size; i++){
        printf("%d", array[i]);
    }
}

unsigned int countOnes(int num){
    unsigned int number_of_ones = 0;
    for(int i= 1; i <= sizeof(unsigned int)*8; i++){
        if(num & 1){               //Bit Masking
            number_of_ones++;
        }
        num = num>>1;              //Bit Shifting(Right shift)
    }
    return number_of_ones;
}

int myStrStr(char haystack[], char needle[], char buffer[]){
    
 int haystak_index = 0;
 int needle_index = 0;
 int buffer_index = 0;
 int len_h = strlen(haystack);
 int len_n = strlen(needle);
 memset(buffer, 0, 255);                                     // emptying the values in buffer[].
 while(haystack[haystak_index] != '\0' && haystak_index <= len_h ){
    if(haystack[haystak_index] == needle[needle_index]){
        buffer[buffer_index] = haystack[haystak_index];      // Assigning the matched character to buffer[].

        buffer_index++;
        haystak_index++;
        needle_index++;
    }
    else{
        haystak_index++;
    }
  }
 for(int i=0; i<=len_n; i++){
     if(buffer[i] == needle[i]){
         return 1;
     }
     else if(buffer[i] != needle[i]){
         return 0;
         break;
     }
 }
}