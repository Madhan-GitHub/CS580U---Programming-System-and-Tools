#ifndef _HASH_H
#define _HASH_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define HASH_SIZE 10

typedef struct Hash{
    char ** data;
    int size;
    int (*insert)(struct Hash *, char *);
    int (*remove)(struct Hash *, char *);
    char * (*find)(struct Hash *, char *);
    void (*print)(struct Hash *);
    void (*delete)(struct Hash *);
    int (*hasher)(struct Hash *, char *);
}Hash;

Hash * newHash(unsigned int size);
int fun_insert(Hash *, char *);
int fun_remove(Hash *, char *);
char * fun_find(Hash *, char *);
void fun_print(Hash *);
void fun_delete(Hash *);
int fun_hasher(Hash *, char *);

#endif