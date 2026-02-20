#include "queue.h"
#include "stack.h"
#include "bank.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Choice readOption(void){
    int userOption;
    checkInputInt(&userOption);
    if (userOption >= OPTION5 && userOption <= OPTION4){
        return (Choice)userOption;
    }else{
        printf("\nInvalid input!\n");
        return NULL;
    }
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
        return 0;
    }  
}

void runBank(void){//Run the bank interface
    int currentOption = NULL;

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
                break;
            case OPTION2://serve next customer
                break;
            case OPTION3://show waiting queue
                break;
            case OPTION4://show service history
                break;
        }
    }while(currentOption != OPTION5);
}

void addCustomer();
void serveCustomer();
void showQueue(Queue *q);
void showHistory(Stack *s);