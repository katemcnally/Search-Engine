/*
 * llist.h
 */

#ifndef LLIST_H_
#define LLIST_H_

#include "LWord.h"

/* Declare the Linked list data structures and functions. */
struct LList {
	struct LNode* root;
	struct LNode* sentinal;
	int size;
};

struct LNode {
	struct LWord* word;
	struct LNode* next;
};

// ==============================================================
// Utility operations
// ==============================================================

// Creates and returns an new node
struct LNode *create_new_node(struct LWord *data);

// Creates and returns an empty list
struct LList *create_empty_list();

// Clears (empties) the specified list
void clear_list(struct LList *list);

// Swaps the elements of a list
void swap_elems(struct LList *list, int idx1, int idx2);

// Prints the list to standard output in the form [elem_1 elem_2 ... elem_n]
void print_list(struct LList *list);

// ==============================================================
// Query functions (no side effects)
// ==============================================================

// Checks if the list is empty
int is_empty(struct LList *list);

// Returns the size of the list
int size(struct LList *list);

// Checks of the list contains the specified data
// Uses the are_equal operation of LWord
int contains(struct LList *list, struct LWord *data);

// ==============================================================
// Add operations
// ==============================================================

// Adds the specified element to the specified position
void add_elem(struct LList *list, struct LWord *data, int idx);

// Adds the specified data to the front of the list
void add_first(struct LList *list, struct LWord *data);

// Adds the specified data to the end of the list
void add_last(struct LList *list, struct LWord *data);

// ==============================================================
// Get operation
// ==============================================================

// Returns a handle (pointer) to the element of the list at the specified position
struct LWord *get_elem(struct LList *list, int idx);

// ==============================================================
// Remove operations
// ==============================================================

// Removes and returns the specified element from the specified position
struct LWord *rem_elem(struct LList *list, int idx);

// Removes and returns the first element in the list
// Assumes that the list is not empty
struct LWord *rem_first(struct LList *list);

// Removes and returns the last element in the list
// Assumes that the list is not empty
struct LWord *rem_last(struct LList *list);

// ==============================================================
// Sort operations
// ==============================================================

// Sorts the list according to the are_ordered operation of LWord
void insertion_sort(struct LList *list);
// NOTE: Use the pseudocode at Wikipedia as a template for your insertion sort:
// for i â† 1 to length(A) - 1
//     j â† i
//     while j > 0 and A[j-1] > A[j]
//         swap A[j] and A[j-1]
//         j â† j - 1

#endif /* LLIST_H_ */