e/*
    ✏️Wrote by GRISZ on 06/2023,
    Description : This file contains the code that permit the program to run correctly (it links the functions from game and dictionary files),,
    Contact :
        Discord : !!-GRISZ-!!#2705
        Mail : griszou12@gmail.com
        Github : https://github.com/eloiD-R/
    Link to file in project repo : https://github.com/
*/

#include "main.h"
#include "game/game.h"
#include "dictionary/dictionary.h"

// Main function.
int main(int argc, char *argv[]){

    // Main loop.
    while(true) {
        // Set console theme to black background and withe text.
        system("color 0f");

        // Ask the user to restart the game.
        system("cls");
        printf("Press ENTER to begin a new game or type EXIT to quit the game > ");

        // Stand for a key press or an exit instruction.
        char userInput[100] = "";
        readStringFromCLI(userInput, 100);

        // Check if the user wants to exit the game.
        if(strcmp(userInput, "EXIT") == 0 | strcmp(userInput, "exit") == 0){
            //emptyStdinBuffer();
            exit(EXIT_SUCCESS);
        } else{
            //emptyStdinBuffer();
        }

        // Get the random word that will be used on the party.
        char* secretWord = getWord();
        char* mystifiedSecretWord = mystifyWord(secretWord);

        // Set the number of lives of the player to ten.
        int userLives = 10;


        // Actual loop of the game.
        while(true){
            getWord();
            // Print the letters of the secret word the user found.
            printf("\nSecret Word : '%s'", mystifiedSecretWord);

            // Display the number of attempts remaining to the user
            printf("\nBe careful you have only %d attempts remaining before being hanged.", userLives);

            // Get a letter from the user.
            int userInputChar = askUserForLetter();

            // Check if there is one or more of the user inputted letters in the word.
            int isUserInputInWord = checkForLettersInWord(userInputChar, secretWord);

            // If there is one or more letters of the user input on the secret word demystify it.
            if(isUserInputInWord == true){
                demystifyWord(userInputChar, secretWord, mystifiedSecretWord);
            } else{
                userLives -= 1;
            }

            // Check if the user has remaining lives.
            if(userLives == 0){
                system("cls");
                system("color 0c");
                printf("Hmm it seems you have no more attempts, so we must hang you.\nOh and the secret word was %s.\n\n", secretWord);
                system("pause");
                break;
            }

            // Check if the player finds the entire word and if yes end the party.
            if(strcmp(mystifiedSecretWord, secretWord) == 0){
                system("cls");
                system("color 0a");
                printf("GG! you find the secret word you are not going to be hanged this time !\n");
                system("pause");
                break;
            }

        }


    }

}
