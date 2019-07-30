#ifndef OPERAND_HPP
# define OPERAND_HPP

# include "IOperand.hpp"
# include "Factory.hpp"
# include <string>
# include <iostream>
# include <sstream>
# include <math.h>

template<typename T>
class Operand : public IOperand {
	public:
		Operand<T>(Factory const &factory, eOperandType type, std::string value)
		: _factory(factory), _type(type), _value(value) {
		}

		Operand<T>(Operand const &src) {
			*this = src;
		}

		~Operand<T>() {
		}

		Operand	&operator=(Operand const &rhs) {
			if (this != &rhs) {
				_factory = rhs.getFactory();
				_type = rhs.getType();
				_value = rhs._value;
			}
			return *this;
		}

		Factory const	&getFactory() { return _factory; }

		// Precision of the type of the instance
		int getPrecision( void ) const {
			return static_cast<int>(_type);
		}

		// Type of the instance
		eOperandType getType( void ) const { return Int8; }



		// !!! NEED TO CHECK FOR !!!
		// • Overflow on a value
		// • Underflow on a value
		// • Division/modulo by 0

		// v____Operators _________________________________________________________

		// Sum
		IOperand const * operator+( IOperand const & rhs ) const {
			double lhsVal = std::stod(_value);
			double rhsVal = std::stod(rhs.toString());

			std::stringstream strm;
			strm << (lhsVal + rhsVal);

			eOperandType type = (getPrecision() >= rhs.getPrecision()) ? _type : rhs.getType();
			return _factory.createOperand(type, strm.str());
		}
		// Difference
		IOperand const * operator-( IOperand const & rhs ) const {
			double lhsVal = std::stod(_value);
			double rhsVal = std::stod(rhs.toString());

			std::stringstream strm;
			strm << (lhsVal - rhsVal);

			eOperandType type = (getPrecision() >= rhs.getPrecision()) ? _type : rhs.getType();
			return _factory.createOperand(type, strm.str());
		}
		// Product
		IOperand const * operator*( IOperand const & rhs ) const {
			double lhsVal = std::stod(_value);
			double rhsVal = std::stod(rhs.toString());

			std::stringstream strm;
			strm << (lhsVal * rhsVal);

			eOperandType type = (getPrecision() >= rhs.getPrecision()) ? _type : rhs.getType();
			return _factory.createOperand(type, strm.str());
		}
		// Quotient
		IOperand const * operator/( IOperand const & rhs ) const {
			double lhsVal = std::stod(_value);
			double rhsVal = std::stod(rhs.toString());

			std::stringstream strm;
			strm << (lhsVal / rhsVal);

			eOperandType type = (getPrecision() >= rhs.getPrecision()) ? _type : rhs.getType();
			return _factory.createOperand(type, strm.str());
		}
		// Modulo
		IOperand const * operator%( IOperand const & rhs ) const {
			double lhsVal = std::stod(_value);
			double rhsVal = std::stod(rhs.toString());

			std::stringstream strm;
			strm << fmod(lhsVal, rhsVal);

			eOperandType type = (getPrecision() >= rhs.getPrecision()) ? _type : rhs.getType();
			return _factory.createOperand(type, strm.str());
		}

		// ^____Operators _________________________________________________________


		// String representation of the instance
		std::string const & toString( void ) const { return _value; }

	private:
		Factory const	&_factory;
		eOperandType	_type;
		std::string		_value;
};

template <>
eOperandType Operand<int8_t>::getType( void ) const { return Int8; }
template <>
eOperandType Operand<int16_t>::getType( void ) const { return Int16; }
template <>
eOperandType Operand<int32_t>::getType( void ) const { return Int32; }
template <>
eOperandType Operand<float>::getType( void ) const { return Float; }
template <>
eOperandType Operand<double>::getType( void ) const { return Double; }

#endif
