#include "Vm.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"

int main(int argc, char const *argv[]) {
	Lexer	lexer;
	Parser	parser;
	Vm		vm;

	// Use lexer to convert the program to Token
	if (argc > 1) {
		if (!lexer.readFromFile(argv[1]))
			return 1;
	} else {
		if (!lexer.readFromStdin())
			return 1;
	}

	// Read Token and verify grammar
	if (!parser.verifyGrammar(lexer.getTokenList()))
		return 1;

	// Execute the program
	if (!vm.run(lexer.getTokenList()))
		return 1;

	return 0;
}
