#include "Value.hpp"

Value::Value() : Token(-1) {
}

Value::Value(int lineNb, eOperandType opType, std::string data)
: Token(lineNb), _opType(opType), _data(data) {
}

Value::Value(Value const &src) : Token(src) {
	*this = src;
}

Value::~Value() {
}

Value &Value::operator=(Value const &rhs) {
	if (this != &rhs) {
		_opType = rhs.getOpType();
		_data = rhs.getData();
	}
	return *this;
}

eOperandType	Value::getOpType() const { return _opType; }
std::string		Value::getData() const { return _data; }
