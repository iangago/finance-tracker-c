#ifndef BANK_H
#define BANK_H

#include "queue.h"
#include "stack.h"

typedef enum{
    OPTION1 = 1, OPTION2 = 2, OPTION3 = 3, OPTION4 = 4, OPTION5 = 0
}Choice;

Choice readOption(void);
int stringToInt(const char *input, int *out);
int checkInputInt(int *value);
void runBank(Queue *q, Stack *s);
void addCustomer(Queue *q);
void serveCustomer(Queue *q, Stack *s);
void showQueue(Queue *q);
void showHistory(Stack *s);

#endif