# Finance Tracker (C)

## Description

A terminal-based personal finance tracker written in C.

The program allows a user to create an account, record income and expenses, and view a summary of their financial activity. All data is saved to a file so it can be loaded again when the program starts.

This project was built as a learning project to practice core concepts of the C programming language and basic software architecture.

---

## Features

* Create and load a user account
* Record income and expenses
* Store transaction history
* Display financial summaries
* Save and load data from a text file
* Terminal-based user interface
* Input validation for user input

---

## Data Structure Design

Transactions are stored using a **singly linked list**.

Each `Account` structure contains a pointer to the first transaction (`head`).
Each transaction contains a pointer to the next transaction.

Structure concept:

```
Account
  |
  └── head → Transaction → Transaction → Transaction → NULL
```

Each transaction node contains:

* value
* type (income or expense)
* description
* date
* pointer to the next transaction

This allows transactions to be dynamically added during program execution.

---

## How It Works

1. The program starts and attempts to load account data from a file.
2. If the file exists, the account information and transaction history are loaded.
3. The user can:

   * add income
   * add expenses
   * view transaction history
   * view a financial summary
4. While the program is running, all account data is saved back to the file if user chooses the terminal option accordaccordingly.

---

## Project Structure

```
finance-tracker/
│
├── src/
│   ├── main.c
│   ├── account.c
│   ├── account.h
│   ├── transaction.c
│   ├── transaction.h
│   ├── file.c
│   ├── file.h
│   ├── input.c
│   ├── input.h
│   ├── terminal.c
│   ├── terminal.h
│   └── account.txt
│
├── .gitignore
└── README.md
```

### Module Responsibilities

**main.c**
Program entry point and main program loop.

**account.c / account.h**
Defines the `Account` structure and manages account operations.

**transaction.c / transaction.h**
Defines the `Transaction` structure and handles transaction creation.

**file.c / file.h**
Handles saving and loading account data from files.

**input.c / input.h**
Handles user input and validation.

**terminal.c / terminal.h**
Responsible for the terminal interface and menu display.

---

## Example Usage

Example of the program running in the terminal:

```
====================================
        FINANCE TRACKER
====================================

Account: Ian
ID: 023
Balance: R$ 2450.00

----------------------------------------
1) Add Income
2) Add Expense
3) View Transactions
4) View Summary
5) Save
6) Exit
----------------------------------------

Select an option: 1

---- ADD INCOME ----

Amount: 1500
Description: freelance work

Income added successfully.

New Balance: R$ 3950.00

Press ENTER to continue...
```

---

## File Format

Account data is stored in a text file with the following structure:

```
username
account_id
balance
value;type;description;date
value;type;description;date
```

Example:

```
Ian
023
250000
100000;1;salary;01032026
5000;0;food;02032026
```

---

## Compilation

Compile the project using GCC:

```
gcc main.c account.c transaction.c file.c input.c terminal.c -o finance
```

---

## Run

```
./finance
```

---

## What I Learned

While building this project I practiced several important programming concepts:

* Designing and working with **structs in C**
* Implementing a **singly linked list**
* Managing dynamic memory using `malloc` and `free`
* Writing modular programs using **header files and multiple source files**
* Handling **file input/output** for persistent data storage
* Parsing structured text data from files
* Building a simple **terminal-based interface**
* Debugging memory and input-related issues in C

---

## Future Improvements

* Expense categories
* Monthly financial statistics
* Transaction filtering
* Improved terminal interface
* Binary file storage
* Graphical interface

---

## Author

Ian Gago Mendes
