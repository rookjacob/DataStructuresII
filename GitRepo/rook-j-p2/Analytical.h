/*
 * @file Analytical.h !!
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

#include"Queue.h"


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
 * @brief 	runSimulation		Function acts as the main function for the Analytical
 * file. All of the simulation code is ran or called inside of runSimulation. The user
 * will call runSimulation and the simulation will run and print out the simulation
 * results. runSimulation first initialize all of the important variables the simulation
 * keeps track of throughout the simulation. Then, the first couple of customers will
 * be added to the PQ to start off the simulation. After the intital customers are
 * added, a while loop is activated to keep running until the PQ is empty. In the while
 * loop the next event will be processed and more arrivals will be added to the PQ
 * when needed. After this the function will do the last bit of calculations to finish
 * the calculations and then call the printSimulation function to print the calculations.
 */
void runSimulation(void);

/*
 * @brief	getInterval			Function calculates a random interval around the given
 * average using the rand() function and negative exponential distribution
 *
 * @param	avg					The average value to calculate a random interval around
 *
 * @return	float				Returns interval
 */
float getInterval(float avg);

/*
 * @brief	PlaceFirstArrivals	Function places M or numService number of arrivals into
 * PQ.
 */
void PlaceFirstArrivals(void);

/*
 * @brief	createNewArrivl		Function creates a new customer variable dynamically
 * in memory, initializes the nextCust, type, and arrivalTime of the variable and
 * returns the pointer to the new customer variable
 *
 * @return	Customer_t*			Returns pointer to the newly created customer variable
 */
Customer_t *createNewArrival(void);

/*
 * @brief	moreArrivals		Function check to see if there are more arrivals to be
 * added to the simulation.
 *
 * @return	int					Returns 1 if more arrivals can be added 0 if not
 */
int moreArrivals(void);

/*
 * @brief	generateNextSet		Function fills the PQ with new arrivals
 */
void generateNextSet(void);

/*
 * @brief	ProcessNextEvent	Function takes the next customer off of the PQ,
 * determines if the customer is an arrival or departure. If the customer is an arrival
 * and their is service available the clock is updated with the customer's arrival time
 * and customer goes straight to the service. If all of the service providers are
 * busy the customer is put in the FIFO queue. If the customer is a departure, the
 * clock is updated with the customers departure time. If the FIFO queue is not empty
 * the customer at the front of the FIFO queue is then served. The customer is switched
 * from an arrival customer to a departure customer, and the departure time is calculated
 * and set for the customer. If there is not a person in the FIFO queue, the function
 * checks to see if there are any customers being served at that moment. If there are
 * no customers being served at that moment then the PoSim is updated because there
 * will be a period of time where there will be no customers in the simulation. This
 * can be calculated to be the difference in time of the next arrival and the last
 * departure. The function then frees the memory of the customer that was processed.
 */
void ProcessNextEvent(void);

/*
 * @brief	processStats		Function adds the appropriate times to the WSim,
 * WqSim, and rhoSim variables to keep track of how much time has elapsed for each
 * simulated calculation.
 *
 * @param	Departure			Departure to process stats
 */
void processStats(Customer_t *Departure);
/*
 * @brief	printSimulation		Function prints the results of the simulation to the
 * output.
 */
void printSimulation(void);

/*
 * @brief	printComparison		Function prints out the percent error of each simulated
 * calculation to the expected calculation. To save the same calculations being made
 * multiple times the function does all of the calculations inside the function.
 */
void printComparison(void);
//END OF FUNCTIONS FOR SIMULATION






#endif /* ANALYTICAL_H_ */
