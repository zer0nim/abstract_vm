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

IOperand const * Factory::createInt8( std::string const & value ) const {
    return new Operand<int8_t>(*this, Int8, value);
}
IOperand const * Factory::createInt16( std::string const & value ) const {
    return new Operand<int8_t>(*this, Int16, value);
}
IOperand const * Factory::createInt32( std::string const & value ) const {
    return new Operand<int8_t>(*this, Int32, value);
}
IOperand const * Factory::createFloat( std::string const & value ) const {
    return new Operand<int8_t>(*this, Float, value);
}
IOperand const * Factory::createDouble( std::string const & value ) const {
    return new Operand<int8_t>(*this, Double, value);
}

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const {
    CreationFunc func = _opFactory[ static_cast<int>(type) ];
    return (this->*func)(value);
}
