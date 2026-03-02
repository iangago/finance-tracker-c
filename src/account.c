#include "input.h"
#include "account.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initAccount(Account *ac){
    //start name
    ac->name = malloc(BUFFER_SIZE);
    if(ac->name == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    } 
    ac->name[0] = '\0';

    //start id
    ac->id = 0;

    //start balance
    ac->balance = 0;

    //start list
    ac->head = NULL;
    ac->tail = NULL;
}

void createAccountUI(Account *ac){ 
    do{
        readInt("\nEnter the account id (3-digit): ", &ac->id);//enter account id

        if(ac->id > 999 || ac->id < 1) printf("\nNumber out of range.\n");

    }while(ac->id > 999 || ac->id < 1);
    
    readStr("\nEnter the account name: ", ac->name);//enter the account name

    ac->balance = 0;//sets the incial balance to zero
}

bool isEmptyList(Account *ac){
    return ac->head == NULL;
}

void freeAccount(Account *ac){
    free(ac->name);
}
