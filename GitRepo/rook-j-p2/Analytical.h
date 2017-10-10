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



/*
 * @brief	Customer_t		Customer structure to hold the various info needed to
 * be stored for the customer
 *
 * @var		type			Variable to indicate whether the customer is an arrival
 * or a departure. "A" for arrival "D" for departure.
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

Customer_t *FIFOHead;
Customer_t *FIFOTail;

/*
 * The Customer Priority Queue (PQ) is implemented using an array based heap of
 * customer pointers. The priority is based off of the customers arrival time or
 * departure time. The customers with the lower arrival or departure time will be
 * of higher priority and will be higher in the heap. The children of the heap
 * elements can be determined by multiplying the element's index by 2 and adding 1.
 * The index*2 and index*2 + 1 are the children of the customer at the index. The
 * size of the heap will be determined by the variable PQSize.
 */
#define PQMAXSIZE 200
Customer_t *PQ[PQMAXSIZE+1];
int PQSize;					//Current size of the PQ


int 	numArrivals;
float 	lambda;
float	mu;
int		numService;






//PQ FUNCTIONS
/*
 *@brief	PQEnque		Function will add a customer to the Priority Queue using
 *percolateUp
 *
 *@param	Customer	Customer to be added to the PQ
 */
void PQEnque(Customer_t *Customer);

/*
 *@brief	PQDeque		Function will take the customer off the head of the PQ,
 *take the lowest customer on the PQ and place them at the top of the PQ, use
 *percolateDown to place the lowest customer to rightful spot, and then return
 *the original customer at the top of the PQ
 *
 *@return	Customer_t	Function will return the customer at the top of the PQ
 *that is being returned
 */
Customer_t *PQDeque(void);

/*
 *@brief	isPQEmpty	Function will check to see if the PQ is empty or not
 *
 *@return	int			Function will return 1 if the PQ is empty, 0 if not empty
 */
int isPQEmpty(void);

/*
 *@brief	percolateUp	Function will add the passed customer to the end of the
 *PQ and use an insert method comparing the parent to the customer to be added.
 *If the parent is of lower priority, the parent will be moved to the current
 *location of the customer to be added and this process will continue to recur
 *until the parent has a higher priority or the customer to be added is a the top
 *of the PQ. When the parent is of higher priority the customer will stay at the
 *current location in the PQ.
 *
 *param		Customer	Customer to be added to the PQ
 */
void percolateUp(Customer_t *Customer);

/*
 *@brief	percolateDown	Function will use an insert method of percolating down
 *the customer at the index passed in the parameters. Typically the percolateDown
 *function will be used when the lowest priority customer has just been moved to
 *the highest priority position (1) and is needed to be percolated down. But,
 *the function can be used at any position in the PQ. However, the function will
 *compare the customers "children" in the heap at indices 2 times the customer's
 *index and 2 time the customer's index plus 1. The customer that needs to be
 *percolated down will be swapped with the higher priority child, if either child
 *is of higher priority. If neither child is of higher priority the algorithm stops
 *and the customer stays at the current index.
 *
 *@param 	index		Index to start the percolateDown function
 */
void percolateDown(int index);

/*
 * @brief	findTime	Function determines which time to use (arrival or departure)
 * and returns that value.
 *
 * @param	Customer	Customer to find the time to return
 *
 * @return	float		Returns the appropriate time (arrival or departure)
 */
float findTime(Customer_t *Customer);
//END OF PQ FUNCTIONS






//FIFO QUEUE FUNCTIONS
/*
 * @brief 	FIFOEnque		Function adds a customer to the end of the FIFO Queue.
 *
 * @param	Customer		Customer to be added to the FIFO Queue
 */
void FIFOEnque(Customer_t *Customer);

/*
 * @brief	FIFODeque		Function removes the customer at the head of the queue
 * and moves the head pointer to the next customer in line. The original head of
 * the queue is returned.
 *
 * @return 	Customer_t*		Head of FIFO queue is returned.
 */
Customer_t *FIFODeque(void);

/*
 * @brief	isFIFOEmpty		Checks to see if the FIFO queue is empty.
 *
 * @return	int				Returns 1 if the FIFO queue is empty, 0 if not
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
/*
 *
 */
float calIdle(void);

/*
 *
 */
float calAvePeopleSys(void);

/*
 *
 */
float calAveTimeSys(void);

/*
 *
 */
float calAveCustQ(void);

/*
 *
 */
float calAveTimeWait(void);

/*
 *
 */
float calUtiliFactor(void);
//END OF EXPECTED CALCULATIONS FOR THE ANALYTICAL MODEL



//FUNCTIONS FOR SIMULATION
/*
 *
 */
void PlaceFirstArrivals(void);

/*
 *
 */
void ProcessNextEvent(void);
//END OF FUNCTIONS FOR SIMULATION






#endif /* ANALYTICAL_H_ */
