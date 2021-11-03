#include <stdio.h>
#include "NumClass.h"
#define True 1 
#define False 0

// is strong function
int isStrong(int x){
    int sum, rem, i, fact, copy; 

    sum = 0;
    copy = x; 
    while(copy != 0){
        rem = copy%10;
        fact = 1;

    for(i = 1 ; i<=rem; i++){
            fact = fact*i;
        }
        sum = sum + fact;
        copy = copy/10;
    }
    if(sum == x){
        return True;
    }
    else{
        return False;
    }

}

// is prime function
int isPrime(int num){
    if(num==1){
        return True;
    }
    for(int i=2; i<num; i++){
        if(num%i==0){
            return False;
        }
    }
    return True;
}