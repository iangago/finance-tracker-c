#include "account.h"
#include "transaction.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

int getCurrentDate(void){
    time_t now = time(NULL);           // 1. get current time
    struct tm *t = localtime(&now);    // 2. convert to date struct

    int year = t->tm_year + 1900;      // years since 1900
    int month = t->tm_mon + 1;         // months since January (0–11)
    int day = t->tm_mday;              // day of the month

    return year * 10000 + month * 100 + day;
}

Transaction *createTransaction(long value, int type, char *description, int date){
    //validate data
    if(value <= 0){
        printf("Invalid transaction value.\n");
        return NULL;
    }
    if(type != withdraw && type != deposit){
        printf("Error in the type of the transaction.\n");
        return NULL;
    }

    //allocate memory
    Transaction *newTransaction = malloc(sizeof(Transaction));
    if(newTransaction == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }

    newTransaction->description = malloc(BUFFER_SIZE);
    if(newTransaction->description == NULL){
        printf("Memory allocation failed\n");
        free(newTransaction);
        exit(1);
    } 

    //store transaction
    //value
    newTransaction->value = value;

    //type
    newTransaction->type = type;

    //description
    strcpy(newTransaction->description, description);

    //date
    newTransaction->date = date;

    return newTransaction;
}

bool applyTransaction(Account *ac, Transaction *t){
    //validate data
    if(t->type == withdraw && t->value > ac->balance){
        printf("Insuficcient funds.\n");
        return false;
    }

    //apply changes
    if(t->type == withdraw){
        ac->balance -= t->value;
    }else if(t->type == deposit){
        ac->balance += t->value;
    }

    return true;
}

void insertTransaction(Account *ac, Transaction *t){
    //insert in list
    t->next = NULL;
    if(ac->head == NULL){//empty list
        ac->head = t;
        ac->tail = t;
    }else{//not empty
        ac->tail->next = t;
        ac->tail = t;
    }
}

void addTransactionUI(Account *ac, int type){
    //collect data
    long value;
    char description[BUFFER_SIZE];

    readMoney("What is the value of the transaction: ", &value);
    readStr("What is the description of the transaction: ", description);
    removeNewLine(description);
    int date = getCurrentDate();

    Transaction *t = createTransaction(value, type, description, date);
    if(t == NULL){
        printf("Error in creating the transaction.\n");
        return;
    }

    if(!applyTransaction(ac, t)){
        free(t->description);
        free(t);
        return;
    }

    insertTransaction(ac, t);
}

void freeTransactions(Account *ac){
    Transaction *current = ac->head;

    while(current != NULL){
        Transaction *next = current->next;

        free(current->description);
        free(current);

        current = next;
    }

    ac->head = NULL;
    ac->tail = NULL;
}
