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
	deallocate_LCS_Var();
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

	int string1_Length = strlen(string1);
	int string2_Length = strlen(string2);
	string1[string1_Length] = '\0';
	string2[string2_Length] = '\0';


	if(string1_Length < string2_Length)
	{
		LCS_X = (char *)malloc((string2_Length ) * sizeof(char));
		LCS_Y = (char *)malloc((string1_Length) * sizeof(char));

		strcpy(LCS_X + 1, string2);
		X_LENGTH = string2_Length - 1;
		strcpy(LCS_Y + 1, string1);
		Y_LENGTH = string1_Length - 1;
	}
	else
	{
		LCS_X = (char *)malloc((string1_Length) * sizeof(char));
		LCS_Y = (char *)malloc((string2_Length) * sizeof(char));

		strcpy(LCS_X + 1, string1);
		X_LENGTH = string1_Length - 1;
		strcpy(LCS_Y + 1, string2);
		Y_LENGTH = string2_Length - 1;
	}

}


void allocate_LCS_C(void)
{
	int i;
	LCS_C = (int **)malloc((X_LENGTH + 1) * sizeof(int *));
	for(i = 0; i < X_LENGTH; i++)
	{
		LCS_C[i] = (int *)malloc((Y_LENGTH + 1) * sizeof(int));
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
		free(LCS_X);
	}
	if(LCS_Y)
	{
		free(LCS_Y);
	}
	if(LCS_C)
	{
		for(i = 0; i <= X_LENGTH; i++)
		{
			if(LCS_C[i])
			{
				free(LCS_C[i]);
			}
		}
		free(LCS_C);
	}
}


void print_LCS(int i, int j)
{
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
	printf("LCS_Multiple\n");
}









