#ifndef OPERAND_HPP
# define OPERAND_HPP

# include "Exception.hpp"
# include "IOperand.hpp"
# include "Factory.hpp"
# include <string>
# include <iostream>
# include <sstream>
# include <math.h>
# include <limits>

enum eOperationType { Add, Sub, Mul, Div, Mod };

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

		// v____Operators _________________________________________________________

		// Sum
		IOperand const * operator+( IOperand const & rhs ) const {
			return doOperation(*this, rhs, eOperationType::Add);
		}
		// Difference
		IOperand const * operator-( IOperand const & rhs ) const {
			return doOperation(*this, rhs, eOperationType::Sub);
		}
		// Product
		IOperand const * operator*( IOperand const & rhs ) const {
			return doOperation(*this, rhs, eOperationType::Mul);
		}
		// Quotient
		IOperand const * operator/( IOperand const & rhs ) const {
			return doOperation(*this, rhs, eOperationType::Div);
		}
		// Modulo
		IOperand const * operator%( IOperand const & rhs ) const {
			return doOperation(*this, rhs, eOperationType::Mod);
		}

		// ^____Operators _________________________________________________________


		// String representation of the instance
		std::string const & toString( void ) const { return _value; }

	private:
		Factory const	&_factory;
		eOperandType	_type;
		std::string		_value;

		IOperand const * doOperation(IOperand const & lhs, IOperand const & rhs, eOperationType opType) const {
			double lhsVal = std::stod(lhs.toString());
			double rhsVal = std::stod(rhs.toString());

			// check for '/' or '%' by 0
			if ((opType == eOperationType::Div || opType == eOperationType::Mod) &&
			rhsVal == 0) {
				throw Exception::DivideByZero();
			}

			// do the operation
			long double res;
			switch (opType) {
				case eOperationType::Add:
					res = lhsVal + rhsVal;
					break;
				case eOperationType::Sub:
					res = lhsVal - rhsVal;
					break;
				case eOperationType::Mul:
					res = lhsVal * rhsVal;
					break;
				case eOperationType::Div:
					res = lhsVal / rhsVal;
					break;
				case eOperationType::Mod:
					res = fmod(lhsVal, rhsVal);
					break;
			}

			// check for overflow / underflow
			if (res > std::numeric_limits<double>::max())
				throw Exception::OverflowValue();
			if (res < std::numeric_limits<double>::lowest())
				throw Exception::UnderflowValue();

			// convert to string and call the Operand factory
			std::stringstream strm;
			strm << res;
			eOperandType resType = (lhs.getPrecision() >= rhs.getPrecision()) ? lhs.getType() : rhs.getType();
			return _factory.createOperand(resType, strm.str());
		}
};

template <>
eOperandType Operand<int8_t>::getType( void ) const { return eOperandType::Int8; }
template <>
eOperandType Operand<int16_t>::getType( void ) const { return eOperandType::Int16; }
template <>
eOperandType Operand<int32_t>::getType( void ) const { return eOperandType::Int32; }
template <>
eOperandType Operand<float>::getType( void ) const { return eOperandType::Float; }
template <>
eOperandType Operand<double>::getType( void ) const { return eOperandType::Double; }

#endif
