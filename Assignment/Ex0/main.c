#include<stdio.h>
#include"NumClass.h"

void main(){
    int a, b;
   printf("\n Hello, how are you? Please enter the two numbers: \n");
   scanf("%d", &a,b);
   a = ("%d", a);
   b = ("%d", b);
   for(a; a<b; a++){
     if(isArmstrong(a) == 1){
         printf(a + " is an armstrong number\n");
     }  
     if(isprime(a) == 1){
         printf(a + " is a prime number\n");
     }
     if(isStrong(a) == 1){
         printf(a + " is a Strong number\n");
     }
     if(isPalindrome(a) == 1){
         printf(a + " is a palindrome number\n" );
     }
   }
}