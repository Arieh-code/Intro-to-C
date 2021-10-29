# This is a makefile for 3 soure files: main.c, add.c, hello.c
# Save the file with name "Makefile"


# #********* Method 1 *********
# final:
# 		gcc main.c add.c hello.c -o final

#********* Method 2 **********
# $(CC) = gcc
# final:
# 		$(CC) main.c add.c hello.c -o final
# Clean: 
# 		rm *.o final

# #********** Method 3 ***********
$(CC) = gcc
final: main.o add.o hello.o
		$(CC) main.o add.o hello.o -o final

main.o: main.c header.h
		$(CC) -c main.c

add.o: add.c header.h
		$(CC) -c add.c

hello.o: hello.c header.h 
		$(CC) -c hello.c 

Clean:
		rm *.o final 