/*
 * RookFunctions.c
 *
 *  Created on: Oct 31, 2017
 *      Author: rookj
 */


#include"RookFunctions.h"

#include<stdio.h>
#include<stdlib.h>


int intInputValid(const char *Prompt, int *variable)
{
	char input[MAXINPUT];

	do
	{
		printf("%s", Prompt);
		gets(input);
		*variable = atoi(input);
		if (!(*variable))
			printError();
	}while(!(int)(*variable));
	return *variable;
}

void printError(void)
{
	printf("Invalid Input!\n");
}







