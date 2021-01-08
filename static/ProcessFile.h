#ifndef PROCESSFILE_H
#define PROCESSFILE_H

#include "ParseFile.h"
#include "DataStructs.h"

RowHolder* RawToRows(RawData* data);
char* ConcatArr(char* arr, unsigned long idx_ini, unsigned long idx_fin);

RowHolder* RawToRows(RawData* data) {

	// Allocating space for rows according to data in RawData object.	
	char** rows = (char**)malloc( sizeof(char*) * data->n_rows );
	int i, idx_ini, idx_fin, length, j = 0;
	unsigned long* lens = (unsigned long*)malloc( sizeof(unsigned long) * data->n_rows );

	for (i = 0; i < data->n_rows; ++i) {
		
		length = 1;
		idx_ini = j;
		while (data->txt[j++] != '\n') {
			length++;
		}
		idx_fin = j;

		rows[i] = ConcatArr(data->txt, i, j);
		lens[i] = length;

	}
	
	RowHolder* result;
	result->n_rows = data->n_rows;
	result->row_sizes = lens;
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


#endif
