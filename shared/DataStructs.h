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
	unsigned long rows;
	unsigned long columns;

	// Data
	int** data_table;

} IntData;

/*
typedef struct FloatData {

} FloatData;

typedef struct DoubleData {

};
*/

#endif
