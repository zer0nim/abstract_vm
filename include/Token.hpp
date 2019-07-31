#ifndef TOKEN_HPP
# define TOKEN_HPP

class Token {
	public:
		Token(int lineNb);
		Token(Token const &src);
		virtual ~Token();

		Token &operator=(Token const &rhs);

		int	getLineNb() const;
	private:
		Token();

		int	_lineNb;
};

#endif
