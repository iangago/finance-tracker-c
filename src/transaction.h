#ifndef TRANSACTION_H
#define TRANSACTION_H

typedef struct Transaction{
    float value;
    int type;//1 = withdraw/ 0 = deposit
    char *description;
    int date;
}Transaction;

typedef struct Node{
    Transaction *data;
    struct Node *next
}Node;

void freeTransactions(History *h);

#endif