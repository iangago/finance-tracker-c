#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void initQueue(Queue *q){//initializing queue
    q->front = NULL;
    q->rear = NULL;
}

int isEmptyQueue(Queue *q){//checking if the list is empty
    return q->front == NULL;
}

void enqueue(Queue *q, char newName[]){//adding a node to the queue
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
    newNode->next = NULL;

    if(isEmptyQueue(q)){//if the list is empty
        q->front = newNode;
        q->rear = newNode;
    }else{//if the list is not empty
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue *q){//removing a node of the queue
    if(isEmptyQueue(q)){//if the list is empty returns 0
        return 0;
    }//if its not empty
    Node *removedNode;
    removedNode = q->front;

    q->front = q->front->next;
    free(removedNode->name);
    free(removedNode);
    if(q->front == NULL){//checks if there was only one value on the list
        q->rear = NULL;
    }
    return 1;
}


void freeQueue(Queue *q){//Delete Queue
    while(!isEmptyQueue(q)){
        dequeue(q);
    }
}
