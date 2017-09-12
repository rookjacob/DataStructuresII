/*
 * tokenize.c
 *
 *  Created on: Sep 8, 2017
 *      Author: rookj
 */

#include "tokenize.h"
#include <string.h>

int Tokenizer (char *String, char *Prt[], char TokenChar)
{
	int i;
	int StringLen = strlen(String);
	int PlaceHolder=0;								//Variable to hold the index of the first character of a token
	int PtrCount=0;									//Variable to step through the pointer list

	if (StringLen == 0)
		return 0;

	/*
	 * This for loop is to take care of the case that the first couple of characters are
	 *	the tokenizing character. The loop will move the PlaceHolder to the first non-tokenizing
	 *	character.
	 */
	while(( String[PlaceHolder] == TokenChar) && ( PlaceHolder < StringLen ))
	{
		PlaceHolder++;
	}

	Prt[PtrCount] = String[PlaceHolder];			//Set the first token pointer to the index of the first token
	PtrCount++;
	i=PlaceHolder;

	while(i<StringLen)
	{
		if ( String[i] == TokenChar )
		{
			String[i] = "\0";						//Set the Token Character to NULL

		}

	}

}

int FindNextToken (char *String, int CurrentLocation, char TokenChar)
{
	int StringLen = strlen(String);

	while((String[CurrentLocation] == TokenChar ) && (CurrentLocation < StringLen))
	{
		CurrentLocation++;
	}

	if (CurrentLocation == StringLen)
		return -1;
	else
		return CurrentLocation;
}

