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
		runMCSim(numCat, freqlist, numEvent);
	}


}

void runMCSim(int numCategories, int frequencyList[], int numEvents)
{
	int i, j;
	double expectation = calExpectation(numCategories, frequencyList);
	double simExpectation;
	int sumFrequencies = -1;
	int sumRandEvents = 0;

	for(i = 0; i < numCategories; i++)
	{
		sumFrequencies = sumFrequencies + frequencyList[i];
		frequencyList[i] = sumFrequencies;
	}
	for(i = 0; i < numEvents; i++)
	{
		sumRandEvents = sumRandEvents + generateRandEvent(numCategories, frequencyList);
	}
	simExpectation = (double)sumRandEvents/ (double)numEvents;
	printSimResults(numEvents, simExpectation, expectation);
}

double calExpectation(int numCategories, int frequencyList[])
{
	int i;
	double expectation = 0;
	int sumFrequencies = 0;

	for(i = 0; i< numCategories; i++)
	{
		sumFrequencies = sumFrequencies + frequencyList[i];
	}

	for(i = 0; i < numCategories; i++)
	{
		expectation = expectation + (double)i * (double)(frequencyList[i])/ (double)(sumFrequencies);
	}
	return expectation;
}

int generateRandEvent(int numCategories, int intervalList[])
{

}

void printSimResults(int numEvents, double simResult, double expectedResult)
{

}

void MCAlgorithm(void)
{
	printf("MCAlgorithm\n");
}















