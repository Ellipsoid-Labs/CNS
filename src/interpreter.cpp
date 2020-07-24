#include <iostream> // std::cout, std::cin, and std::endl
#include <string> // std::string and getline()
#include <cstring> // std::strncmp()
#include <fstream> // std::ifstream and is_open()
#include "C_Headers/error.h" // err() and errorTypes
#include "C_Headers/commands.h" // help()
#include "C_Headers/global.h" // VERSION
#include "C_Headers/stringops.h" // lower() and strip()
#include "C_Headers/read.h" // read()
#include "CPP_Headers/interpreter.hpp"
#define __INTERPRETER_ACTIVE

void interpreter() {
	std::string initInput;
	std::cout << ">> Scatterbrain CNS: Central Nervous System interpreter " << VERSION << "\nCopyrighted under the M.I.T. license (\"copyright\" for more info).\nUse \"help\" to get started.\n";
	for (;;) {
		std::cout << ">> ";
		getline(std::cin, initInput);
		char* input = strip(lower(initInput.c_str())); // input is lowercase version
		// Following are all interpreter interface-specific routines, ending with the call to the main processing function
		if (!std::strncmp(input, "copyright", 9)) {
			std::ifstream license("../LICENSE");
			std::string line;
			if (license.is_open()) while (getline(license, line)) std::cout << line << std::endl;
			else err(Interpreter, "Could not open \"LICENSE\" ...where did our license go?");
			continue;
		}
		if (!std::strncmp(input, "help", 4)) help(1);
		readLn(initInput.c_str());
	}
	return;
}
