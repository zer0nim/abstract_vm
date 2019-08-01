#include "Value.hpp"

// used to print enum name
std::unordered_map<int, std::string> Value::operandMap = {
	{eOperandType::Int8, "Int8"},
	{eOperandType::Int16, "Int16"},
	{eOperandType::Int32, "Int32"},
	{eOperandType::Float, "Float"},
	{eOperandType::Double, "Double"}
};

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

std::ostream & operator << (std::ostream &out, const Value &c) {
	out << "{ opType: " << Value::operandMap[c.getOpType()]
		<< ", data: " << c.getData()
		<< " }";

	return out;
}
