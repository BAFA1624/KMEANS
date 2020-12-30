#ifndef LOAD_DATA_H
#define LOAD_DATA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "DataStructs.h"

unsigned long FileSize(FILE* f) {

	unsigned long fSize;

	fseek(f, 0, SEEK_END);
	fSize = ftell(f);
	rewind(f);

	return fSize;

}

void* getBuffer(unsigned long long sz) {

	void* buffer = malloc(sz);
	if (buffer == NULL) {fputs("Mem Alloc Err", stderr); exit(1);};

	return buffer;

}

RawData* ParseFile(char* filename) {
	FILE* file = fopen(filename, "r");

	// Open file or error out if opening fails.
	if (file != NULL) {
		RawData* result;
		unsigned long fSize;

		// alloc memory for data
		result = (RawData*) malloc(sizeof(RawData));

		// Calculate file size.
		fSize = FileSize(file);

		// Allocate buffer to store chars of file.
		result->txt = (char*)getBuffer(sizeof(char)*fSize);

		// Parse file and store in target
		result->sz = fread(result->txt, 1, fSize, file);
		if (result->sz != fSize) {fputs("File read err", stderr); exit(3);};

		// Close file object
		fclose(file);

		return result; 

	} else {
		
		fputs("File open err", stderr);

	}

}

RawData* LoadIntData(char* filename, char value_delimiter, bool ) {
	
	// Read in data
	RawData* data;
	data = ParseFile(filename);

	unsigned long i, open_square, close_square, open_curly, close_curly;
	i = 0;
	char c;
	c = data->txt[i]
	while (c != NULL) {
		
		if (c == '\n') {

		} else if ( c == delimiter) {

		} else {

		}

		++i;
	}

	return data;

}
	
void* LoadFloatData(char* filename, int verbosity) {
	return NULL;
}

void* LoadDoubleData(char* filename, int verbosity) {
	return NULL;
}
	
#endif
