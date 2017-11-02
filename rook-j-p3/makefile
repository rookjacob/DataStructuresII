rook-j-p3 : rook-j-p3.o TravelingSalesman.o
	gcc -o rook-j-p3 rook-j-p3.o TravelingSalesman.o -lm
TravelingSalesman.o : TravelingSalesman.c TravelingSalesman.h
	gcc -c -g -Wall TravelingSalesman.c
rook-j-p3.o : rook-j-p3.c TravelingSalesman.h
	gcc -c -g -Wall rook-j-p3.c
clean : 
	rm rook-j-p3 rook-j-p3.o TravelingSalesman.o