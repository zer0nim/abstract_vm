#ifndef LEXER_HPP
# define LEXER_HPP

# include "Token.hpp"
# include "Value.hpp"
# include "Exception.hpp"
# include "InstructSyntax.hpp"
# include <vector>

class Lexer {
	public:
		Lexer();
		Lexer(Lexer const &src);
		virtual ~Lexer();

		Lexer &operator=(Lexer const &rhs);

		std::vector<Token> getTokenListCopy() const;
		std::vector<Token> &getTokenList();

		void	parseLine(std::string line, int nb);
		bool	readFromFile(std::string filename);
		bool	readFromStdin();
	private:
		std::vector<Token> _tokenList;
		std::vector<InstructSyntax>	_instructsSyntax;
};

#endif
