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






//SET FUNCTIONS
void setN(int N)
{
	numArrivals = N;
	return;
}


void setLambda(float L)
{
	lambda = L;
	return;
}


void setMu(float M)
{
	mu = M;
	return;
}


void setM(float M)
{
	numService = M;
	return;
}


//END OF SET FUNCTIONS







//EXPECTED CALCULATIONS FOR THE ANALYTICAL MODEL
float calIdle(void)
{
	float sum = 0;
	int i;

	for (i=0; i < numService; i++)
		sum = sum + 1.0/(fact(i)) * (power(lambda/mu, i));
	sum = sum + 1.0/(fact(numService)) * (power(lambda/mu, numService)) * numService * mu /(numService * mu - lambda);
	return 1/sum;
}


float calAvePeopleSys(void)
{
	float L = lambda * mu * power(lambda/mu, numService) * calIdle();
	L = L/( fact(numService - 1) * power((float)numService * mu - lambda, 2));
	return L + lambda/mu;

}


float calAveTimeSys(void)
{
	return calAvePeopleSys()/lambda;
}


float calAveCustQ(void)
{
	return calAveTimeSys() - lambda/mu;
}


float calAveTimeWait(void)
{
	return calAveCustQ()/lambda;
}


float calUtiliFactor(void)
{
	return lambda/numService/mu;
}

void printAllCal(void)
{
	float Pnot = calIdle();
	float L, W, Lq , Wq, rho;
	L = lambda * mu * power(lambda/mu, numService) * Pnot;
	L = L/( fact(numService - 1) * power((float)numService * mu - lambda, 2));
	L = L + lambda/mu;
	W = L/lambda;
	Lq = L - lambda/mu;
	Wq = Lq/lambda;
	rho = lambda/numService/mu;

	 printf("Po  = %.3f\n"
			"L   = %.3f\n"
			"W   = %.3f\n"
			"Lq  = %.3f\n"
			"Wq  = %.3f\n"
			"rho = %.3f\n",
			Pnot,L,W,Lq,Wq,rho);
}

float fact(int n)
{
	if(n == 0)
		return 1;
	else
		return (float)(n * fact(n - 1));
}

float power(float x, int y)
{
	float result = 1;
	while(y>0)
	{
		result = result * x;
		y--;
	}
	return result;
}


//END OF EXPECTED CALCULATIONS FOR THE ANALYTICAL MODEL



//FUNCTIONS FOR SIMULATION
void runSimulation(void)
{
	FIFOFront = FIFORear = NULL;
	PQSize = 0;
	serverAvailable = numService;
	numArrivalsLeft = numArrivals;
	clock = 0;
	PlaceFirstArrivals();

	while (!isPQEmpty())
	{
		ProcessNextEvent();
		if (moreArrivals() && PQSize <= numService)
			generateNextSet();
	}
	printSimulation();
}

float getInterval(float avg)
{
	float interval = (float)rand()/(float)(RAND_MAX);
	interval = -1 * (1.0/avg) * (float)(log(interval));
	return interval;
}

void PlaceFirstArrivals(void)
{

}

Customer_t *createNewArrival(void)
{

}

int moreArrivals(void)
{
	if (numArrivalsLeft == 0)
		return 0;
	return 1;
}

void generateNextSet()
{

}

void ProcessNextEvent(void)
{

}

void printSimulation(void)
{

}


//END OF FUNCTIONS FOR SIMULATION
