#include <stdio.h>
#include "EvaluatePostfix.h"
#include "../Stack/stack.h"

// Function to evaluate a postfix expression
void evaluatePostfix() {
    // Prompt the user to enter a postfix expression
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    Stack* stack = createStack(100);

    int i = 0;
    while (postfix[i] != '\0') {
        char token = postfix[i];
        if (isdigit(token)) {
            push(stack, token - '0'); // Convert character to integer and push onto stack
        } else {
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            int result;

            switch (token) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero is not allowed.\n");
                        return;
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator: %c\n", token);
                    return;
            }

            push(stack, result);
        }
        i++;
    }

    int finalResult = pop(stack);

    if (!isEmpty(stack)) {
        printf("Invalid postfix expression\n");
        return;
    }

    printf("Result of the postfix expression: %d\n", finalResult);
}