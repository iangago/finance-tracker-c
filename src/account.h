#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "transaction.h"

typedef struct Account{
    int id;
    char *name;
    float balance;
    struct History *history;
}Account;

typedef struct History{
   Node *head;
}History;

void createAccount(History *h, Account *ac);
bool isEmptyHistory(History *h);
void freeAccount(Account *ac);

#endif