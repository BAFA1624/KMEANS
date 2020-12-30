#ifndef DATASTRUCTS_H
#define DATASTRUCTS_H

#include <stdlib.h>

typedef struct RawData {

	size_t sz;
	char* txt;

} RawData;

typedef struct IntData {
	// Important attributes
	size_t sz;
	unsigned long n_rows;
	unsigned long n_columns;
	// Data
	int** data_table;
} IntData;

typedef struct FloatData {
	// Important attributes
	size_t sz;
	unsigned long n_rows;
	unsigned long n_columns;
	// Data
	float** data_table;
} FloatData;

typedef struct DoubleData {
	// Important attributes
	size_t sz;
	unsigned long n_rows;
	unsigned long n_columns;
	// Data
	double** data_table;
} DoubleData;


// Custom delete functions


void delRawData(RawData* d) {
	printf("\nI am deleting raw data!\n");
	free(d->txt);
	free(d);
}

void delIntData(IntData* i) {
	int j;
	for (j=0; j<i->n_rows; ++j) {
		free(i->data_table[j]);
	}
	free(i->data_table);
	free(i);
}

void delFloatData(FloatData* f) {
	int i;
	for (i=0; i<f->n_rows; ++i) {
		free(f->data_table[i]);
	}
	free(f->data_table);
	free(f);
}

void delDoubleData(DoubleData* d) {
	int i;
	for (i=0; i<d->n_rows; ++i) {
		free(d->data_table[i]);
	}
	free(d->data_table);
	free(d);
}

#endif
