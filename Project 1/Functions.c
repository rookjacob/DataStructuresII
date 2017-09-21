/*
 * @file main.c This file is the main C file for a basic directory that
 * processes basic Unix/Linux commands.
 *
 * @author Jacob Rook
 * @date 09/05/2017
 * @info Course COP 4534
 * Project 1
 */




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



void CommandOperator(void)
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
		ls();
	}
	else if(!(strcmp(Command, "mkdir")))
	{
		mkdir();
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
		rm(NULL);
	}
	else if(!(strcmp(Command, "bye")))
	{
		bye();
	}
	else if(!(strcmp(Command, "whereis")))
	{
		whereis("File");
	}
	else
	{
		printf("Command \"%s\" was not recognized\n",Tokens[0]);
	}

return;


}


void ls(void)
{
	DirectoryFile *ListPtr = Curr->Children;

	while(ListPtr != NULL)
	{

		printf("\t%c %s\n", ListPtr->Type ,ListPtr->DirName);
		ListPtr = ListPtr->Siblings;
	}
	return;
}


void mkdir(void)
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
	DirectoryFile *NewDir = (DirectoryFile*)malloc(sizeof(DirectoryFile));
	NewDir->Parent = Curr;
	NewDir->Type = 'D';
	strcpy(NewDir->DirName, Tokens[1]);
    NewDir->Children = NULL;
    NewDir->Siblings = NULL;

	Insert(NewDir);
	return;

}

void Insert(DirectoryFile *NewNode)
{
	printf("In Insert\n");
	DirectoryFile *ptr;
	DirectoryFile *prev;

	if (NewNode->Parent->Children == NULL)
	{
		NewNode->Parent->Children = NewNode;
		printf("%s",NewNode->DirName);
		return;
	}

	if(NewNode->Type == 'D') 		//Directory
	{
		ptr = NewNode->Parent->Children;
		prev = NewNode->Parent->Children;
		while((ptr->Type =='D') && (strcmp(NewNode->DirName, ptr->DirName)>=0))
		{
			if(strcmp(NewNode->DirName, ptr->DirName) == 0)
			{
				printf("Directory %s already exists. Directory not made.\n", NewNode->DirName);
				free(NewNode);
				return;
			}
			prev = ptr;
			ptr = ptr->Siblings;
         if (ptr == NULL)
            break;
            
		}
		prev->Siblings = NewNode;
		if(ptr != NULL)
			NewNode->Siblings = ptr;
		printf("%s",NewNode->DirName);
		return;
	}
	else 							//File
	{
		ptr = NewNode->Parent->Children;
		prev = NewNode->Parent->Children;

		while((ptr->Type =='D'))
		{
			prev = ptr;
			ptr = ptr->Siblings;
			if(ptr == NULL)
				break;
		}
		if (ptr == NULL)
		{
			prev->Siblings = NewNode;
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
			ptr = ptr->Siblings;
			if(ptr == NULL)
				break;
		}
		prev->Siblings = NewNode;
		if(ptr != NULL)
			NewNode->Siblings = ptr;
		return;
	}

}


void cd(void)
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
	if(!strcmp(Tokens[1], ".."))
	{
		if (Curr == &ROOT)
		{
			printf("Permission Denied\n");
			return;
		}
		Curr = Curr->Parent;
		pwd();
		return;
	}
	DirectoryFile *ptr = FindDirFile(Tokens[1]);

	if(ptr == NULL)
	{
		printf("%s is not located in %s\n", Tokens[1], Curr->DirName);
		return;
	}
	else
	{
		Curr = ptr;
		pwd();
		return;
	}

}

DirectoryFile *FindDirFile(char DirFileName[])
{
	if (DirFileName == NULL)
	{
		return NULL;
	}
	DirectoryFile *ptr = Curr->Children;

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
		ptr = ptr->Siblings;
	}
}

DirectoryFile *FindPrevDirFile(char DirFileName[])
{
	if (DirFileName == NULL)
	{
		return NULL;
	}
	DirectoryFile *ptr = Curr->Children;
	DirectoryFile *prev = Curr->Children;

	while (1)
	{
		if (ptr == NULL)
		{
			return NULL;
		}
		if(!strcmp(DirFileName, ptr->DirName))
		{
			if(prev != ptr)
				return prev;
			return NULL;
		}
		prev = ptr;
		ptr = ptr->Siblings;
	}
}

void pwd(void)
{
   int i;
	DirectoryFile *ptr = Curr;
      
	while(ptr != &ROOT)
   {
      Push(ptr);
		ptr = ptr->Parent;
	}
   Push(ptr);
   

	while(!(isEmpty()))
	{
		ptr = Pop();
		printf("%s/", ptr->DirName);
	}
	return;
}


void addf(void)
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

	DirectoryFile *NewFile = (DirectoryFile*)malloc(sizeof(DirectoryFile));
	NewFile->Parent = Curr;
	NewFile->Type = 'F';
	strcpy(NewFile->DirName, Tokens[1]);
	NewFile->Children = NULL;
	NewFile->Siblings = NULL;

	Insert(NewFile);
	return;
}


void mv(void)
{
	if (!(strlen(Tokens[1])) || !(strlen(Tokens[2])))
	{
		printf("Not enough arguments given.\n");
		return;
	}
	if ((strlen(Tokens[3])))
	{
		printf("Too many arguments given.\n");
		return;
	}
	DirectoryFile *ptr = FindDirFile(Tokens[1]);
	DirectoryFile *prev = FindPrevDirFile(Tokens[1]);

	if(ptr == NULL)
	{
		printf("%s was not found in %s\n", Tokens[1], Curr->DirName);
		return;
	}
	else
	{
		strcpy(ptr->DirName, Tokens[2]);
		printf("%s\n",ptr->DirName);

		prev->Siblings = ptr->Siblings;
		ptr->Siblings = NULL;

		Insert(ptr);

		return;
	}
}


void cp(void)
{
	printf("cp\n");
}


void rm(DirectoryFile *DeleteFile)
{
	printf("rm\n");
}


void bye(void)
{
	printf("bye\n");
}


void whereis(char *FileName)
{

}

void Push(DirectoryFile *Directory)
{
	Stack *temp = (Stack*)malloc(sizeof(Stack));
	temp->DirPtr = Directory;
	temp->Next = Top;
	Top = temp;

}

DirectoryFile *Pop(void)
{
	Stack *temp;
	DirectoryFile *temp2;
	if(isEmpty())
		return NULL;

	temp = Top;
	Top = Top->Next;
	temp2 = temp->DirPtr;
	free(temp);

	return temp2;

}


int isEmpty(void)
{
	if(Top == NULL)
   {
		return 1;
   }
   else
	   return 0;
}








