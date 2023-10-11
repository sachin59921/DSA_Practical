#ifndef STACK_H
#define STACK_H

// Structure for the stack
struct Stack {
    int capacity;
    int top;
    int* array;
};

typedef struct Stack Stack;

// Function prototypes for stack operations
Stack* createStack(int capacity);
int isFull(Stack* stack);
int isEmpty(Stack* stack);
void push(Stack* stack, int item);
int pop(Stack* stack);
int peek(Stack* stack);
void displayStack(Stack* stack);
void stackOperations();

#endif
