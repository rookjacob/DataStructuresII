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

#define MAXCITIES 20

double CITYGRAPH[MAXCITIES][MAXCITIES];
double PERMUTATION[MAXCITIES];

int CITIES;
int TOURSNGEN;
int GENERATIONS;
int MUTATIONS;


typedef struct T {
	int cityTour[MAXCITIES];
	double tourWeight;
}Tour;

typedef struct Gen {
	struct Gen *Next;
	Tour TourGen;
}Generation;

Generation *Gen1Head;
Generation *Gen2Head;


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
void execBruteForce(void);

/*
 *
 */
int fact(int n);

/*
 *
 */
void swap(int p, int q);

/*
 *
 */
void execGenetic(void);

/*
 *
 */
double calTourWeight(Tour *T);



#endif /* TRAVELINGSALESMAN_H_ */
