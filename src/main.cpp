#include <iostream>
#include <limits>
#include <sstream>
#include <cmath>
#include "Vm.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"
#include "Factory.hpp"
#include "IOperand.hpp"
#include "Exception.hpp"

int main(int argc, char const *argv[]) {
	// double lhsVal = 43;
	// double rhsVal = 2;

	// std::stringstream lhsStrm, rhsStrm;
	// lhsStrm << lhsVal;
	// rhsStrm << rhsVal;

	// Factory factory;
	// const IOperand *lhs = factory.createOperand(eOperandType::Int32, lhsStrm.str());
	// const IOperand *rhs = factory.createOperand(eOperandType::Int32, rhsStrm.str());

	// const IOperand *res1 = *lhs + *rhs;
	// std::cout << lhs->toString() << " + " << rhs->toString() << " = " << res1->toString() << std::endl;

	// const IOperand *res2 = *lhs - *rhs;
	// std::cout << lhs->toString() << " - " << rhs->toString() << " = " << res2->toString() << std::endl;

	// const IOperand *res3 = *lhs * *rhs;
	// std::cout << lhs->toString() << " * " << rhs->toString() << " = " << res3->toString() << std::endl;

	// const IOperand *res4 = *lhs / *rhs;
	// std::cout << lhs->toString() << " / " << rhs->toString() << " = " << res4->toString() << std::endl;

	// const IOperand *res5 = *lhs % *rhs;
	// std::cout << lhs->toString() << " % " << rhs->toString() << " = " << res5->toString() << std::endl;

	Lexer	lexer;
	Parser	parser;
	Vm		vm;

	if (argc > 1) {
		if (!lexer.readFromFile(argv[1]))
			return 1;
	} else {
		if (!lexer.readFromStdin())
			return 1;
	}

	if (!parser.verifyGrammar(lexer.getTokenList()))
		return 1;

	if (!vm.run(lexer.getTokenList()))
		return 1;

	return 0;
}
