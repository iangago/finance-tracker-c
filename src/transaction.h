#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "account.h"
#include <stdbool.h>

struct Account;

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
bool applyTransaction(struct Account *ac, Transaction *t);
void insertTransaction(struct Account *ac, Transaction *t);
bool addTransactionUI(struct Account *ac, int type);
void freeTransactions(struct Account *ac);

#endif