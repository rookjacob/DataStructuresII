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
 * @var DirList 				This variable is the head of the directory/file list that
 * 								are in the Directory.
 */
typedef struct DirFile {
	char Type;
	char DirName[MAXTOKENLEN];
	struct DirFile *Parent;
	struct DirFile *DirList;

}DirectoryFile;

DirectoryFile ROOT;				//This is the root for all the files.
DirectoryFile *Curr;

/*
 * @brief	NameStack			Stack structure to store the file names to be popped off
 *
 * @var		DirectoryName		Name of name to be output when popped
 *
 * @var		Next				Pointer to next member in the stack
 *
 * @var		Prev				Pointer to previous member in the stack
 */
typedef struct NStack{
	DirectoryFile *DirPtr;
	struct NStack *Next;
}Stack;

Stack *Top;				//Pointer for the top of the stack structure


/*
 * @brief	Tokenizer		This function tokenizes a string of characters passed by the
 * user.
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
 * @brief	getToken
 *
 * @param	TokenIndex			Index of token to be returned
 *
 * @return	char*				Returns pointer to beginning of the token with the index passed
 */
char *getToken(int TokenIndex);


/*
 * @brief	CommandOperator		This function determines which Unix\Linux command need to be called
 * 								and calls the function for that command.
 *
 * @param	*Curr				Current location in the Directory Tree
 *
 * @return	void
 */
void CommandOperator(void);

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
 * @brief	FindDirFile			Function finds a directory or file in the current directory
 *
 * @param	Curr				Pointer to current directory
 *
 * @param	DirFileName			Name of directory/file to find
 *
 * @return	char*				Returns pointer to found directory or file. Returns NULL if not found.
 */
DirectoryFile *FindDirFile(char DirFileName[]);

/*
 * @brief	cd					Changes into a specific directory
 *
 */
void cd(void);

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
 * @brief						Locate and remove the file or directory
 *
 */
void rm(void);

/*
 * @brief	bye					Ends the session
 *
 */
void bye(void);

/*
 * @brief	whereis				Show path to first occurrence of file or directory if it exists
 */
void whereis(char *Filename);

/*
 * @brief	Push				Push function for the NameStack stack
 *
 * @param	Top					Location of top of the stack
 *
 * @param	Tail				Location of the tail of the stack
 *
 * @param	Name				String to be popped off the stack
 */
void Push(DirectoryFile *Directory);

/*
 * @brief	Pop					Pop function for the NameStack stack
 *
 * @param	Top					Location of top of the stack
 *
 * @param	Tail				Location of the tail of the stack
 */
DirectoryFile *Pop(void);

/*
 * @brief	isEmpty				 Function to determine if the NameStack is empty or not
 *
 * @param	Top					Location of top of the stack
 *
 * @param	Tail				Location of the tail of the stack
 */
int isEmpty(void);






#endif /* FUNCTIONS_H_ */
