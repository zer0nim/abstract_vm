#include "Parser.hpp"
#include "Exception.hpp"

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
