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
    // Init the tables and table size vars
    const int TABLE_SIZE = 10;
    const int TABLE_MAX_VALUE = 99;
    int table1[10] = {0};
    int tableCopy[10] = {0};
    int sortTable[10];

    // Ask user for ten numbers
    printf("Please choose ten numbers (if the number is more than 99 it will be put to 0 automatically) :\n");
    for(int loopIteration = 1; loopIteration < TABLE_SIZE + 1 ; loopIteration++) {
        printf("Number %d > ", loopIteration);
        scanf("%d", &table1[loopIteration - 1]);
    }
    // Call to functions
    maxTable(table1, TABLE_SIZE, TABLE_MAX_VALUE);
    int tableValuesSum = tableSum(table1, TABLE_SIZE);
    double tableAverageValue = tableAverage(table1, TABLE_SIZE);
    tableSort(table1, sortTable, TABLE_SIZE);

    // Display of the returns from functions
    printf("Table1 operations : \n");
    printf("\nSum of the table1 values : %d", tableValuesSum);
    printf("\nAverage of the table1 values : %f", tableAverageValue);
    printf("\nSorting of the table1 values in ascending order : "); for(int i = 0; i<TABLE_SIZE; i++){ printf("%d-", sortTable[i]); }
    printf("\n\nTables before copy :");
    displayTwoTables(table1, tableCopy, TABLE_SIZE);
    copyTable(table1, tableCopy, TABLE_SIZE);
    printf("\n\nTables after copy :");
    displayTwoTables(table1, tableCopy, TABLE_SIZE);
    printf("\n");
    system("pause");
    return 0;
}

// Compute the sum of a table values
int tableSum (const int table[], int tableSize){
    // init the tableValuesSum var on static to be used on the for loop then put his value to 0 to reuse function correctly
    static int tableValuesSum;
    tableValuesSum = 0;
    // for loop that make the sum of the values
    for(int loopIteration = 0; loopIteration < tableSize; loopIteration++){
        tableValuesSum += table[loopIteration];
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


int displayTwoTables(int table1[], int table2[], int tablesSize){
    printf("\nTable 1 :");
    for (int loopIteration = 0; loopIteration < tablesSize; loopIteration++){
        printf("\n- %d", table1[loopIteration]);
    }
    printf("\nTable 2 :");
    for (int loopIteration = 0; loopIteration < tablesSize; loopIteration++){
        printf("\n- %d", table2[loopIteration]);
    }
}


int copyTable(int table1[], int table2[], int tablesSize){
    for(int loopIteration = 0; loopIteration < tablesSize; loopIteration++){
        table2[loopIteration] = table1[loopIteration];
    }
}
    
int tableSort(int toSortTable[], int outputSortTable[], int tablesSize) {
    copyTable(toSortTable, outputSortTable, tablesSize);
    for (int i = 0; i < tablesSize; i++) {
        for (int j = 0; j < tablesSize; j++) {
            if (outputSortTable[j] > outputSortTable[j + 1]) {
                int temp = outputSortTable[j];
                outputSortTable[j] = outputSortTable[j + 1];
                outputSortTable[j + 1] = temp;
            }
        }
    }
}

int maxTable(int table[], int tableSize, int tableMaxValue){
    for(int loopIteration = 0; loopIteration < tableSize; loopIteration++){
        if(table[loopIteration] > tableMaxValue){
            table[loopIteration] = 0;
        }
    }
}
