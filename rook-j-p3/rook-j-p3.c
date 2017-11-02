/*
 * @file rook-j-p3.c
 *
 * @author Jacob Rook
 * @date 11/02/2017
 * @info Course COP 4534
 * Project 3
 */


#include<stdio.h>
#include<stdlib.h>
#include"TravelingSalesman.h"

int main(void)
{
	int numCities = 0;
	int numTours = 0;
	int numGen = 0;
	double percentMut = 0;
	char newGen;
	/*
	printf("Traveling Salesman Program\n\n");

	printf("Please enter the number of cities to run.\n ");
	scanf("%d", &numCities);
	printf("Please enter the number of individual tours are in a given generation.\n");
	scanf("%d", &numTours);
	printf("Please enter the number of generations to run.\n");
	scanf("%d", &numGen);
	printf("Please enter the percentage of generations that should be comprised of mutations.\n");
	scanf("%lf", &percentMut);
	printf("Will a new cityWeights.txt be generated? (y/n)\n");
	scanf("%c", &newGen);

	if(newGen == 'y')
		startTravel(numCities, numTours, numGen, percentMut, 1);
	else
		startTravel(numCities, numTours, numGen, percentMut, 0);
*/
	genNewWeight();






	return 0;
}

