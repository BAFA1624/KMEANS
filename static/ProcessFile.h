#ifndef PROCESSFILE_H
#define PROCESSFILE_H

#include "ParseFile.h"
#include "DataStructs.h"
#include "ErrorHandle.h"


int** RawToIntArray(RawData* data, char delimiter);
int** FileToIntArray(char* filename, char delimiter);
RowHolder* RawToRows(RawData* data);
char* ConcatArr(char* arr, unsigned long idx_ini, unsigned long idx_fin);
void clearBuffer(void** buffer, unsigned long sz);
Table* FileToTable(char* filename, int skip_top_rows, int skip_bottom_rows);


int**
RawToIntArray(RawData* data, char delimiter) {
	
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

int**
FileToIntArray(char* filename, char delimiter) {

    RawData* data = ParseFile(filename);
    int** result = RawToIntArray(data, delimiter);
    return result;

}

RowHolder*
RawToRows(RawData* data) {

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

char*
ConcatArr(char* arr, unsigned long idx_ini, unsigned long idx_fin) {
	unsigned long i, len = idx_fin - idx_ini + 2;
	char* result = (char*)malloc(len * sizeof(char));
	result[len-1] = '\0';
	
	for (i = idx_ini; i <= idx_fin; ++i) {
		result[i - idx_ini] = arr[i];
	}
	return result;
}

void
clearBuffer(void** buffer, unsigned long sz) {
	unsigned long i;
	for (i = 0; i < sz; ++i) {
		buffer[i] = NULL;
	}
}

// Returns void for the sake of testing. Will return Table* in completed version
Table*
FileToTable(char* filename, int skip_top_rows, int skip_bottom_rows) {
	
	// Load in RawData of file
	RawData* data = ParseFile(filename);
	RowHolder* rows = RawToRows(data);
	Table* result = (Table*) malloc( sizeof(Table) );
	
	// Assign values we know to result
	result -> n_samples = rows -> n_rows - skip_top_rows - skip_bottom_rows;

	// Parsing header rows
	char** headers;
	unsigned long i, j, headers_len = 0, current_start_idx = 0;
	
	// Measure how many headers there are and allocate adequate space
	for ( i = 0; i < rows -> row_sizes[skip_top_rows]; ++i ) {
		if ( rows -> rows[skip_top_rows][i] == ' ' || rows -> rows[skip_top_rows][i] == '\0' ) headers_len++;
	}
	headers = (char**) malloc( headers_len * sizeof(char*) );
	if (!headers) {fputs("<FileToTable> Failed to allocate memory for headers", stderr); exit(1);};
	result->n_headers = headers_len;
	headers_len = 0;

	// Assign header values to headers, then add to result->headers
	for ( i = 0; i < rows -> row_sizes[skip_top_rows]; ++i ) {
		if ( rows -> rows[skip_top_rows][i] == ' ' || rows -> rows[skip_top_rows][i] == '\0' ) {
			headers[headers_len++] = ConcatArr( rows -> rows[skip_top_rows], current_start_idx, i - 1 );
			current_start_idx = i + 1;
		}
	}
	result->headers = headers;

	// Copy values into table
	unsigned long values_len;
	for ( i = 0 + skip_top_rows; i < rows -> n_rows - skip_bottom_rows; ++i ) {
		// Scan row for number of values on current row
		for ( j = 0; j < rows -> row_sizes[i]; ++j ) {
			if ( rows -> rows[i][j] == ' ' || rows -> rows[i][j] == '\0' ) {
				values_len++;
			}
			// catch in case of size mismatch
			if ( values_len == headers_len ) {
				void* values = (void*) malloc( values_len * sizeof(void) );
				values_len = 0;
			} else {
				weak_err("<FileToTable> Size mismatch. n_headers = %lu, number of values measured in row = %lu");
				values_len = headers_len;
			}

		}
	}

	return result;

}

#endif


