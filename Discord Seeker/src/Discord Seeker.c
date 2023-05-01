/*🖋wrote by GRISZ
  on 27/04/2023 at 23h57 (11h57AM) (dd-mm-yyyy)
  Github : https://github.com/EloiD-R
  Discord : GRISZ#2705
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // make a little display to announce that this is my very first project (after the Hello World one obviously)
    printf("+-----------------------------------------------------------------+"
           "\n|This is the very first C program of GRISZ (GRISZ#2705 on discord)|"
           "\n|See comments of source code to know more about GRISZ             |"
           "\n+-----------------------------------------------------------------+\nProgram (discord seeker) :");

    // init the only valid tag
    const int GRISZ_DISCORD_TAG = 2705;

    // ask the user for her discord tag
    int inputTag;
    printf("\n-------------------------------------------------------------------");
    printf("\nPlease input your discord tag (without the \"#\") > ");
    scanf("%d", &inputTag);

    // print the inputted discord tag and the GRISZ taf
    printf("So your discord tag is : #%d, GRISZ one is #%d", inputTag, GRISZ_DISCORD_TAG);

    // make that the program closes when pressing any key
    printf("\n--------------------------------------------------------------------\n\n"); // because the default windows pause message do not contain a newline before it, i print it here
    system("pause"); // the windows pause message is : "Press any key to continue . . ."

    return 0;
}

/*🖋wrote by GRISZ
  on 27/04/2023 at 23h57 (11h57AM) (dd-mm-yyyy)
  Github : https://github.com/EloiD-R
  Discord : GRISZ#2705
*/