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
		int exitCnt = 0;

		for (auto it = tokenList.begin(); it != tokenList.end(); ++it) {
			if ((*it).getInstruction() == eInstruction::Exit) {
				++exitCnt;
				// check if there is code after the exit instruction
				if (it + 1 != tokenList.end())
					throw Exception::UnreachableCode();
			}
		}

		// if there is no exit instruction
		if (exitCnt == 0)
			throw Exception::ExitInstructionNotFound();
	}
	catch(const Exception::ParserException& e) {
		exitStatus = false;
		std::cerr << "[ParserException] " << e.what() << std::endl;
	}

	return exitStatus;
}
