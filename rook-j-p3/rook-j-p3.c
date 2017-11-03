/*
 * @file rook-j-p3.c	File contains the main function for Project 3, the traveling
 * salesman problem. The main function asked the user for the desired input and
 * sends that information to the Traveling Salesman algorithms. The main function
 * asks the user if they want to generate a new cityWeights.txt if so the genNewWight
 * function is called. There is not input validation, so any invalid input will crash
 * the program.
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
	scanf("\n%c", &newGen);

	if(newGen == 'y')
		genNewWeight();
	startTravel(numCities, numTours, numGen, percentMut);







	return 0;
}

