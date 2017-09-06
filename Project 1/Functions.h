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

#include<stdio.h>
#include<string.h>

/*
 * @brief ReadUserInput This function reads the input of the user and places
 * the input into the UserInput structure type.
 *
 * @param EmptyInput This parameter is a pointer to a UserInput variable. The
 * value in the variable will not matter because that data will be overwrote
 * with the new input data from the user.
 *
 * @return UserInput* The pointer to the overwrote UserInput variable will be
 * passed back.
 *
 */
UserInput* ReadUserInput(UserInput* EmptyInput);









#endif /* FUNCTIONS_H_ */
