#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


char* getWord() {
    FILE* dictionaryFile = fopen("C:\\Users\\eloid\\OneDrive\\hangman game\\output\\dictionary.txt", "r");
    if (dictionaryFile == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    int randomLine = getRandomLine();

    // Read the file line by line until the random line is reached.
    char lineBuffer[100];
    int lineCount = 0;
    while (fgets(lineBuffer, sizeof(lineBuffer), dictionaryFile) != NULL) {
        if (lineCount == randomLine)
            break;
        lineCount++;
    }

    // Remove the newline character at the end of the line.
    lineBuffer[strcspn(lineBuffer, "\n")] = '\0';

    // Close the file.
    fclose(dictionaryFile);

    // Allocate memory for the word and copy the line into it.
    char* word = malloc(strlen(lineBuffer) + 1);
    strcpy(word, lineBuffer);

    return word;
}

int getRandomLine() {
    srand(time(NULL));
    int randomLine = rand() % 51;
    return randomLine;
}
