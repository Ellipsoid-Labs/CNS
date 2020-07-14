#include <stdio.h>
#pragma once

enum errorTypes {Generic, Interpreter, Warning};

void err(short int cWarn, char *message) {
	if (!cWarn) printf("\033[1;31mERROR: \033[0m");
	else if (cWarn == 1) printf("\033[0;31mINTERPRETER ERROR: \033[0m");
	else printf("[01;33mWARNING: \033[0m");
	printf("%s\n", message);
	return;
}
