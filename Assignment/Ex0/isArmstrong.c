#include <stdio.h>
#include "NumClass.h"
/* Function to calculate x raised to the power y */
int power(int x, unsigned int y)
{
    if (y == 0)
        return 1;
    if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    return x * power(x, y / 2) * power(x, y / 2);
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
void isArmstrong()
{
    // Calling order function
    int x;
    printf("Please enter a number \n");
    scanf("%d", &x);
    int n = order("%d");
    int temp = "%d", sum = 0;
    while (temp) {
        int r = temp % 10;
        sum += power(r, n);
        temp = temp / 10;
    }
 
    // If satisfies Armstrong condition
    if (sum == "%x")
        return 1;
    else
        return 0;
}


// void main()
// {
//     int x;
//     printf("Please enter a numer \n");
//     scanf("%d", &x);
//     if (isArmstrong(x) == 1)
//         printf("True\n");
//     else
//         printf("False\n"); 
// }

 