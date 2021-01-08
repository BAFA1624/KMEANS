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


// Struct Specific Functions




#endif
