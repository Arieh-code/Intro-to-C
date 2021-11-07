#include <stdio.h>
#include <math.h>
#include "NumClass.h"
#define True 1 
#define False 0


// function to calculate the order of the number using recursion
int order(int num){
    if(num > 0){
    return(1 + order(num/10));
    }
    return 0;
}


/**
 * Recursive function to find reverse of any number
 */
int reverse(int num)
{
    /* Find number of digits in num */
    int digit = order(num)-1;
    
    /* Recursion base condition */
    if(num == 0)
        return 0;

    return ((num%10 * pow(10, digit)) + reverse(num/10));
}

/**
 * Function to check if a number is palindrome or not.
 * This function returns 1 if the number is palindrome otherwise 0.
 */
int isPalindrome(int num)
{
    /* 
     * Check if the given number is equal to 
     * its reverse.
     */
    if(num == reverse(num))
    {
        return True;
    }
    
    return False;
}

// the recursion function that will return a result of armstrong.
int isArmstronghelper(int num, int order)
{
    if(num == 0){
        return 0; 
    }
    return (pow(num%10,order) +isArmstronghelper(num/10, order));
}

//the main function to check if a numer is armstrong
int isArmstrong(int num){
    if(num == isArmstronghelper(num, order(num)))
        return True; 
    return False;
}