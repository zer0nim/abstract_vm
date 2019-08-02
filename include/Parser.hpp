#ifndef PARSER_HPP
# define PARSER_HPP

# include "Token.hpp"
# include <vector>

class Parser {
	public:
		Parser();
		Parser(Parser const &src);
		virtual ~Parser();

		Parser &operator=(Parser const &rhs);

		bool	verifyGrammar(std::vector<Token> tokenList) const;
	private:
};

#endif
