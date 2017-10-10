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

	while (time < findTime(PQ[index/2]))
	{
		PQ[index] = PQ[index/2];
		index /= 2;
	}
	PQ[index] = Customer;
}


Customer_t *PQDeque(void)
{
	Customer_t *tmp = PQ[1];
	PQ[1] = PQ[PQSize--];
	percolateDown(1);
	return tmp;
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
		if (findTime(child) < findTime(tmp))
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
	if(isFIFOEmpty(FIFOFront))
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






//SET FUNCTIONS
void setN(int N)
{
	numArrivals = N;
	return;
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
