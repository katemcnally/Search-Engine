#include "LWord.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//type word
struct LWord *create_word(int documentID, int count, int hash_code, char *letters)
{
    struct LWord *word = (struct LWord*)malloc(sizeof(struct LWord));
    word->documentID = documentID;
    word->count = count;
    word->hash_code = hash_code;
    strcpy(word->letters, letters);
    return word;
}

// Returns true if and only if the documentID of data1 equals the city of data2
int are_equal(struct LWord *word1, struct LWord *word2){
    int temp_letters = strcmp(word1->letters, word2->letters);
    if((word1->documentID == word2->documentID) && temp_letters == 0){
       return 1;
    }
    else{
        return 0;
    }
}

int are_equal_letters(char *a, char *b){
    return !strcmp(a, b);
}

int are_equal_ID(int a, int b){
    if(a == b){
        return 1;
    }
    return 0;
}

void print_word(struct LWord *word){
    printf("(Hash Code %d, ID: %d, count: %d, word: %s)\n", word->hash_code, word->documentID, word->count, word->letters);
}