/*
 * Created by GRISZ
 * Date : 01/05/2023 -> 03/05/2023 (dd/mm/yyyy)
 * Github : https://github.com/EloiD-R
 * Repo : https://github.com/EloiD-R/C-learning
 * Discord : !!-|GRISZ|-!!#2705
 * Description : This code is an exercise from the book : "Apprenez à programmer en C 2nd édition" (translation from french : "Learn to program in C second edition"),
 * to know more about the exercise check out the README.md
 */

// include the necessary libs
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main(){

    // Demonstrate the functions below
    functionsDemo();

    // make a break before program closes
    printf("\n\n\n");
    system("pause");

    // return exit code 0
    return 0;
}

// Functions to manipulate tables

// Print the values of a table
void displayTable(int table[], int numberOfValues){
    // create last value var wish is equal to numberOfValues less 1 because number of values might be for exemple 10 but the last value is 9 because of the table beginning at 0 not 1
    int LAST_VALUE_INDEX = numberOfValues - 1;

    // loop to iterate in the table and print hte values one by one
    for (int loopIteration = 0; loopIteration < numberOfValues; loopIteration++){
        // check if the number is the last value of the table in order to make a display without  dash at the final character else print the dash
        if(loopIteration == LAST_VALUE_INDEX){
            printf("%d", table[loopIteration]);
        } else{
            printf("%d-", table[loopIteration]);
        }
    }
}


// Ask the user for number to put in the table1
void askForTableNumbers(int table[],int numberOfValues){
    // init the variable to get a display from 1 to ten and not 0 to ten
    const int LAST_VALUE_INDEX = 1;

    // print the rules
    printf("Please choose ten numbers (if the number is more than 99 it will be put to 0 automatically) :\n");

    // ask for the numbers (depending on the table size)
    for(int loopIteration = LAST_VALUE_INDEX; loopIteration < numberOfValues + LAST_VALUE_INDEX ; loopIteration++){
        printf("Number %d > ", loopIteration);
        scanf("%d", &table[loopIteration - LAST_VALUE_INDEX]);
    }
}


// Compute the sum of a table values
int tableSum (const int table[], int tableSize){
    // init the tableValuesSum var on static to be used on the for loop then put his value to 0 to reuse function correctly
    static int tableValuesSum;
    tableValuesSum = 0;
    // for loop that compute the sum of the values
    for(int loopIteration = 0; loopIteration < tableSize; loopIteration++){
        tableValuesSum += table[loopIteration];
    }

    // return the sum of the table values
    return tableValuesSum;
}


// Compute the average of a table values
double tableAverage (int table[], int tableSize){
    // compute the sum of the table using tableSum function
    int tableValuesSum = tableSum(table, tableSize);
    // compute the average of the table (formula : (sum of the numbers)/ (number of numbers)
    double tableAverageValue = (double)tableValuesSum/tableSize;

    // return the average value of the table
    return tableAverageValue;
}


// Copy values from a table to another that had the same size or more
void copyTableToAnother(int toCopyTable[], int copyInTable[], int numberOfValuesToCopy){
    // loop to iterate in the values of the tables
    for(int loopIteration = 0; loopIteration < numberOfValuesToCopy; loopIteration++){
        // copy the toCopyTable value into toCopyTable at the same index
        copyInTable[loopIteration] = toCopyTable[loopIteration];
    }
}


/*
This function is an implementation of a bubble sorting algorithm which consists of repeatedly iterating through
the input array, comparing adjacent elements, and swapping them if they are in the wrong order
 */
void ascendingTableBubbleSort(int toSortTable[], int outputSortTable[], int numberOfValues) {
    // Copy the first table to the output one
    copyTableToAnother(toSortTable, outputSortTable, numberOfValues);

    // Bubble sort algorithm to sort the values of the table in ascending order
    // first loop
    for (int loopIterations = 0; loopIterations < numberOfValues; loopIterations++) {
        // nested loop
        for (int NestedLoopIterations = 0; NestedLoopIterations < numberOfValues; NestedLoopIterations++) {
            int NEXT_INDEX = NestedLoopIterations + 1;
            // compare a value from outputSortTable to the next value in outputSortTable and swap values it if the first is greater
            if (outputSortTable[NestedLoopIterations] > outputSortTable[NestedLoopIterations + NEXT_INDEX]) {
                // create a temporary var to store the current value
                int temp = outputSortTable[NestedLoopIterations];
                // swap the table values
                outputSortTable[NestedLoopIterations] = outputSortTable[NestedLoopIterations + NEXT_INDEX];
                outputSortTable[NestedLoopIterations + NEXT_INDEX] = temp;
            }
        }
    }
}

// This function is a security to ensure that any number will be greater than the table maximum value
void maxTableReset(int table[], int tableSize, int tableMaxValue){
    // loop to iterate int the table
    for(int loopIteration = 0; loopIteration < tableSize; loopIteration++){
        // check if the table value is greater than the table maximum value
        if(table[loopIteration] > tableMaxValue){
            // put the value to 0
            table[loopIteration] = 0;
        }
    }
}

// Demonstrate the functions above
void functionsDemo(){
    // Init the tables and table size vars
    const int TABLE_MAX_VALUE = 99;
    const int TABLE_SIZE = 10;
    int table1[TABLE_SIZE];
    int tableCopy[TABLE_SIZE];
    int sortTable[TABLE_SIZE];

    // define a const to store the delimitation line
    const char DELIMITATION_LINE[] = "----------------------------------------------------------------------";

    // Ask user for ten numbers
    askForTableNumbers(table1, TABLE_SIZE);

    // Call to functions :

    // Check if there is a number above 99 and if it is put it to 0
    maxTableReset(table1, TABLE_SIZE, TABLE_MAX_VALUE);

    // Compute the sum of every value on the table
    int tableValuesSum = tableSum(table1, TABLE_SIZE);

    // Compute the average of the table
    double tableAverageValue = tableAverage(table1, TABLE_SIZE);

    // Sort the table values in ascending order
    ascendingTableBubbleSort(table1, sortTable, TABLE_SIZE);

    // Display of the sum, average and sorting in ascending order of the table values
    printf("\n\n%s\nTable1 operations : \n", DELIMITATION_LINE);
    printf("\nSum of the table1 values : %d", tableValuesSum);
    printf("\nAverage of the table1 values : %f", tableAverageValue);
    printf("\nSorting of the table1 values in ascending order : ");displayTable(sortTable, TABLE_SIZE);

    // display the content of the two tables before the copy of table in copyTable
    printf("\n\nTables before copy :");
    printf("\nTable1 :");
    displayTable(table1, TABLE_SIZE);
    printf("\nTable copy :");
    displayTable(tableCopy, TABLE_SIZE);
    copyTableToAnother(table1, tableCopy, TABLE_SIZE);

    // display the content of the two tables after the copy of table1 in copyTable
    printf("\n\nTables after copy :");
    printf("\nTable1 :");
    displayTable(table1, TABLE_SIZE);
    printf("\nTable copy :");
    displayTable(tableCopy, TABLE_SIZE);

    printf("\n%s", DELIMITATION_LINE);
}
