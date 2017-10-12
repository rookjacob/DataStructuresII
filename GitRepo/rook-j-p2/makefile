rook-j-p2 : main.o Analytical.o Queue.o
	gcc -o rook-j-p2 main.o Analytical.o Queue.o -lm
Queue.o : Queue.c Queue.h
	gcc -c -g -Wall Queue.c
Analytical.o : Analytical.c Analytical.h Queue.h
	gcc -c -g -Wall Analytical.c
main.o : main.c Analytical.h
	gcc -c -g -Wall main.c
clean :
	rm rook-j-p2 main.o Analytical.o Queue.o