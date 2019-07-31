#ifndef LEXER_HPP
# define LEXER_HPP

# include "Token.hpp"
# include "Value.hpp"
# include "Exception.hpp"
# include "InstructSyntax.hpp"
# include <queue>
# include <vector>

class Lexer {
	public:
		Lexer();
		Lexer(Lexer const &src);
		virtual ~Lexer();

		Lexer &operator=(Lexer const &rhs);

		std::queue<Token> getTokenListCopy() const;
		std::queue<Token> &getTokenList();

		void	parseLine(std::string line, int nb);
		void	readFromFile(std::string filename);
		void	readFromStdin();
	private:
		std::queue<Token> _tokenList;
		std::vector<InstructSyntax>	_instructsSyntax;
};

#endif
