rook-j-p4 : rook-j-p4.o monteCarlo.o
	gcc -o rook-j-p4 rook-j-p4.o monteCarlo.o
monteCarlo.o : monteCarlo.h monteCarlo.c
	gcc -c -g -Wall monteCarlo.c
rook-j-p4.o : rook-j-p4.c monteCarlo.h
	gcc -c -g -Wall rook-j-p4.c
clean : 
	rm rook-j-p4 rook-j-p4.o monteCarlo.o
	