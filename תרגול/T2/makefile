CC = gcc

prog: main.o mult3.o div2.o
	$(CC) -o prog main.o mult3.o div2.o
main.o: main.c div2.h mult3.h
	$(CC) -c main.c
div2.o: div2.c div2.h
	$(CC) -c div2.c
mult3.o: mult3.c mult3.h
	$(CC) -c mult3.c
.PHONY: clean
clean:
	rm -f *.o prog