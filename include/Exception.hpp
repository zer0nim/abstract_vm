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
				UnknownInstruction();
				UnknownInstruction(int nLineNb);
				UnknownInstruction(UnknownInstruction const &src);
				virtual ~UnknownInstruction();

				UnknownInstruction &operator=(UnknownInstruction const &rhs);

				virtual const char* what() const throw();

				int	lineNb;
		};


		// __ParserException_______________



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
	private:
		Exception();
		~Exception();
};

#endif
