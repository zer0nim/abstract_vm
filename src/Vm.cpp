#include "Vm.hpp"
#include "Exception.hpp"

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

std::vector<IOperand const *>	Vm::getStack() const { return _stack; }


bool	Vm::run(std::vector<Token> &tokenList) {
	for (auto token : tokenList) {
		try {
			Vm::_instrFuncs[token.getInstruction()](_factory, _stack, token.getParam());
		}
		catch(const Exception::RuntimeException& e) {
			std::cerr << "[RuntimeException] Line " << token.getLineNb() << " : " << e.what() << std::endl;
			return false;
		}
	}

	return true;
}
