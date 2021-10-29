#include <stdio.h>
#include "NumClass.h"
/* Function to calculate x raised to the power y */
 int power(int x, unsigned int y){
     while(y>1){
         x *= x;
         y--;
         }
    
     return x;
 }
/* Function to calculate the length of a given number */
int order(int x)
{
    int n = 0;
    while (x) {
        n++;
        x = x / 10;
    }
    return n;
}
 
/* Function to check whether the given number is
 Armstrong number or not */
int isArmstrong(int x)
{
    // Calling order function
    int x;
    int n = order(x);
    int temp = x, sum = 0;
    while (temp) {
        int r = temp % 10;
        sum += power(r, n);
        temp = temp / 10;
    }
 
    // If satisfies Armstrong condition
    if (sum == x)
        return 1;
    else
        return 0;
}

/* Functhion that will reverse a number
*/
int reverse(int x){
    int temp, counter;
    temp = 0;
    counter = order(x); 
    while(x!=0){
        temp += (x%10) * power(10, counter--);
        x/= 10;
    }
    return temp;
}

/* functhion that will check if a number is palindrome
*/
int isPalindrome(int x){
    int r;
    r = reverse(x);
    if(r == x){
        return 1;
    }
    return 0;
}