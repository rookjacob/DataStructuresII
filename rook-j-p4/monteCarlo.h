/*
 * @file monteCarlo.h
 *
 * @author Jacob Rook
 * @date 11/16/2017
 * @info Course COP 4534
 * Project 4
 */

#ifndef MONTECARLO_H_
#define MONTECARLO_H_

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<sys/wait.h>

typedef struct Data {
	int numBatches;
	int numItems;
	int perBadBatch;
	int perBadItem;
	int sampledItems;
	int simBadBatches;
	int simBadBatchesDet;
}DataSet;


/*
 *
 */
void txt2Binary(void);


/*
 *
 */
void MCSimulation(void);

/*
 *
 */
void runMCSim(int numCategories, int frequencyList[], int numEvents);

/*
 *
 */
double calExpectation(int numCategories, int frequencyList[]);

/*
 *
 */
int generateRandEvent(int numCategories, int intervalList[]);

/*
 *
 */
void printSimResults(int numEvents, double simResult, double expectedResult);

/*
 *
 */
void MCAlgorithm(void);

/*
 *
 */
void readConfig(int *numBatch, int *numItems, int *badBatches, int *badItems, int *sampledItems, int file);

/*
 *
 */
void generateDataSets(int numBatch, int numItems, int badBatches, int badItems);


#endif /* MONTECARLO_H_ */
