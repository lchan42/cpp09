#include "RPN.hpp"

rpn::rpn() {/*std::cout << "rpn constructor called"<<std::endl;*/}

rpn::rpn(rpn &cpy) : _myStack(cpy._myStack) { /*std::cout << "rpn copy constructor called" << std::endl;*/}

rpn& rpn::operator=(const rpn &rhs) {_myStack = rhs._myStack; return *this;}

rpn::~rpn(){ /*std::cout << "rpn destructor called" << std::endl; */}

void	rpn::compute(char *s){

	char *token;

	token = strtok(s, " ");
	while (token != NULL){
		try {
			_dealWithToken(token);
		}
		catch (std::exception &e) {
			std::cout << "error: " << e.what() << std::endl;
			return;
		}
		token = strtok(NULL, " ");
	}
	_printResult();
}

bool	rpn::_isOperator(const char c){
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
}

void	rpn::_execOpe(const char c){

	int	ope1, ope2;

	ope1 = _myStack.top();
	_myStack.pop();
	ope2 = _myStack.top();
	_myStack.pop();
	switch (c)
	{
		case '+':
			_myStack.push(ope2 + ope1);
			break;
		case '-':
			_myStack.push(ope2 - ope1);
			break;
		case '*':
			_myStack.push(ope2 * ope1);
			break;
		case '/':
			if (ope1 == 0)
				throw std::invalid_argument(ERR_TOKEN_DIVZERO);
			_myStack.push(ope2 / ope1);
			break;
	}
}

void	rpn::_dealWithToken(const std::string &str){
	if (str.find_first_not_of(VALID_CHAR) != std::string::npos)
		throw std::invalid_argument(ERR_TOKEN_CHAR(str));
	else if (str.size() > 1)
		throw std::invalid_argument(ERR_TOKEN_SIZE(str));
	else if (_isOperator(str[0])) {
		if (_myStack.size() < 2)
			throw std::invalid_argument(ERR_TOKEN_OPE(str));
		else
			_execOpe(str[0]);
	}
	else if (std::isdigit(str[0])){
		_myStack.push(atoi(str.c_str()));
	}
}

void	rpn::_printResult(){
	if (_myStack.size() > 1)
		std::cout << NOTE_MORE_OPERANDES;
	while (_myStack.size() > 0) {
		std:: cout << _myStack.top();
		_myStack.pop();
		if (_myStack.size() > 0)
			std::cout << " ";
	}
	std::cout << std::endl;
}
