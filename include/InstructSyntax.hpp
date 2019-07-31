#ifndef INSTRUCTSYNTAX_HPP
# define INSTRUCTSYNTAX_HPP

# include "Token.hpp"
# include <string>

class InstructSyntax {
	public:
		InstructSyntax();
		InstructSyntax(std::string nRegex, bool nNeedParam, eInstruction nInstruction);
		InstructSyntax(InstructSyntax const &src);
		virtual ~InstructSyntax();

		InstructSyntax &operator=(InstructSyntax const &rhs);

		std::string		regex;
		bool			needParam;
		eInstruction	instruction;
};

#endif
