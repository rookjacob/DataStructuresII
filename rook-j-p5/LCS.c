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

		strcpy(LCS_X, string2);
		X_LENGTH = string2_Length;
		strcpy(LCS_Y, string1);
		Y_LENGTH = string1_Length;
	}
	else
	{
		LCS_X = (char *)malloc((string1_Length + 1) * sizeof(char));
		LCS_Y = (char *)malloc((string2_Length + 1) * sizeof(char));

		strcpy(LCS_X, string1);
		X_LENGTH = string1_Length;
		strcpy(LCS_Y, string2);
		Y_LENGTH = string2_Length;
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









