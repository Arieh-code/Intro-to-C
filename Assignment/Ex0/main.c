#include<stdio.h>
#include"NumClass.h"
#define True 1 
#define False 0

int main(){
    int a, b, i;
    scanf("%d %d", &a,&b);
  

    printf("The Armstrong numbers are:");
     for(i= a; i<=b; i++){
        if(isArmstrong(i) == True){
            printf(" %d", i);          
     } 
   }
   
    printf("\nThe Palindromes are:");
     for(i = a; i<=b; i++){
        if(isPalindrome(i) == True){
            printf(" %d", i);          
     } 
   } 
   
   printf("\nThe Prime numbers are:");
   for(i = a; i<=b; i++){
        if(isPrime(i) == True){
            printf(" %d", i);         
     } 
   } 

    printf("\nThe Strong numbers are:");
     for(i = a; i<=b; i++){
        if(isStrong(i) == True){
            printf(" %d", i);          
     } 
   } 
   
   printf("\n");
   return 0;

}