/*
 * @file main.c		File contains the main function which calls the functions
 * of Analytical.h. The main function first asks the user for the statistic information
 * needed for the simulation and sets the values using the Analytical.h's set
 * functions. Then the main function calls the printAllCal function to print the
 * expected calculations. After, that the runSimulation function is called to run
 * the simulation. And, then the printComparison function is called to compare the
 * expected and simulated values.
 *
 * @author Jacob Rook
 * @date 10/12/2017
 * @info Course COP 4534
 * Project 2
 */

#include<stdio.h>
#include"Analytical.h"


int main (void)
{
	float val;
	printf("Please enter the number of arrivals to simulate: ");
	scanf("%f", &val);
	setN(val);
	printf("Please enter the average arrivals in a time period: ");
	scanf("%f", &val);
	setLambda(val);
	printf("Please enter the average number served in a time period: ");
	scanf("%f", &val);
	setMu(val);
	printf("Please enter the number of service channels: ");
	scanf("%f", &val);
	setM(val);

	printf("\nAnalytical Model Calculations\n");
	printAllCal();
	printf("\n");

	printf("\nSimulated Model Calculations\n");
	runSimulation();

	printf("\n\nSimulation Comparisons\n");
	printComparison();

	return 0;
}
