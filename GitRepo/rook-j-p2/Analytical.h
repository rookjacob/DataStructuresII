/*
 * @file Analytical.h
 *
 * @author Jacob Rook
 * @date 10/12/2017
 * @info Course COP 4534
 * Project 2
 */

#ifndef ANALYTICAL_H_
#define ANALYTICAL_H_

#include<stdio.h>

#define PQMAXSIZE 200

float PQ[PQMAXSIZE+1];

/*
 * @brief	Customer_t		Customer structure to hold the various info needed to
 * be stored for the customer
 *
 * @var		type			Variable to indicate whether the customer is an arrival
 * or a departure
 *
 * @var		arrivalTime		Variable to store the time that the customer arrived
 *
 * @var		startOfServiceTime	Time in which the customer begins the service
 *
 * @var		departureTime	Variable to store the time when the customer will leave
 *
 * @var		nextCust		Variable for the FIFO Queue, this variable will point
 * to the next customer in line after the current customer
 */
typedef struct Cust
{
	char 	type;
	float 	arrivalTime;
	float	startOfServiceTime;
	float 	departureTime;
	struct Cust *nextCust; //For FIFO Queue
}Customer_t;


int 	numArrivals;
float 	lambda;
float	mu;
int		numService;


void setN(int N);

void setLambda(float L);

void setMu(float M);

void setM(float M);


#endif /* ANALYTICAL_H_ */
