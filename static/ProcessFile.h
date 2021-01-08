#ifndef PROCESSFILE_H
#define PROCESSFILE_H

#include "ParseFile.h"
#include "DataStructs.h"

RowHolder* RawToRows(RawData* data);
char* ConcatArr(char* arr, unsigned long idx_ini, unsigned long idx_fin);

RowHolder* RawToRows(RawData* data) {

	// Allocating space for rows according to data in RawData object.	
	char** rows = (char**)malloc( sizeof(char*) * data->n_rows );
	unsigned long* row_lengths = (unsigned long*) malloc( data->n_rows * sizeof(unsigned long) );
	unsigned long i = 0, j = 0, k = 0;

	while (i < data->sz) {	
		if ( data->txt[i] == '\n' ) {
			
			char* row = ConcatArr(data->txt, j, i-1);
			row_lengths[k] = i - j + 1;
			rows[k++] = row;
			
			j = i+1;
		}
		++i;
	}

	RowHolder* result = (RowHolder*) malloc( sizeof(RowHolder) );
	result->n_rows = data->n_rows;
	result->row_sizes = row_lengths;
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
	unsigned long i;
	for (i = 0; i < sz; ++i) {
		buffer[i] = NULL;
	}
}

#endif
