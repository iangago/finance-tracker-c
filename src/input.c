#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <float.h>

void removeNewLine(char *input){
    for(int i = 0; i != '\0'; i++){
        if(input[i] == '\n'){
            input[i] = '\0';
            break;
        }
    }
}

bool parseInt(char *input, int *out){
    if (input == NULL || out == NULL) {//checks if there isnt anything on the input
        return false;
    }   
    
    char *endptr;
    errno = 0;
    long value = strtol(input, &endptr, 10);

    if(endptr == input){//Checks if the string starts with a number
        return false;
    }

    if(errno == ERANGE){//Checks overflow
        return false;
    }

    while(isspace((unsigned char)*endptr)){//gets rid of the \n
        endptr++;
    }

    if(*endptr != '\0'){//checks if there is nothing after the numbers
        return false;
    }

    if(value < INT_MIN || value > INT_MAX){//Checks if the conversion to int is possible
        return false;
    }

    *out = (int)value;//converts it to an int 
    return true;
}

bool parseFloat(char *input, float *out){
    if (input == NULL || out == NULL) {//checks if there isnt anything on the input
        return false;
    }   
    
    char *endptr;
    errno = 0;
    float value = strtof(input, &endptr);

    if(endptr == input){//Checks if the string starts with a number
        return false;
    }

    if(errno == ERANGE){//Checks overflow
        return false;
    }

    if (!isfinite(value)) {
        return false;
    }   

    while(isspace((unsigned char)*endptr)){//skip trailing white space
        endptr++;
    }

    if(*endptr != '\0'){//checks if there is nothing after the numbers
        return false;
    }

    *out = value;//passes the value
    return true;
}

void readFloat(const char *prompt, float *output){
    bool valid = false;
    char buffer[BUFFER_SIZE];

    do{
        printf("%s", prompt);

        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
            printf("Input error.\n");
            return;
        }

        valid = parseFloat(buffer, output);

        if(!valid) printf("\nInvalid input.\n");
    }while(!valid);
}

void readInt(const char *prompt, int *output){
    bool valid = false;
    char buffer[BUFFER_SIZE];

    do{
        printf("%s", prompt);

        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
            printf("Input error.\n");
            return;
        }

        valid = parseInt(buffer, output);

        if(!valid) printf("\nInvalid input.\n");
    }while(!valid);
}

void readStr(const char *prompt, char *output){
    bool valid = false;
    char buffer[BUFFER_SIZE];

    do{
        printf("%s", prompt);

        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
            printf("Input error.\n");
            return;
        }

        valid = checkInputStr(buffer);

        if(!valid) printf("\nInvalid input.\n");
    }while(!valid);
    
    strncpy(output, buffer, BUFFER_SIZE - 1);
    output[BUFFER_SIZE - 1] = '\0';
}

bool checkInputStr(char *string){
    if (!string) return false;//checks if its NULL

    string[strcspn(string, "\n")] = '\0';//removes the \n

    if(string[0] == '\0') return false; //checks if its empty

    for(int i = 0; string[i] != '\0'; i++){//iterates trough the string and sees if it has any integers
        if(isdigit((unsigned char)string[i])) return false;

        if(!isalpha((unsigned char)string[i])) return false;
    }

    return true;
}