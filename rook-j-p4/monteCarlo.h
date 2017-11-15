/*
 * @file monteCarlo.h
 *
 * @author Jacob Rook
 * @date 11/16/2017
 * @info Course COP 4534
 * Project 4
 */

#ifndef MONTECARLO_H_
#define MONTECARLO_H_

#include<stdio.h>
#include<stdlib.h>


/*
 *
 */
void txt2Binary(void);


/*
 *
 */
void MCSimulation(void);

/*
 *
 */
void runMCSim(int numSimulations, int numCategories, int frequencyList[], int numEvents);


/*
 *
 */
void MCAlgorithm(void);


#endif /* MONTECARLO_H_ */
