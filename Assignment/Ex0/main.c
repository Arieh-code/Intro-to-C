#include<stdio.h>
#include"NumClass.h"

void main(){
    int a, b;
   printf("\n Hello, how are you? Please enter the two numbers: \n");
   scanf("%d %d", &a,&b);

   printf("\n isPrime numbers: \n");
   for(a; a<=b; a++){
        if(isPrime(a) == 1){
            printf("%d, ", a);         
     } 
   } 

   printf("\n isStrong numbers: ");
     for(a; a<=b; a++){
        if(isStrong(a) == 1){
            printf("%d, ", a);          
     } 
   } 

   printf("\n isPalindrome numbers: ");
     for(a; a<=b; a++){
        if(isPalindrome(a) == 1){
            printf("%d, ", a);          
     } 
   } 

   printf("\n isArmostrong numbers: ");
     for(a; a<=b; a++){
        if(isArmstrong(a) == 1){
            printf("%d, ", a);          
     } 
   } 

}