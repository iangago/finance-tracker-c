#ifndef TERMINAL_H
#define TERMINAL_H

struct Account;

typedef enum{
    OptionExit = 0, Option1 = 1, Option2 = 2, Option3 = 3, Option4 = 4, Option5 = 5, Option6 = 6,
}Choice;

void waitEnter(void);
void runTerminal(struct Account *ac);

#endif