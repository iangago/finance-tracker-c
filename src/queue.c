#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void initQueue(Queue *q){
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Queue *q){
    if(q->front == NULL){
        return 1;
    }else{
        return 0;
    }
}
