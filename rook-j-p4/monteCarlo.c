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
	int i, j;

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

		for(j = 0; j < numCat; i++)
		{
		fread(freqlist + j, sizeof(int), numCat, fp);
		printf("j = %d  %d", j, *(freqlist +j));

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
	int i;
	int numBatch, numItems, badBatches, badItems, sampledItems;
	for(i = 1; i <= 4; i++)
	{
		readConfig(&numBatch, &numItems, &badBatches, &badItems, &sampledItems, i);
		generateDataSets(numBatch, numItems, badBatches, badItems);
	}

}

void readConfig(int *numBatch, int *numItems, int *badBatches, int *badItems, int *sampledItems, int fileNumber)
{
	FILE *fp;
	char filename[16];

	snprintf(filename, sizeof(filename), "c%d.txt", fileNumber);
	fp = fopen(filename, "r");

	fscanf(fp, "%d", numBatch);
	fscanf(fp, "%d", numItems);
	fscanf(fp, "%d", badBatches);
	fscanf(fp, "%d", badItems);
	fscanf(fp, "%d", sampledItems);

	fclose(fp);

	printf("Running:\n"
			"\tNumber of Batches of Items:                        %4d\n"
			"\tNumber of Items in Each Batch:                     %4d\n"
			"\tPercentage of Batches Containing Bad Items:        %4d%%\n"
			"\tPercentage of Items that are bad in a bad set:     %4d%%\n"
			"\tItems Sampled from Each Set:                       %4d\n",
			*numBatch, *numItems, *badBatches, *badItems, *sampledItems);

}

void generateDataSets(int numBatch, int numItems, int badBatches, int badItems)
{
	srand(time(NULL));

	int i, j;
	int randNum;
	int badItemCount = 0, badBatchCount= 0;
	char filename[32];
	FILE *fp;

	pid_t pid;

	pid = fork();
	if(!pid)
	{
		pid = fork();
		if(!pid)
		{
			execlp("if", "if", "[" ,"!", "-d", "ds_Files", "]", (char *)NULL);


		}
		else
		{
			waitpid(pid, NULL, 0);
			pid = fork();
			if(!pid)
			{
			execlp("then","then", "mkdir", "ds_Files", ";" , (char *)NULL);
			}
			else
			{
				waitpid(pid, NULL, 0);
				execlp("fi", "fi", (char *)NULL);
			}
		}
		printf("Error!");
		exit(1);

	}
	else
	{
		waitpid(pid, NULL, 0);
	}
	printf("\n"
			"Generating Data Sets:\n");
	for(i = 1; i <= numBatch; i++)
	{
		randNum = rand()%100;
		badItemCount = 0;

		snprintf(filename, sizeof(filename), "ds_Files/ds%d.txt", i);
		fp = fopen(filename, "w");

		if(randNum < badBatches)//Bad Batch
		{
			badBatchCount++;
			for(j = 0; j< numItems; j++)
			{
				randNum = rand()%100;
				if(randNum < badItems)	//Bad Item
				{
					badItemCount++;
					fprintf(fp, "b\n");
				}
				else					//Good Item
				{
					fprintf(fp, "g\n");
				}
			}
			printf("Create Bad Set Batch #%3d, totBad = %4d Total = %5d PercentBad = %.2lf\n",
					i, badItemCount, numItems, (double)badItemCount/ (double)numItems * 100.0);
		}
		else	//Good Batch
		{
			for(j = 0; j < numItems; j++)
			{
				fprintf(fp, "g\n");
			}
		}

		fclose(fp);
	}
	printf("Total Bad Sets = %3d\n\n", badBatchCount);

}














