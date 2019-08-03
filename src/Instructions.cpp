#include "Instructions.hpp"
#include "Exception.hpp"
#include <string>

// • add: Unstacks the first two values on the stack, adds them together and stacks the
// result. If the number of values on the stack is strictly inferior to 2, the program
// execution must stop with an error.
void	instrAdd(Factory &factory, std::vector<IOperand const *> &stack, Value *param) {
	(void)factory; // unused param
	(void)param; // unused param

	if (stack.size() < 2)
		throw Exception::needTwoValuesInStack();

	IOperand const *rhs = stack.back();
	stack.pop_back();
	IOperand const *lhs = stack.back();
	stack.pop_back();

	stack.push_back(*lhs + *rhs);
}

// • assert v: Asserts that the value at the top of the stack is equal to the one passed
// as parameter for this instruction. If it is not the case, the program execution must
// stop with an error. The value v has the same form that those passed as parameters
// to the instruction push.
void	instrAssert(Factory &factory, std::vector<IOperand const *> &stack, Value *param) {
	(void)factory; // unused param

	IOperand const *top = stack.back();

	if (top->toString() != param->getData())
		throw Exception::FalseAssertion();
}

// • div: Unstacks the first two values on the stack, divides them, then stacks the result.
// If the number of values on the stack is strictly inferior to 2, the program execution
// must stop with an error. Moreover, if the divisor is equal to 0, the program execution
// must stop with an error too. Chatting about floating point values is relevant a this
// point. If you don’t understand why, some will understand. The linked question is
// an open one, there’s no definitive answer.
void	instrDiv(Factory &factory, std::vector<IOperand const *> &stack, Value *param) {
	(void)factory; // unused param
	(void)param; // unused param

	if (stack.size() < 2)
		throw Exception::needTwoValuesInStack();

	IOperand const *rhs = stack.back();
	stack.pop_back();
	IOperand const *lhs = stack.back();
	stack.pop_back();

	stack.push_back(*lhs / *rhs);
}

// • dump: Displays each value of the stack, from the most recent one to the oldest
// one WITHOUT CHANGING the stack. Each value is separated from the next one
// by a newline.
void	instrDump(Factory &factory, std::vector<IOperand const *> &stack, Value *param) {
	(void)factory; // unused param
	(void)param; // unused param

	for (auto it = stack.rbegin(); it != stack.rend(); ++it)
		std::cout << (*it)->toString() << std::endl;
}

// • exit: Terminate the execution of the current program. If this instruction does not
// appears while all others instruction has been processed, the execution must stop
// with an error.
void	instrExit(Factory &factory, std::vector<IOperand const *> &stack, Value *param) {
	(void)factory; // unused param
	(void)param; // unused param
	(void)stack; // unused param
}

// • mod: Unstacks the first two values on the stack, calculates the modulus, then
// stacks the result. If the number of values on the stack is strictly inferior to 2, the
// program execution must stop with an error. Moreover, if the divisor is equal to 0,
// the program execution must stop with an error too. Same note as above about fp
// values.
void	instrMod(Factory &factory, std::vector<IOperand const *> &stack, Value *param) {
	(void)factory; // unused param
	(void)param; // unused param

	if (stack.size() < 2)
		throw Exception::needTwoValuesInStack();

	IOperand const *rhs = stack.back();
	stack.pop_back();
	IOperand const *lhs = stack.back();
	stack.pop_back();

	stack.push_back(*lhs % *rhs);
}

// • mul: Unstacks the first two values on the stack, multiplies them, then stacks the
// result. If the number of values on the stack is strictly inferior to 2, the program
// execution must stop with an error.
void	instrMul(Factory &factory, std::vector<IOperand const *> &stack, Value *param) {
	(void)factory; // unused param
	(void)param; // unused param

	if (stack.size() < 2)
		throw Exception::needTwoValuesInStack();

	IOperand const *rhs = stack.back();
	stack.pop_back();
	IOperand const *lhs = stack.back();
	stack.pop_back();

	stack.push_back(*lhs * *rhs);
}

// • pop: Unstacks the value from the top of the stack. If the stack is empty, the
// program execution must stop with an error.
void	instrPop(Factory &factory, std::vector<IOperand const *> &stack, Value *param) {
	(void)factory; // unused param
	(void)param; // unused param

	if (stack.empty())
		throw Exception::PopOnEmptyStack();

	stack.pop_back();
}

// • print: Asserts that the value at the top of the stack is an 8-bit integer. (If not,
// see the instruction assert), then interprets it as an ASCII value and displays the
// corresponding character on the standard output.
void	instrPrint(Factory &factory, std::vector<IOperand const *> &stack, Value *param) {
	(void)factory; // unused param
	(void)param; // unused param

	IOperand const *top = stack.back();

	if (top->getType() != eOperandType::Int8)
		throw Exception::FalseAssertion();

	char c = static_cast<char>(std::stod(top->toString()));
	std::cout << c << std::endl;
}

// • push v: Pushes the value v at the top of the stack. The value v must have one of
// the following form:
// ◦ int8(n) : Creates an 8-bit integer with value n.
// ◦ int16(n) : Creates a 16-bit integer with value n.
// ◦ int32(n) : Creates a 32-bit integer with value n.
// ◦ float(z) : Creates a float with value z.
// ◦ double(z) : Creates a double with value z.
void	instrPush(Factory &factory, std::vector<IOperand const *> &stack, Value *param) {
	stack.push_back(factory.createOperand(param->getOpType(), param->getData()));
}

// • sub: Unstacks the first two values on the stack, subtracts them, then stacks the
// result. If the number of values on the stack is strictly inferior to 2, the program
// execution must stop with an error.
void	instrSub(Factory &factory, std::vector<IOperand const *> &stack, Value *param) {
	(void)factory; // unused param
	(void)param; // unused param

	if (stack.size() < 2)
		throw Exception::needTwoValuesInStack();

	IOperand const *rhs = stack.back();
	stack.pop_back();
	IOperand const *lhs = stack.back();
	stack.pop_back();

	stack.push_back(*lhs - *rhs);
}
