#include "Factory.hpp"
#include "Operand.hpp"

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

// !!! NEED TO CONVERT TO THE APROPRIATE TYPE !!!
// !!! WARNING ! NEED TO CHECK FOR !!!
// • Overflow on a value
// • Underflow on a value

// char	Convert::toChar(double val) {
// 	if (val > std::numeric_limits<char>::max() || val < std::numeric_limits<char>::min() || std::isnan(val) || std::isinf(val))
// 		throw ImpossibleConversion();
// 	return static_cast<char>(val);
// }
// int		Convert::toInt(double val) {
// 	if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min() || std::isnan(val) || std::isinf(val))
// 		throw ImpossibleConversion();
// 	return static_cast<int>(val);
// }
// float	Convert::toFloat(double val) {
// 	if (val > std::numeric_limits<float>::max())
// 		return std::numeric_limits<float>::infinity();
// 	return static_cast<float>(val);
// }

IOperand const * Factory::createInt8( std::string const & value ) const {
    return new Operand<int8_t>(*this, Int8, value);
}
IOperand const * Factory::createInt16( std::string const & value ) const {
    return new Operand<int16_t>(*this, Int16, value);
}
IOperand const * Factory::createInt32( std::string const & value ) const {
    return new Operand<int32_t>(*this, Int32, value);
}
IOperand const * Factory::createFloat( std::string const & value ) const {
    return new Operand<float>(*this, Float, value);
}
IOperand const * Factory::createDouble( std::string const & value ) const {
    return new Operand<double>(*this, Double, value);
}

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const {
    CreationFunc func = _opFactory[ static_cast<int>(type) ];
    return (this->*func)(value);
}
