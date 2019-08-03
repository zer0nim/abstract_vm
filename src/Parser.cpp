#include "Parser.hpp"
#include "Exception.hpp"
#include <iostream>

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

bool	Parser::verifyGrammar(std::vector<Token> &tokenList) const {
	bool exitStatus = true;

	try {
		for (auto it = tokenList.begin(); it != tokenList.end(); ++it) {
			if ((*it).getInstruction() == eInstruction::Exit) {
				// check if there is code after the exit instruction
				if (it + 1 != tokenList.end()) {
					std::cout << "[ParserWarning] Line " << (*(it + 1)).getLineNb()
						<< " : Code after the exit instruction is unreachable" << std::endl;
					return true;
				}
			}
		}
	}
	catch(const Exception::ParserException& e) {
		exitStatus = false;
		std::cerr << "[ParserException] " << e.what() << std::endl;
	}

	return exitStatus;
}
