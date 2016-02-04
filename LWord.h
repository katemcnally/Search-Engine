/*
 * data_rec.h
 */

#ifndef LWord_H_
#define LWord_H_

struct LWord {
	int documentID;
	int count;
	int hash_code;
	char letters[21];
};

// Creates and returns an empty data record, where
// document = "", lat = 0.0, lon = 0.0
struct LWord *create_empty_data();

// Creates and returns a data record with the specified values
struct LWord *create_data(int documentID, int count, int hash_code, char *letters);

// Returns true if and only if the document of data1 comes
// alphanumerically before or is the same as the document of data2
int are_ordered(struct LWord *data1, struct LWord *data2);

// Returns true if and only if the document of data1 equals the document of data2
int are_equal(struct LWord *data1, struct LWord *data2);

int are_equal_letters(char *a, char *b);

// Swaps the contents of data1 and data2
void swap_data(struct LWord *data1, struct LWord *data2);

// Resets the information in data to default values (see create_empty_data)
void clear_data(struct LWord *data);

// Prints the data in the format: (document, lat, lon)
// where lat and lon are printed to one decimal place
void print_data(struct LWord *data);

#endif /* LWord_H_ */