/*
 * @file Functions.h This file contains all of the functions used for a basic
 * directory that processes basic Unix/Linux commands.
 *
 * @author Jacob Rook
 * @date 09/05/2017
 * @info Course COP 4534
 * Project 1
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#ifndef MAININCLUDES
#define MAININCLUDES

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#endif

#define MAXTOKENS 4
#define MAXTOKENLEN 100

char Tokens[MAXTOKENS][MAXTOKENLEN];			//Scope variable to store Tokens


/*
 * @brief DirectoryFile 		Structure used for the Directories and files.
 *
 * @var Type 					The distinction between a directory and a file will be made by
 * 								the Type variable. A directory will have a "D" assigned to Type and a file
 * 								will have an "F" assigned to Type.
 *
 * @var DirName 				This variable will store the name of the directory or file.
 *
 * @var Parent 					This variable is a pointer to the directory that the current
 * 								file is in.
 *
 * @var Children 				This variable is the head of the directory/file list that
 * 								are in the Directory.
 *
 * @var Siblings				This variable is the next sibling adjacent to the directory
 *
 */
typedef struct DirFile {
	char Type;
	char DirName[MAXTOKENLEN];
	struct DirFile *Parent;
	struct DirFile *Children;
   struct DirFile *Siblings;

}DirectoryFile;

DirectoryFile ROOT;				//This is the root for all the files.
DirectoryFile *Curr;			//Scope pointer to the current directory

/*
 * @brief	NameStack			Stack structure to store the file names to be popped off
 *
 * @var		DirectoryName		Name of name to be output when popped
 *
 * @var		Next				Pointer to next member in the stack
 */
typedef struct NStack{
	DirectoryFile *DirPtr;
	struct NStack *Next;
}Stack;

Stack *Top;				//Pointer for the top of the stack structure for pwd function
Stack *Top2;			//Pointer for the top of the stack structure for whereis function

/*
 * @brief	Tokenizer		This function tokenizes a string of characters passed by the
 * 							user. And, stores them in the scope variable Tokens 2d array
 *
 * @param	String[]  		String of characters to be tokenized
 *
 * @param	TokenChar[]		Character array to identify the end of a token
 *
 * @return	int 			Returns the number of tokens
 *
 */
int Tokenizer (char String[], const char TokenChar[]);


/*
 * @brief	CommandOperator		This function determines which Unix\Linux command need to be called
 * 								and calls the function for that command.
 *
 * @return	void
 */
int CommandOperator(void);

/*
 * @brief	ls					Lists all files and directories in the current directory, indicating
 * 								which (file or directory) it is
 *
 */
void ls(void);

/*
 * @brief	mkdir				Creates a new directory if it does not already exist
 *
 */
void mkdir(void);

/*
 * @brief	Insert				Inserts a new directory or file in its current list of directories alphabetically
 *
 * @param	NewNode				New Node to be placed into its current directory
 */
void Insert(DirectoryFile *NewNode);

/*
 * @brief	cd					Changes into a specific directory
 *
 */
void cd(void);

/*
 * @brief	FindDirFile			Function finds a directory or file in the current directory
 *
 * @param	DirFileName			Name of directory/file to find
 *
 * @return	DirectoryFile*		Returns pointer to found directory or file. Returns NULL if not found.
 */
DirectoryFile *FindDirFile(char DirFileName[]);

/*
 * @brief	FindPrevDirFile		Function finds the node to the left of passed node. If the node does
 * 								not have a left node NULL is returned. Used in the mv and rm functions
 *
 * @param	DirFileName			Name of directory/file to be found
 */
DirectoryFile *FindPrevDirFile(char DirFileName[]);


/*
 * @brief	pwd					Specifies the current directory as: <yourname>/root/nextdir/etc/
 *
 */
void pwd(void);

/*
 * @brief	addf				Adds a file to the current directory
 *
 */
void addf(void);

/*
 * @brief	mv					Change the name of the file or directory to the new name
 */
void mv(void);

/*
 * @brief	cp					Copy file or folder to the new name
 *
 */
void cp(void);

/*
 * @brief	Duplicate			Copies info from Original to Copy
 *
 * @param	Copy				Place to be copied to
 *
 * @param	Original			Original directory to be copied
 */
void Duplicate(DirectoryFile *Copy, DirectoryFile *Original);

/*
 * @brief	cpRecur				Recursive function for cp
 */
void cpRecur(void);

/*
 * @brief						Locate and remove the file or directory
 *
 */
void rm(void);

/*
 * @brief	del					Secondary delete function for rm
 *
 * @param	Head				Head node to be deleted
 */
void del(DirectoryFile *Head);

/*
 * @brief	bye					Ends the session
 *
 */
void bye(void);

/*
 * @brief	whereis				Show path to first occurrence of file or directory if it exists
 */
void whereis(void);

/*
 * @brief						Recursive function for the whereis function
 */
void whereisrecur(void);

/*
 * @brief	Push				Push function for the NameStack stack
 *
 *
 * @param	Directory			Directory to be pusehd onto the stack
 */
void Push(DirectoryFile *Directory);

/*
 * @brief	Pop					Pop function for the NameStack stack
 *
 */
DirectoryFile *Pop(void);

/*
 * @brief	isEmpty				 Function to determine if the NameStack is empty or not
 *
 */
int isEmpty(void);

/*
 * @brief	Push				Push function for the stack for whereis
 *
 * @param	Directory			Directory to be popped off the stack
 */
void Push2(DirectoryFile *Directory);

/*
 * @brief	Pop2				Pop function for the stack for whereis
 *
 */
DirectoryFile *Pop2(void);

/*
 * @brief	isEmpty2			Function to determine if the stack for whereis is empty
 *
 */
int isEmpty2(void);





#endif /* FUNCTIONS_H_ */
