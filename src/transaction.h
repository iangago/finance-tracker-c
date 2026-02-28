#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "account.h"

typedef enum{
    withdraw = 1, deposit = 0
}Type;

typedef struct Transaction{
    int value;
    int type;//W = withdraw/ D = deposit
    char *description;
    int date;

    struct Transaction *next;
}Transaction;

int getCurrentDate(void);
void addTransaction(Account *ac, int type);
void freeTransactions(Account *ac);

#endif