#ifndef LEXER_HPP
# define LEXER_HPP

# include "Token.hpp"
# include "Value.hpp"
# include "Exception.hpp"
# include <vector>
# include <string>

class Lexer {
	public:
		Lexer();
		Lexer(Lexer const &src);
		virtual ~Lexer();

		Lexer &operator=(Lexer const &rhs);

		std::vector<Token> getTokenListCopy() const;
		std::vector<Token> &getTokenList();

		void	parseLine(std::string line, int lineNb);
		bool	readFromFile(std::string filename);
		bool	readFromStdin();
	private:
		std::vector<Token>			_tokenList;
		static std::vector<std::string>	_instrsNames;
		static std::vector<std::string>	_valuesSyntax;

		bool	createToken(int lineNb, eInstruction instr, std::string line, Token	&token);
};

#endif
