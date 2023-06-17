#include <stdio.h>
#include <string.h>

#define MAX_EXPR_LENGTH 100

int main() {
    char expression[MAX_EXPR_LENGTH];
    char opcode[10];
    char operand1[10];
    char operand2[10];
    char result[10];

    printf("Enter an arithmetic expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = '\0';

    int tempCount = 1;
    int i = 0;

    printf("\nGenerated Three Address Code:\n");

    while (expression[i] != '\0') {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            opcode[0] = expression[i];
            opcode[1] = '\0';

            operand1[0] = expression[i - 1];
            operand1[1] = '\0';

            operand2[0] = expression[i + 1];
            operand2[1] = '\0';

            result[0] = 't';
            result[1] = tempCount + '0';
            result[2] = '\0';

            printf("%s %s %s %s\n", opcode, operand1, operand2, result);

            tempCount++;
        }

        i++;
    }

    result[0] = expression[i - 1];
    result[1] = '\0';

    printf("= %s\n", result);

    return 0;
}
