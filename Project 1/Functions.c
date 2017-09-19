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

#include "Functions.h"


int Tokenizer (char String[], const char TokenChar[])
{
	Tokens[0][0] = '\0';			//Initialize the tokens to NULL so no overlap happens
	Tokens[1][0] = '\0';
	Tokens[2][0] = '\0';
	Tokens[3][0] = '\0';

	int i = 0;
	char *prt;
	prt = strtok(String, TokenChar);

	while((prt != NULL) && (i<MAXTOKENS))
	{
		strcpy(Tokens[i], prt);
		prt = strtok(NULL, TokenChar);
		i++;
	}
	return i;




}


void CommandOperator(DirectoryFile *Curr)
{

	/*
	 * Determining which, if any command is the first token
	 */
	if(!(strcmp(Tokens[0], "ls")))
	{
		ls(Curr);
	}
	else if(!(strcmp(Tokens[0], "mkdir")))
	{
		mkdir(Curr);
	}
	else if(!(strcmp(Tokens[0], "cd")))
	{
		cd();
	}
	else if(!(strcmp(Tokens[0], "pwd")))
	{
		pwd();
	}
	else if(!(strcmp(Tokens[0], "addf")))
	{
		addf();
	}
	else if(!(strcmp(Tokens[0], "mv")))
	{
		mv();
	}
	else if(!(strcmp(Tokens[0], "cp")))
	{
		cp();
	}
	else if(!(strcmp(Tokens[0], "rm")))
	{
		rm();
	}
	else if(!(strcmp(Tokens[0], "bye")))
	{
		bye();
	}
	else if(!(strcmp(Tokens[0], "whereis")))
	{
		whereis();
	}
	else if (Tokens[0][0] == '\0')
	{
		printf("No input\n");
	}
	else
	{
		printf("Command \"%s\" was not recognized\n",Tokens[0]);
	}




}


void ls(DirectoryFile *Curr)
{
	DirectoryFile *ListPtr = Curr->DirList;

	while(ListPtr != NULL)
	{

		printf("\t%c %s\n", ListPtr->Type ,ListPtr->DirName);
		ListPtr = ListPtr->DirList;
	}
	return;
}


void mkdir(DirectoryFile *Curr)
{
	if(Tokens[1][0] == '\0');
	{
		printf("File name was not given\n");
		return;
	}
	if(Tokens[2][0] != '\0')
	{
		printf("Too many arguments were given\n");
		return;
	}

	DirectoryFile *NewDir = malloc(sizeof(DirectoryFile));
	NewDir->Parent = Curr;
	NewDir->Type = 'D';
	strcpy(NewDir->DirName, Tokens[1]);

}

void Insert(DirectoryFile *NewNode)
{
	if (NewNode->Parent->DirList == NULL)
	{
		NewNode->Parent->DirList = NewNode;
		return;
	}
	//int cmp = strcmp(NewNode->DirName)

}


void cd(void)
{
	printf("cd\n");
}


void pwd(void)
{
	printf("pwd\n");
}


void addf(void)
{
	printf("addf\n");
}


void mv(void)
{
	printf("mv\n");
}


void cp(void)
{
	printf("cp\n");
}


void rm(void)
{
	printf("rm\n");
}


void bye(void)
{
	printf("bye\n");
}


void whereis(void)
{
	printf("whereis\n");
}









