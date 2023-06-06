/*
    ✏️Wrote by GRISZ on 06/2023,
    Description : This file is the header of the file that contains functions to pick a word from a dictionary file,,
    Contact :
        Discord : !!-GRISZ-!!#2705
        Mail : griszou12@gmail.com
        Github : https://github.com/eloiD-R/
    Link to file in project repo : https://github.com/eloiD-R/.
*/
// Avoid any infinite inclusion.
#ifndef HANGMAN_GAME_DICTIONARY_H
#define HANGMAN_GAME_DICTIONARY_H


// Includes :
    // Standards libs import :
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>


// Defines :
    // No defines.


// Functions prototypes :
    // Generate a random number that can be used as a random line to generate a random line.
    int getRandomLine();

    // Generate the random word, then return it.
    char* getWord();


#endif //HANGMAN_GAME_DICTIONARY_H
