#include <stdio.h> // printf()
#include <stdlib.h> // exit()
#include "C_Headers/error.h"

unsigned long long int errorCount = 0;
extern unsigned long long int errorCount;

void checkErr() {
        if (errorCount) {
                printf("\033[0;31m%llu\033[0m errors were generated.\n", errorCount);
                exit(0);
        }
        return;
}

void err(short int cWarn, const char *message) {
	errorCount++;
	if (!cWarn) printf("\033[0;31mERROR: \033[0m");
	else if (cWarn == 1) printf("\033[1;31mINTERPRETER ERROR: \033[0m");
	else if (cWarn == 3) {
		printf("\033[0;31mFATAL ERROR: \033[0m%s\n", message);
		checkErr();
	}
	else {
		errorCount--;
		printf("[01;33mWARNING: \033[0m%s\n", message);
		return;
	}
	printf("%s\n", message);
	return;
}
