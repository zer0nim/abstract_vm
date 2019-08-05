#ifndef VM_HPP
# define VM_HPP

# include "Token.hpp"
# include "IOperand.hpp"
# include "Instructions.hpp"
# include <vector>

class Vm {
	public:
		Vm();
		Vm(Vm const &src);
		virtual ~Vm();

		Vm &operator=(Vm const &rhs);

		std::vector<IOperand const *>	getStack() const;

		bool	run(std::vector<Token> &tokenList, bool verbose);
		void	syntaxHighlight(std::vector<Token> &tokenList);
	private:
		std::vector<IOperand const *>	_stack;
		static std::vector<InstrFunc>	_instrFuncs;
		Factory							_factory;
};

#endif
