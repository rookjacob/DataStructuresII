/*
 * @file rook-j-p5.c
 *
 * @author Jacob Rook
 * @date 12/07/2017
 * @info Course COP 4534
 * Project 5
 */
#include<stdio.h>
#include"LCS.h"



int main(void)
{


	LCS_Length_C("twoSequences.txt");
	print_LCS();


	LCS_Multiple_Length("multipleSequence.txt");



	return 0;
}
