#include "file.h"
#include "account.h"
#include "transaction.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <file.h>
#include <stdbool.h>

bool loadAccount(Account *ac, const char *filename){
    FILE *mainFile;

    mainFile = fopen(filename, "r");

    //sees if there is no file
    if(mainFile == NULL){
        initAccount(ac);
        return true;
    }
    
    //if there is a file
    char buffer[BUFFER_SIZE];
    int line = 1;

    //while it doesnt reach the end of file
    while(fgets(buffer, BUFFER_SIZE, mainFile) != NULL){
        //name
        if(line == 1){
            removeNewLine(buffer);

            ac->name = malloc(strlen(buffer) + 1);
            if(ac->name == NULL){
                printf("Memory allocation failed\n");
                exit(1);
            } 

            strcpy(ac->name, buffer);

        //id
        }else if(line == 2){
            removeNewLine(buffer);
            parseInt(buffer, &ac->id);

        //balance
        }else if(line == 3){
            removeNewLine(buffer);
            parseInt(buffer, &ac->balance);

        //trasactions
        }else{
            removeNewLine(buffer);
            Transaction *newTransaction = parseTransactionLine(buffer);
            if(newTransaction == NULL){
                printf("Error in creating the transaction.\n");
                fclose(mainFile);
                return false;
            }

            insertTransaction(ac, newTransaction);
        }
        line++;
    }

    fclose(mainFile);
    return true;
}

bool saveAccount(const Account *ac, const char *filename){
    FILE *mainFile;

    mainFile = fopen(filename, "w");

    if (mainFile == NULL) {
        return false;
    }
    
    //name
    fprintf(mainFile, "%s\n", ac->name);

    //id
    fprintf(mainFile, "%d\n", ac->id);

    //balance
    fprintf(mainFile, "%ld\n", ac->balance);

    //transactions
    Transaction *currentT = ac->head;
    while(currentT != NULL){
        //value
        fprintf(mainFile, "%ld;", currentT->value);

        //type
        fprintf(mainFile, "%d;", currentT->type);

        //description
        fprintf(mainFile, "%s;", currentT->description);

        //date
        fprintf(mainFile, "%d\n", currentT->date);

        currentT = currentT->next;
    }

    fclose(mainFile);
    return true;
}

Transaction *parseTransactionLine(char *line){
    //10000;1;food;04032026
    char *fields[4];   

    fields[0] = strtok(line, ";");
    fields[1] = strtok(NULL, ";");
    fields[2] = strtok(NULL, ";");
    fields[3] = strtok(NULL, ";");

    if (!fields[0] || !fields[1] || !fields[2] || !fields[3]) {
        return NULL;
    }
    
    return createTransaction(atol(fields[0]), atoi(fields[1]), fields[2], atoi(fields[3]));
}