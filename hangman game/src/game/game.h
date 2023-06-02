// Avoid any infinite inclusion.
#ifndef HANGMAN_GAME_GAME_H
#define HANGMAN_GAME_GAME_H

// Includes :
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


// Defines :
#define true 1
#define false 0


// Functions prototypes :

// This function returns the random word.
char* generateRandomWord();

// This function asks and returns one int (the character inputted by the user).
int askUserForLetter();

// This function check if there is one (or more) iterations of the letter in the word.
int checkForLettersInWord(int letter, char word[]);

// This function replaces all letters of a word by '*'.
char* mystifyWord(char* word);

// Replace a '*' or multiples '*' by their original letter
void demystifyWord(int letter, char* originalWord, char* mystifiedWord);

// Empty the stdin buffer after used it with getchar() or fgets().
void emptyStdinBuffer();

// This function is here to automatically empty the stdin buffer and all these things when it is needed to call fgets().
int readStringFromCLI(char *chaine, int longueur);


#endif //HANGMAN_GAME_GAME_H
