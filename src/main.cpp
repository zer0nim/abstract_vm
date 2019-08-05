#include "Vm.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"
#include <regex>

int	usage() {
	std::cout << "usage: ./avm [--verbose | -v] [filename]" << std::endl;
	return 1;
}

int main(int argc, char const *argv[]) {
	Lexer		lexer;
	Parser		parser;
	Vm			vm;

	// verbose option
	std::string	space = "[^\\S\\r\\n]*";
	std::string	verboseReg = "^" + space + "((-v)|(--verbose))" + space + "$";
	bool		verbose = false;

	// Use lexer to convert the program to Token
	if (argc > 3) {
		return usage();
	} else if (argc > 1) {
		if (argc == 2) {
			// ./avm --verbose
			if (std::regex_match(argv[1], std::regex(verboseReg))) {
				verbose = true;
				if (!lexer.readFromStdin())
					return 1;
			} else { // ./avm filename
				if (!lexer.readFromFile(argv[1]))
					return 1;
			}
		}
		else {
			// ./avm --verbose filename
			if (std::regex_match(argv[1], std::regex(verboseReg))) {
				verbose = true;
				if (!lexer.readFromFile(argv[2]))
					return 1;
			} // ./avm filename --verbose
			else if (std::regex_match(argv[2], std::regex(verboseReg))) {
				verbose = true;
				if (!lexer.readFromFile(argv[1]))
					return 1;
			} else {
				return usage();
			}
		}
	} else {
		if (!lexer.readFromStdin())
			return 1;
	}

	// Read Token and verify grammar
	if (!parser.verifyGrammar(lexer.getTokenList()))
		return 1;

	// Execute the program
	if (!vm.run(lexer.getTokenList(), verbose))
		return 1;

	return 0;
}
