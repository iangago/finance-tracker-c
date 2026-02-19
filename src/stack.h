#ifndef STACK_H
#define STACK_H

typedef struct Node{
    char *name;
    struct Node *next;
}Node;

typedef struct{
    Node *top;
}Stack;

// Public Functions
void initStack(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, char newName[]);
int pop(Stack *s);
char * peek(Stack *s);
void freeStack(Stack *s);

#endif