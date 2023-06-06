/*
    ✏️Wrote by GRISZ on 06/2023,
    Description : This file contains the functions to pick a random word from a dictionary file,,
    Contact :
        Discord : !!-GRISZ-!!#2705
        Mail : griszou12@gmail.com
        Github : https://github.com/eloiD-R/
    Link to file in project repo : https://github.com/eloiD-R/.
*/
#include "dictionary.h"


// Generate the random word, then return it.
char* getWord() {
    FILE* dictionaryFile = fopen("dictionary.txt", "r");
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

// Generate a random number that can be used as a random line to generate a random line.
int getRandomLine() {
    srand(time(NULL));
    int randomLine = rand() % 51;
    return randomLine;
}
