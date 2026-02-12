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
int isEmpty(Queue *q);
void enqueue(Queue *q, char *name);
char dequeue(Queue *q);
void freeQueue(Queue *q);

#endif