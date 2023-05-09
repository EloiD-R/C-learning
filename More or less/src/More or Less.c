#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // set the seed for the rand() function
    srand(time(NULL));

    // init the var that will be used later to store the user input
    int inputtedNumber;

    // init the max and min number value and generate the random number
    const int MIN_NUMBER = 0, MAX_NUMBER = 100;
    int toFind = (rand() % (MAX_NUMBER - MIN_NUMBER + 1)) + MIN_NUMBER;

    // information to the user that the min number is MIN_NUMBER and max is MAX_NUMBER
    printf("\n The number you need to find is between %d and %d", MIN_NUMBER, MAX_NUMBER);

    // main loop
    while (1){
        // Ask the player for a number
        printf("\nWhat is the number ? > ");
        scanf("%d", &inputtedNumber);

        // check if the number is the secret one or not and if it is change screen color and say it's nice then close the program
        if(inputtedNumber == toFind){
            system("cls");
            system("color a");
            printf("Wow you found the secret number you are very strong !\n");
            system("pause");
            system("color 0f");
            system("cls");
            break;
        }
        // if the number is not the right one verify if it is under or above the value of the secrete one
        else if(inputtedNumber < toFind){
            printf("\nNope that's not the secret Number (it is more than %d)", inputtedNumber);
            continue;
        }
        else if(inputtedNumber > toFind){
            printf("\nNope that's not the secret Number (it is less than %d)", inputtedNumber);
            continue;
        }
        // if the user entered nothing or chars or some other kind of stuff this section will tell him he is not nice then restart
        else{
            printf( "\n%d is not even a number.", inputtedNumber);
            continue;
        }
    }

    return 0;
}