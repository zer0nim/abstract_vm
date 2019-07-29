#ifndef FACTORY_HPP
# define FACTORY_HPP

# include "IOperand.hpp"
# include <vector>

class Factory {
	public:
		Factory();
		Factory(Factory const &src);
		~Factory();

		Factory &operator=(Factory const &rhs);

		IOperand const * createOperand( eOperandType type, std::string const & value ) const;
	private:
		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;

		typedef IOperand const * (Factory::*CreationFunc)(std::string const & value) const;
		std::vector<CreationFunc> _opFactory;
};

#endif
