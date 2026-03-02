#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "account.h"
#include <stdbool.h>

typedef enum{
    withdraw = 1, deposit = 0
}Type;

typedef struct Transaction{
    long value;
    int type;//W = withdraw/ D = deposit
    char *description;
    int date;

    struct Transaction *next;
}Transaction;

int getCurrentDate(void);
Transaction *createTransaction(long value, int type, char *description, int date);
bool applyTransaction(Account *ac, Transaction *t);
void insertTransaction(Account *ac, Transaction *t);
void addTransactionUI(Account *ac, int type);
void freeTransactions(Account *ac);

#endif