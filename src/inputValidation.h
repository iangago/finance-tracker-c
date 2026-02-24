#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#define BUFFER_SIZE 4096

#include <stdbool.h>

bool parseInt(char *input, int *out);
void readInt(const char *prompt, int *result);
void readStr(const char *prompt, char *output);
bool checkInputStr(char *string);

#endif