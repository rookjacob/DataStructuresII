/*
 * @file main.c This file is the main C file for a basic directory that
 * processes basic Unix/Linux commands.
 *
 * @author Jacob Rook
 * @date 09/05/2017
 * @info Course COP 4534
 * Project 1
 */

#include <stdio.h>
#include <string.h>
#include "Structs.h"
#include"Functions.h"
#include "Tokenize.h"





int main(void)
{

	FILE * CommandInput;
	char CommandFile[]="TestFile.txt";			//File to read the commands from
	CommandInput = fopen(CommandFile, "r");		//Opening the file containing the commands

	char CommandLine[100]="\0";					//Character array to store the command line input from file

	char *Tokens[10];							//Array of pointers to store the tokens of the command line input


	while(fgets(CommandLine, 100, CommandInput) != NULL)
	{
		printf("%s", CommandLine);

	}



	fclose(CommandInput);
	printf("\nexit");
	return 0;

}

