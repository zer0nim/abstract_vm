#include "Lexer.hpp"
#include <iostream>
#include <fstream>
#include <string>

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

std::queue<Token> &Lexer::getTokenList() { return _tokenList; }
std::queue<Token> Lexer::getTokenListCopy() const { return _tokenList; }

void	Lexer::parseLine(std::string line, int nb) {
	std::cout << "parse line " << nb << " => " << line << std::endl;
}

void	Lexer::readFromFile(std::string filename) {
	std::ifstream   ifs(filename);

	if (!ifs) {
		std::cerr << "Error opening files!" << std::endl;
		// !!! NEED TO TROW EXCEPTION !
	}

	// parse the file line by line
	std::string line;
	for (size_t nb = 1; std::getline(ifs, line); nb++) {
		parseLine(line, nb);
	}

	ifs.close();
}

void	Lexer::readFromStdin() {
	// parse stdin line by line
	std::string line;
	for (size_t nb = 1; std::getline(std::cin, line)
	&& line.find(";;") == std::string::npos; nb++) {
		parseLine(line, nb);
    }
}
