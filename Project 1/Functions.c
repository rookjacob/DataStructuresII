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
	/*
	 * Need to convert the first token into a character array so that the character
	 * array can be used in the strcmp function. strcmp function will not work with
	 * the pointer.
	 */
	char FirstCommand[8] = "\0";
	char *ptr = Tokens[0];
	int i = 0;
	while (i<8)
	{
		FirstCommand[i] = *(ptr+i);
		if(FirstCommand[i] == '\0')
			break;
		i++;
	}

	/*
	 * Determining which, if any command is the first token
	 */
	if(!(strcmp(FirstCommand, "ls")))
	{
		printf("ls\n");
		printf("%s\n",ROOT.DirName);
	}
	else if(!(strcmp(FirstCommand, "mkdir")))
	{
		printf("mkdir\n");
	}
	else if(!(strcmp(FirstCommand, "cd")))
	{
			printf("cd\n");
	}
	else if(!(strcmp(FirstCommand, "pwd")))
	{
		printf("pwd\n");
	}
	else if(!(strcmp(FirstCommand, "addf")))
	{
		printf("addf\n");
	}
	else if(!(strcmp(FirstCommand, "mv")))
	{
		printf("mv\n");
	}
	else if(!(strcmp(FirstCommand, "cp")))
	{
		printf("cp\n");
	}
	else if(!(strcmp(FirstCommand, "rm")))
	{
		printf("rm\n");
	}
	else if(!(strcmp(FirstCommand, "bye")))
	{
		printf("bye\n");
	}
	else if(!(strcmp(FirstCommand, "whereis")))
	{
		printf("whereis\n");
	}
	else
	{
		printf("Wrong Input\n");
	}




}


void ls(void)
{

}


void mkdir(void)
{

}


void cd(void)
{

}


void pwd(void)
{

}


void addf(void)
{

}


void mv(void)
{

}


void cp(void)
{

}


void rm(void)
{

}


void bye(void)
{

}


void whereis(void)
{

}









