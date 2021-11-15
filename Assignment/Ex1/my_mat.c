#include<stdio.h>
#include"my_mat.h"
#define Max 10
#define True 1
#define False -1

// int[Max][Max] mat;
/* first function is to create a 2d array(AKA a matrix)
will get all the input from the user
*/
void make_mat(int mat[Max][Max]){
    int i, j;
    for(i = 0; i<Max; i++){
        for(j=0; j<Max; j++){
            scanf("%d", &mat[i][j]);
        }
    }
}

/* this function will check if a path exists meaning 
if the place in the matrix doesnt equal 0*/
void exsits(int mat[Max][Max], int a, int b){
    if(mat[a][b]!= 0){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
}

/* min fucntion to help finding the smallest number*/
int min(int num1, int num2) 
{
    return (num1 > num2 ) ? num2 : num1;
}

/* making the 10th matrix will give us the shortest routes 
between each node*/
void shortest_route(int mat[Max][Max]){
    int k, i, j;
    for(k=0; k < Max; k++){
        for(i = 0; i<Max; i++){
            for(j=0; j< Max; j++){
                // if either are 0, means there is no path so keep the original number
                if(mat[i][k] == 0 || mat[k][j] == 0){
                    continue;
                }
                // if number is 0 it will stay the smallest and wont get changed since there is no path
                mat[i][j] = min(mat[i][j], (mat[i][k]+mat[k][j]));
            }
        }
    } 

}

/* function to find the shortest path, will be used after
the void function is used on the matrix to make the shortest routes*/
void print_shortestpath(int mat[Max][Max], int a, int b){
    if(mat[a][b] == 0){
        printf("%d\n", False);
    }
    printf("%d\n", mat[a][b]);
}

