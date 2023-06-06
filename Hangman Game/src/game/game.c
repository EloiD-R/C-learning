/*
    ✏️Wrote by GRISZ on 06/2023,
    Description : This file contains the functions to pick a random word from a dictionary file,,
    Contact :
        Discord : !!-GRISZ-!!#2705
        Mail : griszou12@gmail.com
        Github : https://github.com/eloiD-R/
    Link to file in project repo : https://github.com/eloiD-R/.
*/
#include "game.h"

// This function returns the random word.
char* generateRandomWord(){
    return "BANANA";
}


// This function asks and returns one int (the character inputted by the user).
int askUserForLetter(){
    // Ask the user for a letter.
    printf("\nPurpose a letter > ");

    // Detect the input and store it into a variable.
    int inputtedCharacter = getchar();
    inputtedCharacter = toupper (inputtedCharacter);

    // Empty getchar() buffer.
    while (getchar() != '\n');

    return inputtedCharacter;
}


// This function check if there is one (or more) iterations of the letter in the word.
int checkForLettersInWord(int letter, char* word){
    // Store the length of the word.
    size_t wordLength = strlen(word);

    // Create an array to store if the word contains the letter or not for every letter of the word.
    int isLetterOnWord[strlen(word)];

    // Check if the word contains the letter.
    for(int letterIndex = 0; letterIndex < strlen(word); letterIndex += 1){
        if(word[letterIndex] == letter) {
            isLetterOnWord[letterIndex] = true;
        } else{
            isLetterOnWord[letterIndex] = false;
        }
    }

    // Check the isLetterOnWord array.
    for(int index = 0; index < wordLength; index += 1){
        if(isLetterOnWord[index] == true) {
            printf("Yep! the letter \"%c\" is actually a part of the secret word.\n", letter);
            return true;
        } else{
            if(index == wordLength - 1){
                printf("Nope! The secret word does not contains the letter \"%c\".\n", letter);
            }
        }
    }
    return false;
}


// This function replaces all letters of a word by '*'.
char* mystifyWord(char* word){
    // Get the length of the parameter word.
    size_t wordLength = strlen(word);

    // Create a new string which will contain the '*' and allocate him the size of the word parameter (+1 to store the '\0' character).
    char* mystifiedWord = malloc((wordLength +1) * sizeof(char));

    // Loop to put every character of the string by '*'.
    for(int characterIndex = 0; characterIndex < wordLength; characterIndex++){
        mystifiedWord[characterIndex] = '*';
    }

    // Add the '\0' character at the end of the string.
    mystifiedWord[wordLength] = '\0';

    // Return the word replaced with '*'.
    return mystifiedWord;
}


// Replace a '*' or multiples '*' by their original letter
void demystifyWord(int letter, char* originalWord, char* mystifiedWord){
    for(int i = 0; i < strlen(originalWord); i++){
        if(originalWord[i] == letter){
            mystifiedWord[i] = (char)letter;
        }
    }
}


// Empty the stdin buffer after used it with getchar() or fgets().
void emptyStdinBuffer(){
    // Store the actual character.
    int character = 0;

    // Read the characters in the buffer until there is no remaining
    while(character != '\n' && character != EOF){
        character = getchar();
    }
}


// This function is here to automatically empty the stdin buffer and all these things when it is needed to call fgets().
int readStringFromCLI(char *string, int size){
    char *entryPosition = NULL;

    if (fgets(string, size, stdin) != NULL)
    {
        entryPosition = strchr(string, '\n');
        if (entryPosition != NULL)
        {
            *entryPosition = '\0';
        }
        else
        {
            emptyStdinBuffer();
        }
        return 1;
    }
    else
    {
        emptyStdinBuffer();
        return 0;
    }
}
