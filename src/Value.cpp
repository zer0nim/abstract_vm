#include "Value.hpp"

Value::Value() : _opType(eOperandType::Double), _data("0.0") {
}

Value::Value(eOperandType opType, std::string data)
: _opType(opType), _data(data) {
}

Value::Value(Value const &src) {
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
