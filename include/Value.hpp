#ifndef VALUE_HPP
# define VALUE_HPP

# include "IOperand.hpp"
# include <string>
# include <iostream>
# include <unordered_map>

class Value {
	public:
		Value();
		Value(eOperandType opType, std::string data);
		Value(Value const &src);
		virtual ~Value();

		Value &operator=(Value const &rhs);

		eOperandType	getOpType() const;
		std::string		getData() const;

		static std::unordered_map<int, std::string> operandMap;
	private:
		eOperandType	_opType;
		std::string		_data;
};

std::ostream & operator << (std::ostream &out, const Value &c);

#endif
