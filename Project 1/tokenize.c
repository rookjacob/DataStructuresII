/*
 * tokenize.c
 *
 *  Created on: Sep 8, 2017
 *      Author: rookj
 */

#include "tokenize.h"
#include <string.h>

int Tokenizer (char String[], char *Prt[], char TokenChar[])
{
	int i;

	Prt[0] = strtok(String, TokenChar);

	if ( Prt[0] == NULL )
		return 0;

	i=1;

	while (1)
	{
		Prt[i] = strtok(NULL, TokenChar);

		if(Prt[i] == NULL)
			return i;
		i++;
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

