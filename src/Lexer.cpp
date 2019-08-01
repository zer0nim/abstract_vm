#include "Lexer.hpp"
#include "Exception.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

Lexer::Lexer() {
	_instructsSyntax = {
		InstructSyntax("add", false, eInstruction::Add),
		InstructSyntax("assert", true, eInstruction::Assert),
		InstructSyntax("div", false, eInstruction::Div),
		InstructSyntax("dump", false, eInstruction::Dump),
		InstructSyntax("exit", false, eInstruction::Exit),
		InstructSyntax("mod", false, eInstruction::Mod),
		InstructSyntax("mul", false, eInstruction::Mul),
		InstructSyntax("pop", false, eInstruction::Pop),
		InstructSyntax("print", false, eInstruction::Print),
		InstructSyntax("push", true, eInstruction::Push),
		InstructSyntax("sub", false, eInstruction::Sub),
	};
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

std::queue<Token> &Lexer::getTokenList() { return _tokenList; }
std::queue<Token> Lexer::getTokenListCopy() const { return _tokenList; }

void	Lexer::parseLine(std::string line, int nb) {
	// comment or blank line
	if (std::regex_match(line, std::regex("^(;.*)?$")))
		return;

	Token	newToken;
	auto it = _instructsSyntax.begin();
	while (it != _instructsSyntax.end() && !it->createToken(nb, line, newToken))
		++it;

	// if there is no match
	if (it == _instructsSyntax.end()) {
		throw Exception::UnknownInstruction(nb);
	}

	// else create the token
	_tokenList.push(newToken);
}

void	Lexer::readFromFile(std::string filename) {
	std::ifstream   ifs(filename);

	if (!ifs)
		throw Exception::ErrorOpeningFile();

	// parse the file line by line
	std::string line;
	for (size_t nb = 1; std::getline(ifs, line); nb++) {
		try {
			parseLine(line, nb);
		}
		catch(const Exception::LexerException& e) {
			std::cerr << e.what() << '\n';
		}
	}

	ifs.close();
}

void	Lexer::readFromStdin() {
	// parse stdin line by line
	std::string line;
	for (size_t nb = 1; std::getline(std::cin, line); nb++) {
		try {
			parseLine(line, nb);
		}
		catch(const Exception::LexerException& e) {
			std::cerr << e.what() << '\n';
		}
		if (line.find(";;") != std::string::npos)
			break;
	}
}
