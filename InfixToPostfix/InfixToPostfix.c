#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "InfixToPostfix.h"
#include "../Stack/stack.h"


// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
    }
// Function to perform infix-to-postfix conversion
void infixToPostfix() {
    // Prompt the user to enter an infix expression
    char infix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    char postfix[100];  // To store the postfix expression
    int i, j;
    i = j = 0;
    Stack* stack = createStack(100);

    while (infix[i] != '\0') {
        char token = infix[i];
        if (isalnum(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(stack, token);
        } else if (token == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) == '(') {
                pop(stack);
            } else {
                printf("Invalid expression: Mismatched parentheses\n");
                return;
            }
        } else {
            while (!isEmpty(stack) && getPrecedence(token) <= getPrecedence(peek(stack))) {
                postfix[j++] = pop(stack);
            }
            push(stack, token);
        }
        i++;
    }

    while (!isEmpty(stack)) {
        if (peek(stack) == '(') {
            printf("Invalid expression: Mismatched parentheses\n");
            return;
        }
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
}
