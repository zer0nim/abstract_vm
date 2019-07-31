#include "Instruction.hpp"

Instruction::Instruction() : Token(-1), _param(-1, eOperandType::Double, "") {
}

Instruction::Instruction(int lineNb, eInstruction instruction, Value param)
: Token(lineNb), _instruction(instruction), _param(param) {
}

Instruction::Instruction(Instruction const &src) : Token(src), _param(-1, eOperandType::Double, "") {
	*this = src;
}

Instruction::~Instruction() {
}

Instruction &Instruction::operator=(Instruction const &rhs) {
	if (this != &rhs) {
		_instruction = rhs.getInstruction();
		_param = rhs.getParam();
	}
	return *this;
}

eInstruction	Instruction::getInstruction() const { return _instruction; }
Value			Instruction::getParam() const { return _param; }
