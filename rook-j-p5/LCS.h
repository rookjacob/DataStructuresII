/*
 * @file LCS.h
 *
 * @author Jacob Rook
 * @date 12/07/2017
 * @info Course COP 4534
 * Project 5
 */



#ifndef LCS_H_
#define LCS_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAX_LCS_LENGTH 1000
#define MAX_NUM_LCS 50

/*
 * @brief	LCS_C		Variable to point to the dynamically allocated memory for the "C"
 * array in the dynamic programming algorithm for the LCS problem.
 */
int LCS_C[MAX_LCS_LENGTH + 1][MAX_LCS_LENGTH + 1];

/*
 * brief	LCS_X LCS_Y		Variable to point to the dynamically allocated memory to store
 * strings of interest for the LCS
 */
char LCS_X[MAX_LCS_LENGTH + 1];
char LCS_Y[MAX_LCS_LENGTH + 1];

/*
 * @brief	X_LENGTH Y_LENGTH	Variables to store the length of hte LCS_X LCS_Y strings
 */
int X_LENGTH;
int Y_LENGTH;

/*
 * @brief	NUM_LCS		Variable to store how many strings are in the file passed to the
 * LCS_Multiple_Length function to calculate the LCS for
 */
int NUM_LCS;

/*
 * @brief	INT_LIST	Variable to point to the dynamically allocated memory to store the
 * interval list for the LCS_Multiple_Length function. The locations in the passed files for
 * all of the strings are stored in this array.
 */
int INT_LIST[MAX_NUM_LCS];

/*
 * @brief	LCS_M1 LCS_M2		Variable to point to the dynamically allocate memory to
 * store the temporary arrays to do the LCS calculations
 */
int LCS_M1[MAX_LCS_LENGTH + 1];
int LCS_M2[MAX_LCS_LENGTH + 1];

/*
 * @brief	LCS_Length_C	This function calculates the LCS of two strings in the file
 * passed by the function by declaring an m + 1 by n + 1 array and using the array to
 * calculate the LCS. The function first calls init_XY_C to initialize LCS_X and LCS_Y for
 * the two dimensional array method of solving for the LCS. Once LCS_X and LCS_Y are
 * initialized, the "C" array is allocated with respect of the LCS_X and LCS_Y strings.
 *
 * From there..(Algorithm)
 *
 * The function then prints the LCS to the stdout, deallocates the variables, and returns
 * the length of the LCS.
 *
 * @param	FileName		Name of the file to open for to get the strings for the LCS.
 * The file must have two strings, each on own line.
 *
 * @return	int				Returns the length of the LCS
 *
 */
int LCS_Length_C(char *FileName);

/*
 * @brief	init_XY_C		Function initializes LCS_X LCS_Y to the strings stored in the
 * FileName file. The function is expecting the file to have two strings, one per line.
 *
 * @param	FileName		File to get the strings for LCS_X and LCS_Y
 *
 */
void init_XY_C(char *FileName);

/*
 * @brief 	allocate_LCS_C		Function dynamically allocates memory for the "C" LCS_C
 * array that is used to solve for the LCS. Function also initializes the 0th row and 0th
 * column to 0. The dimensions of LCS_C are determined by the X_LENGTH and Y_LENGTH variables
 * that are initialized the the init_XY_C function.
 *
 */
void init_LCS_C(void);

/*
 * @brief	print_LCS		Function prints the actual LCS of the two strings.
 */
void print_LCS(int i, int j);

/*
 * @brief	LCS_Multiple_Length		This function measures the "similarity" of multiple
 * strings to one another. The function opens the file passed to the function, reads how
 * many strings there are in the file, then creates an interval list used to determine the
 * start of each string in the file. The file passed should have the number of strings in
 * the file followed by that many strings each on its own line.
 *
 * The function then starts to print a table with the comparisons between each string.
 * The comparison is based off the length of both strings and the length of the LCS, given
 * by the sequence_Similarity() function.
 *
 */
void LCS_Multiple_Length(char *FileName);

/*
 *
 */
void init_Interval_List(char *FileName);

/*
 *
 */
void read_NUM_LCS(char *FileName);

/*
 *
 */
char sequence_Similarity(int r, int c, char *FileName);

/*
 *
 */
void init_XY_2M(int r, int c, char *FileName);

/*
 *
 */
int LCS_Length_2M(void);

/*
 *
 */
void init_LCS_M12(void);

/*
 *
 */
void swap_Top_Bottom(int *Top, int *Bottom);



#endif /* LCS_H_ */
