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
	initXY(FileName);






	if(LCS_X)
	{
		free(LCS_X);
	}
	if(LCS_Y)
	{
		free(LCS_Y);
	}
	if(LCS_C)
	{
		free(LCS_C);
	}
}

void initXY(char *FileName)
{
	FILE *fp;
	fp = fopen(FileName, "r");

	if(!fp)
	{
		printf("Error with %s\n", FileName);
		fclose(fp);
		exit(1);
	}

	char string1[MAX_LCS_LENGTH + 1];
	char string2[MAX_LCS_LENGTH + 1];

	if(!fgets(string1, MAX_LCS_LENGTH, fp))
	{
		printf("Error with %s\n",FileName);
		fclose(fp);
		exit(1);
	}

	if(!fgets(string2, MAX_LCS_LENGTH, fp))
	{
		printf("Error with %s\n",FileName);
		fclose(fp);
		exit(1);
	}

	int string1_Length = strlen(string1);
	int string2_Length = strlen(string2);

	if(string1_Length > string2_Length)
	{
		LCS_X = (char *)malloc((string2_Length + 1) * sizeof(char));
		LCS_Y = (char *)malloc((string1_Length + 1) * sizeof(char));

		strcpy(LCS_X + 1, string2);
		X_LENGTH = string2_Length;
		strcpy(LCS_Y + 1, string1);
		Y_LENGTH = string1_Length;
	}
	else
	{
		LCS_X = (char *)malloc((string1_Length + 1) * sizeof(char));
		LCS_Y = (char *)malloc((string2_Length + 1) * sizeof(char));

		strcpy(LCS_X + 1, string1);
		X_LENGTH = string1_Length;
		strcpy(LCS_Y + 1, string2);
		Y_LENGTH = string2_Length;
	}

}


void allocate_LCS_C(void)
{
	int i;
	LCS_C = (char **)malloc(Y_LENGTH * sizeof(char *));
	for(i = 0; i < Y_LENGTH; i++)
	{
		LCS_C[i] = (char *)malloc(X_LENGTH * sizeof(char));
	}
}


int print_LCS(void)
{

}

void LCS_Multiple_Length(char *FileName)
{

}









