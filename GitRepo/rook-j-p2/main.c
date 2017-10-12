/*
 * @file main.c
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
