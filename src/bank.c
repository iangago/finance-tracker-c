#include "queue.h"
#include "stack.h"
#include "bank.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> 
#include <limits.h>
#include <ctype.h>

Choice readOption(void){
    int userOption = -1;
    checkInputInt(&userOption);

    if (userOption >= OPTION5 && userOption <= OPTION4){
        return (Choice)userOption;
    }

    printf("\nInvalid input!\n");
    return -1;
}

int stringToInt(const char *input, int *out){
    char *end;
    errno = 0;
    long value = strtol(input, &end, 10);

    if(end == input){//Checks if the string starts with a number
        return 0;
    }
    if(*end != '\0'){//checks if there is nothing after the numbers
        return 0;
    }
    if(errno == ERANGE){//Checks overflow
        return 0;
    }
    if(value < INT_MIN || value > INT_MAX){//Checks if the conversion to int is possible
        return 0;
    }
    *out = (int)value;//converts it to an int 
    return 1;
}

int checkInputInt(int *value){
    char input[50];

    //Read input as a string
    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = '\0';
    if(stringToInt(input, value) != 1){
        *value = 5;
        return 0;
    }  
}

void runBank(Queue *q, Stack *s){//Run the bank interface
    int currentOption = 0;

    do{//Loops while the user doesnt select exit
        do{//Loops while the user doesnt select a number from 0 - 4
            printf("\n==== BANK SIMULATOR ====\n");
            printf("\n1 - Add customer\n");
            printf("2 - Serve next customer\n");
            printf("3 - Show waiting queue\n");
            printf("4 - Show service history\n");
            printf("0 - Exit\n");
            printf("\nChoose an option: ");
            currentOption = readOption();//Gets user input and filters it trough the function
        }while(currentOption < OPTION5 || currentOption > OPTION4);
        switch(currentOption){
            case OPTION1://add customer
                addCustomer(q);
                break;
            case OPTION2://serve next customer
                serveCustomer(q, s);
                break;
            case OPTION3://show waiting queue
                showQueue(q);
                break;
            case OPTION4://show service history
                showHistory(s);
                break;
        }
    }while(currentOption != OPTION5);
    printf("\nClosing bank system...\n");
    printf("Goodbye!");
}

void addCustomer(Queue *q){
    char name[50];
    int hasDigit = 1;

    do{
        printf("\nEnter the customer's name: ");//Prompts for the name              
        //Read input as a string
        fgets(name, 50, stdin);
        name[strcspn(name, "\n")] = '\0';
        for(int i = 0; name[i]; i++){//iterates trough the string and sees if it has any integers
            if(isdigit((unsigned char)name[i])){
                printf("\nInvalid input!\n");
                break;
            }else{
                if(i == strlen(name) - 1){//if it doesnt it breaks out of the loops
                    hasDigit = 0;
                    break;
                }
            }
        }
    }while(hasDigit == 1);
    enqueue(q, name);
    printf("\nCustomer %s added to queue.\n", name);
}

void serveCustomer(Queue *q, Stack *s){
    if(isEmptyQueue(q)){
        printf("\nNo customers in queue.\n");
    }else{
        printf("\nServing customer: %s\n", q->front->name);
        push(s, q->front->name);
        dequeue(q);
    }
}

void showQueue(Queue *q){
    int i = 1;
    Node *currentNode;
    currentNode = q->front;

    if(isEmptyQueue(q)){
        printf("\nQueue is empty.\n");
    }else{
        printf("\nWaiting queue:\n");
        do{
            printf("%d. %s\n", i, currentNode->name);
            i++;
            currentNode = currentNode->next;
            if(currentNode == NULL){
                i = 0;
            }
        }while(i != 0);
    }
}

void showHistory(Stack *s){
    int i = 1;
    Node *currentNode;
    currentNode = s->top;
    
    if(isEmptyStack(s)){
        printf("\nHistory is empty.\n");
    }else{
        printf("\nService history:\n");
        do{
            printf("%d. %s\n", i, currentNode->name);
            i++;
            currentNode = currentNode->next;
            if(currentNode == NULL){
                i = 0;
            }
        }while(i != 0);
    }
}