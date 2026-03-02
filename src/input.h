#ifndef INPUT_H
#define INPUT_H

#define BUFFER_SIZE 4096

#include <stdbool.h>

void removeNewLine(char *input);
bool parseMoney(char *input, long *out);
bool parseInt(char *input, int *out);
bool parseFloat(char *input, float *out);
void readMoney(const char *prompt, long *output);
void readInt(const char *prompt, int *output);
void readFloat(const char *prompt, float *output);
void readStr(const char *prompt, char *output);
bool checkInputStr(char *string);

#endif