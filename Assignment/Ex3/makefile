CC = gcc
AR = ar -rcs
FLAGS = -Wall -g
OBJECTS_MAIN = main.o
OBJECT_MY_MAT = algo.o

all: graph graphfunc 

graphfunc: libclassgraph.a


libclassgraph.a:$(OBJECT_MY_MAT)
		$(AR) libclassgraph.a $(OBJECT_MY_MAT)

graph:$(OBJECTS_MAIN) libclassgraph.a
		$(CC) $(FLAGS) -o graph $(OBJECTS_MAIN) libclassgraph.a

main.o: algo.c graph.h
		$(CC) $(FLAGS) -c main.c

algo.o: algo.c graph.h
		$(CC) $(FLAGS) -c algo.c

.PHONY: clean all

Clean:
		rm -f *.o *.a *.txt graph  