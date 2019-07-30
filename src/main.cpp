#include <iostream>
#include <limits>
#include <sstream>
#include <cmath>
#include "Factory.hpp"
#include "IOperand.hpp"
#include "Exception.hpp"

int main(void) {
	double lhsVal = 43;
	double rhsVal = 2;

	std::stringstream lhsStrm, rhsStrm;
	lhsStrm << lhsVal;
	rhsStrm << rhsVal;

	Factory factory;
	const IOperand *lhs = factory.createOperand(eOperandType::Int32, lhsStrm.str());
	const IOperand *rhs = factory.createOperand(eOperandType::Int32, rhsStrm.str());

	const IOperand *res1 = *lhs + *rhs;
	std::cout << lhs->toString() << " + " << rhs->toString() << " = " << res1->toString() << std::endl;

	const IOperand *res2 = *lhs - *rhs;
	std::cout << lhs->toString() << " - " << rhs->toString() << " = " << res2->toString() << std::endl;

	const IOperand *res3 = *lhs * *rhs;
	std::cout << lhs->toString() << " * " << rhs->toString() << " = " << res3->toString() << std::endl;

	const IOperand *res4 = *lhs / *rhs;
	std::cout << lhs->toString() << " / " << rhs->toString() << " = " << res4->toString() << std::endl;

	const IOperand *res5 = *lhs % *rhs;
	std::cout << lhs->toString() << " % " << rhs->toString() << " = " << res5->toString() << std::endl;

	return 0;
}
