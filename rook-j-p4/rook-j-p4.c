/*
 * @file rook-j-p4.c	This file contains the main file for the Monte Carlo to call]
 * the functions for the Monte Carlo simulation and algorithm. The main function will
 * ask the user if they would like to convert the SimParameters.txt to a binary file
 * if so, the program will call txt2Binary to do just that. Then the program will ask
 * if the user will want to do the Monte Carlo simulation or algorithm continuously
 * until the exit program option is chosen.
 *
 * @author Jacob Rook
 * @date 11/16/2017
 * @info Course COP 4534
 * Project 4
 */

#include<stdio.h>

#include"monteCarlo.h"


int main(void)
{
	char cond;
	printf("Would you like to convert SimParameters.txt to a binary file? (y/n)");
	scanf("\n%c", &cond);
	if(cond == 'Y' || cond == 'y')
	{
		txt2Binary();
	}
	while(1)
	{
		printf("\n"
				" Option                      Choice\n\n"
				"    1          Implement a Monte Carlo Simulation\n"
				"    2          Implement a Simple Monte Carlo Algorithm\n"
				"    3          Exit Program\n"
				"\n"
				"Please enter an Option: ");

		scanf("\n%c", &cond);

		switch(cond)
		{
		case '1':
			MCSimulation();
			break;
		case '2':
			MCAlgorithm();
			break;
		case '3':
			return 0;
		default:
			printf("Invalid Option\n");
			break;
		}
	}


	return 0;
}
