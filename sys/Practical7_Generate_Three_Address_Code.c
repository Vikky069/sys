#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tempCount = 0;

char *generateTemp()
{
    char *temp = (char *)malloc(4 * sizeof(char));
    sprintf(temp, "t%d", tempCount++);
    return temp;
}

void generateThreeAddressCode(char *expression)
{
    int len = strlen(expression);
    char *result = generateTemp();
    char *operand1 = (char *)malloc(len * sizeof(char));
    char *operand2 = (char *)malloc(len * sizeof(char));

    int i = 0, j = 0;
    while (expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '/')
    {
        operand1[j++] = expression[i++];
    }
    operand1[j] = '\0';

    char operator= expression[i++];

    j = 0;
    while (i < len)
    {
        operand2[j++] = expression[i++];
    }
    operand2[j] = '\0';

    printf("%s = %s %c %s\n", result, operand1, operator, operand2);

    free(result);
    free(operand1);
    free(operand2);
}

int main()
{
    char expression[100];

    printf("Enter the arithmetic expression: ");
    fgets(expression, sizeof(expression), stdin);

    // Remove newline character
    expression[strcspn(expression, "\n")] = '\0';

    generateThreeAddressCode(expression);

    return 0;
}
