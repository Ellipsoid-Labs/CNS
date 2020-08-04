#include <iostream> // std::cout and std::cin
#include <string> // std::string and getline()
#include <cstring> // std::strncmp()
#include <fstream> // std::ifstream and is_open()
#include <boost/lexical_cast.hpp> // boost::lexical_cast and boost::bad_lexical_cast
#include <boost/algorithm/string.hpp> // boost::split() and boost::is_any_of()
#include <vector> // std::vector, at(), and size()
#include "C_Headers/error.h" // err() and errorTypes
#include "C_Headers/commands.h" // help() and CLEAR
#include "C_Headers/global.h" // VERSION
#include "C_Headers/stringops.h" // lower() and strip()
#include "C_Headers/read.h" // read()
#include "CPP_Headers/interpreter.hpp"
#define __INTERPRETER_ACTIVE

void safetyHelp(const char* argv) {
        try { help(boost::lexical_cast<int>(argv)); }
        catch (boost::bad_lexical_cast) { help(-1); }
}

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
		}
		else if (!std::strncmp(input, "help", 4)) {
			std::vector<std::string> splitArray;
			boost::split(splitArray, input, boost::is_any_of(" "));
			if (splitArray.size() > 1) safetyHelp(splitArray.at(1).c_str());
		}
		else if (!std::strncmp(input, "clear", 5)) CLEAR;
		else readLn(initInput.c_str());
	}
	return;
}
