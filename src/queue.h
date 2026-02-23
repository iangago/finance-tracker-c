#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node{
    char *name;
    struct Node *next;
}Node;

typedef struct{
    Node *front;
    Node *rear;
}Queue;

// Public Functions
void initQueue(Queue *q);
int isEmptyQueue(Queue *q);
void enqueue(Queue *q, char newName[]);
int dequeue(Queue *q);
void freeQueue(Queue *q);

#endif