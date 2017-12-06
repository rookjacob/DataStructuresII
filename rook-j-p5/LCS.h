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

int **LCS_C;

char *LCS_X;
char *LCS_Y;

int X_LENGTH;
int Y_LENGTH;

int Seq1_Length;
int Seq2_Length;

/*
 *
 */
int LCS_Length_C(char *FileName);

/*
 *
 */
void initXY(char *FileName);

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
