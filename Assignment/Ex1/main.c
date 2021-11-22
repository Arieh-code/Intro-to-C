#include<stdio.h>
#include"my_mat.h"
#define Max 10

extern int mat[Max][Max];

int main(){
    char input;
    scanf("%c", &input);
    while(input != 'D'){
        if(input == 'A'){
           Make_mat();
        //    for(int i = 0; i<Max; i++){
        //        for(int j=0; j<Max; j++){
        //            printf("%d ", mat[i][j]);
        //        }
        //    }
           shortest_route();
        //    for(int i = 0; i<Max; i++){
        //        for(int j=0; j<Max; j++){
        //            printf("%d ", mat[i][j]);
        //        }
        //    }
        }
        else if(input == 'B'){
            exsits();
        }
        else if(input == 'C'){
            print_shortest_route();
        }
        scanf("%c", &input);
    }
    return 0;
}