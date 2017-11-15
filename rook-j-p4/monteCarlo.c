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
		fprintf(fp2, "%d", i);
	}

}

void MCSimulation(void)
{
	int i;

	int numSim, numCat, numEvent;
	int *freqlist = NULL;

	FILE *fp;

	fp = fopen("SimParameters.bin", "rb");
	if(!fp)
	{
		printf("Unable to open SimParameters.bin!");
		exit(1);
	}
	fread(&numSim, sizeof(int), 1, fp);

	for(i = 0; i < numSim; i++)
	{
		fread(&numCat, sizeof(int), 1 , fp);
		freqlist = realloc(freqlist, numCat * sizeof(int));

		if (fread(freqlist, sizeof(int), numCat, fp) != (numCat * sizeof(int)) )
		{
			printf("Error with reading SimParameters.bin!");
			exit(1);
		}
		fread(&numEvent, sizeof(int), 1, fp);

		printf("Simulation %d\n", i+1);
		runMCSim(numSim, numCat, freqlist, numEvent);
	}


}

void runMCSim(int numSimulations, int numCategories, int frequencyList[], int numEvents)
{

}

void MCAlgorithm(void)
{
	printf("MCAlgorithm\n");
}















