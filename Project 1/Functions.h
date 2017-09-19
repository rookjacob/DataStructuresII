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

#define MAXTOKENS 4
#define MAXTOKENLEN 100

char Tokens[MAXTOKENS][MAXTOKENLEN];			//Scope variable to store Tokens

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
 * @brief	CommandOperator		This function determines which Unix\Linux command need to be called
 * 								and calls the function for that command.
 *
 * @param	*Tokens[]			Array of pointers to the tokens
 *
 * @param	NumberTokens		The number of tokens in the array of pointers
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
void whereis(void);






#endif /* FUNCTIONS_H_ */
