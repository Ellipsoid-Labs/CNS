#include <iostream> // std::cout and std::endl
#include <string> // std::string, getline()
#include <boost/lexical_cast.hpp> // boost::lexical_cast and boost::bad_lexical_cast
#include <fstream> // ifstream, is_open()
#include "C_Headers/constants.h" // VERSION
#include "C_Headers/commands.h" // help()
#include "C_Headers/error.h" // err() and errorTypes
#include "C_Headers/read.h" // read()
#include "CPP_Headers/interpreter.hpp" // interpreter()

int main(int argc, char** argv) {
	std::string argv1 = argv[1];
	if (argc < 2) interpreter();
	else if (argv1 == "--version") std::cout << VERSION << std::endl;
	else if (argv1 == "--help" || argv1 == "--man") {
		if (argc != 2) {
			try { help(boost::lexical_cast<int>(argv[2])); }
			catch (boost::bad_lexical_cast) { help(-1); }
		}
		else help(1);
	}
	else { 
		std::ifstream source(argv1);
		if (!source.is_open()) err(Fatal, "File '" + argv1 + "' not found!");
		std::string line;
		while (getline(source, line)) read(line.c_str());
	}
	return 0;
}
