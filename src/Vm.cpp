#include "Vm.hpp"
#include "Exception.hpp"
#include "termcolor.hpp"

std::vector<InstrFunc> Vm::_instrFuncs = {
	&instrAdd,
	&instrAssert,
	&instrDiv,
	&instrDump,
	nullptr, // exit instruction
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
			// stop the execution on exit
			if (token.getInstruction() == eInstruction::Exit)
				return true;

			Vm::_instrFuncs[token.getInstruction()](_factory, _stack, token.getParam());
		}
		catch(const Exception::RuntimeException& e) {
			std::cerr << termcolor::red << "[RuntimeException] Line " << token.getLineNb() << " : " << e.what() << termcolor::reset << std::endl;
			return false;
		}
	}

	std::cerr << termcolor::red << "[RuntimeException] The program doesn’t have an exit instruction" << termcolor::reset << std::endl;
	return false;
}
