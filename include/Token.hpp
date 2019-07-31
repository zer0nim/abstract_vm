#ifndef TOKEN_HPP
# define TOKEN_HPP

# include "Value.hpp"

enum eInstruction { Add, Assert, Div, Dump, Exit, Mod, Mul, Pop, Print, Push, Sub };

class Token {
	public:
		Token(int lineNb, eInstruction instruction, Value *param);
		Token(Token const &src);
		virtual ~Token();

		Token &operator=(Token const &rhs);

		eInstruction	getInstruction() const;
		int				getLineNb() const;
		const Value		*getParam() const;
	private:
		Token();

		eInstruction	_instruction;
		Value			*_param;
		int				_lineNb;
};

#endif
