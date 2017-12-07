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
	int i, j;
	initXY(FileName);

	LCS_C = NULL;
	LCS_X = NULL;
	LCS_Y = NULL;

	allocate_LCS_C();

	for(i = 1; i <= X_LENGTH; i++)
	{
		for(j = 1; j <= Y_LENGTH; j++)
		{
			if(LCS_X[i] == LCS_Y[j])
			{
				LCS_C[i][j] = LCS_C[i-1][j-1] + 1;
			}
			else
			{
				if(LCS_C[i-1][j] >= LCS_C[i][j -1])
				{
					LCS_C[i][j] = LCS_C[i-1][j];
				}
				else
				{
					LCS_C[i][j] = LCS_C[i][j-1];
				}
			}
		}
	}
	printf("LCS: ");
	print_LCS(X_LENGTH,Y_LENGTH);
	printf("\n");

	i = LCS_C[X_LENGTH][Y_LENGTH];
	//deallocate_LCS_Var(); //NOT WORKING
	return i;
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

	if(!fgets(string1, MAX_LCS_LENGTH + 1, fp))
	{
		printf("Error with %s\n",FileName);
		fclose(fp);
		exit(1);
	}

	if(!fgets(string2, MAX_LCS_LENGTH + 1, fp))
	{
		printf("Error with %s\n",FileName);
		fclose(fp);
		exit(1);
	}
	fclose(fp);
	int string1_Length = strlen(string1);
	int string2_Length = strlen(string2);
	string1[string1_Length] = '\0';

	string2[string2_Length] = '\0';


	if(string1_Length < string2_Length)
	{
		LCS_X = (char *)realloc(LCS_X,(string2_Length ) * sizeof(char));
		LCS_Y = (char *)realloc(LCS_Y, (string1_Length) * sizeof(char));

		strcpy(LCS_X + 1, string2);
		X_LENGTH = string2_Length - 1;
		strcpy(LCS_Y + 1, string1);
		Y_LENGTH = string1_Length - 1;
	}
	else
	{
		LCS_X = (char *)realloc(LCS_X, (string1_Length) * sizeof(char));
		LCS_Y = (char *)realloc(LCS_Y, (string2_Length) * sizeof(char));

		strcpy(LCS_X + 1, string1);
		X_LENGTH = string1_Length - 1;
		strcpy(LCS_Y + 1, string2);
		Y_LENGTH = string2_Length - 1;
	}
	LCS_X[0] = ' ';
	LCS_Y[0] = ' ';

}


void allocate_LCS_C(void)
{
	int i;
	LCS_C = (int **)realloc(LCS_C,(X_LENGTH + 1) * sizeof(int *));
	for(i = 0; i <= X_LENGTH; i++)
	{
		LCS_C[i] = (int *)realloc(LCS_C[i],(Y_LENGTH + 1) * sizeof(int));
	}
	for(i = 1; i <= X_LENGTH ; i++)
	{
		LCS_C[i][0] = 0;
	}
	for(i = 0; i <= Y_LENGTH; i++)
	{
		LCS_C[0][i] = 0;
	}
}

void deallocate_LCS_Var(void)
{
	int i;
	if(LCS_X)
	{
		realloc(LCS_X, 0);
	}
	if(LCS_Y)
	{
		realloc(LCS_Y, 0);
	}
	if(LCS_C)
	{
		for(i = 0; i <= X_LENGTH; i++)
		{
			if(LCS_C[i])
			{
				realloc(LCS_C[i], 0);
			}
		}
		realloc(LCS_C, 0);
	}
}


void print_LCS(int i, int j)
{
	if(i <= 0 || j <= 0)
	{
		return;
	}
	if(LCS_X[i] == LCS_Y[j])
	{
		print_LCS(i-1, j-1);
		printf("%c", LCS_X[i]);
	}
	else if(LCS_C[i-1][j] >= LCS_C[i][j-1])
	{
		print_LCS(i-1,j);
	}
	else
	{
		print_LCS(i,j-1);
	}
}

void LCS_Multiple_Length(char *FileName)
{
	INT_LIST = NULL;
	init_Interval_List(FileName);

}

void init_Interval_List(char *FileName)
{
	read_NUM_LCS(FileName);
	INT_LIST = (int *)realloc(INT_LIST, (NUM_LCS + 1) * sizeof(char));

	FILE *fp;
	fp = fopen(FileName, "r");
	fseek(fp, 0, SEEK_SET);

	int i;
	char tmp[MAX_LCS_LENGTH + 2];

	tmp = fgets(tmp, MAX_LCS_LENGTH + 2, fp);
	INT_LIST[0] = strlen(tmp);
	for(i = 1; i < NUM_LCS; i++)
	{
		if(fgets(tmp, MAX_LCS_LENGTH + 2, fp))
		{
			INT_LIST[i] = strlen(tmp) + INT_LIST[i - 1];
			if(!INT_LIST[i])
			{
				printf("Error reading string %d", i);
				fclose(fp);
				exit(1);
			}
		}
		else
		{
			printf("Error reading %s\n", FileName);
			fclose(fp);
			exit(1);
		}
	}
	fclose(fp);
}

void read_NUM_LCS(char *FileName)
{
	FILE *fp;
	fp = fopen(FileName, "r");

	if(!fp)
	{
		printf("Error with %s\n", FileName);
		fclose(fp);
		exit(1);
	}


	int tmp = fscanf(fp, "%d",&NUM_LCS);

	if(tmp == EOF || tmp != 1)
	{
		printf("%s has invalid format\n", FileName);
		fclose(fp);
		exit(1);
	}
	fclose(fp);
}









