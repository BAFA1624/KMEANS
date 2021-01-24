#ifndef DATASTRUCTS2_H
#define DATASTRUCTS2_H

#include <stdlib.h>

typedef struct RawData {

	unsigned long sz;
	unsigned long n_rows;
	char* txt;

} RawData;

typedef struct RowHolder {

	unsigned long n_rows;
	unsigned long* row_sizes;
	char** rows;	
	
} RowHolder;

typedef struct Table {

	char** headers;
	void** data;
	unsigned long n_headers;
	unsigned long n_samples;

} Table;

// Custom delete functions


void delRawData(RawData* d) {
	free(d->txt);
	free(d);
}

void delRowHolder(RowHolder* r) {
	unsigned long i;
	for (i = 0; i < r->n_rows; ++i) {
		free(r->rows[i]);
	}
	free(r->rows);
	free(r->row_sizes);
	free(r);
}

void delTable(Table* t) {
	unsigned long i, j;
	for (i = 0; i < t->n_headers; ++i) {
		free(t->headers[i]);
		for (j = 0; j < t->n_samples; ++j) {
			free(t->data[i]);
		}
	}
	free(t);
}

// Struct Specific Functions

/*
void PrintTable(Table* t) {
// Still to implement	
}
*/

#endif
