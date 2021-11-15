CC = gcc
AR = ar -rcs
FLAGS = -Wall -g
OBJECTS_MAIN = main.o
OBJECT_MY_MAT = my_mat.o

all: mains mats matd

mats: libclassmymat.a

matd: libclassmymat.so

libclassmymat.a:$(OBJECT_MY_MAT)
		$(AR) libclassmymat.a $(OBJECT_MY_MAT)

libclassmymat.so:$(OBJECT_MY_MAT)
		$(CC) -shared -o libclassmymat.so $(OBJECT_MY_MAT)

mains:$(OBJECTS_MAIN) libclassmymat.a
		$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libclassmymat.a

main.o: main.c my_mat.h
		$(CC) $(FLAGS) -c main.c

my_mat.o: my_mat.c my_mat.h
		$(CC) $(FLAGS) -c my_mat.c

.PHONY: clean all

Clean:
		rm -f *.o *.a *.so *.txt mains mats matd