#include "input.h"
#include "account.h"
#include "transaction.h"
#include "terminal.h"
#include "file.h"
#include <stdio.h>
#include <stdlib.h>

void runTerminal(struct Account *ac){
    int currentChoice;
    char enter;

    do{
        do{
            //print terminal
            printf("\n========================================\n        PERSONAL FINANCE TRACKER\n========================================\n");
            if(ac->id < 1 || ac->name[0] == '\0'){
                printf("\nNo account found.\n");
            }else{
                printf("\nAccount: %s\nID: %03d\nCurrent Balance: R$ %ld.%02ld\n", ac->name, ac->id, ac->balance / 100, ac->balance % 100);
            }
            printf("\n----------------------------------------\n1) Add Account\n2) Add Income\n3) Add Expense\n4) View Transaction History\n5) View Summary\n6) Save\n0) Exit\n----------------------------------------\n");
            readInt("\nSelect an option:", &currentChoice);
            //numbers not on the selected range
            if(currentChoice < OptionExit || currentChoice > Option6) printf("\nInvalid input.\n");
                
        }while(currentChoice < OptionExit || currentChoice > Option6);
        switch(currentChoice){
            //Add Account
            case Option1:
                if(ac->id < 1 || ac->name[0] == '\0'){
                    createAccountUI(ac);
                }else{
                    printf("\nThere is already an account.\n");
                }
                break;
            //Add Income
            case Option2:
                if(ac->id < 1 || ac->name[0] == '\0'){
                    printf("\nCreate an account to continue.\n");
                }else{
                    printf("\n---- ADD INCOME ----\n");

                    if(!addTransactionUI(ac, deposit)){
                        printf("\nError making the transaction.");
                    }else{
                        printf("\nIncome added successfully.\n\nNew Balance: R$ %ld.%02ld", ac->balance / 100, ac->balance % 100);
                    }

                    waitEnter();
                }
                break;
            //Add Expense
            case Option3:
                if(ac->id < 1 || ac->name[0] == '\0'){
                    printf("\nCreate an account to continue.\n");
                }else{
                    printf("\n---- ADD EXPENSE ----\n");

                    if(!addTransactionUI(ac, withdraw)){
                        printf("\nError making the transaction.");
                    }else{
                        printf("\nExpense added successfully.\n\nNew Balance: R$ %ld.%02ld", ac->balance / 100, ac->balance % 100);
                    }

                    waitEnter();
                }
                break;
            //View Transaction History
            case Option4:
                if(ac->head == NULL){
                    printf("\nNo transactions yet.\n");
                }else{
                    do{
                        printf("\n----------- TRANSACTION HISTORY -----------\n");
                        printf("\n1) Show all\n2) Show Income\n3) Show Expenses\n\n--------------------------------------------\n");
                        readInt("\nSelect an option:", &currentChoice);
                    }while(currentChoice > 3 || currentChoice < 1);

                    printf("\n#   TYPE      AMOUNT      DESCRIPTION\n--------------------------------------------\n");

                    int total = 0;
                    Transaction *currentT;
                    currentT = ac->head;

                    while(currentT != NULL){
                        if(currentChoice == 2 && currentT->type == withdraw){
                            currentT = currentT->next;
                            continue;
                        }else if(currentChoice == 3 && currentT->type == deposit){
                            currentT = currentT->next;
                            continue;
                        }
                        total++;
                        //number of transaction
                        printf("%d", total);

                        //type of the transaction
                        if(currentT->type == deposit){
                            printf("   INCOME    +");
                        }else{
                            printf("   EXPENSE   -");
                        }

                        //value
                        printf("%ld.%02ld", currentT->value / 100, currentT->value % 100);

                        //description
                        printf("      %s\n", currentT->description);

                        currentT = currentT->next;
                       
                    }

                    printf("\n--------------------------------------------\nTotal Transactions: %d", total);

                    waitEnter();
                }

                break;
            //View Summary
            case Option5:
                long totalI = 0;
                long totalE = 0;
                if(ac->head == NULL){
                    printf("\nNo transactions yet.\n");
                }else{
                    Transaction *currentT;
                    currentT = ac->head;
                    while(currentT != NULL){
                        if(currentT->type == deposit){
                            totalI += currentT->value;
                        }else{
                            totalE += currentT->value;
                        }

                        currentT = currentT->next;
                    }
                    double ratio = ((double) totalE / totalI) * 100;

                    printf("\n-------------- SUMMARY ----------------\n");
                    printf("\nTotal Income:     R$ %ld.%02ld", totalI / 100, totalI % 100);
                    printf("\nTotal Expenses:   R$ %ld.%02ld", totalE / 100, totalE % 100);
                    printf("\nNet Balance:      R$ %ld.%02ld", ac->balance / 100, ac->balance % 100);
                    printf("\nExpense ratio:       %.0f%%", ratio);
                    printf("\n\n---------------------------------------");

                    waitEnter();
                }
                
                break;
            //Save
            case Option6:
                printf("\nSaving account data...\n");

                if(saveAccount(ac, "account.txt")){
                    printf("\nData saved successfully to:\n");
                    printf("account.txt");
                }else{
                    printf("\nFailed to save data.\n");
                }

                waitEnter();
                break;
        }

    }while(currentChoice != OptionExit);
}

void waitEnter(){
    char buffer[8];
    printf("\n\nPress ENTER to continue...");
    fgets(buffer, sizeof(buffer), stdin);
}