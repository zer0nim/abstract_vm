#include "Token.hpp"

Token::Token() : Token(-1) {
}

Token::Token(int lineNb) : _lineNb(lineNb) {
}

Token::Token(Token const &src) {
	*this = src;
}

Token::~Token() {
}

Token &Token::operator=(Token const &rhs) {
	if (this != &rhs)
		_lineNb = rhs.getLineNb();
	return *this;
}

int	Token::getLineNb() const { return _lineNb; }
