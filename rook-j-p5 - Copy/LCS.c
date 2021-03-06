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
	LCS_X = NULL;
	LCS_Y = NULL;

	init_XY_C(FileName);

	LCS_C = NULL;
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
	deallocate_LCS_Var(); //NOT WORKING
	return i;
}

void init_XY_C(char *FileName)
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
		exit(1);
	}

	if(!fgets(string2, MAX_LCS_LENGTH + 1, fp))
	{
		printf("Error with %s\n",FileName);
		exit(1);
	}
	fclose(fp);
	int string1_Length = strlen(string1);
	int string2_Length = strlen(string2);
	string1[string1_Length - 1] = '\0';
	printf("[%s]\n",string1);
	string2[string2_Length - 1] = '\0';
	printf("[%s]\n", string2);

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
		LCS_C[i] = (int *)realloc(NULL,(Y_LENGTH + 1) * sizeof(int));
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
	//free(LCS_X);
	LCS_X = realloc(LCS_X, 0);

	LCS_Y = realloc(LCS_Y, 0);

	for(i = 0; i <= X_LENGTH; i++)
	{
		if(LCS_C[i])
		{
			LCS_C[i] = realloc(LCS_C[i], 0);
		}
	}
	LCS_C = realloc(LCS_C, 0);

	LCS_M1 = realloc(LCS_M1, 0);
	LCS_M2 = realloc(LCS_M2,0);

	INT_LIST = realloc(INT_LIST,0);

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

	int i, j;

	printf("   ");
	for(i = 1; i <= NUM_LCS; i++)
	{
		printf("%d  ", i);
	}
	printf("\n");

	for(i = 1; i <= NUM_LCS; i++)
	{
		printf("%d  ",i);
		for(j = 1; j <= NUM_LCS; j++)
		{
			if(i >= j)
			{
				printf("-  ");
			}
			else
			{
				printf("%c  ", sequence_Similarity(i,j,FileName));
			}
		}
		printf("\n");
	}

}

void init_Interval_List(char *FileName)
{
	read_NUM_LCS(FileName);
	INT_LIST = (int *)realloc(INT_LIST, (NUM_LCS) * sizeof(int));

	FILE *fp;
	fp = fopen(FileName, "r");
	fseek(fp, 0, SEEK_SET);

	int i;
	char tmp[MAX_LCS_LENGTH + 2];

	fgets(tmp, MAX_LCS_LENGTH + 2, fp);
	INT_LIST[0] = strlen(tmp);

	for(i = 1; i < NUM_LCS; i++)
	{
		if(fgets(tmp, MAX_LCS_LENGTH + 1, fp))
		{
			INT_LIST[i] = strlen(tmp) + INT_LIST[i - 1];
			printf("%d %d\n", i, INT_LIST[i]);
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
	fclose(fp);//NEED TO FIXX
}

void read_NUM_LCS(char *FileName)
{
	FILE *fp;
	fp = fopen(FileName, "r");

	if(!fp)
	{
		printf("Error with %s\n", FileName);
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

char sequence_Similarity(int r, int c, char *FileName)
{
	init_XY_2M(r,c, FileName);

	int LCS_L = LCS_Length_2M();

	double XY_percent_Length = (double)Y_LENGTH / (double)X_LENGTH;
	double LCS_percent_Length = (double)LCS_L / (double)Y_LENGTH;

	if(XY_percent_Length >= .9 && LCS_percent_Length >= .8)
	{
		return 'H';
	}
	else if(XY_percent_Length >= .8 && LCS_percent_Length >= .6)
	{
		return 'M';
	}
	else if(XY_percent_Length >= .6 && LCS_percent_Length >= .5)
	{
		return 'L';
	}
	else
	{
		return 'D';
	}
}

void init_XY_2M(int r, int c, char *FileName)
{
	char tmp1[MAX_LCS_LENGTH + 1];
	char tmp2[MAX_LCS_LENGTH + 1];

	FILE *fp = fopen(FileName, "r");
	if(!fp)
	{
		printf("Error with %s\n", FileName);
		exit(1);
	}

	fseek(fp, INT_LIST[r - 1], SEEK_SET);
	fgets(tmp1, MAX_LCS_LENGTH, fp);

	fseek(fp, INT_LIST[c - 1], SEEK_SET);
	fgets(tmp2, MAX_LCS_LENGTH, fp);

	fclose(fp);

	int tmp1_Length = strlen(tmp1);
	int tmp2_Length = strlen(tmp2);

	tmp1[tmp1_Length] = '\0';
	tmp2[tmp2_Length] = '\0';


	if(tmp1_Length < tmp2_Length)
	{
		LCS_X = (char *)realloc(LCS_X,(tmp2_Length ) * sizeof(char));
		LCS_Y = (char *)realloc(LCS_Y, (tmp1_Length) * sizeof(char));

		strcpy(LCS_X + 1, tmp2);
		X_LENGTH = tmp2_Length - 1;
		strcpy(LCS_Y + 1, tmp1);
		Y_LENGTH = tmp1_Length - 1;
	}
	else
	{
		LCS_X = (char *)realloc(LCS_X, (tmp1_Length) * sizeof(char));
		LCS_Y = (char *)realloc(LCS_Y, (tmp2_Length) * sizeof(char));

		strcpy(LCS_X + 1, tmp1);
		X_LENGTH = tmp1_Length - 1;
		strcpy(LCS_Y + 1, tmp2);
		Y_LENGTH = tmp2_Length - 1;
	}
	LCS_X[0] = ' ';
	LCS_Y[0] = ' ';

}

int LCS_Length_2M(void)
{
	init_LCS_M12();

	int *Top = LCS_M1;
	int *Bottom = LCS_M2;
	int i, j;

	for(i = 1; i <= X_LENGTH; i++)
	{
		for(j = 1; j <= Y_LENGTH; j++)
		{
			if(LCS_X[i] == LCS_Y[j])
			{
				Bottom[j] = Top[j - 1] + 1;
			}
			else
			{
				if(Top[j] >= Bottom[j-1])
				{
					Bottom[j] = Top[j];
				}
				else
				{
					Bottom[j] = Bottom[j -1];
				}
			}
		}
		swap_Top_Bottom(Top,Bottom);
	}
}

void init_LCS_M12(void)
{
	LCS_M1 = (int *)realloc(LCS_M1, Y_LENGTH * sizeof(int));
	LCS_M2 = (int *)realloc(LCS_M2, Y_LENGTH * sizeof(int));

	int i;

	for(i = 0; i < Y_LENGTH; i++)
	{
		LCS_M1[i] = 0;
	}
	LCS_M2[0] = 0;
}

void swap_Top_Bottom(int *Top, int *Bottom)
{
	int *tmp = Top;
	Top = Bottom;
	Bottom = tmp;
	Bottom[0] = 0;
}









