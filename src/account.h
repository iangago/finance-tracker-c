#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "transaction.h"

typedef struct Account{
    int id;
    char *name;
    int balance;

    struct Transaction *head;
    struct Transaction *tail;
}Account;

void initAccount(Account *ac);
void createAccount(Account *ac);
bool isEmptyList(Account *ac);
void freeAccount(Account *ac);

#endif