# include<stdio.h>
# include<string.h>
# include"ex2.h"

# define TXT 1024
# define WORD 30

int main(){
        char word [WORD];
    char text [TXT]; 
    char word_temp[WORD];
    char text_temp[TXT];
    makeWord(word);
    makeText(text);
    strcpy(word_temp, word);
    strcpy(text_temp, text);
    Gematria_Sequences(word_temp, text_temp);
    strcpy(word_temp, word);
    strcpy(text_temp, text);
    Atbash_Sequences(word_temp, text_temp);
    strcpy(word_temp, word);
    strcpy(text_temp, text);
    Anagram_Sequences(word_temp, text_temp);
    return 0; 
}