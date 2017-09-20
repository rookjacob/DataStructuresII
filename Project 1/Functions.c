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
		cd(Curr);
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
	if (strlen(Tokens[1]) == 0)				//If there is no parameters do nothing: print newline
	{
		printf("\n");
		return;
	}
	if(strlen(Tokens[2]) != 0)
	{
		printf("Too many arguments were given\n");
		return;
	}
	if(!stcmp(Tokens[1], ".."))
	{
		if (Curr->Parent == &ROOT)
		{
			printf("Permission Denied\n");
			return;
		}
		Curr = Curr->Parent;
		pwd(Curr);
		return;
	}
	char *ptr = FindDirFile(Curr, Tokens[1]);

	if(ptr == NULL)
	{
		printf("%s is not located in %s\n", Tokens[1], Curr->DirName);
		return;
	}
	else
	{
		Curr = ptr;
		pwd(Curr);
		return;
	}

}

DirectoryFile *FindDirFile(DirectoryFile *Curr, char DirFileName[])
{
	if (DirFileName == NULL)
	{
		return NULL;
	}
	DirectoryFile *ptr = Curr->DirList;

	while (1)
	{
		if (ptr == NULL)
		{
			return NULL;
		}
		if(!strcmp(DirFileName, ptr->DirName))
		{
			return ptr;
		}
		ptr = ptr->DirList;
	}
}

void pwd(DirectoryFile *Curr)
{
	DirectoryFile *ptr = Curr;
	Stack *Top = NULL;
	Push(Top, ptr);
	while(ptr != &ROOT)
	{
		ptr = ptr->Parent;
		Push(Top, ptr);
	}
	ptr = Pop(Top);
	printf("%s",ptr->DirName);				//This has to be the ROOT directory

	while(!isEmpty(Top))
	{
		ptr = Pop(Top);
		printf("%s/", ptr->DirName);
	}
	return;
}


void addf(DirectoryFile *Curr)
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

	DirectoryFile *NewFile = malloc(sizeof(DirectoryFile));
	NewFile->Parent = Curr;
	NewFile->Type = 'F';
	strcpy(NewFile->DirName, Tokens[1]);
	NewFile->DirList = NULL;

	Insert(NewFile);
	return;
}


void mv(DirectoryFile *Curr)
{
	if (!(strlen(Tokens[1])) || !(strlen(Tokens[2])))
	{
		printf("Not enough arguments given.\n");
		return;
	}
	if (!(strlen(Tokens[3])))
	{
		printf("Too many arguments given.\n");
		return;
	}
	DirectoryFile *ptr = FindDirFile(Curr, Tokens[1]);

	if(ptr == NULL)
	{
		printf("%s was not found in %s\n", Tokens[1], Curr->DirName);
		return;
	}
	else
	{
		strcpy(ptr->DirName, Tokens[2]);
		printf("%s\n",ptr->DirName);
		return;
	}
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

void Push(Stack *Top, DirectoryFile *Directory)
{
	if (Directory == NULL)
	{
		return;
	}

	Stack *NewNode = malloc(sizeof(Stack));
	NewNode->DirPtr = Directory;
	NewNode->Next = NULL;
	NewNode->Prev =NULL;

	if(Top == NULL)
	{
		Top = NewNode;
		return;
	}

	NewNode->Prev = Top;
	Top->Next = NewNode;
	Top = NewNode;

	return;

}

DirectoryFile *Pop(Stack *Top)
{
	if(isEmpty(Top))
	{
		return NULL;
	}
	DirectoryFile *Dir = Top->DirPtr;

	if((Top->Next == NULL) && (Top->Prev == NULL))
	{
		free(Top);
		Top = NULL;
		return Dir;
	}
	Stack *Tmp = Top->Prev;

	Tmp->Next = NULL;
	free(Top);
	Top = Tmp;
	return Dir;
}

char *Peak(Stack *Top)
{
	if(Top != NULL)
		return Top->DirPtr->DirName;
	return NULL;

}

int isEmpty(Stack *Top)
{
	if(Top == NULL)
		return 1;
	return 0;
}








