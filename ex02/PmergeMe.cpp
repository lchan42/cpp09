#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
	std::cout << "constructor called" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe &rhs){
	std::cout << "constructor called" << std::endl;
}

PmergeMe::~PmergeMe() {
	std::cout << "destructor called" << std::endl;
}

PmergeMe& PmergeMe::operator= (PmergeMe &rhs){
	std::cout << "operator = called" << std::endl;
	_parseFlag = rhs._parseFlag;
	_list		= rhs._list;
	_vector		= rhs._vector;

	return *this;
}




void	PmergeMe::compute(char *tab[]){
	try {
		_parse(tab);
	}
	catch (std::exception &e) {
		std::cout << "error :" << e.what() << std::endl;
	}
}

void	PmergeMe::_parse(char *tab[]){
	int			i = 0;
	int			n;

	while (tab[i] != NULL)
	{
		_checkNumber(tab[i]);
		_addNumber(std::atoi(tab[i]));
		i++;
	}
}

void	PmergeMe::_checkNumber(const char *s) {
	std::string	str(s);

	if (str.find_first_not_of(VALID_DIGIT) != std::string::npos)
		throw std::invalid_argument(str + " invalid char.");
	else if (std::atol(s) > INT_MAX)
		throw std::invalid_argument(str + "val must be a positive int.");
}

void	PmergeMe::_addNumber(int n) {
	_list.push_back(n);
	_vector.push_back(n);
}




