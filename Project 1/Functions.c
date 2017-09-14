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

#include "Functions.h"
#include "Structs.h"

int Tokenizer (char String[], char *Tokens[], char TokenChar[])
{

	int i;

	Tokens[0] = strtok(String, TokenChar);

	if ( Tokens[0] == NULL )
		return 0;

	i=1;

	while (1)
	{
		Tokens[i] = strtok(NULL, TokenChar);

		if(Tokens[i] == NULL)
			return i;
		i++;
	}

}


void CommandOperator(char *Tokens[], int NumberTokens)
{
	//if(Tokens[0][0] == 'l')
	{
		printf("ls\n");
		printf("%s",ROOT.DirName);
		return;
	}
	/*
	if(strcmp(Tokens[0], "ls") == 0)
	{
		printf("ls\n");
		//printf("%s",ROOT.DirName);
	}
	else if(strcmp(Tokens[0], "mkdir") == 0)
	{
		printf("mkdir\n");
	}
	else if(strcmp(Tokens[0], "cd") == 0)
	{
			printf("cd\n");
	}
	else if(strcmp(Tokens[0], "pwd") == 0)
	{
		printf("pwd\n");
	}
	else if(strcmp(Tokens[0], "addf") == 0)
	{
		printf("addf\n");
	}
	else if(strcmp(Tokens[0], "mv") == 0)
	{
		printf("mv\n");
	}
	else if(strcmp(Tokens[0], "cp") == 0)
	{
		printf("cp\n");
	}
	else if(strcmp(Tokens[0], "rm") == 0)
	{
		printf("rm\n");
	}
	else if(strcmp(Tokens[0], "bye") == 0)
	{
		printf("bye\n");
	}
	else if(strcmp(Tokens[0], "whereis") == 0)
	{
		printf("whereis\n");
	}
	else
	{
		printf("Wrong Input\n");
	}

*/


}


int StringCompare(char *String, const char Command[])
{
	int i=0;

	while(String[i] == Command[i])
	{
		if((String[i] == '\0') || (Command[i] == '\0'))
			break;
		i++;
	}

	if((String[i] == '\0' )  && (Command[i]  == '\0' ))
		return 1;
	else
		return 0;
}









