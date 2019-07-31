#ifndef VALUE_HPP
# define VALUE_HPP

# include "IOperand.hpp"
# include <string>

class Value {
	public:
		Value();
		Value(eOperandType opType, std::string data);
		Value(Value const &src);
		virtual ~Value();

		Value &operator=(Value const &rhs);

		eOperandType	getOpType() const;
		std::string		getData() const;
	private:
		eOperandType	_opType;
		std::string		_data;
};

#endif
