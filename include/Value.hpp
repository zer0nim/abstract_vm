#ifndef VALUE_HPP
# define VALUE_HPP

# include "Token.hpp"
# include "IOperand.hpp"
# include <string>

class Value : public Token {
	public:
		Value(int lineNb, eOperandType opType, std::string data);
		Value(Value const &src);
		virtual ~Value();

		Value &operator=(Value const &rhs);

		eOperandType	getOpType() const;
		std::string		getData() const;
	private:
		Value();

		eOperandType	_opType;
		std::string		_data;
};

#endif
