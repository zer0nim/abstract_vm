#include "Token.hpp"

Token::Token() {
}

Token::Token(int lineNb, eInstruction instruction, Value *param)
: _instruction(instruction), _param(param), _lineNb(lineNb) {
}

Token::Token(Token const &src) {
	*this = src;
}

Token::~Token() {
}

Token &Token::operator=(Token const &rhs) {
	if (this != &rhs) {
		_instruction = rhs.getInstruction();
		_param = (getParam() != nullptr) ? new Value(*getParam()) : nullptr;
		_lineNb = rhs.getLineNb();
	}
	return *this;
}

eInstruction	Token::getInstruction() const { return _instruction; }
const Value		*Token::getParam() const { return _param; }
int	Token::getLineNb() const { return _lineNb; }
