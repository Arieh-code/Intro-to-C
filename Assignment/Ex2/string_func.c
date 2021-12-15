#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ex2.h"

#define TXT 1024
#define WORD 30


void makeWord(char word[30]){
    char curr;
    int counter = 0;
    while(curr != ' ' && curr != '\t' && curr != '\n' && counter < 30){
        scanf("%c" , &curr);
        word[counter] = curr;
        counter++;
    }
}

void makeText(char text[1024]){
    char curr;
    int counter = 0;
    while(curr != '~' && counter < 1024){
        scanf("%c" , &curr);
        text[counter] = curr;
        counter++;
    }
}

char lowerCase(char c){
    if(c >= 'A' && c <= 'Z'){
        return c + 32;
    }
    return c;
}

int Gimatria(char c){
    if(c >= 'a' && c <= 'z'){
        return c%96;
    }
    else if(c >= 'A' && c <= 'Z'){
        return c%64;
    }
    return 0;
}

void Gematria_Sequences(char a[], char b[]){
    int i;
    i = 0;  
    int sum = 0;
    i = 0;  
    while(a[i]){
        sum += Gimatria(a[i]);
        i++;
    } 
    char ans[TXT] = "", *begin_ptr, *helper_ptr;
    begin_ptr = b;
    // ans_ptr = ans;
    int sum_word = 0;
    i = 1;
    while(*begin_ptr){
        char helper[TXT] = "";
        helper_ptr = helper;
        strncpy(helper, begin_ptr, i);
        helper_ptr = helper;
        if(!Gimatria(helper[0])){
            begin_ptr++;
        }
        else{
            while(*helper_ptr){
                sum_word+= Gimatria(*helper_ptr);
                ++helper_ptr;
            }
            if( i > strlen(begin_ptr)){
                break;
            }
            if(sum_word < sum){
                i++;
                helper_ptr = helper;
                sum_word = 0;
            }
            else if(sum_word > sum){
                begin_ptr++;
                sum_word = 0;
                i = 1; 
            }
            else{
                strcat(ans, helper);
                int len = strlen(ans);
                ans[len] = '~';
                sum_word = 0;
                begin_ptr++;
                i = 1;
            }
        }
    }
    ans[strlen(ans)-1] = '\0';
    printf("Gematria Sequences: %s\n", ans);
}

char convert(char c){
if(!((c >=0 && c <65)||(c>90&& c<97)||(c>122&&c<=127))){
   if(c>='A'&&c<='Z'){
       return c = 'Z'+'A'-c;
   }
   else if(c>='a'&&c<='z'){
        return c = 'z'+'a'-c;
   }
 }
 return 0; 
}

// function definition of the revstr()  
void revstr(char arr[])  
{  
    // declare variable  
    int i, len, temp;  
    len = strlen(arr); // use strlen() to get the length of str string  
      
    // use for loop to iterate the string   
    for (i = 0; i < len/2; i++)  
    {  
        // temp variable use to temporary hold the string  
        temp = arr[i];  
        arr[i] = arr[len - i - 1];  
        arr[len - i - 1] = temp;  
    }  
}  



void Atbash_Sequences(char a[], char b[]){
    a[strlen(a)-1] = '\0';
    int i = 0; 
    char copy_word[strlen(a)];
    strcpy(copy_word, a);
    revstr(copy_word);
    while(a[i]){
        a[i] = convert(a[i]);
        i++;
    }
    // i = 0;
    // while(r_a[i]){
    //     r_a[i] = convert(r_a[i]);
    //     i++;
    // }
    i = 0;
    while(copy_word[i]){
        copy_word[i] = convert(copy_word[i]);
        i++;
    }
    char helper[TXT] = "", *helper_ptr, *b_ptr;
    helper_ptr = helper;
    b_ptr = b;
    i = 1;
    while(*b_ptr){
        if(Gimatria(*b_ptr)){
            strncat(helper,b_ptr,i);
            b_ptr++;

        }
        else{
            b_ptr++;
        }
    } 
    int len = strlen(a); 
    char ans[TXT] = "" ;
    while(*helper_ptr){
        char helper1[TXT] = "";
        // helper1_ptr = helper1;
        strncpy(helper1,helper_ptr, len);
        if(!strcmp(helper1, a) || !strcmp(helper1, copy_word)){
            strcat(ans, helper1);
            ans[strlen(ans)] = '~';
            helper_ptr++;
        }
        else{
            helper_ptr++;
        }
    }
    ans[strlen(ans)-1] = '\0';
    printf("Atbash Sequences: %s\n", ans);
}

int isAnagram(char* a, char* b) {
    // b[strlen(b)-1] = '\0';
    int checkAnagram[177] = {0};
    for(int i = 0 ; i < strlen(a); i++){
        if(a[i] != ' '){
            checkAnagram[(int)*(a+i)] += 1;
        }
    }
    for(int i = 0; i < strlen(b); i++){
        if(b[i] != ' '){
            checkAnagram[(int)*(b+i)] -= 1;
        }
    }
    for(int i = 0; i < 177; i++){
        if(checkAnagram[i] != 0){
            return 0;
        }
    }
    return 1;
}



void Anagram_Sequences(char a[], char b[]){
    a[strlen(a)-1] = '\0';
    char *begb_ptr, *endb_ptr, *a_ptr;
    begb_ptr = b; 
    char ans[TXT] = "";
    
    
    while(*begb_ptr){
        char helper[TXT] = "";
        int counter = 0; 
        endb_ptr = begb_ptr;
        a_ptr = a;
        while(counter < strlen(a_ptr)){
        if(*endb_ptr == 32 && !strlen(helper)){
            break;
        }
        else if (*endb_ptr != 32){
            counter ++;
        }
        strncat(helper, endb_ptr,1);
        endb_ptr++;

        if(strlen(a_ptr) == counter){
            if(isAnagram(helper, a_ptr)){
                strcat(ans, helper);
                ans[strlen(ans)] = '~';
                counter = 0; 
            }
        }
        
        }
        begb_ptr++;
    }
    ans[strlen(ans)-1] = '\0'; 
    printf("Anagram Sequences: %s", ans);
}

 





// int main(){
//     char word [WORD];
//     char text [TXT]; 
//     char word_temp[WORD];
//     char text_temp[TXT];
//     makeWord(word);
//     makeText(text);
//     strcpy(word_temp, word);
//     strcpy(text_temp, text);
//     Gematria_Sequences(word_temp, text_temp);
//     strcpy(word_temp, word);
//     strcpy(text_temp, text);
//     Atbash_Sequences(word_temp, text_temp);
//     strcpy(word_temp, word);
//     strcpy(text_temp, text);
//     Anagram_Sequences(word_temp, text_temp);
//     return 0; 
// }
