#include "queue.h"
#include "stack.h"
#include "bank.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> 
#include <limits.h>
#include <ctype.h>

int main(){
    Queue queue;
    Stack stack;
    initQueue(&queue);
    initStack(&stack);

    runBank(&queue, &stack);

    freeQueue(&queue);
    freeStack(&stack);
    return 0;
}