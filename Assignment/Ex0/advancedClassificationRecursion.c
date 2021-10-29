/**
 * C program to check palindrome number using recursion
 */
 
#include <stdio.h>
#include <math.h>
#include "NumClass.h"




/**
 * Function to check whether a number is palindrome or not.
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
        return 1;
    }
    
    return 0;
}


/**
 * Recursive function to find reverse of any number
 */
int reverse(int num)
{
    /* Find number of digits in num */
    int digit = (int)log10(num);
    
    /* Recursion base condition */
    if(num == 0)
        return 0;

    return ((num%10 * pow(10, digit)) + reverse(num/10));
}
//the main function to check if a numer is armstrong
int isArmstrong(int num){
    if(num == isArmstronghelper(num))
        return 1; 
    return 0;
}

// the recursion function that will return a result of armstrong.
int isArmstronghelper(int num)
{
    int len;
    len = order(num);
     if(num>0)
    return (power(num%10,len) +check_ArmstrongNumber(num/10));
}

// function to calculate the order of the number using recursion
int order(int num){
    if(num > 0)
    return(1 + order(num/10));
}



/* Function to calculate x raised to the power y */
int power(int x, unsigned int y)
{
    if (y == 0)
        return 1;
    if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    return x * power(x, y / 2) * power(x, y / 2);
}