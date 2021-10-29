#include<stdio.h>
#include"header.h"

void main(){
    printf("\nI am in main.c\n");
    printf("\nCalling hello function");
    hello();
    printf("\ncalling add function\n");
    add(10,23);
    printf("\nBack in main.c\n");
}