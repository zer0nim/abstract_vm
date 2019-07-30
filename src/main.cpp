#include <iostream>
#include "Factory.hpp"
#include "IOperand.hpp"

int main(void) {
	Factory factory;
	const IOperand *lhs = factory.createOperand(Int8, "43");
	const IOperand *rhs = factory.createOperand(Int8, "2");

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
