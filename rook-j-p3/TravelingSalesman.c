/*
 * @file TravelingSalesman.c
 *
 * @author Jacob Rook
 * @date 11/02/2017
 * @info Course COP 4534
 * Project 3
 */

#include"TravelingSalesman.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>



void startTravel(int numCities, int numTours, int numGen, double percentMut, int newGen)
{
	//struct timespec TimeStart, TimeEnd;
	//double BFTime, GTime;

	initTourVar(numCities, numTours, numGen, percentMut, newGen);

	//clock_gettime(CLOCK_REALTIME, &TimeStart);
	execBruteForce();
	//clock_gettime(CLOCK_REALTIME, &TimeEnd);
	//BFTime = calTimeDiff(&TimeEnd, &TimeStart);

	//clock_gettime(CLOCK_REALTIME, &TimeStart);
	execGenetic();
	//clock_gettime(CLOCK_REALTIME, &TimeEnd);
	//GTime = calTimeDiff(&TimeEnd, &TimeStart);



}

void initTourVar(int numCities, int numTours, int numGen, double percentMut, int newGen)
{
	CITIES = numCities;
	TOURSNGEN = numTours;
	GENERATIONS = numGen;
	MUTATIONS = floor(percentMut *  TOURSNGEN / 100);

	if (MUTATIONS > (TOURSNGEN - 2))
		MUTATIONS = TOURSNGEN - 2;

	if(newGen)
		genNewWeight();

	populateGraph();



}

void genNewWeight(void)
{
	FILE *fp = fopen("cityWeights.txt", "w");
	int i;
	double DoubleMax = 100.0;
	double tmp;
	srand((unsigned int)time(NULL));

	for(i = 0 ; i < 380 ; i++)
	{
		tmp = ((double)rand()/(double)RAND_MAX) * DoubleMax;
		fprintf(fp, "%lf\n", tmp);
	}

}

void populateGraph(void)
{
	FILE *fp = fopen("cityWeights.txt", "r");
	int i;
	int j;
	double tmp;

	for(i = 1; i < MAXCITIES; i++)
	{
		printf("\n");
		for(j = 0; j < MAXCITIES; j++)
		{
			if(i == j)
				continue;
			fscanf(fp, "%lf ", &tmp);
			printf("%lf ", tmp);
			CITYGRAPH[i][j] = tmp;
		}
	}
}

void execBruteForce(void)
{

}

int fact(int n)
{

}

void swap(int p, int q)
{

}

void execGenetic(void)
{

}

double calTourWeight(Tour *T)
{

}
/*
double calTimeDiff(struct timespec *End, struct timespec *Start)
{
	return difftime(End->tv_sec, Start->tv_sec) + ((double)End->tv_nsec - (double)Start->tv_nsec)/1000000000.0;
}
*/

