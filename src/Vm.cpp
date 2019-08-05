#include "Vm.hpp"
#include "Lexer.hpp"
#include "Exception.hpp"
#include "termcolor.hpp"

std::vector<InstrFunc> Vm::_instrFuncs = {
	&instrAdd,		// eInstruction::Add
	&instrAssert,	// eInstruction::Assert
	&instrDiv,		// eInstruction::Div
	&instrDump,		// eInstruction::Dump
	nullptr,		// eInstruction::Exit
	&instrMod,		// eInstruction::Mod
	&instrMul,		// eInstruction::Mul
	&instrPop,		// eInstruction::Pop
	&instrPrint,	// eInstruction::Print
	&instrPush,		// eInstruction::Push
	&instrSub,		// eInstruction::Sub
	// bonus
	&instrAbs,		// eInstruction::Abs
	&instrMin,		// eInstruction::Min
	&instrMax,		// eInstruction::Max
	&instrPow,		// eInstruction::Pow
	&instrNot,		// eInstruction::Not
	&instrAnd,		// eInstruction::And
	&instrOr,		// eInstruction::Or
	&instrXor,		// eInstruction::Xor
	&instrClear		// eInstruction::Clear
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


bool	Vm::run(std::vector<Token> &tokenList, bool verbose) {
	for (auto token : tokenList) {
		try {
			if (verbose) {
				std::cout << termcolor::cyan << token.cleanFormat() << termcolor::reset << std::endl;
			}

			// stop the execution on exit
			if (token.getInstruction() == eInstruction::Exit)
				return true;

			Vm::_instrFuncs[token.getInstruction()](_factory, _stack, token.getParam());

			if (verbose) {
				std::cout << termcolor::green << "stack {";
				for (auto it = _stack.rbegin(); it != _stack.rend(); ++it) {
					if (it != _stack.rbegin())
						std::cout << ", ";
					std::cout << (*it)->toString();
				}
				std::cout << "}" << termcolor::reset << std::endl << std::endl;
			}
		}
		catch(const Exception::RuntimeException& e) {
			std::cerr << termcolor::red << "[RuntimeException] Line " << token.getLineNb() << " : " << e.what() << termcolor::reset << std::endl;
			return false;
		}
	}

	std::cerr << termcolor::red << "[RuntimeException] The program doesn’t have an exit instruction" << termcolor::reset << std::endl;
	return false;
}
