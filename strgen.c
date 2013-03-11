#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strgen.h"

char * substr(const char* source, int start) {
	return source + start;
}

char * substr(const char *source, int start, int length) {
	char * g;
	strncpy(g, source + start, length);
	return g;
}
