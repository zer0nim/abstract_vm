#include "Vm.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"
#include <unistd.h>

int	usage() {
	std::cout << "usage: ./avm [-vVcC] [filename]" << std::endl;
	return 1;
}

int main(int argc, char *argv[]) {
	Lexer		lexer;
	Parser		parser;
	Vm			vm;

	// for command params
	int		opt;
	bool	verbose = false;			// -v
	bool	cleanSyntax = false;		// -c
	bool	stopOnWarning = false;		// -w
	bool	continueOnError = false;	// -e

	// parse params
	while ((opt = getopt(argc, argv, "vVcCwWeE")) != EOF) {
        switch(opt) {
            case 'v': case 'V':
				verbose = true;
				break;
            case 'c': case 'C':
				cleanSyntax = true;
				break;
            case 'w': case 'W':
				stopOnWarning = true;
				break;
            case 'e': case 'E':
				continueOnError = true;
				break;
            case '?': default:
				return usage();
        }
	}

	// check for undesired extra param
	if (argc - optind > 1)
		return usage();

	// Use lexer to convert the program to Token
	if (argc - optind == 1) {
		// parse program from file
		if (!lexer.readFromFile(argv[optind]))
			return 1;
	} else {
		// parse program from stdin
		if (!lexer.readFromStdin(continueOnError))
			return 1;
	}

	// Read Token and verify grammar
	if (!parser.verifyGrammar(lexer.getTokenList(), stopOnWarning))
		return 1;

	// if bonus cleanSyntax is enabled, print the program with syntax highlighted
	if (cleanSyntax) {
		vm.syntaxHighlight(lexer.getTokenList());
		return 0;
	}

	// Execute the program
	if (!vm.run(lexer.getTokenList(), verbose))
		return 1;

	return 0;
}
