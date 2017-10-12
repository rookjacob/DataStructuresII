/*
 * @file Queue.c !!
 *
 * @author Jacob Rook
 * @date 10/12/2017
 * @info Course COP 4534
 * Project 2
 */

#include"Queue.h"

//PQ FUNCTIONS
void PQEnque(Customer_t *Customer)
{
	PQ[0] = Customer;
	int index = ++PQSize;				//Location to add the new customer
	float time = findTime(Customer);	//Finding the time of the event (arrival or departure time)

	while (time < findTime(PQ[index/2]))	//Comparing the time of the parent in the heap
	{
		PQ[index] = PQ[index/2];
		index /= 2;
	}
	PQ[index] = Customer;

}


Customer_t *PQDeque(void)
{
	Customer_t *tmp = PQ[1];	//Store the Customer that is being Dequeued
	PQ[1] = PQ[PQSize--]; 	//Assigning the last customer in the heap to the highest priority and percolating the customer down
	percolateDown(1);
	return tmp;					//Returning dequeued customer
}


int isPQEmpty(void)
{
	if(PQSize == 0)
		return 1;
	return 0;
}



void percolateDown(int index)
{
	int child;
	Customer_t *tmp = PQ[index];

	while(index*2 <= PQSize)
	{
		child = index * 2;
		if( (child != PQSize ) && ( findTime(PQ[child +1]) < findTime(PQ[child])) )
				child++;
		if (findTime(PQ[child]) < findTime(tmp))
			PQ[index] = PQ[child];
		else
			break;
		index = child;
	}
	PQ[index] = tmp;
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
	Customer->nextCust = NULL;
	if(FIFOFront == NULL && FIFORear == NULL)
	{
		FIFOFront = FIFORear = Customer;
		return;
	}
	FIFORear->nextCust = Customer;
	FIFORear = Customer;
}


Customer_t *FIFODeque(void)
{
	Customer_t *tmp = FIFOFront;
	if(isFIFOEmpty())
		return NULL;
	if(FIFOFront == FIFORear)
		FIFOFront = FIFORear = NULL;
	else
		FIFOFront = FIFOFront->nextCust;
	return tmp;
}


int isFIFOEmpty(void)
{
	if(FIFOFront == NULL)
		return 1;
	return 0;
}

//END OF FIFO QUEUE FUNCTIONS
