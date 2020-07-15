#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include "C_Headers/error.h" // err() and errorTypes
#include "CPP_Headers/interpreter.hpp"

void interpreter() {
	std::string input;
	std::cout << ">> Scatterbrain CNS: Central Nervous System interpreter V0.0.1 ALPHA\nCopyrighted under the M.I.T. license (\"copyright\" for more info).\n";
	for (;;) {
		std::cout << ">> ";
		getline(std::cin, input);
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);
		// Following are all interpreter interface-specific routines, ending with the call to the main processing function
		if (input == "copyright") { // TODO: Make strip function
			std::ifstream license("../LICENSE");
			std::string line;
			if (license.is_open()) while (getline(license, line)) std::cout << line << std::endl;
			else err(Interpreter, "Could not open \"LICENSE\" ...where did our license go?");
		}
	}
	return;
}
