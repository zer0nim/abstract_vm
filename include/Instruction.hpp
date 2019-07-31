#ifndef INSTRUCTION_HPP
# define INSTRUCTION_HPP

# include "Token.hpp"
# include "Value.hpp"

enum eInstruction { Push, Pop, Dump, Assert, Add, Sub, Mul, Div, Mod, Print, Exit };

class Instruction : public Token {
	public:
		Instruction(int lineNb, eInstruction instruction, Value param);
		Instruction(Instruction const &src);
		virtual ~Instruction();

		Instruction &operator=(Instruction const &rhs);

		eInstruction	getInstruction() const;
		Value			getParam() const;
	private:
		Instruction();

		eInstruction	_instruction;
		Value			_param;
};

#endif
