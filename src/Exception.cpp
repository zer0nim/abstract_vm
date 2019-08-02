#include "Exception.hpp"
#include <string>

Exception::Exception() {
}

Exception::~Exception() {
}


// __LexerException________________

const char* Exception::ErrorOpeningFile::what() const throw() {
    return ("Error while attempting to open file");
}

Exception::UnknownInstruction::UnknownInstruction()
: lineNb(-1) {
}

Exception::UnknownInstruction::UnknownInstruction(int nLineNb)
: lineNb(nLineNb) {
}

Exception::UnknownInstruction::UnknownInstruction(UnknownInstruction const &src) {
    *this = src;
}

Exception::UnknownInstruction::~UnknownInstruction() {
}

Exception::UnknownInstruction &Exception::UnknownInstruction::operator=(UnknownInstruction const &rhs) {
    if (this != &rhs)
        lineNb = rhs.lineNb;
    return *this;
}

const char* Exception::UnknownInstruction::what() const throw() {
    return ("Line " + std::to_string(lineNb) + " : Error : An instruction is unknown").c_str();
}


// __ParserException_______________

const char* Exception::ExitInstructionNotFound::what() const throw() {
    return ("The program doesn’t have an exit instruction");
}
const char* Exception::UnreachableCode::what() const throw() {
    return ("Unreachable code after the exit instruction");
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
