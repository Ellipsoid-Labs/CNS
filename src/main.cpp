#include <iostream> // std::cout and std::endl
#include <string> // std::string, find(), std::string::npos, and getline()
#include <boost/lexical_cast.hpp> // boost::lexical_cast and boost::bad_lexical_cast
#include <fstream> // ifstream, is_open()
#include <cstdlib> // malloc()
#include "C_Headers/global.h" // VERSION
#include "C_Headers/commands.h" // help()
#include "C_Headers/error.h" // err() and errorTypes
#include "C_Headers/read.h" // read()
#include "CPP_Headers/interpreter.hpp" // interpreter()

std::string commentFormat(std::string line, std::string substring) { 
	if (line.find(substring) != std::string::npos) return line.substr(0, line.find(substring));
	else return line;
}

int main(int argc, char** argv) {
	if (argc < 2) {
		interpreter();
		return 0;
	}
	std::string argv1 = argv[1];
	if (argv1 == "--version") std::cout << VERSION << std::endl;
	else if (argv1 == "--help" || argv1 == "--man") {
		if (argc != 2) {
			try { help(boost::lexical_cast<int>(argv[2])); }
			catch (boost::bad_lexical_cast) { help(-1); }
		}
		else help(1);
	}
	else { 
		std::ifstream source(argv1);
		if (!source.is_open()) {
			std::string FNF = "File '" + argv1 + "' not found!";
                	if (argv1.substr(0, 2) == "--") FNF += "\nDid you mean to input a command?";
			err(Fatal, FNF.c_str());
		}
		std::string line;
		std::string file;
		bool inComment = false;
		while (getline(source, line)) {
			line = commentFormat(line, "//");
			if (line.find("/*") != std::string::npos) {
				commentFormat(line, "/*");
				inComment = true;
			}
			if (inComment) {
				if (line.find("*/") != std::string::npos) {
					line = line.substr(line.find("*/") + 2, line.length() - 1);
					inComment = false;
				}
				else continue;
			}
			file += line + "\n";
		}
		readLn(line.c_str());
	}
	return 0;
}
