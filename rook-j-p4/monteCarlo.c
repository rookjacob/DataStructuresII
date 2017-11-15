/*
 * @file monteCarlo.c
 *
 * @author Jacob Rook
 * @date 11/16/2017
 * @info Course COP 4534
 * Project 4
 */

#include"monteCarlo.h"


void txt2Binary(void)
{
	int i;

	FILE *fp = fopen("SimParameters.txt", "r");
	FILE *fp2 = fopen("SimParameters.bin", "wb");

	while(fp || fscanf(fp, "%d", &i) != EOF )
	{
		fprintf(fp2, "%d", &i);
	}

}

void MCSimulation(void)
{
	printf("MCSimulation\n");
}

void MCAlgorithm(void)
{
	printf("MCAlgorithm\n");
}















