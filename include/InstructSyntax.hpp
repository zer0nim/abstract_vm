#ifndef INSTRUCTSYNTAX_HPP
# define INSTRUCTSYNTAX_HPP

# include "Token.hpp"
# include "IOperand.hpp"
# include <string>
# include <vector>
# include <tuple>

class InstructSyntax {
	public:
		InstructSyntax();
		InstructSyntax(std::string nName, bool nNeedParam, eInstruction nInstruction);
		InstructSyntax(InstructSyntax const &src);
		virtual ~InstructSyntax();

		InstructSyntax &operator=(InstructSyntax const &rhs);

		std::string		name;
		bool			needParam;
		eInstruction	instruction;

		bool	createToken(int nb, std::string line, Token	&token) const;
	private:
		static std::vector< std::tuple<std::string, eOperandType> >	_opTypes;
};

#endif
