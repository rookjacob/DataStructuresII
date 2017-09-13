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

	//FILE* CommandInput;
	//char CommandFile[]="TestFile.txt";		//File to read the commands from

	char CommandLine[100]="Hello hi  akffhkl   kjhlk  kjhlk kjbk \0";				//Character arry to store the command line input from file

	char *Tokens[10];
/*
	CommandInput = fopen(CommandFile, "r");

	int i=0;
	do
	{
		fscanf(CommandInput, "%c", (CommandLine[i]));
		i++;


	}while(CommandLine[i-1]!= '\n');

	CommandLine[i-1]='\0';					//Adding NULL character at the end of the string.
*/
	Tokens[0] = strtok(CommandLine, " \t");
	printf("%s\n", Tokens[0]);
	int i=1;
	while(1)
	{
		Tokens[i] = strtok(NULL, " \t");
		printf("%s\n", Tokens[i]);
		if (Tokens[i] == NULL)
			return 0;
		i++;
	}


	return 0;

}

