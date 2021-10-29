$(CC) = gcc
final: main.o isArmstrong.o hello.o
		$(CC) main.o isArmstrong.o hello.o -o final

main.o: main.c header.h
		$(CC) -c main.c

isArmstrong.o: isArmstrong.c header.h
		$(CC) -c isArmstrong.c

hello.o: hello.c header.h 
		$(CC) -c hello.c

 

Clean:
		rm *.o final 