#include <string.h> // strlen() and strrev()
#include <stdlib.h> // malloc()
#include <ctype.h> // isspace()
#include <stdbool.h>
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

char *strip(const char *string) {
	unsigned short whitespaceCharCountBefore = 0;
	unsigned short whitespaceCharCountAfter = 0;
	unsigned short strip__stringLength = strlen(string);
	unsigned short newLen;
	
	for (; isspace(string[whitespaceCharCountBefore]); whitespaceCharCountBefore++)   if (whitespaceCharCountBefore == strip__stringLength)   return (char*)malloc(0); //Count whitspace characters
	for (; isspace(string[strip__stringLength - whitespaceCharCountAfter - 1]); whitespaceCharCountAfter++);
	
	newLen = strip__stringLength - (whitespaceCharCountBefore + whitespaceCharCountAfter);
	
	char *returnString = (char*)malloc((newLen+1)*sizeof(char));
	memcpy( returnString, &string[whitespaceCharCountBefore], newLen);
	returnString[newLen] = '\0';
	return returnString;
}


char *reduce(const char *string, int reduceAllWhitespace) {
	unsigned short reduce__stringLength = strlen(string);
	char *intermediaryString = (char*)malloc(reduce__stringLength*sizeof(char));
	
	
	if(reduceAllWhitespace) {
		for(int i = 0; i < reduce__stringLength; i++) {
			if(isspace(string[i])) {
				intermediaryString[i] = ' ';
			} else {
				intermediaryString[i] = string[i];
			}
		}
	} else {
		memcpy(intermediaryString, string, reduce__stringLength + 1);
	}
	
	
	unsigned short newLen = 0;
	bool prevCharIsSpace = false;
	for(int i = 0; i < reduce__stringLength; i++) {
		if(intermediaryString[i] == ' ') {
			if(!prevCharIsSpace) {
				intermediaryString[newLen] = ' ';
				newLen++;
			}
			prevCharIsSpace = true;
		} else {
			intermediaryString[newLen] = intermediaryString[i];
			newLen++;
			prevCharIsSpace = false;
		}
	}
	
	
	char *returnString = (char*)malloc((newLen+1)*sizeof(char));
	memcpy(returnString, intermediaryString, newLen);
	returnString[newLen] = '\0';
	
	return returnString;
}
