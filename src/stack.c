#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void initStack(Stack *s){//initializing stack
    s->top = NULL;
}

int isEmpty(Stack *s){//checking if the list is empty
    return s->top == NULL;
}

void push(Stack *s, char newName[]){//Adding node
    Node *newNode;//creating new node
    newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    } 
    newNode->name = malloc(strlen(newName) + 1); // +1 para o '\0'
    if(newNode->name == NULL){
        printf("Memory allocation failed\n");
        free(newNode);
        exit(1);
    }
    strcpy(newNode->name, newName);

    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack *s){
    if(isEmpty(s)){//if the list is empty returns 0
        return 0;
    }//if its empty
    Node *removedNode;
    removedNode = s->top;

    s->top = s->top->next;
    free(removedNode->name);
    free(removedNode);
    return 1;

}

char * peek(Stack *s){//See top
    if(!isEmpty(s)){
        return s->top->name;
    }
    return NULL;
}

void freeStack(Stack *s){//Delete stack
    while(!isEmpty(s)){
        pop(s);
    }
}