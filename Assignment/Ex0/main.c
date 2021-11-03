#include<stdio.h>
#include"NumClass.h"

void main(void){
    int a, b, i;
    scanf("%d %d", &a,&b);
  

    printf("\n The Armostrong numbers are: ");
     for(i= a; i<=b; i++){
        if(isArmstrong(i) == 1){
            printf("%d, ", i);          
     } 
   }
   
    printf("\n The Palindromes are: ");
     for(i = a; i<=b; i++){
        if(isPalindrome(i) == 1){
            printf("%d, ", i);          
     } 
   } 
   
   printf("\n The Prime numbers are: ");
   for(i = a; i<=b; i++){
        if(isPrime(i) == 1){
            printf("%d, ", i);         
     } 
   } 

    printf("\n The Strong numbers are: ");
     for(i = a; i<=b; i++){
        if(isStrong(i) == 1){
            printf("%d, ", i);          
     } 
   } 
   
   printf("\n");

}