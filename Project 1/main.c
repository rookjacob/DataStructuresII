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
#include<stdlib.h>

#endif

#include"Functions.h"






int main(void)
{
	ROOT.Type = 'D';							//Initializing ROOT variables
	strcpy(ROOT.DirName, "rook/root");
	DirectoryFile *Curr;// = (DirectoryFile*)malloc(sizeof(DirectoryFile));
	Curr = &ROOT;
	/*
	DirectoryFile Node = { 'D', "NODE", &ROOT, NULL};
	DirectoryFile Node1 = { 'D', "NODE1", &ROOT, &Node};
	ROOT.DirList = &Node1;
	*/


	FILE * CommandInput;
	char CommandFile[]="TestFile.txt";			//File to read the commands from
	CommandInput = fopen(CommandFile, "r");		//Opening the file containing the commands

	char CommandLine[100]="\0";					//Character array to store the command line input from file

	int i;
	int j;

	while(fgets(CommandLine, 100, CommandInput) != NULL)
	{
		printf("\n$ %s", CommandLine);
		j=Tokenizer(CommandLine, " \t\n");

		/*for(i=0;i<j;i++)
			printf("%s ",Tokens[i]);
		printf("\n");*/

		CommandOperator(Curr);


	}



	fclose(CommandInput);
	printf("\nexit");
	return 0;

}

