#include "InstructSyntax.hpp"

InstructSyntax::InstructSyntax()
: regex(""), needParam(false), instruction(eInstruction::Add) {
}

InstructSyntax::InstructSyntax(std::string nRegex, bool nNeedParam, eInstruction nInstruction)
: regex(nRegex), needParam(nNeedParam), instruction(nInstruction) {
}

InstructSyntax::InstructSyntax(InstructSyntax const &src) {
	*this = src;
}

InstructSyntax::~InstructSyntax() {
}

InstructSyntax &InstructSyntax::operator=(InstructSyntax const &rhs) {
	if (this != &rhs) {
		regex = rhs.regex;
		needParam = rhs.needParam;
		instruction = rhs.instruction;
	}
	return *this;
}
