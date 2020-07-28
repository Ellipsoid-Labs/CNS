#include <stdio.h> // printf()
#include <stdlib.h> // exit()
#include <string.h> // strlen()
#include "C_Headers/error.h"

unsigned long long errorCount = 0;
extern unsigned long long errorCount;

void checkErr() {
        if (errorCount) {
                printf("\033[0;31m%llu\033[0m errors were generated.\n", errorCount);
                exit(0);
        }
        return;
}

void errLine(char *string, short charPos) {
	printf("%s\n", string);
	for (int i = 0; i < charPos - 1; i++) printf(" ");
	printf("\033[1;35m^\033[0m");
	return;
}

void err(short cWarn, const char *message) {
	errorCount++;
	if (!cWarn) printf("\033[0;31mERROR: \033[0m");
	else if (cWarn == 1) printf("\033[1;31mINTERPRETER ERROR: \033[0m");
	else if (cWarn == 3) {
		printf("\033[0;31mFATAL ERROR: \033[0m%s\n", message);
		checkErr();
	}
	else {
		errorCount--;
		printf("\033[01;33mWARNING: \033[0m%s\n", message);
		return;
	}
	printf("%s\n", message);
	return;
}
