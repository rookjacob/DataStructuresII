/*
 * @file rook-j-p4.c
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
		//Call function
	}
	while(1)
	{
		printf("\n "
				" Option		Choice"
				"    1			Implement a Monte Carlo Simulation\n"
				"    2          Implement a Simple Monte Carlo Algorithm\n"
				"	 3 			Exit Program");
		scanf("\n%c", &cond);

		switch(cond)
		{
		case '1':
			//Call function
			break;
		case '2':
			//Call function
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
