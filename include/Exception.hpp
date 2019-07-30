#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP

# include <exception>

class Exception {
	public:
		class UnknownInstruction : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class OverflowValue : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class UnderflowValue : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class PopOnEmptyStack : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class DivideByZero : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class ExitInstructionNotFound : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FalseAssertion : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class needTwoValuesInStack : public std::exception {
			public:
				virtual const char* what() const throw();
		};
	private:
		Exception();
		~Exception();
};

#endif
