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

Customer_t *PQ[PQMAXSIZE+1];
int PQSize;					//Current size of the PQ


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






//PQ FUNCTIONS
/*
 *
 */
void PQEnque(Customer_t *Customer);

/*
 *
 */
Customer_t *PQDeque(void);

/*
 *
 */
int isPQEmpty(void);

/*
 *
 */
void percolateUp(Customer_t *Customer);

/*
 *
 */
void percolateDown(int index);
//END OF PQ FUNCTIONS






//FIFO QUEUE FUNCTIONS
/*
 *
 */
void FIFOEnque(Customer_t *Customer);

/*
 *
 */
Customer_t *FIFODeque(void);

/*
 *
 */
int isFIFOEmpty(void);

//END OF FIFO QUEUE FUNCTIONS






//SET FUNCTIONS
/*
 * @brief	setN		This function sets the value for numArrivals to the passed
 * value
 *
 * @param	N			Value to set numArrivals
 */
void setN(int N);

/*
 * @brief	setLambda	This function sets the value for lambda to the passed value
 *
 * @param	L			Value to set lambda
 */
void setLambda(float L);

/*
 * @brief	setMu		This function sets the value for mu to the passed value
 *
 * @param	M			Value to set mu
 */
void setMu(float M);

/*
 * @brief	setM		This function sets the value for numService to the passed
 * value
 *
 * @param	M			Value to set numService
 */
void setM(float M);
//END OF SET FUNCTIONS




//EXPECTED CALCULATIONS FOR THE ANALYTICAL MODEL


//END OF EXPECTED CALCULATIONS FOR THE ANALYTICAL MODEL






#endif /* ANALYTICAL_H_ */
