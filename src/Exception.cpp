#include "Exception.hpp"

Exception::Exception() {
}

Exception::~Exception() {
}

const char* Exception::ErrorOpeningFile::what() const throw() {
    return ("Error while attempting to open file");
}
const char* Exception::UnknownInstruction::what() const throw() {
    return ("An instruction is unknown");
}


const char* Exception::ExitInstructionNotFound::what() const throw() {
    return ("The program doesn’t have an exit instruction");
}


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
