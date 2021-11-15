#include<stdio.h>
#include"my_mat.h"
#define Max 10
#define True 1
#define False -1

int main(){
    int matrix[Max][Max];
    char input;
    while(input != 'D'){
    scanf("%c", &input);
    if(input == 'A'){
        make_mat(matrix);
        shortest_route(matrix);
    }
    else if(input == 'B'){
        int i, j;
        scanf("%d,%d", &i,&j);
        exsits(matrix, i, j);
    }
    else if(input == 'C'){
        int a, b;
        scanf("%d,%d", &a,&b);
        print_shortestpath(matrix, a, b);
    }
    
    }
    return 0;
}