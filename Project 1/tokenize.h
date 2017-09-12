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
 * @return	Void
 *
 */
void Tokenizer (char *String, char *Ptr[], char TokenChar);


#endif /* TOKENIZE_H_ */
