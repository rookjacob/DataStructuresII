rook-j-p5 : rook-j-p5.o LCS.o
	gcc -o rook-j-p5 rook-j-p5.o LCS.o 
LCS.o : LCS.h LCS.c
	gcc -c -O0 -g -Wall LCS.c
rook-j-p5.o : rook-j-p5.c LCS.h
	gcc -c -O0 -g -Wall rook-j-p5.c
clean : 
	rm rook-j-p5 rook-j-p5.o LCS.o
	