/*
 * @file TravelingSalesman.h
 *
 * @author Jacob Rook
 * @date 11/02/2017
 * @info Course COP 4534
 * Project 3
 */

#ifndef TRAVELINGSALESMAN_H_
#define TRAVELINGSALESMAN_H_
#include<time.h>

#define MAXCITIES 20

double CITYGRAPH[MAXCITIES][MAXCITIES];

int CITIES;
int TOURSNGEN;
int GENERATIONS;
int MUTATIONS;


typedef struct T {
	int cityTour[MAXCITIES];
	double tourWeight;
}Tour;

Tour BESTTOUR;

Tour *GenHeap1;
int GenHeap1Size;
Tour *GenHeap2;
int GenHeap2Size;

/*
 *
 */
void HeapEnqueue(Tour *TourEnque, Tour **Heap, int *HeapSize);

/*
 *
 */
Tour *HeapDequeue(Tour **Heap, int *HeapSize);

/*
 *
 */
int isHeapEmpty(int *HeapSize);

/*
 *
 */
void percolateDown(Tour **Heap, int *HeapSize, int index);


/*
 *
 */
void startTravel(int numCities, int numTours, int numGen, double percentMut);

/*
 *
 */
void initTourVar(int numCities, int numTours, int numGen, double percentMut);

/*
 *
 */
void genNewWeight(void);


/*
 *
 */
void populateGraph(void);

/*
 *
 */
void initGeneration(void);

/*
 *
 */
void execBruteForce(void);

/*
 *
 */
void initTour(Tour *init);

/*
 *
 */
int fact(int n);

/*
 *
 */
void swap(int p, int q, Tour *TourSwap);

/*
 *
 */
int compareTour(Tour *Tour1, Tour *Tour2);

/*
 *
 */
void setTourEqual(Tour *T1, Tour *T2);

/*
 *
 */
void execGenetic(void);

/*
 *
 */
void populateGeneration(Tour **Heap2, int *Heap2Size, Tour **Heap1, int *Heap1Size);

/*
 *
 */
void tourMutate(Tour *Mut);

/*
 *
 */
void tourRandPerm(Tour *Perm);

/*
 *
 */
double calTourWeight(Tour *T);

/*
 *
 */
void printTour(Tour *T);

/*
 *
 */
double calTimeDiff(struct timespec *End, struct timespec *Start);



#endif /* TRAVELINGSALESMAN_H_ */
