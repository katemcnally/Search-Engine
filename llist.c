#include "llist.h"
#include "LWord.h"
#include "LWord.c"
#include <stdio.h>
#include <stdlib.h>


// ==============================================================
// Utility operations
// ==============================================================

// Creates and returns an empty list
struct LList *create_empty_list(){
	struct LList *list1 = (struct LList*)malloc(sizeof(struct LList));
	//node1->word = (*node1).word	
	list1->sentinal = NULL;
	list1->root = list1->sentinal;
	list1->size = 0;
	return list1;
}

// ==============================================================
// Query functions (no side effects)
// ==============================================================

// Returns the size of the list
int size(struct LList *list){
	return list->size;
}

// Checks of the list contains the specified word
// Uses the are_equal operation of LWord
int contains(struct LList *list, struct LWord *word){
	struct LNode *temp = (struct LNode*)malloc(sizeof(*temp));
	temp = list->root;
	while(temp!=list->sentinal){
		if(are_equal(temp->word, word)){
			return 1; 
		}
		else{
			temp = temp->next;
		}
	}
	return 0;
}

int contains_sq(struct LList *list, char* word_letters, int docID){
	struct LNode *temp;
	temp = list->root;
	int doc;
	while(temp!=list->sentinal){
		if(are_equal_letters(temp->word->letters, word_letters) &&
			are_equal_ID(temp->word->documentID, docID)){
			doc = temp->word->documentID;
			return doc;
		}
		else{
			temp = temp->next;
		}
	}
	return 4;
}

// ==============================================================
// Add operations
// ==============================================================

// Adds the specified word to the front of the list
void add_first(struct LList *list, struct LWord *word){
	struct LNode *node1 = (struct LNode*)malloc(sizeof(*node1));
	node1->word = word;
	//strcpy(word->letters, letters)
	node1->next = list->root;
	list->root = node1;
	(list->size)++;
}

// ==============================================================
// Get operation
// ==============================================================

// Returns a handle (pointer) to the element of the list at the specified position
int get_elem_count(struct LList *list, char *word_letters){
	struct LNode *temp;
	temp = list->root;
	int i;
	while(temp!=list->sentinal){
		if(are_equal_letters(temp->word->letters, word_letters)){
			i = temp->word->count; 
			return i;
		}
		else{
			temp = temp->next;
		}
	}
	return 0;
}

void increase_count(struct LList *list, struct LWord *word){
	struct LNode *temp;
	temp = list->root;
	while(temp!=list->sentinal){
		if(are_equal(temp->word, word)){
			temp->word->count++;
			break;
		}
		else{
			temp = temp->next;
		}
	}
}

void print_list(struct LList *list){
	struct LNode *temp = (struct LNode*)malloc(sizeof(*temp));
	temp = list->root;
	while(temp!=list->sentinal){
		printf("[");
		print_word(temp->word);
		temp = temp->next;
	}
//	printf(" ]");
	free(temp);
}

//this code was written by: Kate McNally