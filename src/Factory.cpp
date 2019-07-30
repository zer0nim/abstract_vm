#include "Factory.hpp"
#include "Operand.hpp"
#include <sstream>

Factory::Factory() {
    _opFactory = {
        &Factory::createInt8,
        &Factory::createInt16,
        &Factory::createInt32,
        &Factory::createFloat,
        &Factory::createDouble
    };
}

Factory::Factory(Factory const &src) {
    *this = src;
}

Factory::~Factory() {
}

Factory &Factory::operator=(Factory const &rhs) {
    if (this != &rhs)
        ;
    return *this;
}

IOperand const * Factory::createInt8(std::string const & value) const {
    double numVal = std::stod(value);

    // check for overflow / underflow
    if (numVal > std::numeric_limits<int8_t>::max())
        throw Exception::OverflowValue();
    if (numVal < std::numeric_limits<int8_t>::lowest())
        throw Exception::UnderflowValue();

    int8_t convertVal = static_cast<int8_t>(numVal);

    std::stringstream strm;
	strm << +convertVal;

    return new Operand<int8_t>(*this, eOperandType::Int8, strm.str());
}
IOperand const * Factory::createInt16(std::string const & value) const {
    double numVal = std::stod(value);

    // check for overflow / underflow
    if (numVal > std::numeric_limits<int16_t>::max())
        throw Exception::OverflowValue();
    if (numVal < std::numeric_limits<int16_t>::lowest())
        throw Exception::UnderflowValue();

    int16_t convertVal = static_cast<int16_t>(numVal);
    std::stringstream strm;
	strm << convertVal;

    return new Operand<int16_t>(*this, eOperandType::Int16, strm.str());
}
IOperand const * Factory::createInt32(std::string const & value) const {
    double numVal = std::stod(value);

    // check for overflow / underflow
    if (numVal > std::numeric_limits<int32_t>::max())
        throw Exception::OverflowValue();
    if (numVal < std::numeric_limits<int32_t>::lowest())
        throw Exception::UnderflowValue();

    int32_t convertVal = static_cast<int32_t>(numVal);
    std::stringstream strm;
	strm << convertVal;

    return new Operand<int32_t>(*this, eOperandType::Int32, strm.str());
}
IOperand const * Factory::createFloat(std::string const & value) const {
    double numVal = std::stod(value);

    // check for overflow / underflow
    if (numVal > std::numeric_limits<float>::max())
        throw Exception::OverflowValue();
    if (numVal < std::numeric_limits<float>::lowest())
        throw Exception::UnderflowValue();

    float convertVal = static_cast<float>(numVal);
    std::stringstream strm;
	strm << convertVal;

    return new Operand<float>(*this, eOperandType::Float, strm.str());
}
IOperand const * Factory::createDouble(std::string const & value) const {
    double numVal = std::stod(value);

    std::stringstream strm;
	strm << numVal;

    return new Operand<double>(*this, eOperandType::Double, strm.str());
}

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const {
    CreationFunc func = _opFactory[ static_cast<int>(type) ];
    return (this->*func)(value);
}
