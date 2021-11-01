#include<stdio.h>
#include"NumClass.h"

void main(void){
    int a, b, i;
   printf("\n Hello, how are you? Please enter the two numbers: \n");
   scanf("%d %d", &a,&b);
  
  
   printf("\n isPrime numbers: \n");
   for(i = a; i<=b; i++){
        if(isPrime(i) == 1){
            printf("%d, ", i);         
     } 
   } 
   
   printf("\n isStrong numbers: \n");
     for(i = a; i<=b; i++){
        if(isStrong(i) == 1){
            printf("%d, ", i);          
     } 
   } 
   
   printf("\n isPalindrome numbers: \n");
     for(i = a; i<=b; i++){
        if(isPalindrome(i) == 1){
            printf("%d, ", i);          
     } 
   } 
   
   printf("\n isArmostrong numbers: \n");
     for(i= a; i<=b; i++){
        if(isArmstrong(i) == 1){
            printf("%d, ", i);          
     } 
   } 

}