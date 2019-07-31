#include "Lexer.hpp"

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
