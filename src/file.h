#ifndef FILE_H
#define FILE_H

#include "account.h"
#include <stdbool.h>

bool loadAccount(Account *ac, const char *filename);
bool saveAccount(const Account *ac, const char *filename);
Transaction *parseTransactionLine(char *line);

#endif