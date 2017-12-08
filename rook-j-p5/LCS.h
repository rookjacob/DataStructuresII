/*
 * @file LCS.h		File contains all of the function prototypes for the
 * functions to determine the LCS of given sequences. For more details of the
 * functionality read the function descriptions.
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
 * @brief	LCS_C		Two dimensional array used to calculate the LCS
 */
int LCS_C[MAX_LCS_LENGTH + 1][MAX_LCS_LENGTH + 1];

/*
 * brief	LCS_X LCS_Y		Variables to store the strings compared in the LCS
 */
char LCS_X[MAX_LCS_LENGTH + 1];
char LCS_Y[MAX_LCS_LENGTH + 1];

/*
 * @brief	X_LENGTH Y_LENGTH	Variables to store the length of the LCS_X LCS_Y strings
 */
int X_LENGTH;
int Y_LENGTH;

/*
 * @brief	NUM_LCS		Variable to store how many strings are in the file passed to the
 * LCS_Multiple_Length function to calculate the LCS for
 */
int NUM_LCS;

/*
 * @brief	INT_LIST	Variable to store the interval list for the LCS_Multiple_Length
 * function. The locations in the passed files for all of the strings are stored
 * in this array.
 */
int INT_LIST[MAX_NUM_LCS];

/*
 * @brief	LCS_M1 LCS_M2		Variable store the temporary arrays to calculate
 *  the LCS
 */
int LCS_M1[MAX_LCS_LENGTH + 1];
int LCS_M2[MAX_LCS_LENGTH + 1];

/*
 * @brief	LCS_Length_C	This function calculates the LCS of two strings in the file
 * passed by the function by initializing an m + 1 by n + 1 array and using the array to
 * calculate the LCS. The function first calls init_XY_C to initialize LCS_X and LCS_Y for
 * the two dimensional array method of solving for the LCS. Once LCS_X and LCS_Y are
 * initialized, the "C" array is initialized with respect of the LCS_X and LCS_Y strings.
 *
 * From there the LCS algorithm provided is implemented.
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
 * @brief 	init_LCS_C		Function initializes the "C" array or LCS_C
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
 * @brief	init_Interval_List		Function reads the file with the given name in
 * FileName to get the number of strings in the file. Then the function reads the
 * file to determine the position of the start of each string and records it into
 * the INT_LIST array.
 */
void init_Interval_List(char *FileName);

/*
 * @brief	read_NUM_LCS		Function reads the first line of the file and
 * stores the integer value into NUM_LCS
 */
void read_NUM_LCS(char *FileName);

/*
 * @brief	sequence_Similarity		Function compares the two sequences of letters
 * and returns the character representation of the comparison.
 */
char sequence_Similarity(int r, int c, char *FileName);

/*
 * @brief	init_XY_2M		Function initializes LCS_X and LCS_Y with the given
 * position in the file. The function read the file at the location given by
 * the INT_LIST array and stores it into either LCS_X or LCS_Y
 */
void init_XY_2M(int r, int c, char *FileName);

/*
 * @brief	LCS_Length_2M	This function performs the calcualtion of the LCS with
 * only two arrays and swapping them as the algorithm moved down the rows, using
 * the swap_Top_Bottom function
 */
int LCS_Length_2M(void);

/*
 * @brief	init_LCS_M12		Function initializes LCS_M1 and LCS_M2
 */
void init_LCS_M12(void);

/*
 * @brief	swap_Top_Bottom		Moves the Top pointer to the Bottom pointer and
 * the Bottom pointer to the Top position.
 */
void swap_Top_Bottom(int *Top, int *Bottom);



#endif /* LCS_H_ */
