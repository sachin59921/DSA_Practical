#include <stdio.h>
#include "BracketMatching.h"
#include "../Stack/Stack.h"

// Function to perform bracket matching
void bracketMatching() {
    // Prompt the user to enter an expression with brackets
    char expression[100];
    printf("Enter an expression with brackets: ");
    scanf("%s", expression);

    Stack* stack = createStack(100);

    int i = 0;
    while (expression[i] != '\0') {
        char bracket = expression[i];
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            push(stack, bracket);
        } else if (bracket == ')' || bracket == ']' || bracket == '}') {
            if (isEmpty(stack)) {
                printf("Unmatched closing bracket: %c\n", bracket);
                return;
            }
            char topBracket = pop(stack);
            if ((bracket == ')' && topBracket != '(') ||
                (bracket == ']' && topBracket != '[') ||
                (bracket == '}' && topBracket != '{')) {
                printf("Mismatched brackets: %c and %c\n", topBracket, bracket);
                return;
            }
        }
        i++;
    }

    if (!isEmpty(stack)) {
        printf("Unmatched opening bracket(s)\n");
        return;
    }

    printf("Brackets are balanced in the expression.\n");
}