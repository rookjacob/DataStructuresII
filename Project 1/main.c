/*
 * @file main.c This file is the main C file for a basic directory that
 * processes basic Unix/Linux commands.
 *
 * @author Jacob Rook
 * @date 09/05/2017
 * @info Course COP 4534
 * Project 1
 */

#ifndef MAININCLUDES
#define MAININCLUDES

#include<stdio.h>
#include<string.h>

#endif

#include"Functions.h"






int main(void)
{
	ROOT.Type = 'D';							//Initializing ROOT variables
	strcpy(ROOT.DirName, "rook/root");
	CURR = &ROOT;

	FILE * CommandInput;
	char CommandFile[]="TestFile.txt";			//File to read the commands from
	CommandInput = fopen(CommandFile, "r");		//Opening the file containing the commands

	char CommandLine[100]="\0";					//Character array to store the command line input from file


	while(fgets(CommandLine, 100, CommandInput) != NULL)
	{
		printf("\n$ %s", CommandLine);
		Tokenizer(CommandLine, " \t\n");

		CommandOperator();


	}



	fclose(CommandInput);
	printf("\nexit");
	return 0;

}

