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
#include<string.h>


#define MAX_LCS_LENGTH 50

int **LCS_C;
int Seq1_Length;
int Seq2_Length;

/*
 *
 */
int LCS_Length_C(char *FileName);

/*
 *
 */
void allocate_LCS_C(int r, int c);

/*
 *
 */
int print_LCS(void);

/*
 *
 */
void LCS_Multiple_Length(char *FileName);



#endif /* LCS_H_ */
