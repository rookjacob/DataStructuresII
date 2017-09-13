/*
 * @file main.c This file is the main C file for a basic directory that
 * processes basic Unix/Linux commands.
 *
 * @author Jacob Rook
 * @date 09/05/2017
 * @info Course COP 4534
 * Project 1
 */


#ifndef MAININCLUDES
#define MAININCLUDES

#include<stdio.h>
#include<string.h>

#endif
#include "Functions.h"

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

void Trim (char *String )
{
	int i = strlen(String)-1;
	if((i>0) && (String[i] == '\n'))
		String[i] = '\0';
	return;
}








