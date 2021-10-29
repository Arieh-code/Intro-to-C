#include <stdio.h>
#include "NumClass.h"
#include <math.h>

int isPrime(int x)
{
    int n, i, flag = 1;

    // will asign n = x

    n = x;
    
    // Iterate from 2 to sqrt(n)
    for (i = 2; i <= sqrt(n); i++) {
 
        // If n is divisible by any number between
        // 2 and n/2, it is not prime
        if (n % i == 0) {
            flag = 0;
            break;
        }
    }
 
    if (n <= 1)
        flag = 0;
  
    return flag;
}


int isStrong(int x){
    int sum, rem, i, fact, copy; 

    sum = 0;
    copy = x; 
    while(x != 0){
        rem = x%10;
        fact = 1;

        for(i = 0 ; i<rem; i++){
            fact = fact*i;
        }
        sum = sum + fact;
        copy = copy/10;
    }
    if(sum == copy){
        return 1;
    }
    else{
        return 0;
    }

}