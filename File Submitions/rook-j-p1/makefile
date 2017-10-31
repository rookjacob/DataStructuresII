rook-j-p1 : main.o Functions.o
	gcc -o rook-j-p1 main.o Functions.o
Functions.o : Functions.c Functions.h
	gcc -c -Wall Functions.c
main.o : main.c Functions.h
	gcc -c -Wall main.c
clean :
	rm rook-j-p1 main.o Functions.o