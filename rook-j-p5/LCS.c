/*
 * @file LCS.c
 *
 * @author Jacob Rook
 * @date 12/07/2017
 * @info Course COP 4534
 * Project 5
 */

#include"LCS.h"


int LCS_Length_C(char *FileName)
{
	FILE *fp;
	fp = fopen(FileName, "r");

	char string1[MAX_LCS_LENGTH];
	char string2[MAX_LCS_LENGTH];

	if(!fgets(string1, MAX_LCS_LENGTH, fp))
	{
		printf("Error with %s\n",FileName);
		fclose(fp);
		exit(1);
	}

}


void allocate_LCS_C(int r, int c)
{

}


int print_LCS(void)
{

}

void LCS_Multiple_Length(char *FileName)
{

}









