/*
 * Created by GRISZ
 * Date : 01/05/2023
 * Github : https://github.com/EloiD-R
 * Repo : https://github.com/EloiD-R/C-learning
 * Discord : !!-|GRISZ|-!!#2705
 * Description : This code is an exercise from the book : "Apprenez à programmer en C 2nd édition" (translation from french : "Learn to program in C second edition") to know more about the exercise check out the README.md
 */


#include <stdio.h>
#include "main.h"

int main(){
    // Init the table and table size vars
    const int TABLE_SIZE = 4;
    int table[4] = {1, 6, 5, 8};

    // Call to functions
    int tableValuesSum = tableSum(table, TABLE_SIZE);
    double tableAverageValue = tableAverage(table, TABLE_SIZE);

    // Display of the returns from functions
    printf("Tables operations :");
    printf("\nSum of the table values : %d", tableValuesSum);
    printf("\nAverage of the tables values : %f", tableAverageValue);

    return 0;
}

// Compute the sum of a table values
int tableSum (const int table[], int tableSize){
    // init the tableValuesSum var on static to be used on the for loop then put his value to 0 to reuse function correctly
    static int tableValuesSum;
    tableValuesSum = 0;
    // for loop that make the sum of the values
    for(int i = 0; i < tableSize; i++){
        tableValuesSum += table[i];
    }

    return tableValuesSum;
}

// Compute the average of a table values
double tableAverage (int table[], int tableSize){
    // Compute the sum of the table using tableSum function
    int tableValuesSum = tableSum(table, tableSize);
    // Compute the average of the table (formula : (sum of the numbers)/ (number of numbers)
    double tableAverageValue = (double)tableValuesSum/tableSize;

    return tableAverageValue;
}

// TODO : copyTable func that take the original table and an empty table, then copy the original table values on the copy

// TODO : maxTable and sortTable funcs
