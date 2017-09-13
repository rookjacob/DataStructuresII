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

	char CommandLine[]="This file is the main C file for a basic directory that processes basic Unix/Linux commands. \0";				//Character arry to store the command line input from file

	char *Tokens[30];
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
	int i = Tokenizer(CommandLine, Tokens, " \t");
	int j;
	printf("%d", i);
	for (j=0;j<i;j++)
	{
		printf("%s\n", Tokens[j]);
	}

	printf("bye");
	return 0;

}

