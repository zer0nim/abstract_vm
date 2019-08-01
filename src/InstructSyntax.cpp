#include "InstructSyntax.hpp"
#include <iostream>
#include <regex>

std::vector< std::tuple<std::string, eOperandType> >	InstructSyntax::_opTypes = {
	{"double\\(([-]?[0-9]+.[0-9]+)\\)", eOperandType::Double},
	{"float\\(([-]?[0-9]+.[0-9]+)\\)", eOperandType::Float},
	{"int32\\(([-]?[0-9]+)\\)", eOperandType::Int32},
	{"int16\\(([-]?[0-9]+)\\)", eOperandType::Int16},
	{"int8\\(([-]?[0-9]+)\\)", eOperandType::Int8}
};

InstructSyntax::InstructSyntax()
: name(""), needParam(false), instruction(eInstruction::Add) {
}

InstructSyntax::InstructSyntax(std::string nName, bool nNeedParam, eInstruction nInstruction)
: name(nName), needParam(nNeedParam), instruction(nInstruction) {
}

InstructSyntax::InstructSyntax(InstructSyntax const &src) {
	*this = src;
}

InstructSyntax::~InstructSyntax() {
}

InstructSyntax &InstructSyntax::operator=(InstructSyntax const &rhs) {
	if (this != &rhs) {
		name = rhs.name;
		needParam = rhs.needParam;
		instruction = rhs.instruction;
	}
	return *this;
}

bool	InstructSyntax::createToken(int nb, std::string line, Token	&token) const {
	std::string	space = "[^\\S\\r\\n]*";
	std::string	regexStr = "^" + space + name + space + "(;.*)?$";

	// without param:
	if (!needParam && std::regex_match(line, std::regex(regexStr))) {
		token = Token(nb, instruction, nullptr);
		return true;
	} // with param:
	else if (needParam) {
		std::cmatch m;	// used to get the diferents parts of the match

		// test different types of value (int32, float, ...)
		for (auto it = InstructSyntax::_opTypes.begin(); it != InstructSyntax::_opTypes.end(); ++it) {
			regexStr = "^" + space + name + space + std::get<0>(*it) + space + "(;.*)?$";
			if (std::regex_match(line.c_str(), m, std::regex(regexStr))) {
				token = Token(nb, instruction, new Value(std::get<1>(*it), m[1]));
				return true;
			}
		}
	}
	return false;
}
