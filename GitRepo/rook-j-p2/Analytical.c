/*
 * @file Analytical.c
 *
 * @author Jacob Rook
 * @date 10/12/2017
 * @info Course COP 4534
 * Project 2
 */

#include"Analytical.h"





//PQ FUNCTIONS
void PQEnque(Customer_t *Customer)
{
	PQ[0] = Customer;
	int index = ++PQSize;
	float time = findTime(Customer);
	float parentTime = findTime(PQ[index/2]);

	while (time < parentTime)
	{
		PQ[index] = PQ[index/2];
		index /= 2;
		parentTime = findTime(PQ[index/2]);
	}
	PQ[index] = Customer;
}


Customer_t *PQDeque(void)
{

}


int isPQEmpty(void)
{

}


void percolateUp(Customer_t *Customer)
{

}


void percolateDown(int index)
{

}


float findTime(Customer_t *Customer)
{
	if (Customer->type == 'A')
		return Customer->arrivalTime;
	else
		return Customer->departureTime;

}


//END OF PQ FUNCTIONS






//FIFO QUEUE FUNCTIONS
void FIFOEnque(Customer_t *Customer)
{

}


Customer_t *FIFODeque(void)
{

}


int isFIFOEmpty(void)
{

}

//END OF FIFO QUEUE FUNCTIONS






//SET FUNCTIONS
void setN(int N)
{

}


void setLambda(float L)
{

}


void setMu(float M)
{

}


void setM(float M)
{

}


//END OF SET FUNCTIONS







//EXPECTED CALCULATIONS FOR THE ANALYTICAL MODEL
float calIdle(void)
{

}


float calAvePeopleSys(void)
{

}


float calAveTimeSys(void)
{

}


float calAveCustQ(void)
{

}


float calAveTimeWait(void)
{

}


float calUtiliFactor(void)
{

}


//END OF EXPECTED CALCULATIONS FOR THE ANALYTICAL MODEL



//FUNCTIONS FOR SIMULATION
void PlaceFirstArrivals(void)
{

}


void ProcessNextEvent(void)
{

}


//END OF FUNCTIONS FOR SIMULATION
