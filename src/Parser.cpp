#include "Token.hpp"
#include "Parser.hpp"
#include "Exception.hpp"
#include "termcolor.hpp"
#include <iostream>

std::vector<bool> Parser::_instrsTakeParam = {
	false,	// eInstruction::Add
	true,	// eInstruction::Assert
	false,	// eInstruction::Div
	false,	// eInstruction::Dump
	false,	// eInstruction::Exit
	false,	// eInstruction::Mod
	false,	// eInstruction::Mul
	false,	// eInstruction::Pop
	false,	// eInstruction::Print
	true,	// eInstruction::Push
	false,	// eInstruction::Sub
	// bonus
	false,	// eInstruction::Abs
	false,	// eInstruction::Min
	false,	// eInstruction::Max
	false,	// eInstruction::Pow
	false,	// eInstruction::Not
	false,	// eInstruction::And
	false,	// eInstruction::Or
	false,	// eInstruction::Xor
	false	// eInstruction::Clear
};

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

bool	Parser::verifyGrammar(std::vector<Token> &tokenList, bool stopOnWarning) const {
	bool exitStatus = true;
	bool unreachableWarn = true;

	for (auto it = tokenList.begin(); it != tokenList.end(); ++it) {
		try {
			// verify instructions parameters
			if ((*it).getParam() == nullptr && Parser::_instrsTakeParam[(*it).getInstruction()]) {
				throw Exception::InstrTakeParam();
				exitStatus = false;
			} else if ((*it).getParam() != nullptr && !Parser::_instrsTakeParam[(*it).getInstruction()]) {
				throw Exception::InstrDontTakeParam();
				exitStatus = false;
			}

			if (unreachableWarn && (*it).getInstruction() == eInstruction::Exit
			&& unreachableWarn && it + 1 != tokenList.end()) {
				unreachableWarn = false; // to avoid to repeat the same warning
				std::cout << termcolor::yellow << "[ParserWarning] Line " << (*(it + 1)).getLineNb()
					<< " : Code after the exit instruction is unreachable" << termcolor::reset << std::endl;
				if (stopOnWarning)
					exitStatus = false;
			}
		}
		catch(const Exception::ParserException& e) {
			exitStatus = false;
			std::cerr << termcolor::red << "[ParserException] Line " << (*it).getLineNb() << " : " << e.what() << termcolor::reset << std::endl;
		}
	}

	return exitStatus;
}
