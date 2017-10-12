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
#include<stdlib.h>
#include<math.h>



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

/*
 * Absolute clock for simulation. The clock will progress whenever an event occurs.
 * The clock will be set to the events time and all other new events will be based
 * off the clock. Therefore, the simulation will be monotonically increasing.
 */
float clock;

//Initial statistic values provided by the user
int 	numArrivals;
float 	lambda;
float	mu;
int		numService;

//Variables for the current numService and numArrivals left in the simulation
int serverAvailable;
int numArrivalsLeft;


//Variables to keep track of the statistics data through out the simulation
float PoSim;		//Simulated time between last customer being served until next arrival
float WSim;			//Simulated average Time a customer spends in the system
float WqSim;		//Simulated average time a customer spends waiting in queue
float rhoSim;		//Simulated utilization factor for system
int   numWait;		//Number of customers added to the FIFO Queue
float waitProb;		//Simulated wait probability





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






//SET FUNCTIONS
/*
 * The set functions are used to set the numArrivals, lambda, mu, and numService
 * variables.
 */

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
 * The expected calculations for the analytical model functions are use to do just
 * that calculate the expected calculations of the simulation. The user can decide
 * to use the individual functions to get each calculation individually or the
 * user can use the printAllCal function to just simply print the calculated
 * values.
 */

/*
 * @brief	calIdle		Function calculates the expected percent idle time (Po),
 * the percent of time that no one is in the system, of a long simulation
 *
 * @return	float		Returns the value of the expected percent idle time
 */
float calIdle(void);

/*
 * @brief	calAvePeopleSys		Function calculates the expected average number of
 * people in the system (L) of a long simulation
 *
 * @return 	float				Returns the value of the expected average number
 * of people in the simulation
 */
float calAvePeopleSys(void);

/*
 * @brief	calAveTimeSys		Function calculates the expected average time a
 * customer spends in the system (W), the time the customer spent in line plus the
 * time spent getting service, of a long simulation
 *
 * @return	float				Returns the expected average time a customer spends
 * in the system
 */
float calAveTimeSys(void);

/*
 * @brief	calAveCustQ			Function calculates the expected average number
 * of customers in the queue (Lq) of a long simulation
 *
 * @return 	float				Returns expected average number of customers in queue
 */
float calAveCustQ(void);

/*
 * @brief	calAveTimeWait		Function calculates the expected average time a
 * customer spends wait in the FIFO queue (Wq), or in line, of a long simulation
 *
 * @return	float				Returns the expected average time a customer spends
 * waiting in the FIFO queue
 */
float calAveTimeWait(void);

/*
 * @brief	calUtiliFactor		Function calculates the expected utilization factor
 * for the system (rho), that is, the proportion of the system's resources which
 * is used by the traffic which arrives of a long simulation
 *
 * @return	float				Returns the expected utilization factor for the system
 */
float calUtiliFactor(void);

/*
 * @breif	printAllCal			Function prints all of the expected calculations:
 * Po, L, W, Lq, Wq, and rho. The function calculates the values of the expected
 * calculations itself rather than call the individual functions to save multiple
 * calcualtions of the same variables.
 */
void printAllCal(void);

/*
 * @brief	fact				Function calculates the factorial of the integer n
 *
 * @return	float				Returns the factorial of n as float to simplify
 * calculations in the cal functions
 */
float fact(int n);

/*
 * @brief	power				Function calculates x^y
 *
 * @return	float				Returns x^y
 */
float power(float x, int y);
//END OF EXPECTED CALCULATIONS FOR THE ANALYTICAL MODEL



//FUNCTIONS FOR SIMULATION
/*
 *
 */

/*
 *
 */
void runSimulation();

/*
 *
 */
float getInterval(float avg);

/*
 *
 */
void PlaceFirstArrivals(void);

/*
 *
 */
Customer_t *createNewArrival(void);

/*
 *
 */
int moreArrivals(void);

/*
 *
 */
void generateNextSet(void);

/*
 *
 */
void ProcessNextEvent(void);

/*
 *
 */
void processStats(Customer_t *Departure);
/*
 *
 */
void printSimulation(void);

/*
 *
 */
void printComparison(void);
//END OF FUNCTIONS FOR SIMULATION






#endif /* ANALYTICAL_H_ */
