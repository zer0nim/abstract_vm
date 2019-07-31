#ifndef LEXER_HPP
# define LEXER_HPP

# include "Token.hpp"
# include <queue>

class Lexer {
	public:
		Lexer();
		Lexer(Lexer const &src);
		virtual ~Lexer();

		Lexer &operator=(Lexer const &rhs);

		std::queue<Token> getTokenListCopy() const;
		std::queue<Token> &getTokenList();
	private:
		std::queue<Token> _tokenList;
};

#endif
