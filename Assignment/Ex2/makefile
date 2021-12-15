CC = gcc
AR = ar -rcs
FLAGS = -Wall -g
OBJECTS_MAIN = main.o
OBJECT_MY_MAT = string_func.o

all: stringProg funcs 

funcs: libclassfunc.a


libclassfunc.a:$(OBJECT_MY_MAT)
		$(AR) libclassfunc.a $(OBJECT_MY_MAT)

stringProg:$(OBJECTS_MAIN) libclassfunc.a
		$(CC) $(FLAGS) -o stringProg $(OBJECTS_MAIN) libclassfunc.a

main.o: string_func.c ex2.h
		$(CC) $(FLAGS) -c main.c

string_func.o: string_func.c ex2.h
		$(CC) $(FLAGS) -c string_func.c

.PHONY: clean all

Clean:
		rm -f *.o *.a stringProg funcs 