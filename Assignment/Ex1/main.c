#include<stdio.h>
#include"my_mat.h"
#define Max 10
#define True 1
#define False -1

int main(){
    int matrix[Max][Max];
    char input;
    while(input != 'D'){
    scanf("%c", input);
    if(input == 'A'){
        make_mat(matrix);
    }
    else if(input == 'B'){
        int i, j;
        scanf("%d,%d", &i,&j);
        if(exsits(matrix, i, j) == True){
            printf("True\n");
        }
        else{
            printf("False\n");
        }
    }
    else if(input == "C"){
        int a, b;
        scanf("%d,%d", &a,&b);
        shortest_route(matrix);
        print_shortestpath(matrix, a, b);

    }
    
    }
}