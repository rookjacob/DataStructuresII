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
	FILE *fp2 = fopen("SimParameters.dat", "wb");

	while(fp && fscanf(fp, "%d", &i) != EOF )
	{
		fwrite(&i, sizeof(int),1, fp2);
	}
	fclose(fp);
	fclose(fp2);
}

void MCSimulation(void)
{
	int i;

	int numSim, numCat, numEvent;
	int *freqlist = NULL;

	FILE *fp;

	fp = fopen("SimParameters.dat", "rb");
	if(!fp)
	{
		printf("Unable to open SimParameters.dat!");
		exit(1);
	}
	fread(&numSim, sizeof(int), 1, fp);
	printf("numSim = %d\n", numSim);

	for(i = 0; i < numSim; i++)
	{
		fread(&numCat, sizeof(int), 1 , fp);
		printf("numCat = %d\n", numCat);
		freqlist = (int *)realloc(freqlist, numCat * sizeof(int));

		if (fread(&freqlist, sizeof(int), numCat, fp) != (numCat * sizeof(int)) )
		{
			printf("Error with reading SimParameters.dat!");
			//exit(1);
		}
		fread(&numEvent, sizeof(int), 1, fp);
		printf("numEvent = %d\n", numEvent);
		printf("Simulation %d\n", i+1);
		runMCSim(numCat, freqlist, numEvent);
	}
	fclose(fp);

}

void runMCSim(int numCategories, int frequencyList[], int numEvents)
{
	int i;
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
	srand(time(NULL));

	int i = 0;

	int randNum = rand() % intervalList[numCategories - 1];
	while(i < numCategories)
	{
		if(randNum > intervalList[i])
			continue;
		else
			break;
	}
	return i;
}

void printSimResults(int numEvents, double simResult, double expectedResult)
{
	double error = (simResult - expectedResult)/expectedResult;
	if(error < 0)
		error = error * -1;
	printf("\n"
			"N: %d\n"
			"Simulated result: %.2lf\n"
			"Expected value: %.2lf\n"
			"Error percent: %0.3lf\n",
			numEvents, simResult, expectedResult, error );
}

void MCAlgorithm(void)
{
	printf("MCAlgorithm\n");
}















