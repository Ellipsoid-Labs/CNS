#include <string.h> // strlen()
#include <stdlib.h> // malloc() and free()
#include "C_Headers/stringops.h"

char *lower(const char *string) {
	char *returnString = (char *)malloc(strlen(string)*sizeof(char))
	for (int i = 0; i < strlen(string); i++) returnString[i] = tolower(string[i]);
	return returnString;
}
