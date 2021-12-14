#include<stdio.h>
#include"my_mat.h"
#define Max 10

// extern int mat[Max][Max];

int main(){
    int matrix[Max][Max];
    int (*mat)[Max];
    mat = matrix;
    char input;
    scanf("%c", &input);
    while(input != 'D'){
        if(input == 'A'){
           Make_mat(mat);
           for(int i = 0; i<Max; i++){
               for(int j = 0; j<Max; j++){
                   printf("%d ", *(*(mat+i)+j));
               }
           }
           
           shortest_route(mat);
           for(int i = 0; i<Max; i++){
               for(int j = 0; j<Max; j++){
                   printf("%d ", *(*(mat+i)+j));
               }
           }
          
        }
        else if(input == 'B'){
            exsits(mat);
        }
        else if(input == 'C'){
            print_shortest_route(mat);
        }
        scanf("%c", &input);
    }
    return 0;
}