#ifndef PARSEFILE_H
#define PARSEFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ErrorHandle.h"
#include "DataStructs.h"

unsigned long FileSize(FILE* f) {

	unsigned long fSize;

	fseek(f, 0, SEEK_END);
	fSize = ftell(f);
	rewind(f);

	return fSize;

}

void* getBuffer(unsigned long sz) {

	void* buffer = malloc(sz);
	if (buffer == NULL) {fputs("<getBuffer> Failed allocating file buffer", stderr); exit(1);};
	
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
		result->txt = (char*)getBuffer(sizeof(char)*fSize + 1);
		if ( *(result->txt + fSize - 1) != '\0' ) {
			*(result->txt + fSize) = '\0';
		} else {
			result->txt = realloc(result->txt, fSize);
		}
		
		// Parse file and store in target
		result->sz = fread(result->txt, 1, fSize, file);
		if (result->sz != fSize) {err_exit("<ParseFile> Size disparity: alloc mem vs measured sz", 1);};

		unsigned long i, count = 0;
		for (i = 0; i < result->sz; ++i) {
			if ( *(result->txt + i) == '\n' ) {
				++count;
			}
		}
		result->n_rows = ++count;

		// Close file object
		fclose(file);

		return result; 

	} else {
		
		fputs("\nFile open err\n", stderr);
		exit(1);
	}

}

#endif
