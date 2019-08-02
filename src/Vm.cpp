#include "Vm.hpp"

std::vector<InstrFunc> Vm::_instrFuncs = {
	&instrAdd,
	&instrAssert,
	&instrDiv,
	&instrDump,
	&instrExit,
	&instrMod,
	&instrMul,
	&instrPop,
	&instrPrint,
	&instrPush,
	&instrSub
};

Vm::Vm() {
}

Vm::Vm(Vm const &src) {
	*this = src;
}

Vm::~Vm() {
}

Vm &Vm::operator=(Vm const &rhs) {
	if (this != &rhs)
		_stack = getStack();
	return *this;
}

std::vector<IOperand *>	Vm::getStack() const { return _stack; }


bool	Vm::run(std::vector<Token> &tokenList) {
	bool exitStatus = true;

	for (auto token : tokenList) {
		// std::cout << "Token: " << token << std::endl;
		Vm::_instrFuncs[token.getInstruction()](_stack, token.getParam());
	}

	return exitStatus;
}
