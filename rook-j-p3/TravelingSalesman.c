/*
 * @file TravelingSalesman.c
 *
 * @author Jacob Rook
 * @date 11/02/2017
 * @info Course COP 4534
 * Project 3
 */

#include"TravelingSalesman.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


void HeapEnqueue(Tour *TourEnque, Tour Heap[], int *HeapSize)
{
	TourEnque->tourWeight = calTourWeight(TourEnque);
	setTourEqual(&Heap[0], TourEnque);
	int index = ++(*HeapSize);

	while(TourEnque->tourWeight < Heap[index/2].tourWeight)
	{
		setTourEqual(&Heap[index], &Heap[index/2]);
		index /=2;
	}
	setTourEqual(&Heap[index], TourEnque);
}

Tour HeapDequeue(Tour Heap[], int *HeapSize)
{
	Tour tmp;
	setTourEqual(&tmp, &Heap[1]);
	setTourEqual(&Heap[1], &Heap[(*HeapSize)--]);
	percolateDown(Heap, HeapSize, 1);
	return tmp;
}

int isHeapEmpty(int *HeapSize)
{
	return !(*HeapSize);
}

void percolateDown(Tour Heap[], int *HeapSize, int index)
{
	int child;
	Tour tmp;
	setTourEqual(&tmp, &Heap[index]);

	while(index * 2 <= *HeapSize)
	{
		child = index * 2;
		if((child != *HeapSize) && (Heap[child +1].tourWeight < Heap[child].tourWeight))
			child++;
		if(Heap[child].tourWeight < tmp.tourWeight)
			setTourEqual(&Heap[index], &Heap[child]);
		else
			break;
		index = child;
	}
	setTourEqual(&Heap[index], &tmp);
}





void startTravel(int numCities, int numTours, int numGen, double percentMut)
{
	struct timespec TimeStart, TimeEnd;
	double BFTime, GTime;

	initTourVar(numCities, numTours, numGen, percentMut);

	clock_gettime(CLOCK_REALTIME, &TimeStart);
	execBruteForce();
	clock_gettime(CLOCK_REALTIME, &TimeEnd);
	BFTime = calTimeDiff(&TimeEnd, &TimeStart);

	clock_gettime(CLOCK_REALTIME, &TimeStart);
	execGenetic();
	clock_gettime(CLOCK_REALTIME, &TimeEnd);
	GTime = calTimeDiff(&TimeEnd, &TimeStart);

	printf("Brute Force took %lfs", BFTime);
	printf("Genetic took     %lfs", GTime);


}

void initTourVar(int numCities, int numTours, int numGen, double percentMut)
{
	CITIES = numCities;
	TOURSNGEN = numTours;
	GENERATIONS = numGen;
	MUTATIONS = floor(percentMut *  TOURSNGEN / 100);

	if (MUTATIONS > (TOURSNGEN - 2))
		MUTATIONS = TOURSNGEN - 2;

	populateGraph();

	initGeneration();

}

void genNewWeight(void)
{
	FILE *fp = fopen("cityWeights.txt", "w");
	int i;
	double DoubleMax = 100.0;
	double tmp;
	srand((unsigned int)time(NULL));

	for(i = 0 ; i < 380 ; i++)
	{
		tmp = ((double)rand()/(double)RAND_MAX) * DoubleMax;
		fprintf(fp, "%lf\n", tmp);
	}
	fclose(fp);

}

void populateGraph(void)
{
	FILE *fp = fopen("cityWeights.txt", "r");
	int i;
	int j;
	double tmp;

	for(i = 0; i < MAXCITIES; i++)
	{
		printf("\n");
		for(j = 0; j < MAXCITIES; j++)
		{
			if(i == j)
			{
				continue;
			}
			fscanf(fp, "%lf ", &tmp);
			CITYGRAPH[i][j] = tmp;
		}
	}
	fclose(fp);
}

void initGeneration(void)
{
	GenHeap1 = (Tour *)malloc((GENERATIONS + 1)* sizeof(Tour ));
	GenHeap2 = (Tour *)malloc((GENERATIONS + 1) * sizeof(Tour ));
	GenHeap1Size = 0;
	GenHeap2Size = 0;
	int n, m, k, p, q;
	n = CITIES - 1;

	Tour TmpTour;
	initTour(&TmpTour);
	HeapEnqueue(&TmpTour, GenHeap1, &GenHeap1Size);
	while(GenHeap1Size < TOURSNGEN)
	{
		m = n - 2;
		while(TmpTour.cityTour[m] > TmpTour.cityTour[m+1])
			m = m - 1;
		k = n - 1;
		while(TmpTour.cityTour[m] > TmpTour.cityTour[k])
			k = k - 1;
		swap(m, k, &TmpTour);
		p = m + 1;
		q = n - 1;
		while(p < q)
		{
			swap(p, q, &TmpTour);
			p++;
			q--;
		}
		HeapEnqueue(&TmpTour, GenHeap1, &GenHeap1Size);
	}

}

