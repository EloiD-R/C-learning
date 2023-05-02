/*
 * Created by GRISZ
 * Date : 01/05/2023
 * Github : https://github.com/EloiD-R
 * Repo : https://github.com/EloiD-R/C-learning
 * Discord : !!-|GRISZ|-!!#2705
 * Description : In this code there are prototypes of the main.c exercise from the book : "Apprenez à programmer en C 2nd édition" (translation from french : "Learn to program in C second edition") to know more about the exercise check out the README.md
 */

// Compute the sum of a table values
int tableSum (const int table[], int tableSize);
// Compute the average of a table values
double tableAverage(int table[], int tableSize);
// Display two tables of the same size
int displayTwoTables(int table1[], int table2[], int tablesSize);
// Make a copy of a table
int copyTable(int table1[], int table2[], int tablesSize);
// Sort the table in ascending order
int tableSort(int toSortTable[], int outputSortTable[], int tablesSizes);
// If the value entered by the user is more then 99 it will be put to 0
int maxTable(int table[], int tableSize, int tableMaxValue);