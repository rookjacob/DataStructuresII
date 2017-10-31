/*
 * @file Queue.h 		File contains the data structures for a the Analytical files.
 * The data structures defined in this file are a customer structure, a FIFO queue,
 * and a priority queue. The customer structure stores all of the information needed
 * for the Analytical files and a customer pointer that is used in the FIFO queue
 * data structure. The FIFO queue uses the pointer in the customer structure to
 * create a linked list of customers. When a customer is added to the FIFO queue, the
 * customer is placed at the rear of the linked list and removals from the FIFO
 * queue are taken from the front of the linked list. The front and rear of the linked
 * list are tracked using a FIFOFront and FIFORear pointer. The priority queue data
 * structure is implemented using an array based heap of pointers to customer data
 * structures. The higher priority customers are those which have the lower arrival
 * time or departure time.
 *
 * @author Jacob Rook
 * @date 10/12/2017
 * @info Course COP 4534
 * Project 2
 */

#ifndef QUEUE_H_
#define QUEUE_H_

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
//Pointers to the Front and Rear of the FIFO Queue
Customer_t *FIFOFront;
Customer_t *FIFORear;


//FIFO QUEUE FUNCTIONS
/*
 * The FIFO Queue functions are used to manipulate the FIFO Queue. In the simulation
 * the FIFO queue is used to simulate a line of customers waiting to be served.
 */

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
int PQSize;					//Current size of the PQ throughout the simulation

//PQ FUNCTIONS
/*
 * The PQ functions are used to manipulate the array based heap used to simulate
 * a priority queue. The PQ is used in the simulation to prioritize events based
 * on the time that the event occurs. Earlier events have higher priority.
 */
/*
 *@brief	PQEnque		Function will add the passed customer to the end of the
 *PQ and use an insert method comparing the parent to the customer to be added.
 *If the parent is of lower priority, the parent will be moved to the current
 *location of the customer to be added and this process will continue to recur
 *until the parent has a higher priority or the customer to be added is a the top
 *of the PQ. When the parent is of higher priority the customer will stay at the
 *current location in the PQ.
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
 * @brief	percolateDown	Function will use an insert method of percolating down
 * the customer at the index passed in the parameters. Typically the percolateDown
 * function will be used when the lowest priority customer has just been moved to
 * the highest priority position (1) and is needed to be percolated down. But,
 * the function can be used at any position in the PQ. However, the function will
 * compare the customers "children" in the heap at indices 2 times the customer's
 * index and 2 time the customer's index plus 1. The customer that needs to be
 * percolated down will be swapped with the higher priority child, if either child
 * is of higher priority. If neither child is of higher priority the algorithm stops
 * and the customer stays at the current index.
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




#endif /* QUEUE_H_ */
