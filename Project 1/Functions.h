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

/*
 * @brief	Tokenizer	This function tokenizes a string of characters passed by the
 * user.
 *
 * @param	String[]  	String of characters to be tokenized
 *
 * @param	*Prt[]		Array of pointers to store each token
 *
 * @param	TokenChar[]	Character array to identify the end of a token
 *
 * @return	int 		Returns the number of tokens
 *
 */
int Tokenizer (char String[], char *Ptr[], char TokenChar[]);

/*
 * @breif	Trim		This function is used to get rid of the newline character the
 * fgets function places on the end of the string.
 *
 * @param	String[]	String to take delete '\n'
 *
 * @return	void
 */









#endif /* FUNCTIONS_H_ */
