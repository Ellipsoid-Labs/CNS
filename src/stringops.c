#include <string.h> // strlen() and strrev()
#include <stdlib.h> // malloc()
#include "C_Headers/stringops.h"

char *lower(const char *string) {
	char *returnString = (char *)malloc(strlen(string)*sizeof(char));
	for (int i = 0; i < strlen(string); i++) returnString[i] = tolower(string[i]);
	return returnString;
}

int frequency(const char *string, char substring) {
	int charCount;
	for (int i = 0; i < strlen(string); i++) if (string[i] == substring) charCount++;
	return charCount;
}

int findPos(const char *string, char substring) {
	for (int i = 0; i < strlen(string); i++) if (string[i] == substring) return i;
        return -1;
}	
