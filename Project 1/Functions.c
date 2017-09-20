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
	
	strcpy(Tokens[0] , "\0");			//Initialize the tokens to NULL so no overlap happens
	strcpy(Tokens[1], "\0");
	strcpy(Tokens[2], "\0");
	strcpy(Tokens[3], "\0");

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

char *getToken(int TokenIndex)
{
	if(TokenIndex >= MAXTOKENS)
		return NULL;
	return Tokens[TokenIndex];
}



void CommandOperator(DirectoryFile *Curr)
{
	char *Command = getToken(0);
	/*
	 * Determining which, if any command is the first token
	 */
	if (Command == NULL)
	{
			printf("No input\n");
	}
	else if(!(strcmp(Command, "ls")))
	{
		ls(Curr);
	}
	else if(!(strcmp(Command, "mkdir")))
	{
		mkdir(Curr);
	}
	else if(!(strcmp(Command, "cd")))
	{
		cd();
	}
	else if(!(strcmp(Command, "pwd")))
	{
		pwd();
	}
	else if(!(strcmp(Command, "addf")))
	{
		addf();
	}
	else if(!(strcmp(Command, "mv")))
	{
		mv();
	}
	else if(!(strcmp(Command, "cp")))
	{
		cp();
	}
	else if(!(strcmp(Command, "rm")))
	{
		rm();
	}
	else if(!(strcmp(Command, "bye")))
	{
		bye();
	}
	else if(!(strcmp(Command, "whereis")))
	{
		whereis();
	}
	else
	{
		printf("Command \"%s\" was not recognized\n",Tokens[0]);
	}

return;


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
	if((strlen(Tokens[1]) == 0))
	{
		printf("File name was not given\n");
		return;
	}
	if(strlen(Tokens[2]) != 0)
	{
		printf("Too many arguments were given\n");
		return;
	}
	DirectoryFile *NewDir = malloc(sizeof(DirectoryFile));
	NewDir->Parent = Curr;
	NewDir->Type = 'D';
	strcpy(NewDir->DirName, Tokens[1]);
   NewDir->DirList = NULL;

	Insert(NewDir);
	return;

}

void Insert(DirectoryFile *NewNode)
{
	DirectoryFile *ptr;
	DirectoryFile *prev;

	if (NewNode->Parent->DirList == NULL)
	{
		NewNode->Parent->DirList = NewNode;
		printf("%s",NewNode->DirName);
		return;
	}

	if(NewNode->Type == 'D') 		//Directory
	{
		ptr = NewNode->Parent->DirList;
		prev = NewNode->Parent->DirList;
		while((ptr->Type =='D') && (strcmp(NewNode->DirName, ptr->DirName)>=0))
		{
			if(strcmp(NewNode->DirName, ptr->DirName) == 0)
			{
				printf("Directory %s already exists. Directory not made.\n", NewNode->DirName);
				free(NewNode);
				return;
			}
			prev = ptr;
			ptr = ptr->DirList;
         if (ptr == NULL)
            break;
            
		}
		prev->DirList = NewNode;
		if(ptr != NULL)
			NewNode->DirList = ptr;
		printf("%s",NewNode->DirName);
		return;
	}
	else 							//File
	{
		ptr = NewNode->Parent->DirList;
		prev = NewNode->Parent->DirList;

		while((ptr->Type =='D') && (ptr != NULL))
		{
			prev = ptr;
			ptr = ptr->DirList;
		}
		if (ptr == NULL)
		{
			prev->DirList = NewNode;
			printf("%s",NewNode->DirName);
			return;
		}
		while((strcmp(NewNode->DirName,ptr->DirName)>=0))
		{
			if (strcmp(NewNode->DirName, ptr->DirName) == 0)
			{
				printf("File %s already exists. File not made. \n", NewNode->DirName);
				free(NewNode);
				return;
			}
			prev = ptr;
			ptr = ptr->DirList;
			if(ptr == NULL)
				break;
		}
		prev->DirList = NewNode;
		if(ptr != NULL)
			NewNode->DirList = ptr;
		return;
	}

}


void cd(DirectoryFile *Curr)
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









