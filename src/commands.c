#include <stdio.h> // printf()
#include <stdlib.h> // system()
#include "C_Headers/error.h" // err() and errorTypes
#include "C_Headers/commands.h"

static char *man[1] = {"COMMAND LINE FORMAT: (parantheses indicate notes regarding the formattting, ARGX: means that the usage of the following commands can be utilized for X argument, anything in [] is optional, and anything in {} is an example of what you could place there.)\nARG0: CNS\nARG1: [{fileName.sb}]\nOPTIONS: (last argument of command assuming that last argument != ARG0 under any circumstances)\n--version: Returns version number.\n--help/--man [x]: Returns this message; x gives specific page.\n--copyright: Returns copyright information."};
static int manSize = sizeof(man) / sizeof(char*);

void help(int page) {
	if (page > manSize || page < 1) err(Generic, "Provided man page is out of bounds.");
	else {
		page--;
		for (;page < manSize; page++) {
			CLEAR;
			printf("%s\n\n\n\033[1;36m(Page \033[0m\033[4;32m%d \033[0m\033[1;36m/\033[0m \033[4;32m%d\033[0m ; ENTER key to continue, any other sequence of characters + ENTER key to escape)\n", man[page], page, manSize);
			if (getchar() != '\n') break;
		}
		CLEAR;
	}
	return;
}
