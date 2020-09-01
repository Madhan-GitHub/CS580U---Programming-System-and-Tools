#include "mthanga1_Hash.h"
#include "mthanga1_Hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(){

    printf("\n\tTEST #1: Create a hash of the correct size\n");

    Hash * passwords = newHash(10);
    assert(passwords->size == 10);

	//*********************************************************
	// Step 1: Read in the password file
	//*********************************************************
    FILE * pass_file = fopen("password.txt", "r");

    if (!pass_file){
        printf("Unable to open 'password.txt'!\n");
        return -1;
    }

    printf("\n\t========================PASS========================\n");
    printf("\n\tTEST #2: Insert values into the Hash\n");
    char name[80];
    while (fscanf(pass_file, "%s\n", name)> 0){
        assert(passwords->insert(passwords, name) > -1);
    }

	passwords->print(passwords);

    printf("\n\t========================PASS========================\n");
    printf("\n\tTEST #3: Verify invalid password doesn't work\n");

    char * stored_pass = passwords->find(passwords, "This shouldn't exists in your hash");
    assert(stored_pass == NULL);


    printf("\n\t========================PASS========================\n");
    printf("\n\tTEST #4: Verify valid passwords are retrievable\n");
    clearerr(pass_file);
    fseek(pass_file, 0, SEEK_SET);
    while (fscanf(pass_file, "%s\n", name) > 0){
        stored_pass = passwords->find(passwords, name);
        assert(strcmp(name,stored_pass) == 0);
    }

    passwords->print(passwords);

    printf("\n\t========================PASS========================\n");
    printf("\n\tTEST #5: Remove entries from the hash\n");
    clearerr(pass_file);
    fseek(pass_file, 0, SEEK_SET);
    while (fscanf(pass_file, "%s\n", name) > 0){
        stored_pass = passwords->find(passwords, name);
        fprintf(stderr, "\t====> DEBUG: %s, %s\n", name, stored_pass);
        passwords->print(passwords);
        if(stored_pass != NULL){
            assert(passwords->remove(passwords, name) == 1);
            assert(passwords->size == 10);
            assert(passwords->find(passwords, name) == NULL);
        }else{
            assert(0);
        }
    }

    fclose(pass_file);
    passwords->delete(passwords);
    printf("\n\t========================PASS========================\n");
    printf("\n\tAll Tests Passed.\nDon't forget to run with Valgrind and submit to Blackboard!\n");

	return 0;

}