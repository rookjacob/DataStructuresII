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
 * @brief	Tokenizer		This function tokenizes a string of characters passed by the
 * user.
 *
 * @param	String[]  		String of characters to be tokenized
 *
 * @param	*Tokens[]		Array of pointers to the tokens
 *
 * @param	TokenChar[]		Character array to identify the end of a token
 *
 * @return	int 			Returns the number of tokens
 *
 */
int Tokenizer (char String[], char *Tokens[], char TokenChar[]);

/*
 * @breif	CommandOperator		This function determines which Unix\Linux command need to be called
 * 								and calls the function for that command.
 *
 * @param	*Tokens[]			Array of pointers to the tokens
 *
 * @param	NumberTokens		The number of tokens in the array of pointers
 *
 * @return	void
 */
void CommandOperator(char *Tokens[], int NumberTokens);

/*
 * @breif	StringCompare		This function compares a string of the passed character pointer and
 * 								a constant character array.
 *
 * @param	*String				The pointer to the beginning of the string to be compared
 *
 * @param	Command				A constant character array to be compared with String. Should be passed
 * 								in form: "rm".
 */
int StringCompare(char *String, const char Command[]);







#endif /* FUNCTIONS_H_ */
