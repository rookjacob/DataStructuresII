/*
 * tokenize.h
 *
 *  Created on: Sep 8, 2017
 *      Author: rookj
 */

#ifndef TOKENIZE_H_
#define TOKENIZE_H_

/*
 * @brief	Tokenizer	This function tokenizes a string of characters passed by the
 * user.
 *
 * @param	*String  	String of characters to be tokenized
 *
 * @param	*prt[]		Array of pointers to store each token
 *
 * @param	TokenChar	Character to identify the end of a token
 *
 * @return	int 		Returns the number of tokens
 *
 */
void Tokenizer (char *String, char *Ptr[], char TokenChar);

/*
 * @brief	FindNextToken	This function finds the location of the next token.
 *
 * @param	*String  		Original string of characters to be tokenized
 *
 * @param	CurrentLocation Current location in the string
 *
 * @param	TokenChar		Character to identify the end of a token
 *
 * @return	int 			Returns the index of the next token if -1, no token found
 *
 */
int FindNextToken (char *String, int CurrentLocation, char TokenChar);


#endif /* TOKENIZE_H_ */
