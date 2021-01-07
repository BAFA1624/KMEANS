#ifndef PROCESSFILE_H
#define PROCESSFILE_H

#include "ParseFile.h"
#include "DataStructs.h"

RowHolder* RawToRows(RawData* data);
char* ConcatArr(char* arr, unsigned long idx_ini, unsigned long idx_fin);

RowHolder* RawToRows(RawData* data) {
	
	char** rows = (char**)malloc( sizeof(char*) * data->rows );
	int i, idx_ini, idx_fin, length, j = 0;
	unsigned long* lens = (unsigned long*)malloc( sizeof(unsigned long) * data->rows );

	for (i = 0; i < data->rows; ++i) {
		
		length = 0;
		idx_ini = j;
		while (data->txt[j++] != '\n') {
			length++;
		}
		idx_fin = j;

		rows[i] = ConcatArr(data->txt, i, j);
		lens[i] = length;

	}
	
	RowHolder* result;
	result->n_rows = data->rows;
	result->row_sizes = lens;
	result->rows = rows;

	free(lens);

	return result;

}

char* ConcatArr(char* arr, unsigned long idx_ini, unsigned long idx_fin) {
	unsigned long i, len = idx_fin - idx_ini + 1;
	char* result = (char*)malloc(len * sizeof(char));
	result[idx_fin + 1] = '\0';
	for (i = idx_ini; i <= idx_fin; ++i) {
		result[i - idx_ini] = arr[i];
	}
	return result;
}


#endif
