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

	printAllCal();
	printf("fact(5) = %f",fact(5));
	printf("\n 5^5 = %f", power(5,5));

	return 0;
}
