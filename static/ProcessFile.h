#ifndef PROCESSFILE_H
#define PROCESSFILE_H

#include "ParseFile.h"
#include "DataStructs.h"

RowHolder* RawToRows(RawData* data);
char* ConcatArr(char* arr, unsigned long idx_ini, unsigned long idx_fin);

RowHolder* RawToRows(RawData* data) {

	// Allocating space for rows according to data in RawData object.	
	char** rows = (char**)malloc( sizeof(char*) * data->n_rows );
	int i, j = 0, idx_ini = 0, idx_fin = 0, length = 0;
	unsigned long* newlines = (unsigned long*)malloc( sizeof(unsigned long) * data->n_rows );
	printf("\nnewlines size = %lu, data->sz = %lu\n", data->n_rows, data->sz);

	for (i = 0; i < data->sz; ++i) {
		if ( data->txt[i] == '\n' ) {
			newlines[j] = i;
			printf("\n\tj = %d, newlines[j] = %d\n", j, i);
			++j;
		}
	}

	RowHolder* result;
	//result->n_rows = data->n_rows;
	//result->row_sizes = lens;
	result->rows = rows;

	return result;

}

char* ConcatArr(char* arr, unsigned long idx_ini, unsigned long idx_fin) {
	unsigned long i, len = idx_fin - idx_ini + 2;
	char* result = (char*)malloc(len * sizeof(char));
	result[len-1] = '\0';
	
	for (i = idx_ini; i <= idx_fin; ++i) {
		result[i - idx_ini] = arr[i];
	}
	return result;
}

void clearBuffer(void** buffer, unsigned long sz) {
	int i;
	for (i = 0; i < sz; ++i) {
		buffer[i] = NULL;
	}
}

#endif
