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
	int n, m, k, p, q, i, nfact;
	n = CITIES - 1;
	nfact = fact(n);

	Tour TmpTour;
	initTour(&TmpTour);
	BESTTOUR = &TmpTour;
	printTour(&TmpTour);
	for(i = 1; i < nfact; i++)
	{
		m = n - 2;
		while(TmpTour.cityTour[m] > TmpTour.cityTour[m+1])
			m = m - 1;
		k = n - 1;
		while(TmpTour.cityTour[m] > TmpTour.cityTour[k])
			k = k - 1;
		swap(m, k, &TmpTour);
		p = m + 1;
		q = n - 1;
		while(p < q)
		{
			swap(p, q, &TmpTour);
			p++;
			q--;
		}
		calTourWeight(&TmpTour);
		printTour(&TmpTour);
		if(compareTour(&TmpTour, BESTTOUR))
			BESTTOUR = &TmpTour;


	}



}

void initTour(Tour *init)
{
	int i;

	for(i = 1; i < CITIES; i++)
		init->cityTour[i-1] = i;
	init->tourWeight = calTourWeight(init);
}

int fact(int n)
{
	if (n == 1)
		return 1;

	return n * fact(n-1);
}

void swap(int p, int q, Tour *TourSwap)
{
	int tmp = p;
	TourSwap->cityTour[p] = TourSwap->cityTour[q];
	TourSwap->cityTour[q] = tmp;
}

int compareTour(Tour *Tour1, Tour *Tour2)
{
	if(Tour1->tourWeight < Tour2->tourWeight)
		return 1;
	return 0;
}
void execGenetic(void)
{

}

double calTourWeight(Tour *T)
{
	double weight = CITYGRAPH[0][T->cityTour[0]];	//From starting city to first city
	int i;

	for(i = 0; i < CITIES; i++)
	{
		weight += CITYGRAPH[T->cityTour[i]][T->cityTour[i+1]];
	}

	weight += CITYGRAPH[T->cityTour[CITIES - 1]][0]; //From last city to starting city
	T->tourWeight = weight;
	return weight;
}

void printTour(Tour *T)
{
	int i;
	printf("0->");
	for(i = 0; i < CITIES; i++)
	{
		printf("%d->",T->cityTour[0]);
	}
	printf("0\nWeight: %lf\n", T->tourWeight);
}
/*
double calTimeDiff(struct timespec *End, struct timespec *Start)
{
	return difftime(End->tv_sec, Start->tv_sec) + ((double)End->tv_nsec - (double)Start->tv_nsec)/1000000000.0;
}
*/

