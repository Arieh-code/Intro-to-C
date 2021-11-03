#include <stdio.h>
#include "NumClass.h"

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
        return 1;
    }
    else{
        return 0;
    }

}

// is prime function
int isPrime(int num){
    if(num==1){
        return 1;
    }
    for(int i=2; i<num; i++){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
}