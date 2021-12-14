#include<stdio.h>
#include"my_mat.h"
#define Max 10
#define False -1

// int mat[Max][Max];

void Make_mat(int (*mat)[Max]){
    int i, j;
    for(i = 0; i<Max; i++){
        for(j = 0; j<Max; j++){
            scanf("%d", &(*(*(mat+i)+j)));
        }
    }
}

void print_shortest_route(int (*mat)[Max]){
    int i, j;
    scanf("%d", &i);
    scanf("%d", &j);
    if(*(*(mat+i)+j) == 0){
        printf("%d\n", False);
    }
    else{
        printf("%d\n", *(*(mat+i)+j));
    }
}

void shortest_route(int (*mat)[Max]){
    int i, j, k;
    for(k = 0; k<Max; k++){
        for(i = 0; i<Max; i++){
            for(j = 0; j<Max; j++){
               if ((*(*(mat+i)+k)) == 0 || *(*(mat+k)+j) == 0){
                    continue;
                }
                if(*(*(mat+i)+j) == 0 && i != j){
                    *(*(mat+i)+j) = (*(*(mat+i)+k)) + (*(*(mat+k)+j));
                }
                else if(*(*(mat+i)+j) < *(*(mat+i)+k) + *(*(mat+k)+j)){
                    *(*(mat+i)+j) = (*(*(mat+i)+k)) + (*(*(mat+k)+j));
            }
        }
    }
}
    
}

void exsits(int (*mat)[Max]){
    int i,j;
    scanf("%d", &i);
    scanf("%d", &j);
    if(*(*(mat+i)+j)!=0){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
    
}



