#include <ctype.h>
#include <stdlib.h>
#include "error.h"
#pragma once

char *lower(char *string) {
	char *lowStr = (char *)malloc(sizeof(string));
	if (lowStr == NULL) err(Interpreter, "In \"stringops.h\", \"malloc(sizeof(string))\" returns NULL");
	for (int i = 0; i < sizeof(string) / sizeof(char); i++) lowStr[i] = tolower(string[i]);
	return lowStr;
}
