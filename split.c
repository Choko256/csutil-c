#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "split.h"

void fillstr(char * destination, char * source, size_t size, int * z__current) {
	destination = (char*) malloc(size);
	int j = 0;
	for(j = 0; j < size - 1; j++) {
		destination[i][j] = source[*z__current];
		(*z__current)++;
	}
	destination[i][size - 1] = '\0';
	(*z__current)++;
}

char ** splitstr(const char * source, char separator, int* chunknums) {
	char ** result;
	size_t nboccur = 0;
	int i = 0;
	int j = 0, written = 0;
	char * previous;
	size_t sizetoalloc;

	// Computing separator occurences in source string
	for(i = 0; i < strlen(source); i++) {
		if(source[i] == separator) {
			nboccur ++;
		}
	}
	// Return this counter into referenced parameter
	*chunknums = nboccur+1;

	i = 0;
	// Allocation of string array
	result = (char**) malloc(nboccur + 1);

	// First find
	char * sepoccur = strchr(source, (int) separator);
	while(sepoccur != NULL) {
		// Computing size of string BEFORE the detected separator
		sizetoalloc = sepoccur - source - written + 1;
		// Allocating string
		/* result[i] = (char*) malloc(sizetoalloc);

		// Filling string
		for(j = 0; j < sizetoalloc - 1 ; j++) {
			result[i][j] = source[written];
			written++;
		}
		result[i][sizetoalloc - 1] = '\0';
		written++;
		*/
		fillstr(result[i], source, sizetoalloc, &written);
		// Keeping previous detected
		previous = sepoccur + 1;
		// Next find
		sepoccur = strchr(sepoccur + 1, (int) separator);
		i++;
	}
	// Computing size of last string
	sizetoalloc = strlen(source) - written + 1;
	// Allocating string
	/*result[i] = (char*) malloc(sizetoalloc);
	// Filling string
	for(j = 0; j < sizetoalloc - 1 ; j++) {
		result[i][j] = source[written];
		written++;
	}
	result[i][sizetoalloc - 1] = '\0';
	written++;
	*/
	fillstr(result[i], source, sizetoalloc, &written);
	// Result is full
	return result;
}
