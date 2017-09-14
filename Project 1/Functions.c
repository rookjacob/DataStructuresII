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
	char FirstCommand[8] = "\0";
	int i = 0;
	while (i<8)
	{
		FirstCommand[i] = Tokens[0]+i;
		if(FirstCommand[i] == '\0')
			break;
		i++;
	}

	if(!(strcmp(FirstCommand, "ls")))
	{
		printf("ls\n");
		printf("%s\n",ROOT.DirName);
	}
	else if(StringCompare(Tokens[0], "mkdir"))
	{
		printf("mkdir\n");
	}
	else if(StringCompare(Tokens[0], "cd"))
	{
			printf("cd\n");
	}
	else if(StringCompare(Tokens[0], "pwd"))
	{
		printf("pwd\n");
	}
	else if(StringCompare(Tokens[0], "addf"))
	{
		printf("addf\n");
	}
	else if(StringCompare(Tokens[0], "mv"))
	{
		printf("mv\n");
	}
	else if(StringCompare(Tokens[0], "cp"))
	{
		printf("cp\n");
	}
	else if(StringCompare(Tokens[0], "rm"))
	{
		printf("rm\n");
	}
	else if(StringCompare(Tokens[0], "bye"))
	{
		printf("bye\n");
	}
	else if(StringCompare(Tokens[0], "whereis"))
	{
		printf("whereis\n");
	}
	else
	{
		printf("Wrong Input\n");
	}




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









