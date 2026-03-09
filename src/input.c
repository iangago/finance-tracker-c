#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <float.h>

void removeNewLine(char *str){
    str[strcspn(str, "\n")] = '\0';
}

bool parseMoney(char *input, long *out){
    //checks if there isnt anything on the input
    if (input == NULL || out == NULL) {
        return false;
    }   

    //skip white space
    while (isspace((unsigned char)*input)) input++;

    //checks if the number is negative
    if(*input == '-') return false;

    char *endptr;
    errno = 0;
    long dollars = strtol(input, &endptr, 10);        
    int cents = 0;
    long amount;

    //Checks if the string starts with a number
    if(endptr == input){
        return false;
    }

    //Checks overflow
    if(errno == ERANGE){
            return false;
    }

    //skip white space
    while (isspace((unsigned char)*endptr)) endptr++;

    //if there is no point it just return the amount in cents
    if(*endptr == '\0'){
        *out = dollars * 100;
        return true;
    }

    //checks if there is a point
    if(*endptr == '.'){

        int digits = 0;
        endptr++;
        
        while(isdigit((unsigned char)*endptr)){
            cents = cents * 10 + (*endptr - '0');
            digits++;
            endptr++;
        }

        //no digits after the point
        if(digits  == 0) return false;

        //more than 2 digits
        if (digits > 2) return false;

        //normalize if only one digit
        if(digits == 1){
            cents *= 10;
        }
    }

    //gets rid of the \n
    while(isspace((unsigned char)*endptr)){
        endptr++;
    }

    //checks if there is nothing after the numbers
    if(*endptr != '\0'){
        return false;
    }

    //finalize the 
    amount = dollars * 100 + cents;

    *out = amount;
    return true;
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

void readMoney(const char *prompt, long *output){
    bool valid = false;
    char buffer[BUFFER_SIZE];

    do{
        printf("%s", prompt);

        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
            printf("Input error.\n");
            return;
        }

        valid = parseMoney(buffer, output);

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
    
    removeNewLine(buffer);
    strncpy(output, buffer, BUFFER_SIZE - 1);
    output[BUFFER_SIZE - 1] = '\0';
}

bool checkInputStr(char *string){
    if (!string) return false;//checks if its NULL

    string[strcspn(string, "\n")] = '\0';//removes the \n

    if(string[0] == '\0') return false; //checks if its empty

    for(int i = 0; string[i] != '\0'; i++){//iterates trough the string and sees if it has any integers
        if(isdigit((unsigned char)string[i])) return false;

        if(!isalpha((unsigned char)string[i])){
            if(string[i] != ' '){
                return false;  
            }
        }
    }

    return true;
}