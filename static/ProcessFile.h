#ifndef PROCESSFILE_H
#define PROCESSFILE_H

#include "ParseFile.h"
#include "DataStructs.h"

RowHolder* RawToRows(RawData* data);
char* ConcatArr(char* arr, unsigned long idx_ini, unsigned long idx_fin);

int** RawToIntArray(RawData* data, char delimiter) {
	
	// Inefficient, but I know it works and is reasonably fast
	RowHolder* rows = RawToRows(data);
	int** result = (int**) malloc( sizeof(int*) * data->n_rows );
	unsigned long i, j, row_len = 0, result_len = 0;

	// Iterate through every row
	for (i = 0; i < rows->n_rows; ++i) {
		char* char_row = rows->rows[i];

		// Iterate through every char in row, count delimiters to get total num
	        for (j = 0; j < rows->row_sizes[i]; ++j) {
			if ( char_row[j] == delimiter ) row_len++;
		}

		// Allocate mem for row
		int* int_row = (int*) malloc( row_len * sizeof(int) );
		row_len = 0;

		unsigned long idx_ini = 0;
		// Reiterate through the row, slice using ConcatArr, convert using atoi(). Re-using row_len to represent the initial index of the number (idx_ini in ConcatArr)
		for (j = 0; j < rows->row_sizes[i]; ++j) {
			if ( char_row[j] == delimiter || char_row[j] == '\0' ) {
				int_row[row_len++] = atoi(ConcatArr(char_row, idx_ini, j - 1));
				idx_ini = j + 1;
			}
		}

		// Assign the new int array to the result array
		result[result_len++] = int_row;

	}

	return result;

}

int** RowToIntArray(RowHolder* data, char delimiter) {

}

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
