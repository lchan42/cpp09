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
		std::cout << "error : " << e.what() << std::endl;
	}
	// sort
}


/****************** parsing ******************/
void	PmergeMe::_parse(char *tab[]){
	int			i = 0;
	int			n;

	while (tab[i] != NULL)
	{
		_checkNumber(tab[i]);
		_addNumber(std::atoi(tab[i]));
		i++;
	}
	printStl(_vector);
	// printStl(_list);
	_parseFlag = true;
	_InsertSort<std::vector<int> >(_vector);
	_InsertSort<std::list<int> >(_list);
	std::cout << "result for vector : " << std::endl;
	printStl(_vector);
	std::cout << "result for list : " << std::endl;
	printStl(_list);


}

void	PmergeMe::_checkNumber(const char *s) {
	std::string	str(s);

	// std::cout << "str = " << str << std::endl;

	if (str.find_first_not_of(VALID_DIGIT) != std::string::npos)
		throw std::invalid_argument("\"" + str + "\"" + " : has invalid char.");
	else if (str.size() > 10 || std::atol(s) > INT_MAX)
		throw std::invalid_argument("\"" + str + "\"" + " : val must be between 0 and 2147483647");
}

void	PmergeMe::_addNumber(int n) {
	_list.push_back(n);
	_vector.push_back(n);
}

/****************** insert sort ******************/

// void	PmergeMe::_vectorInsertSort(std::vector<int> &v) {
// 	int	i = 0, j, tmpVal;

// 	for (; i < v.size(); i++)
// 	{
// 		j = i + 1;
// 		tmpVal = v[j];
// 		while (j > 0 && v[j - 1] > tmpVal)
// 			j--;
// 		if (j != i + 1)
// 		{
// 			v.erase(v.begin() + i);
// 			v.insert(v.begin() + j, tmpVal);
// 		}
// 	}
// }

// void	PmergeMe::_listInsertSort(std::list<int> &list) {
// 	int				tmpVal;
// 	listIterator	it2, tmp;

// 	for (listIterator it1 = list.begin(); it1 != list.end(); it1++)
// 	{
// 		it2 = it1;
// 		tmp = ++it2;
// 		tmpVal = *tmp;
// 		do
// 			it2--;
// 		while (it2 != list.begin() && *(it2) > *(tmp));
// 		if (it2 != it1)
// 		{
// 			list.erase(tmp);
// 			list.insert(it2, tmpVal);
// 		}
// 	}
// }

template <typename STL>
void	PmergeMe::_InsertSort(STL &stl)
{
	int						tmpVal;
	typename STL::iterator	it1, it2, insertPos;

	std::cout << "here, end = " << *(stl.end()) << std::endl;
	for (it1 = stl.begin(); it1 != stl.end(); it1++)
	{
		it2 = it1;
		it2++;
		if (it2 == stl.end()) break;
		tmpVal = *it2;
		insertPos = std::upper_bound(stl.begin(), it2, tmpVal);
		if (it2 != insertPos) {
			stl.erase(it2);
			stl.insert(insertPos, tmpVal);
		}
	}
}

// template <typename STL>
// void	PmergeMe::_InsertSortList(STL &stl){
// 	int						tmpVal;
// 	typename STL::iterator	it1, it2, insertPos;

// 	for (it1 = stl.begin(); it1 != stl.end(); it1++)
// 	{
// 		it2 = it1;
// 		it2++;
// 		if (it2 == stl.end()) break;
// 		tmpVal = *it2;
// 		insertPos = std::upper_bound(stl.begin(), it2, tmpVal);
// 		std::cout << "for val = " << *it2 << "insertPos = : "<< *insertPos << std::endl;
// 		if (it2 != insertPos) {
// 			stl.erase(it2);
// 			stl.insert(insertPos, tmpVal);
// 		}
// 	}
// }

	// std::cout << "initial list = "<< std::endl; printStl(_vector); std::cout << " ------------------"<< std::endl;

	// std::cout << "list is now equal too : "<< std::endl; printStl(_vector); std::cout << " ------------------"<< std::endl;
