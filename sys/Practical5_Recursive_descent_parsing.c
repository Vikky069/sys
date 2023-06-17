
// grammar used.
// expression -> term { ('+' | '-') term }
// term -> factor { ('*' | '/') factor }
// factor -> digit | '(' expression ')'

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Function prototypes
int evaluateExpression();
int evaluateTerm();
int evaluateFactor();

char input[100];
int position;

int evaluateExpression() {
    int result = evaluateTerm();

    while (input[position] == '+' || input[position] == '-') {
        char operator = input[position];
        position++;

        int operand = evaluateTerm();

        if (operator == '+') {
            result += operand;
        } else {
            result -= operand;
        }
    }

    return result;
}

int evaluateTerm() {
    int result = evaluateFactor();

    while (input[position] == '*' || input[position] == '/') {
        char operator = input[position];
        position++;

        int operand = evaluateFactor();

        if (operator == '*') {
            result *= operand;
        } else {
            if (operand == 0) {
                printf("Error: Division by zero.\n");
                exit(1);
            }
            result /= operand;
        }
    }

    return result;
}

int evaluateFactor() {
    int result = 0;

    if (isdigit(input[position])) {
        while (isdigit(input[position])) {
            result = result * 10 + (input[position] - '0');
            position++;
        }
    } else if (input[position] == '(') {
        position++;
        result = evaluateExpression();

        if (input[position] == ')') {
            position++;
        } else {
            printf("Error: Missing closing parenthesis.\n");
            exit(1);
        }
    } else {
        printf("Error: Invalid expression.\n");
        exit(1);
    }

    return result;
}

int main() {
    printf("Enter an arithmetic expression: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    position = 0;
    int result = evaluateExpression();

    printf("Result: %d\n", result);

    return 0;
}
