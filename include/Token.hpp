#ifndef TOKEN_HPP
# define TOKEN_HPP

# include "Value.hpp"
# include <iostream>

enum eInstruction { Add, Assert, Div, Dump, Exit, Mod, Mul, Pop, Print, Push, Sub };

class Token {
	public:
		Token();
		Token(int lineNb, eInstruction instruction, Value *param);
		Token(Token const &src);
		virtual ~Token();

		Token &operator=(Token const &rhs);

		eInstruction	getInstruction() const;
		int				getLineNb() const;
		const Value		*getParam() const;

		static std::unordered_map<int, std::string> instructMap;
	private:
		int				_lineNb;
		eInstruction	_instruction;
		Value			*_param;
};

std::ostream & operator << (std::ostream &out, const Token &c);

#endif
