# Bank Simulator (C)

## Description
A simple bank queue simulator written in C.
It uses the queue to manage customers and a stack to store service history.

This project was built to practice:
- Control flow
- Strutcts
- Basic program structure in C
- Queues
- Stacks
- Git
- Basic project structure
- Dynamic memory management (malloc/free)
- Modular programming with header files

## Project Structure
bank-simulator/
    src/
        main.c
        bank.c
        bank.h
        queue.c
        queue.h
        stack.c
        stack.h
    .gitignore
    README.md

- main.c       -> program entry point
- bank.c       -> main system logic
- queue.c/.h   -> queue implementation
- stack.c/.h   -> stack implementation

## .gitignore
Ignore compiled artifacts like .exe files

## Features
- Add customers to the queue
- Serve the next customer
- Display waiting queue
- Display service history
- Input validation for user options

## How it works
- The waiting line is implemented using a Queue (FIFO)
- The service history is implemented using a Stack (LIFO)
- User input is validated before processing

## Compilation
gcc main.c queue.c stack.c bank.c -o main

## Run
./main

## Future Improvements
- Add a graphical interface
- Save history to a file
- Improve user input handling

## Contributing
Feel free to open issues or PRs if you want to help improve this project 😊

## Author
Ian Gago Mendes