void execBruteForce(void)
{
	int n, m, k, p, q, i, nfact;
	n = CITIES - 1;
	nfact = fact(n);

	Tour TmpTour;
	initTour(&TmpTour);
	setTourEqual(&BESTTOUR, &TmpTour);
	for(i = 1; i < nfact; i++)
	{
		m = n - 2;
		while(TmpTour.cityTour[m] > TmpTour.cityTour[m+1])
			m = m - 1;
		k = n - 1;
		while(TmpTour.cityTour[m] > TmpTour.cityTour[k])
			k = k - 1;
		swap(m, k, &TmpTour);
		p = m + 1;
		q = n - 1;
		while(p < q)
		{
			swap(p, q, &TmpTour);
			p++;
			q--;
		}
		calTourWeight(&TmpTour);
		if(compareTour(&TmpTour, &BESTTOUR))
			setTourEqual(&BESTTOUR, &TmpTour);


	}

}

void initTour(Tour *init)
{
	int i;

	for(i = 1; i < CITIES; i++)
		init->cityTour[i-1] = i;
	init->tourWeight = calTourWeight(init);
}

int fact(int n)
{
	if (n == 1)
		return 1;

	return n * fact(n-1);
}

void swap(int p, int q, Tour *TourSwap)
{
	int tmp = TourSwap->cityTour[p];
	TourSwap->cityTour[p] = TourSwap->cityTour[q];
	TourSwap->cityTour[q] = tmp;
}

int compareTour(Tour *Tour1, Tour *Tour2)
{
	if(Tour1->tourWeight < Tour2->tourWeight)
		return 1;
	return 0;
}

/*
 *
 */
void setTourEqual(Tour *T1, Tour *T2)
{
	int i;

	for( i = 0; i < CITIES; i++)
		T1->cityTour[i]= T2->cityTour[i];
	T1->tourWeight = T2->tourWeight;
}

void execGenetic(void)
{
	int i;
	int condition = 0;
	for(i = 0; i < GENERATIONS; i++)
	{
		if(condition)
		{
			populateGeneration(GenHeap1, &GenHeap1Size, GenHeap2, &GenHeap2Size );
			condition = 0;
		}
		else
		{
			populateGeneration(GenHeap2, &GenHeap2Size, GenHeap1, &GenHeap1Size );
			condition = 1;
		}
	}
}

void populateGeneration(Tour Heap2[], int *Heap2Size, Tour Heap1[], int *Heap1Size)
{	//Store best Heap 1 into Heap 2
	Tour BestTour = HeapDequeue(Heap1,Heap1Size) ;
	Tour SecondBTour = HeapDequeue(Heap1,Heap1Size);
	Heap2Size = 0;
	HeapEnqueue(&BestTour,Heap2, Heap2Size);
	HeapEnqueue(&SecondBTour,Heap2, Heap2Size);

	int i;
	Tour tmp;
	for(i = 0; i < MUTATIONS; i++)
	{
		if(i%2)
		{
			setTourEqual(&tmp, &SecondBTour);
			tourMutate(&tmp, 15,5);
			HeapEnqueue(&tmp, Heap2, Heap2Size);
		}
		else
		{
			setTourEqual(&tmp, &BestTour);
			tourMutate(&tmp, 5,3);
			HeapEnqueue(&tmp, Heap2, Heap2Size);
		}


	}
	while(*Heap2Size < TOURSNGEN)
	{

		setTourEqual(&tmp, HeapDequeue(Heap1, Heap1Size));

	}
}

void tourMutate(Tour *Mut, int MUTRANGEMAX, int MUTRANGEMIN)
{
	srand(time(CLOCK_REALTIME));
	int i, MutRange = rand() % (MUTRANGEMAX - MUTRANGEMIN) + MUTRANGEMIN;

	for(i = 0; i < MutRange; i++)
	{
		swap(rand()%(CITIES - 2), rand()%(CITIES - 2), Mut);
	}
}

void tourRandPerm(Tour *Perm)
{
	int n, m, k, p, q, i = 0;
	n = CITIES - 1;
	int randMax = 50, randMin = 20;
	srand(CLOCK_REALTIME);

	Tour TmpTour;
	setTourEqual(&TmpTour, Perm);
	while(i < rand() % (randMax - randMin) + randMin)
	{
		m = n - 2;
		while(TmpTour.cityTour[m] > TmpTour.cityTour[m+1])
			m = m - 1;
		k = n - 1;
		while(TmpTour.cityTour[m] > TmpTour.cityTour[k])
			k = k - 1;
		swap(m, rand() % k, &TmpTour);
		p = m + 1;
		q = n - 1;
		while(p < q)
		{
			swap(p, rand() % q, &TmpTour);
			p++;
			q--;
		}
		swap(rand() % (CITIES - 2), rand() % (CITIES - 2), &TmpTour);
		i++;
	}
	setTourEqual(Perm, &TmpTour);
}


double calTourWeight(Tour *T)
{
	double weight = CITYGRAPH[0][T->cityTour[0]];	//From starting city to first city
	int i;

	for(i = 0; i < CITIES - 2; i++)
	{
		weight += CITYGRAPH[T->cityTour[i]][T->cityTour[i+1]];
	}

	weight += CITYGRAPH[T->cityTour[CITIES - 2]][0]; //From last city to starting city
	T->tourWeight = weight;
	return weight;
}

void printTour(Tour *T)
{
	int i;
	printf("0->");
	for(i = 0; i < CITIES - 1; i++)
	{
		printf("%d->",T->cityTour[i]);
	}
	printf("0\nWeight: %lf\n", T->tourWeight);
}

double calTimeDiff(struct timespec *End, struct timespec *Start)
{
	return difftime(End->tv_sec, Start->tv_sec) + ((double)End->tv_nsec - (double)Start->tv_nsec)/1000000000.0;
}


