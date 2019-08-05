#include "Token.hpp"
#include "Lexer.hpp"
#include "termcolor.hpp"

// used to print enum name
std::unordered_map<int, std::string> Token::instructMap = {
	{eInstruction::Add, "Add"},
	{eInstruction::Assert, "Assert"},
	{eInstruction::Div, "Div"},
	{eInstruction::Dump, "Dump"},
	{eInstruction::Exit, "Exit"},
	{eInstruction::Mod, "Mod"},
	{eInstruction::Mul, "Mul"},
	{eInstruction::Pop, "Pop"},
	{eInstruction::Print, "Print"},
	{eInstruction::Push, "Push"},
	{eInstruction::Sub, "Sub"},
};

Token::Token()
: _lineNb(-1), _instruction(eInstruction::Add), _param(nullptr) {
}

Token::Token(int lineNb, eInstruction instruction, Value *param)
: _lineNb(lineNb), _instruction(instruction), _param(param) {
}

Token::Token(Token const &src) {
	*this = src;
}

Token::~Token() {
	if (_param != nullptr) {
		delete _param;
		_param = nullptr;
	}
}

Token &Token::operator=(Token const &rhs) {
	if (this != &rhs) {
		_instruction = rhs.getInstruction();
		_param = (rhs.getParam() != nullptr) ? new Value(*(rhs.getParam())) : nullptr;
		_lineNb = rhs.getLineNb();
	}
	return *this;
}

eInstruction	Token::getInstruction() const { return _instruction; }
Value			*Token::getParam() const { return _param; }
int				Token::getLineNb() const { return _lineNb; }

void			Token::cleanFormat(bool syntaxOn) const {
	if (syntaxOn) {
		std::cout << termcolor::yellow << Lexer::_instrsNames[getInstruction()];
		std::cout << termcolor::reset;
		if (getParam() != nullptr) {
			std::cout << " " << termcolor::magenta << Lexer::_typesNames[getParam()->getOpType()];
			std::cout << termcolor::reset;
			std::cout << "(" << termcolor::cyan << getParam()->getData() << termcolor::reset << ")";
		}
	} else {
		std::cout << Lexer::_instrsNames[getInstruction()];
		if (getParam() != nullptr) {
			std::cout << " " << Lexer::_typesNames[getParam()->getOpType()];
			std::cout << "(" << getParam()->getData() << ")";
		}
	}
	std::cout << std::endl;
}


std::ostream & operator << (std::ostream &out, const Token &c) {
	out << "{ line: " << c.getLineNb()
		<< ", instruction: " << Token::instructMap[c.getInstruction()];

	if (c.getParam() != nullptr)
		out << ", param: " << *(c.getParam());
	out << " }";

	return out;
}
