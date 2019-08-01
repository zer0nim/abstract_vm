#include "Parser.hpp"

Parser::Parser() {
}

Parser::Parser(Parser const &src) {
	*this = src;
}

Parser::~Parser() {
}

Parser &Parser::operator=(Parser const &rhs) {
	if (this != &rhs)
		;
	return *this;
}

void	Parser::verifyGrammar(std::vector<Token> tokenList) const {
	std::cout << "In verifyGrammar:" << std::endl << std::endl;
	for (Token token : tokenList) {
		std::cout << "token: " << token << std::endl;
	}

	// need to check grammar errors like no exit instr, no enought attribute, ...
}
