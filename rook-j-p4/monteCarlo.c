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

	for(i = 0; i < numSim; i++)
	{
		fread(&numCat, sizeof(int), 1 , fp);
		freqlist = (int *)realloc(freqlist, numCat * sizeof(int));

		for(j = 0; j < numCat; j++)
		{
		fread(freqlist + j, sizeof(int), 1, fp);

		}

		fread(&numEvent, sizeof(int), 1, fp);
		printf("\n\nSimulation %d\n", i+1);
		runMCSim(numCat, freqlist, numEvent);
	}
	fclose(fp);

}

void runMCSim(int numCategories, int frequencyList[], int numEvents)
{
	int i;
	double expectation = calExpectation(numCategories, frequencyList);
	double simExpectation;
	int sumFrequencies = 0;
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
	srand(time(CLOCK_REALTIME));

	int i = 0;

	int randNum = rand() % intervalList[numCategories - 1];
	while(randNum > intervalList[i] && i < numCategories - 1)
	{

		i++;
	}
	return i;
}

void printSimResults(int numEvents, double simResult, double expectedResult)
{
	double error = (simResult - expectedResult)/expectedResult * 100.0;
	if(error < 0)
		error = error * -1;
	printf("\n"
			"N: %d\n"
			"Simulated result: %.2lf\n"
			"Expected value: %.2lf\n"
			"Error percent: %.3lf\n",
			numEvents, simResult, expectedResult, error );
}

void MCAlgorithm(void)
{
	int i;
	DataSet dataArray[4];

	FILE *fp;
	char filename[16];

	for(i = 0; i < 4; i++)
	{
		snprintf(filename, sizeof(filename), "c%d.txt", i + 1 );
		fp = fopen(filename, "r");

		readConfig(&dataArray[i], fp);
		fclose(fp);
		generateDataSets(&dataArray[i]);
		analyzeDataSets(&dataArray[i]);
	}
	printSummary(dataArray, 4);

}

void readConfig(DataSet *data, FILE *fp)
{


	fscanf(fp, "%d", &data->numBatches);
	fscanf(fp, "%d", &data->numItems);
	fscanf(fp, "%d", &data->perBadBatch);
	fscanf(fp, "%d", &data->perBadItem);
	fscanf(fp, "%d", &data->sampledItems);


	printf("Running:\n"
			"\tNumber of Batches of Items:                        %4d\n"
			"\tNumber of Items in Each Batch:                     %4d\n"
			"\tPercentage of Batches Containing Bad Items:        %4d%%\n"
			"\tPercentage of Items that are bad in a bad set:     %4d%%\n"
			"\tItems Sampled from Each Set:                       %4d\n",
			data->numBatches, data->numItems, data->perBadBatch,
			data->perBadItem, data->sampledItems);

}

void generateDataSets(DataSet *data)
{
	srand(time(NULL));

	int i, j;
	int randNum;
	int badItemCount = 0;//, badBatchCount= 0;
	data->simBadBatches = 0;
	char filename[32];
	FILE *fp;


	printf("\n"
			"Generating Data Sets:\n");
	for(i = 1; i <= data->numBatches; i++)
	{
		randNum = rand()%100;
		badItemCount = 0;

		snprintf(filename, sizeof(filename), "ds_Files/ds%d.txt", i);
		fp = fopen(filename, "w");

		if(randNum < data->perBadBatch)//Bad Batch
		{
			data->simBadBatches++;
			for(j = 0; j< data->numItems; j++)
			{
				randNum = rand()%100;
				if(randNum < data->perBadItem)	//Bad Item
				{
					badItemCount++;
					fprintf(fp, "b\n");
				}
				else					//Good Item
				{
					fprintf(fp, "g\n");
				}
			}
			printf("\tCreate Bad Set Batch #%3d, totBad = %4d Total = %5d PercentBad = %.2lf\n",
					i, badItemCount, data->numItems,
					(double)badItemCount/ (double)data->numItems * 100.0);

		}
		else	//Good Batch
		{
			for(j = 0; j < data->numItems; j++)
			{
				fprintf(fp, "g\n");
			}
		}

		fclose(fp);
	}
	printf("Total Bad Sets = %3d\n\n", data->simBadBatches);

}

void analyzeDataSets(DataSet *data)
{

}

void printSummary(DataSet *data, int size )
{
	int i;
	double PF;
	for(i = 0; i < size; i++)
	{
		PF = pow(1.0 -(double)(data + i)->perBadItem / 100.0,(data + i)->sampledItems );
		printf("\n"
				"Run %d:\n"
				"Number of Batches of Items:                      %4d\n"
				"Number of Items in Each Batch:                   %4d\n"
				"Percentage of Batches Containing Bad Items:      %4d\n"
				"Percentage of Items that are Bad in a Bad Set:   %4d\n"
				"Items Sampled from Each Set:                     %4d\n"
				"Base = %.2lf Exponent = %d\n"
				"P(Failure to Detect Bad Item) = %lf\n"
				"P(Batch is Good) = %lf\n"
				"Percentage of Bad Batches Detected = %d%%\n",
				i, (data + i)->numBatches, (data + i)->numItems, (data + i)->perBadBatch,
				(data + i)->perBadItem, (data + i)->sampledItems,
				1.0 -(double)(data + i)->perBadItem, (data + i)->sampledItems,
				PF, 1.0 - PF, (data +i)->simBadBatchesDet);
	}
}













