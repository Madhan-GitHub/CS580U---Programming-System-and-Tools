#include "mthanga1_Hash.h"

Hash* newHash(unsigned int size){
        Hash* temp = (Hash*) malloc(sizeof(Hash));
        temp -> data = (char**) calloc(size, sizeof(char*));
        for(int i = 0; i< size; i++){ temp -> data[i]= NULL; }
        temp -> size = size;
        temp -> insert = fun_insert;
        temp -> remove = fun_remove;
        temp -> find = fun_find;
        temp -> print = fun_print;
        temp -> delete = fun_delete;
        temp -> hasher = fun_hasher;
        return temp;
}

int fun_insert(Hash *password, char *name){
        int index = password->hasher(password, name);
        int count = HASH_SIZE;
        while(count && password -> data[index] ){
                index = (index +1) % HASH_SIZE;
                count --;
        }
        if(count){
                password -> data[index] = malloc(strlen(name)+1);
                memcpy(password -> data[index], name , strlen(name)+1);
        }
        else{
                return -1;
        }
        return index;
}

int fun_remove(Hash *password, char *name){
        int index = password->hasher(password, name);
        int count = HASH_SIZE;
        while(count ){
                if(password -> data[index]){
                        if (strcmp(name, password -> data[index]) == 0)
                        break;
                }
                index = (index +1) % HASH_SIZE;
                count --;
        }
        if (!count)
                return -1;
        else if(strcmp(name, password -> data[index]) == 0){
                free(password -> data[index]);
                password -> data[index]= NULL;
        }
        return 1;
}

char * fun_find(Hash *password, char *name){
        int index = password->hasher(password, name);
        int count = HASH_SIZE;
        while(count){
                if(password -> data[index]){
                     if (strcmp(name, password -> data[index]) == 0)
                        break;
                }
                index = (index +1) % HASH_SIZE;
                count --;
        }

        if (!count)
                return '\0';
        else if(strcmp(name, password -> data[index]) == 0){
                return (password -> data[index]);
        }
}

void fun_print(Hash *password){
        int i;
        printf("\t========   Hash Table   ========\n");
        for (i=0; i< HASH_SIZE; i++){
                if(password -> data !=  NULL){
                        printf( "\tIndex:%d \t Value:%s\n",i, password -> data[i] );
                }
                else{
                        printf( "\tIndex:%d \t Value:%s\n",i, "" );
                }
        }
}

void fun_delete(Hash *password){
        int i;
        for (i=0; i< HASH_SIZE; i++){
                if(password -> data[i])
                free(password -> data[i]);
        }       
        free(password->data);
        free(password);
}

int fun_hasher(Hash *password, char *name){
    unsigned int hash =0;
    short int index =0;
    int i,len;
    len = strlen(name);
    hash = index =0;
    for (i=0; i< len;i++)
        hash = hash + name[i];
    index = hash % 10;
    return index;
}