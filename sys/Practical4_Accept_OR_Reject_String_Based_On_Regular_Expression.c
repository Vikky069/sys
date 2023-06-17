#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// for regular expression a*b
bool matchesRegularExpression1(const char* str) {
    const char* ptr = str;

    // Check for zero or more 'a' characters
    while (*ptr == 'a') {
        ptr++;
    }

    // Check for a single 'b' character at the end of the string
    if (*ptr == 'b' && *(ptr + 1) == '\0') {
        return true;
    }

    return false;
}
// for regular expression a+ b* a
bool matchesRegularExpression2(const char* str) {
    const char* ptr = str;

    if(*ptr != 'a') return false;

    while(*ptr == 'a') ptr++;

    while(*ptr == 'b') ptr++;

    if(*ptr != 'a') return false;

    return true;
}

int main() {
    char input[100];

    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';
    // if you want to use second regular expression change use second expression.
    if (matchesRegularExpression1(input)) {
        printf("Input string matches the regular expression.\n");
    } else {
        printf("Input string does not match the regular expression.\n");
    }

    return 0;
}



