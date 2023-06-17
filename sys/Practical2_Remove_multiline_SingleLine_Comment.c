#include <stdio.h>

void removeMultilineComments(char* sourceCode) {
    int insideComment = 0;
    char* sourcePtr = sourceCode;
    char* destPtr = sourceCode;

    while (*sourcePtr != '\0') {
        if (!insideComment && *sourcePtr == '/' && *(sourcePtr + 1) == '*') {
            insideComment = 1;
            sourcePtr += 2;
        } else if (insideComment && *sourcePtr == '*' && *(sourcePtr + 1) == '/') {
            insideComment = 0;
            sourcePtr += 2;
        } else if (!insideComment) {
            *destPtr++ = *sourcePtr++;
        } else {
            sourcePtr++;
        }
    }

    *destPtr = '\0';
}

void removeSingleLineComments(char* sourceCode) {
    char* sourcePtr = sourceCode;
    char* destPtr = sourceCode;

    while (*sourcePtr != '\0') {
        if (*sourcePtr == '/' && *(sourcePtr + 1) == '/') {
            while (*sourcePtr != '\n')
                sourcePtr++;
        } else {
            *destPtr++ = *sourcePtr++;
        }
    }

    *destPtr = '\0';
}

void removeWhitespace(char* sourceCode) {
    char* sourcePtr = sourceCode;
    char* destPtr = sourceCode;

    while (*sourcePtr != '\0') {
        if (*sourcePtr == ' ' || *sourcePtr == '\t' || *sourcePtr == '\n' || *sourcePtr == '\r') {
            sourcePtr++;
        } else {
            *destPtr++ = *sourcePtr++;
        }
    }

    *destPtr = '\0';
}

int main() {
    char sourceCode[] = "/* This is a multiline comment */\n"
                        "int main() {\n"
                        "    // This is a single-line comment\n"
                        "    int a = 10; // Initializing a variable\n"
                        "    \n"
                        "    /*\n"
                        "    This is a\n"
                        "    multiline comment\n"
                        "    */\n"
                        "    \n"
                        "    printf(\"Hello, World!\\n\");\n"
                        "    return 0;\n"
                        "}\n";

    printf("Before removing comments and whitespace:\n%s\n", sourceCode);

    removeMultilineComments(sourceCode);
    removeSingleLineComments(sourceCode);
    removeWhitespace(sourceCode);

    printf("\nAfter removing comments and whitespace:\n%s\n", sourceCode);

    return 0;
}
