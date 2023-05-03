/*
 * Created by GRISZ
 * Date : 01/05/2023 -> 03/05/2023 (dd/mm/yyyy)
 * Github : https://github.com/EloiD-R
 * Repo : https://github.com/EloiD-R/C-learning
 * Discord : !!-|GRISZ|-!!#2705
 * Description : This code contains prototypes of main.c,
 * to now more about it check out the README.md
 */

// Display a table (for loop)
void displayTable(int table[], int numberOfValues);

// Ask the user for number to put in table 1
void askForTableNumbers(int table[],int numberOfValues);

// Compute the sum of a table values
int tableSum (const int table[], int tableSize);

// Compute the average of a table values
double tableAverage (int table[], int tableSize);

// Make a copy of a table
void copyTableToAnother(int toCopyTable[], int copyInTable[], int numberOfValuesToCopy);

// Sort the table in ascending order with a Bubble sorting algorithm
void ascendingTableBubbleSort(int toSortTable[], int outputSortTable[], int numberOfValues);

// If the value entered by the user is more than 99 it will be put to 0
void maxTableReset(int table[], int tableSize, int tableMaxValue);

// Demonstrate the functions above
void functionsDemo();