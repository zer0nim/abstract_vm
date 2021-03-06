#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP

# include <exception>

class Exception {
	public:
		// exception category
		class LexerException : public std::exception {};
		class ParserException : public std::exception {};
		class RuntimeException : public std::exception {};

		// __LexerException________________

		class UnknownInstruction : public LexerException {
			public:
				virtual const char* what() const throw();
		};


		// __ParserException_______________

		class InstrTakeParam : public ParserException {
			public:
				virtual const char* what() const throw();
		};
		class InstrDontTakeParam : public ParserException {
			public:
				virtual const char* what() const throw();
		};

		// __RuntimeException______________

		class OverflowValue : public RuntimeException {
			public:
				virtual const char* what() const throw();
		};
		class UnderflowValue : public RuntimeException {
			public:
				virtual const char* what() const throw();
		};
		class PopOnEmptyStack : public RuntimeException {
			public:
				virtual const char* what() const throw();
		};
		class DivideByZero : public RuntimeException {
			public:
				virtual const char* what() const throw();
		};
		class FalseAssertion : public RuntimeException {
			public:
				virtual const char* what() const throw();
		};
		class needTwoValuesInStack : public RuntimeException {
			public:
				virtual const char* what() const throw();
		};
		class EmptyStack : public RuntimeException {
			public:
				virtual const char* what() const throw();
		};
		class NeedInteger : public RuntimeException {
			public:
				virtual const char* what() const throw();
		};
	private:
		Exception();
		~Exception();
};

#endif
