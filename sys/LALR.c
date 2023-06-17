#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Constants for terminals and non-terminals
#define TERMINALS_COUNT 3
#define NON_TERMINALS_COUNT 3

enum Terminals {
    TERMINAL_ID,
    TERMINAL_PLUS,
    TERMINAL_EOF
};

enum NonTerminals {
    NON_TERMINAL_E,
    NON_TERMINAL_T,
    NON_TERMINAL_F
};

// Parse table entry structure
struct ParseTableEntry {
    bool isAction;
    union {
        int state;
        void (*action)();
    };
};

// Parse table
struct ParseTableEntry parseTable[NON_TERMINALS_COUNT + 1][TERMINALS_COUNT + 1] = {
    {{true, {0}}, {true, {0}}, {true, {0}}, {true, {0}}},
    {{true, {0}}, {true, {0}}, {true, {0}}, {true, {0}}},
    {{true, {0}}, {true, {0}}, {true, {0}}, {true, {0}}},
    {{true, {0}}, {true, {0}}, {true, {0}}, {true, {0}}}
};

// Stack structure
struct Stack {
    int state;
    int symbol;
};

// Stack operations
void push(struct Stack* stack, int* top, int state, int symbol) {
    stack[++(*top)].state = state;
    stack[*top].symbol = symbol;
}

struct Stack pop(struct Stack* stack, int* top) {
    return stack[(*top)--];
}

struct Stack peek(struct Stack* stack, int top) {
    return stack[top];
}

// Action functions
void shift() {
    printf("Shift\n");
}

void reduce() {
    printf("Reduce\n");
}

void accept() {
    printf("Accept\n");
}

// Main parsing function
void parse(char* input) {
    struct Stack stack[100];  // Adjust the stack size as needed
    int top = -1;
    int i = 0;
    push(stack, &top, 0, TERMINAL_EOF);  // Initial state and EOF symbol

    while (true) {
        struct Stack current = peek(stack, top);
        int currentState = current.state;
        int currentSymbol = current.symbol;
        int inputSymbol;

        if (i < strlen(input)) {
            switch (input[i]) {
                case 'id':
                    inputSymbol = TERMINAL_ID;
                    break;
                case '+':
                    inputSymbol = TERMINAL_PLUS;
                    break;
                default:
                    printf("Invalid input symbol\n");
                    return;
            }
        } else {
            inputSymbol = TERMINAL_EOF;
        }

        struct ParseTableEntry entry = parseTable[currentState][inputSymbol];

        if (entry.isAction) {
            if (entry.action == shift) {
                push(stack, &top, entry.state, inputSymbol);
                i++;
            } else if (entry.action == reduce) {
                printf("Reduce rule\n");  // Implement your reduce logic here
            } else if (entry.action == accept) {
                printf("Input accepted\n");
                return;
            } else {
                printf("Invalid action\n");
                return;
            }
        } else {
            printf("Invalid parse table entry\n");
            return;
        }
    }
}

int main() {
    // Initialize the parse table
    parseTable[0][TERMINAL_ID].isAction = true;
    parseTable[0][TERMINAL_ID].action = shift;
    parseTable[0][NON_TERMINAL_E].isAction = true;
    parseTable[0][NON_TERMINAL_E].action = 1;
    // Add more parse table entries as needed

    // Test the parser
    char* input = "id + id";
    parse(input);

    return 0;
}
