#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string.h>
# include <string>
# include <stdio.h>
# include <exception>
# include <cstdlib>

# define VALID_CHAR "0123456789+-*/"
# define ERR_TOKEN_SIZE(str) "invalid argument: \""+ str + "\" numbers cant exceed 10 and each element must be space separated"
# define ERR_TOKEN_CHAR(str) "invalid char: \"" + str + "\""
# define ERR_TOKEN_DIVZERO "error, invalid division"
# define ERR_TOKEN_OPE(str) "invalid operators: \"" + str + "\" operator must be preceed my at least 2 operandes"
# define NOTE_MORE_OPERANDES "argument has more operandes than operators, partial result: "

class rpn {
	private :
		void	_printResult();
		void	_execOpe(const char c);
		void	_dealWithToken(const std::string &str);
		bool	_isOperator(const char c);

		std::stack<int>	_myStack;

	public:
		rpn();
		rpn(rpn &cpy);
		~rpn();
		rpn&	operator=(const rpn &rhs);

		void compute(char *str);
};

#endif
