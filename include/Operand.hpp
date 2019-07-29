#ifndef OPERAND_HPP
# define OPERAND_HPP

# include "IOperand.hpp"
# include "Factory.hpp"
# include <string>

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
			if (this != &rhs)
				_value = rhs._value;
			return *this;
		}

		// Precision of the type of the instance
		int getPrecision( void ) const {
			return static_cast<int>(_type);
		}

		// Type of the instance
		eOperandType getType( void ) const { return Int8; }

		// Sum
		IOperand const * operator+( IOperand const & rhs ) const {
			eOperandType type = (getPrecision() >= rhs.getPrecision()) ? _type : rhs.getType();
			return _factory.createOperand(type, "42");
		}
		// Difference
		IOperand const * operator-( IOperand const & rhs ) const {
			eOperandType type = (getPrecision() >= rhs.getPrecision()) ? _type : rhs.getType();
			return _factory.createOperand(type, "42");
		}
		// Product
		IOperand const * operator*( IOperand const & rhs ) const {
			eOperandType type = (getPrecision() >= rhs.getPrecision()) ? _type : rhs.getType();
			return _factory.createOperand(type, "42");
		}
		// Quotient
		IOperand const * operator/( IOperand const & rhs ) const {
			eOperandType type = (getPrecision() >= rhs.getPrecision()) ? _type : rhs.getType();
			return _factory.createOperand(type, "42");
		}
		// Modulo
		IOperand const * operator%( IOperand const & rhs ) const {
			eOperandType type = (getPrecision() >= rhs.getPrecision()) ? _type : rhs.getType();
			return _factory.createOperand(type, "42");
		}

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
