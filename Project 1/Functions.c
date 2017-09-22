/*
 * @file Functions.c 	This file contains all of the code for the functions
 * to execute the Linux\Unix commands.
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


int CommandOperator(void)
{
	/*
	 * Determining which, if any command is the first token
	 */
	if (Tokens[0] == NULL)
	{
			printf("No input\n");
	}
	else if(!(strcmp(Tokens[0], "ls")))
	{
		ls();
	}
	else if(!(strcmp(Tokens[0], "mkdir")))
	{
		mkdir();
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
		return 1;
	}
	else if(!(strcmp(Tokens[0], "whereis")))
	{
		whereis();
	}
	else
	{
		printf("Tokens[0] \"%s\" was not recognized\n",Tokens[0]);
	}

return 0;


}


void ls(void)
{
	DirectoryFile *ListPtr = Curr->Children;
	int i =1;
	while(ListPtr != NULL)
	{
		if(i != 1)
			printf("\n");
		printf("\t%c %s", ListPtr->Type ,ListPtr->DirName);
		ListPtr = ListPtr->Siblings;
		i++;
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
		printf("%s", NewNode->DirName);
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
			return NULL;		//If ptr is at the beginning of the list
		}
		prev = ptr;
		ptr = ptr->Siblings;
	}
}

void pwd(void)
{
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
		prev->Siblings = ptr->Siblings;
		ptr->Siblings = NULL;

		Insert(ptr);

		return;
	}
}


void cp(void)
{
	if(strlen(Tokens[3]))
	{
		printf("Too many arguments given.\n");
		return;
	}
	if(FindDirFile(Tokens[2]))
	{
		printf("File name already taken. No copy made\n");
		return;
	}
	DirectoryFile *OldNode = FindDirFile(Tokens[1]);
	DirectoryFile *NewNode = (DirectoryFile*)malloc(sizeof(DirectoryFile));

	Duplicate(NewNode, OldNode);
	Insert(NewNode);

	return;
}

void Duplicate(DirectoryFile *Copy, DirectoryFile *Original)
{
	if((Copy == NULL) || (Original == NULL))
	{
		return;
	}
	strcpy(Copy->DirName, Tokens[2]);
	Copy->Parent = Original->Parent;
	if (Original->Type == 'D')
		Copy->Type = 'D';
	else
		Copy->Type = 'F';
}


void rm(void)
{
	if(strlen(Tokens[2]))
	{
		printf("Too many arguments given.\n");
		return;
	}

	DirectoryFile *ptr = FindDirFile(Tokens[1]);

	if(ptr == NULL)
	{
		printf("%s was not found in %s. No files deleted.\n", Tokens[1], Curr->DirName);
		return;
	}

	if(ptr == &ROOT)
	{
		printf("Can not remove root.\n");
		return;
	}
	DirectoryFile *prev = FindPrevDirFile(Tokens[1]);
	if(prev == NULL)			//First item on list
	{
		ptr->Parent->Children = ptr->Siblings;
		ptr->Siblings = NULL;
		del(ptr);
	}
	else
	{
		prev->Siblings = ptr->Siblings;
		ptr->Siblings = NULL;
		del(ptr);
	}


	return;
}

void del(DirectoryFile *Head)
{
	if(Head == NULL)
	{
		return;
	}
	del(Head->Children);
	del(Head->Siblings);
	free(Head);

	return;
}


void bye(void)
{
	DirectoryFile *Tmp;
	DirectoryFile *Tmp2;

	while(1)
	{
		Tmp = &ROOT;
		Tmp = Tmp->Children;
		if(Tmp == NULL)
		{
			return;
		}
      if(Tmp->Siblings != NULL)
      {
		   Tmp2 = Tmp->Siblings;
		   Tmp2->Parent->Children = Tmp2;
			Tmp->Siblings = NULL;
			del(Tmp);


      }
      else
      {
    	  Tmp->Siblings = NULL;
    	  del(Tmp);
    	  Tmp2->Parent->Children = NULL;
    	  return;
      }

	}
}


void whereis(void)
{
	if(strlen(Tokens[2]) !=0)
	{
		printf("Too many arguments given.\n");
	}
	DirectoryFile *Dptr = (DirectoryFile*)malloc(sizeof(DirectoryFile));
	Dptr = &ROOT;
	Push2(Dptr->Children);

	whereisrecur();

	while (!isEmpty())
	{
		Pop2();
	}

}

void whereisrecur(void)
{

	if (!strcmp(Tokens[1], Top2->DirPtr->DirName))
	{
		DirectoryFile *Temp = Curr;
		Curr = Top2->DirPtr;
		pwd();
		Curr = Temp;
		Pop2();
		return;
	}
	if ((Top2->DirPtr->Children == NULL) && (Top2->DirPtr->Siblings == NULL))
	{
			Pop2();
			return;
	}
	if(Top2->DirPtr->Children != NULL)
		Push2(Top2->DirPtr->Children);
	if(Top2->DirPtr->Siblings != NULL)
		Push2(Top2->DirPtr->Siblings);
	whereisrecur();
	return;
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

void Push2(DirectoryFile *Directory)
{
	Stack *temp = (Stack*)malloc(sizeof(Stack));
	temp->DirPtr = Directory;
	temp->Next = Top2;
	Top2 = temp;

}

DirectoryFile *Pop2(void)
{
	Stack *temp;
	DirectoryFile *temp2;
	if(isEmpty2())
		return NULL;

	temp = Top2;
	Top2 = Top2->Next;
	temp2 = temp->DirPtr;
	free(temp);

	return temp2;

}


int isEmpty2(void)
{
	if(Top2 == NULL)
   {
		return 1;
   }
   else
	   return 0;
}








