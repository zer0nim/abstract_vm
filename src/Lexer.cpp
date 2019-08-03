#include "Lexer.hpp"
#include "IOperand.hpp"
#include "Exception.hpp"
#include "termcolor.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

std::vector<std::string>	Lexer::_instrsNames {
	"add",		// eInstruction::Add
	"assert",	// eInstruction::Assert
	"div",		// eInstruction::Div
	"dump",		// eInstruction::Dump
	"exit",		// eInstruction::Exit
	"mod",		// eInstruction::Mod
	"mul",		// eInstruction::Mul
	"pop",		// eInstruction::Pop
	"print",	// eInstruction::Print
	"push",		// eInstruction::Push
	"sub"		// eInstruction::Sub
};

std::vector<std::string>	Lexer::_valuesSyntax {
	"int8\\(([-]?[0-9]+)\\)",			// eOperandType::Int8
	"int16\\(([-]?[0-9]+)\\)",			// eOperandType::Int16
	"int32\\(([-]?[0-9]+)\\)",			// eOperandType::Int32
	"float\\(([-]?[0-9]+.[0-9]+)\\)",	// eOperandType::Float
	"double\\(([-]?[0-9]+.[0-9]+)\\)"	// eOperandType::Double
};

Lexer::Lexer() {
}

Lexer::Lexer(Lexer const &src) {
	*this = src;
}

Lexer::~Lexer() {
}

Lexer &Lexer::operator=(Lexer const &rhs) {
	if (this != &rhs)
		_tokenList = rhs.getTokenListCopy();
	return *this;
}

std::vector<Token> &Lexer::getTokenList() { return _tokenList; }
std::vector<Token> Lexer::getTokenListCopy() const { return _tokenList; }

bool	Lexer::createToken(int lineNb, eInstruction instr, std::string line, Token	&token) {
	std::string	space = "[^\\S\\r\\n]*";
	std::string	regexStr = "^" + space + Lexer::_instrsNames[instr] + space + "(;.*)?$";

	// test without param
	if (std::regex_match(line, std::regex(regexStr))) {
		token = Token(lineNb, instr, nullptr);
		return true;
	}
	else { // test with param
		std::cmatch m;	// used to get the diferents parts of the match

		// test different types of value (int32, float, ...)
		for (auto it = Lexer::_valuesSyntax.begin(); it != Lexer::_valuesSyntax.end(); ++it) {
			regexStr = "^" + space + Lexer::_instrsNames[instr] + space + *it + space + "(;.*)?$";

			if (std::regex_match(line.c_str(), m, std::regex(regexStr))) {
				eOperandType opType = static_cast<eOperandType>(it - Lexer::_valuesSyntax.begin());
				token = Token(lineNb, instr, new Value(opType, m[1]));
				return true;
			}
		}
	}
	return false;
}

void	Lexer::parseLine(std::string line, int lineNb) {
	// comment or blank line
	if (std::regex_match(line, std::regex("^(;.*)?$")))
		return;

	Token	newToken;
	auto it = Lexer::_instrsNames.begin();
	while (it != Lexer::_instrsNames.end()
	&& !createToken(lineNb, static_cast<eInstruction>(it - Lexer::_instrsNames.begin()), line, newToken))
		++it;

	// if there is no match
	if (it == Lexer::_instrsNames.end()) {
		throw Exception::UnknownInstruction();
	}

	// else create the token
	_tokenList.push_back(newToken);
}

bool	Lexer::readFromFile(std::string filename) {
	bool exitStatus = true;
	std::ifstream   ifs(filename);

	if (!ifs) {
		std::cerr << termcolor::red << "[LexerException] Error while attempting to open file" << termcolor::reset << std::endl;
		return false;
	}

	// parse the file line by line
	std::string line;
	for (size_t lineNb = 1; std::getline(ifs, line); lineNb++) {
		try {
			parseLine(line, lineNb);
		}
		catch(const Exception::LexerException& e) {
			exitStatus = false;
			std::cerr << termcolor::red << "[LexerException] Line " << lineNb << " : " << e.what() << termcolor::reset << std::endl;
		}
	}

	ifs.close();
	return exitStatus;
}

bool	Lexer::readFromStdin() {
	bool exitStatus = true;
	// parse stdin line by line
	std::string line;
	for (size_t lineNb = 1; std::getline(std::cin, line); lineNb++) {
		try {
			parseLine(line, lineNb);
		}
		catch(const Exception::LexerException& e) {
			exitStatus = false;
			std::cerr << termcolor::red << "[LexerException] Line " << lineNb << " : " << e.what() << termcolor::reset << std::endl;
		}
		if (line.find(";;") != std::string::npos)
			break;
	}
	return exitStatus;
}
