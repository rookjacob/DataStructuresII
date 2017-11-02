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



void startTravel(int numCities, int numTours, int numGen, double percentMut)
{
	//struct timespec TimeStart, TimeEnd;
	//double BFTime, GTime;

	initTourVar(numCities, numTours, numGen, percentMut);

	//clock_gettime(CLOCK_REALTIME, &TimeStart);
	execBruteForce();
	//clock_gettime(CLOCK_REALTIME, &TimeEnd);
	//BFTime = calTimeDiff(&TimeEnd, &TimeStart);

	//clock_gettime(CLOCK_REALTIME, &TimeStart);
	execGenetic();
	//clock_gettime(CLOCK_REALTIME, &TimeEnd);
	//GTime = calTimeDiff(&TimeEnd, &TimeStart);



}

void initTourVar(int numCities, int numTours, int numGen, double percentMut)
{
	CITIES = numCities;
	TOURSNGEN = numTours;
	GENERATIONS = numGen;
	MUTATIONS = floor(percentMut *  TOURSNGEN / 100);

	if (MUTATIONS > (TOURSNGEN - 2))
		MUTATIONS = TOURSNGEN - 2;

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
	fclose(fp);

}

void populateGraph(void)
{
	FILE *fp = fopen("cityWeights.txt", "r");
	int i;
	int j;
	double tmp;

	for(i = 0; i < MAXCITIES; i++)
	{
		printf("\n");
		for(j = 0; j < MAXCITIES; j++)
		{
			if(i == j)
			{
				continue;
			}
			fscanf(fp, "%lf ", &tmp);
			CITYGRAPH[i][j] = tmp;
		}
	}
	fclose(fp);
}

void execBruteForce(void)
{
	Tour BestTour;
	BestTour.cityTour[0] = 0;
	BestTour.cityTour[1] = 1;
	BestTour.cityTour[2] = 2;
	BestTour.cityTour[3] = 3;
	BestTour.cityTour[4] = 0;
	int n = 3;
	int m, k, p, q, i;
	int nfact = fact(n);
	double tmp;
	printf("01234\n");
	for(i = 1; i < nfact; i++)
	{
		m = n - 2;
		while(BestTour.cityTour[m] > BestTour.cityTour[m+1])
			m = m - 1;
		k = n -1;
		tmp = BestTour.cityTour[m];
		BestTour.cityTour[m] = BestTour.cityTour[k];
		BestTour.cityTour[k] = tmp;

		p = m + 1;
		q = n - 1;
		while (p < q)
		{
			tmp = BestTour.cityTour[p];
			BestTour.cityTour[p] = BestTour.cityTour[q];
			BestTour.cityTour[q] = tmp;
			p++;
			q--;
		}
		printf("%d %d%d%d %d\n",BestTour.cityTour[0],BestTour.cityTour[1],BestTour.cityTour[2],BestTour.cityTour[3],BestTour.cityTour[4]);



	}




}

int fact(int n)
{
	if (n == 1)
		return 1;

	return n * fact(n-1);
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

