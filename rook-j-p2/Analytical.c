/*
 * @file Analytical.c		File contains all of the function definitions for the
 * function prototypes defined in Analytical.h. The detailed description of functions
 * are in Analytical.h.
 *
 * @author Jacob Rook
 * @date 10/12/2017
 * @info Course COP 4534
 * Project 2
 */

#include"Analytical.h"






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
	//Main initial variable set
	FIFOFront = FIFORear = NULL;		// Initialize FIFO Q to be empty
	PQSize = 0;							//Initialize PQ to be empty
	numArrivalsLeft = numArrivals;		//Initialize number of arrivals left in simulation equal to total number of arrivals
	clock = 0;							//Initialize absolute clock to 0
	PoSim = WSim = WqSim = rhoSim = 0;	//Initialize Simulation Stats
	waitProb = 0;
	PlaceFirstArrivals();
	serverAvailable = numService;		//Initialize servers Available to total servers



	while (!isPQEmpty())
	{
		ProcessNextEvent();
		if (moreArrivals() && PQSize <= numService)
			generateNextSet();
	}
	PoSim /= clock;
	WSim /= numArrivals;
	WqSim /= numArrivals;
	rhoSim /= ((float)numService * clock);
	waitProb = (float)numWait /((float)numArrivals);


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
	int i = 1;
	float TmpTime=0;
	while (i <= numService)
	{
	Customer_t *Arrival = createNewArrival();
	if(i == 1)
		PoSim = Arrival->arrivalTime;		//Accounting for the time between the start of the simulation and the first arrival
	Arrival->arrivalTime += TmpTime;
	TmpTime = Arrival->arrivalTime;

	PQEnque(Arrival);


	i++;
	}
	return;
}

Customer_t *createNewArrival(void)
{
	Customer_t *newArrival = (Customer_t *)malloc(sizeof(Customer_t));
	newArrival->nextCust = NULL;
	newArrival->type = 'A';
	newArrival->arrivalTime = getInterval(lambda);
	return newArrival;
}

int moreArrivals(void)
{
	if (numArrivalsLeft <= 0)
		return 0;
	return 1;
}

void generateNextSet()
{
	float TmpTime = clock;
	while(PQSize < PQMAXSIZE && numArrivalsLeft > 0)
	{
		Customer_t *Arrival = createNewArrival();
		Arrival->arrivalTime += TmpTime;
		TmpTime = Arrival->arrivalTime;

		PQEnque(Arrival);
		numArrivalsLeft--;

	}
}

void ProcessNextEvent(void)
{
	Customer_t *Event = PQDeque();

	if(Event->type == 'A')
	{
		clock = Event->arrivalTime;
		if(serverAvailable > 0)
		{
			serverAvailable--;
			Event->startOfServiceTime = Event->arrivalTime;
			Event->departureTime = Event->arrivalTime + getInterval(mu);
			Event->type = 'D';

			PQEnque(Event);
		}
		else
		{
			FIFOEnque(Event);
			numWait++;
		}
	}
	else	//Processing Departure
	{
		clock = Event->departureTime;
		serverAvailable++;
		processStats(Event);

		if(!isFIFOEmpty())
		{
			Customer_t *FIFOCust = FIFODeque();
			FIFOCust->startOfServiceTime = Event->departureTime;
			FIFOCust->departureTime = FIFOCust->startOfServiceTime + getInterval(mu);
			FIFOCust->type = 'D';

			PQEnque(FIFOCust);
			serverAvailable--;
		}
		else if (serverAvailable == numService)
		{//Event is the last customer to be served, meaning there are no customers being served
			PoSim += PQ[1]->arrivalTime - Event->departureTime;
		}


		free(Event);
	}
}

void processStats(Customer_t *Departure)
{
	WSim += Departure->departureTime - Departure->arrivalTime;
	WqSim += Departure->startOfServiceTime - Departure->arrivalTime;
	rhoSim += Departure->departureTime - Departure->startOfServiceTime;
}

void printSimulation(void)
{
	printf( "PoSim    = %.3f\n"
			"Wsim     = %.3f\n"
			"WqSim    = %.3f\n"
			"rhoSim   = %.3f\n"
			"waitProb = %.3f\n",
			PoSim, WSim, WqSim, rhoSim, waitProb);
}

void printComparison(void)
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

	printf( "Po  Percent Error = %%%6.3f\n"
			"W   Percent Error = %%%6.3f\n"
			"Wq  Percent Error = %%%6.3f\n"
			"rho Percent Error = %%%6.3f\n",
			(PoSim - Pnot)/Pnot * 100.0,
			(WSim - W)/W * 100.0,
			(WqSim - Wq)/Wq * 100.0,
			(rhoSim - rho)/rho * 100.0);

}


//END OF FUNCTIONS FOR SIMULATION
