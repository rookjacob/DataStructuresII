/*
 * tokenize.c
 *
 *  Created on: Sep 8, 2017
 *      Author: rookj
 */

#include "tokenize.h"
#include <string.h>

void Tokenizer (char *String, char *Prt[], char TokenChar)
{
	int i;
	int StringLen = strlen(String);
	int PlaceHolder=0;	//Variable to hold the index of the first character of a token
	int PtrCount=0;		//Variable to step through the pointer list

	if (StringLen == 0)
		return;
	/*
	for(i=0;i<StringLen;i++)
	{/*This for loop is to take care of the case that the first couple of characters are
		the tokenizing character. The loop will move the PlaceHolder to the first non-tokenizing
		character.
	///
		if (String[PlaceHolder] == TokenChar)
			PlaceHolder++;
		else
		{
			*Prt[PtrCount] = String[PlaceHolder];
			PtrCount++;
			break;
		}
	}
	*/
	/*	This for loop is to take care of the case that the first couple of characters are
		the tokenizing character. The loop will move the PlaceHolder to the first non-tokenizing
		character.
	*/
	while(( String[PlaceHolder] == TokenChar) && ( PlaceHolder < StringLen ))
	{
		PlaceHolder++;
	}

	while(i<=StringLen)//Reuse the i from the for loop, pick up from where the for loop left off
	{


	}

}

