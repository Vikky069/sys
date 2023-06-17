#include <stdio.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_LINE_LENGTH 1000

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char line[MAX_LINE_LENGTH];
    int characterCount = 0;
    int wordCount = 0;
    int lineCount = 0;

    // Read the filename from the user
    printf("Enter the filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the file line by line
    while (fgets(line, sizeof(line), file)) {
        lineCount++;
        characterCount += strlen(line);

        // Count the number of words in the line
        int inWord = 0;
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
                inWord = 0;
            } else if (inWord == 0) {
                inWord = 1;
                wordCount++;
            }
        }
    }

    // Close the file
    fclose(file);

    // Print the results
    printf("Number of characters: %d\n", characterCount);
    printf("Number of words: %d\n", wordCount);
    printf("Number of lines: %d\n", lineCount);

    return 0;
}
