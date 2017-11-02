/*
 * @file TravelingSalesman.c
 *
 * @author Jacob Rook
 * @date 11/02/2017
 * @info Course COP 4534
 * Project 3
 */

#include"TravelingSalesman.h"
#include<time.h>
#include<stdio.h>


void startTravel(int numCities, int numTours, int numGen, double percentMut)
{
	struct timespec TimeStart, TimeEnd;
	double BFTime, GTime;

	initTourVar(numCities, numTours, numGen, percentMut);

	clock_gettime(CLOCK_REALTIME, &TimeStart);
	execBruteForce();
	clock_gettime(CLOCK_REALTIME, &TimeEnd);
	BFTime = calTimeDiff(&TimeEnd, &TimeStart);

	clock_gettime(CLOCK_REALTIME, &TimeStart);
	execGenetic();
	clock_gettime(CLOCK_REALTIME, &TimeEnd);
	GTime = calTimeDiff(&TimeEnd, &TimeStart);



}

void initTourVar(int numCities, int numTours, int numGen, double percentMut)
{
	CITIES = numCities;

}

void genNewWeight(void)
{

}

void populateGraph(void)
{

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

double calTimeDiff(struct timespec *End, struct timespec *Start)
{
	return difftime(End->tv_sec, Start->tv_sec) + ((double)End->tv_nsec - (double)Start->tv_nsec)/1000000000.0;
}


