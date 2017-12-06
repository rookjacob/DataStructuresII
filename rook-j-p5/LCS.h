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

int **LCS_C;

char *LCS_X;
char *LCS_Y;

int X_LENGTH;
int Y_LENGTH;

int NUM_LCS;

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
void allocate_LCS_C(void);

/*
 *
 */
void deallocate_LCS_Var(void);

/*
 *
 */
void print_LCS(int i, int j);

/*
 *
 */
void LCS_Multiple_Length(char *FileName);

/*
 *
 */
void init_Interval_List(char *FileName);



#endif /* LCS_H_ */
