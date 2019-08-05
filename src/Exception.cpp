#include "Exception.hpp"
#include <string>

Exception::Exception() {
}

Exception::~Exception() {
}


// __LexerException________________

const char* Exception::UnknownInstruction::what() const throw() {
    return ("An instruction is unknown");
}


// __ParserException_______________

const char* Exception::InstrTakeParam::what() const throw() {
    return ("The instruction need a parameter");
}
const char* Exception::InstrDontTakeParam::what() const throw() {
    return ("The instruction don't take parameter");
}

// __RuntimeException______________

const char* Exception::OverflowValue::what() const throw() {
    return ("Overflow on a value");
}
const char* Exception::UnderflowValue::what() const throw() {
    return ("Underflow on a value");
}
const char* Exception::PopOnEmptyStack::what() const throw() {
    return ("Instruction pop on an empty stack");
}
const char* Exception::DivideByZero::what() const throw() {
    return ("Division/modulo by 0");
}
const char* Exception::FalseAssertion::what() const throw() {
    return ("An assert instruction is not true");
}
const char* Exception::needTwoValuesInStack::what() const throw() {
    return ("The stack is composed of strictly less that two values when an arithmetic instruction is executed.");
}
const char* Exception::EmptyStack::what() const throw() {
    return ("Instruction need at least one value in the stack");
}
const char* Exception::NeedInteger::what() const throw() {
    return ("Instruction need an integer type");
}
