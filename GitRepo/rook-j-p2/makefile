rook-j-p2 : main.o Analytical.o
	gcc -o rook-j-p2 main.o Analytical.o -lm
Analytical.o : Analytical.c Analytical.h
	gcc -c -g -Wall Analytical.c
main.o : main.c Analytical.h
	gcc -c -g -Wall main.c
clean :
	rm rook-j-p2 main.o Analytical.o