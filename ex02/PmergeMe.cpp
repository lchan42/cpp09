#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { std::cout << "constructor called" << std::endl; }

PmergeMe::PmergeMe(PmergeMe &rhs) : _parseFlag(rhs._parseFlag), _list(rhs._list), _vector(rhs._vector) { std::cout << "constructor called" << std::endl; }

PmergeMe::~PmergeMe() { std::cout << "destructor called" << std::endl; }

PmergeMe& PmergeMe::operator= (PmergeMe &rhs)
{
	std::cout << "operator = called" << std::endl;
	_parseFlag = rhs._parseFlag;
	_list		= rhs._list;
	_vector		= rhs._vector;

	return *this;
}

void	PmergeMe::compute(char *tab[])
{
	try {
		_parse(tab);
	}
	catch (std::exception &e) {
		std::cout << "error : " << e.what() << std::endl;
	}
}


/****************** parsing ******************/
void	PmergeMe::_parse(char *tab[])
{
	int			i = 0;
	int			n;

	while (tab[i] != NULL)
	{
		_checkNumber(tab[i]);
		_addNumber(std::atoi(tab[i]));
		i++;
	}

	_listMergeSort(_list);
	_vectorMergeSort(_vector);
	// printStl(_vector);
	// printStl(_list);
	// _parseFlag = true;
	// _InsertSort<std::vector<int> >(_vector);
	// std::cout << "result for list : " << std::endl;


	// _InsertSort<std::list<int> >(_list);
	// std::cout << "result for vector : " << std::endl;
	// printStl(_vector);


	//_listInsertSort(_list);
	//printStl(_list);
	// std::cout << "final result for vector : " << std::endl;
	// printStl(_vector);
	_checkResult();
}

void	PmergeMe::_checkNumber(const char *s)
{
	std::string	str(s);

	if (str.find_first_not_of(VALID_DIGIT) != std::string::npos)
		throw std::invalid_argument("\"" + str + "\"" + " : has invalid char.");
	else if (str.size() > 10 || std::atol(s) > INT_MAX)
		throw std::invalid_argument("\"" + str + "\"" + " : val must be between 0 and 2147483647");
}

void	PmergeMe::_addNumber(int n)
{
	_list.push_back(n);
	_vector.push_back(n);
}

/****************** vector sort ******************/

void	PmergeMe::_vectorMergeSort (std::vector<int> &v1)
{
	std::vector<int>	v2;

	if (v1.size() > MERGE_LIM_HIGH) {
		_splitVector(v1, v2);
		_vectorMergeSort(v1);
		_vectorMergeSort(v2);
	}
	_vectorInsertSort(v1);
	_vectorInsertSort(v2);
	_mergeVector(v1, v2);
}

void	PmergeMe::_vectorInsertSort(std::vector<int> &v)
{
	int	tmpVal;
	vIt	it1, insertPos;

	for (it1 = v.begin(); it1 != v.end(); it1++)
	{
		tmpVal = *it1;
		insertPos = std::upper_bound(v.begin(), it1, tmpVal);
		if (insertPos != it1 && it1 != v.end()) {
			v.erase(it1);
			v.insert(insertPos, tmpVal);
		}
	}
}

void	PmergeMe::_splitVector(std::vector<int> &v1, std::vector<int> &v2)
{
	int	halfSize = v1.size() / 2;

	v2.assign(v1.begin() + halfSize, v1.end());
	v1.erase(v1.begin() + halfSize, v1.end());
}

void	PmergeMe::_mergeVector(std::vector<int> &v1, std::vector<int> &v2)
{
	vIt	it1 = v1.begin();
	for (long unsigned int i = 0; i < v2.size(); ++i) {
		while (it1 != v1.end() && v2[i] > *it1)
			it1++;
		v1.insert(it1, v2[i]);
	}
}

/****************** list sort ******************/

void	PmergeMe::_listInsertSort(std::list<int> &lst)
{
	int	tmpVal;

	for (listIter it1 = lst.begin(); it1 != lst.end(); it1++)
	{
		if (it1 != lst.begin() && *it1 < *(_listIterPrev(it1)))
		{
			for (listIter it2 = lst.begin(); it2 != it1; it2++){
				tmpVal = *it1;
				if (*it2 > *it1){
					lst.splice(it2, lst, it1);
					break;
				}
			}
		}
	}
}

void	PmergeMe::_listMergeSort (std::list<int> &list1)
{
	std::list<int>	list2;

	if (list1.size() > MERGE_LIM_HIGH) {
		_splitList(list1, list2);
		_listMergeSort(list1);
		_listMergeSort(list2);
	}
	_listInsertSort(list1);
	_listInsertSort(list2);
	_mergeList(list1, list2);
}

void	PmergeMe::_splitList(std::list<int> &list1 , std::list<int> &list2)
{
	listIter	halfPosition = list1.begin();

	std::advance(halfPosition, list1.size()/2);
	list2.splice(list2.begin(), list1, list1.begin(), halfPosition);
}

void	PmergeMe::_mergeList(std::list<int> &list1, std::list<int> &list2)
{
	listIter	it1 = list1.begin(), it2;

	while (list2.size() > 0)
	{
		it2 = list2.begin(); //according to c++ref, call to splice makes it2 invalide
		while (*it1 < *it2 && it1 != list1.end()){
			it1++;
		}
		list1.splice(it1, list2, it2);
	}
}

/****************** tool ******************/
listIter	PmergeMe::_listIterPrev(listIter it) {return (--it);}

/******************* checker *******************/
void	PmergeMe::_checkResult()
{
	bool		flag = true;
	listIter	l1 = _list.begin(), l2 = l1;
	int			j = 0;

	/* to test if checker is working or not **************/
		// _vector[_list.size() / 2] -= 10000;
		// std::advance(l1, _list.size() / 2); *l1 -= 10000;
	 /*****************************************************/

	for (l1 = _list.begin(), l2++; l2 != _list.end(); l2++){
		if (*l1 > *l2) {
			std::cout << "error in list, ite1 = " << *l1 << " > ite2 = " << *l2 << std::endl;
			flag = false;
		}
	}
	for (long unsigned int i = 1; i < _vector.size(); i++){
		j = i - 1;
		if (_vector[i] < _vector[j]) {
			std::cout << "error in vector, v[" << j << "] = " << _vector[j] << " > v[" << i << "] = " << _vector[i] << std::endl;
			flag = false;
		}
	}
	if (flag == true) {
		std::cout << "both list are sorted" << std::endl;
	}
}
