#include "input.h"
#include "account.h"
#include "transaction.h"
#include "terminal.h"
#include "file.h"
#include "terminal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(void){
    Account mainAccount;
    
    if(!loadAccount(&mainAccount, "account.txt")){
        printf("\nError loading the account.\n");
    }

    runTerminal(&mainAccount);

    freeTransactions(&mainAccount);
    freeAccount(&mainAccount);
    return 0;
}