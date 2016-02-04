#include <stdio.h>
#include <string.h>
#include <math.h>
#include "llist.c"
#include "LWord.h"

int n;
char sq[2000]; //temporary storage
struct LList **hash_table;

//================
//   hash code
//================
int hash_code(char *input){
    //n = # of buckets
    //printf("hi hash code\n");
    int i;
    int len = 0;
    for(i = 0; input[i]!='\0'; i++){
        len++;
    }
    int sum = 0;
    for(i = 0; i<len; i++){
        sum += input[i];
    }
    //printf("sum = %d\n", sum);
    int b;
    //printf("n = %d", n);
    b = sum%n;
    //printf("b = %d", b);
    return b;
}

//=========================
//    hash table insert
//=========================

void hash_table_insert(char *input, int i){
    int hc;
    hc = hash_code(input);
    struct LWord *word = create_word(i, 1, hc, input); //where n = #of buckets
    add_first(hash_table[hc], word);
}

void training(){
    //scan in documents
    //hash each word and increase count for # of times in document
    //return hash table
    FILE *document;
    char newword[20];
    int word_num;
    int hc;

//==================
//     D1 file
//==================
    document = fopen("D1.txt","r");
    while(fscanf(document, "%s", newword) ==1){
        hc = hash_code(newword);
        struct LWord word;
        word.documentID = 0;
        strcpy(word.letters, newword);
        if(!contains(hash_table[hc], &word)){
            hash_table_insert(newword, 0);
        }
        else{
            increase_count(hash_table[hc], &word);
        }
    }
    fclose(document);
//==================
//     D2 file
//==================
    document = fopen("D2.txt","r");
    while(fscanf(document, "%s", newword) == 1){
        hc = hash_code(newword);
        struct LWord word;
        word.documentID = 1;
        strcpy(word.letters, newword);
        if(!contains(hash_table[hc], &word)){
            hash_table_insert(newword, 1);
        }
        else{
            increase_count(hash_table[hc], &word);
        }
    }
//==================
//     D3 file
//==================
    document = fopen("D3.txt","r");
    while(fscanf(document, "%s", newword) == 1){
        hc = hash_code(newword);
        struct LWord word;
        word.documentID = 2;
        strcpy(word.letters, newword);
        if(!contains(hash_table[hc], &word)){
            hash_table_insert(newword, 2);
        }
        else{
            increase_count(hash_table[hc], &word);
        }
    }
    // int i;
    // for(i=0; i<n; i++){
    //     print_list(hash_table[i]);
    // }
}

//===================
//    read search
//===================
char* read_query(){
    char* temp = malloc(sizeof(char)*2000);
    printf("\nEnter Search:");
    scanf(" %[^\n]", temp);
    return temp;
}

//===================
//       rank
//===================
void rank(){
    int hc;
    double d1_score = 0.0;
    double d2_score = 0.0;
    double d3_score = 0.0;
    double term_freq_D1 = 0.0;
    double term_freq_D2 = 0.0;
    double term_freq_D3 = 0.0;
    double inverse_freq = 0.0;

    char *str = read_query();
    char s[2] = " ";
    char *token;
    
    token = strtok(str, s);
    
    while(token != NULL){ //loop through buckets
        inverse_freq = 0.0;
        double term_freq_D1 = 0.0;
        double term_freq_D2 = 0.0;
        double term_freq_D3 = 0.0;
        //printf("term freq D2 = %f", term_freq_D2);
        hc = hash_code(token);
        //int doc;
        //doc = contains_sq(hash_table[hc], token);
    	 //loop through linked list
    	    if(contains_sq(hash_table[hc], token, 0) == 0){ //if D1
    	        term_freq_D1 = get_elem_count(hash_table[hc], token);
    	        inverse_freq = inverse_freq + 1;
    	    }
    	    if(contains_sq(hash_table[hc], token, 1) == 1){ //if D2
    	        term_freq_D2 = get_elem_count(hash_table[hc], token);
    	        inverse_freq = inverse_freq + 1;
    	    }
    	    if(contains_sq(hash_table[hc], token, 2) == 2){ //if D3
    	        term_freq_D3 = get_elem_count(hash_table[hc], token);
    	        inverse_freq = inverse_freq + 1;
    	    }
    	    if(inverse_freq == 0){
    	        inverse_freq = log(3.0/(1+(double)inverse_freq));
    	    }
    	    else{
    	        inverse_freq = log(3.0/((double)inverse_freq));
    	    }
    	    //printf("d1 score: %f, d2 score: %f, d3 score: %f\n", d1_score, d2_score, d3_score);
    	    d1_score = (term_freq_D1*inverse_freq) + d1_score;
    	    d2_score = (term_freq_D2*inverse_freq) + d2_score;
    	    d3_score = (term_freq_D3*inverse_freq) + d3_score;
    	token = strtok(NULL, s);
    }
    //printf("d1 score: %f, d2 score: %f, d3 score: %f\n", d1_score, d2_score, d3_score);
    printf("Results are...\n");
    if(d1_score>=d2_score && d2_score>=d3_score){
        printf("D1.txt \nD2.txt \nD3.txt");
    }
    else if(d1_score>=d3_score && d3_score>=d2_score){
        printf("D1.txt \nD3.txt \nD2.txt");
    }
    else if(d2_score>=d1_score && d1_score>=d3_score){
        printf("D2.txt \nD1.txt \nD3.txt");
    }
    else if(d2_score>=d3_score && d3_score>=d1_score){
        printf("D2.txt \nD3.txt \nD1.txt");
    }
    else if(d3_score>=d1_score && d1_score>=d2_score){
        printf("D3.txt \nD1.txt \nD2.txt");
    }
    else if(d3_score>=d2_score && d2_score>=d1_score){
        printf("D3.txt \nD2.txt \nD1.txt");
    }
    else{
        printf("D1.txt \nD2.txt \nD3.txt");
    }
    printf("\n");
    free(str);
}

int main(){
    printf("Hi, Welcome to Kate's Search Engine!\nEnter the number of buckets you wish to use:\n");
    scanf(" %d", &n);
    hash_table = (struct LList *) malloc(sizeof(struct LList *)*n);
    int i;
    for(i=0; i<n; i++){
        hash_table[i] = (struct LList*)malloc(sizeof(struct LList));
    }
    training();
    char option;
    do{
        printf("Enter S for search or X to Exit\n");
        scanf(" %c", &option);
        if(option == 'X'){
            exit(0);
        }
        rank();
    }while(1);
}