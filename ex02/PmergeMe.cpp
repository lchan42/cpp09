#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _parseFlag(0) { std::cout << "constructor called" << std::endl; }

PmergeMe::PmergeMe(PmergeMe &rhs) : _parseFlag(rhs._parseFlag), _initialList(rhs._initialList), _list(rhs._list), _vector(rhs._vector), _lTime(rhs._lTime), _vTime(rhs._vTime) { std::cout << "constructor called" << std::endl; }

PmergeMe::~PmergeMe() { std::cout << "destructor called" << std::endl; }

PmergeMe& PmergeMe::operator= (PmergeMe &rhs)
{
	std::cout << "operator = called" << std::endl;
	_parseFlag		= rhs._parseFlag;
	_initialList	= rhs._initialList;
	_list			= rhs._list;
	_vector			= rhs._vector;
	_lTime			= rhs._lTime;
	_vTime			= rhs._vTime;

	return *this;
}

void	PmergeMe::compute(char *tab[])
{
	try {
		_parse(tab);
		_parseFlag = true;
	}
	catch (std::exception &e) {
		std::cout << "error : " << e.what() << std::endl;
	}
	if (_parseFlag) {

		// std::cout << "before : "; printStl(_vector); std::cout << std::endl;
		_getTime(_lTime);
		_listMergeSort(_list);
		_timeDiff(_lTime);
		_getTime(_vTime);
		_vectorMergeInsertSort(_vector.begin(), _vector.end());
		// _vectorMergeSort(_vector);
		_timeDiff(_vTime);
		_printResult();
	}
}

void	PmergeMe::_printResult() {
	timeval	test;

	std::cout << "before : "; printStl(_initialList);
	std::cout << "after : "; printStl (_vector);
	std::cout << "Time to process a range of " << _list.size() << " elements with std::list : " << _lTime.tv_sec * 1000000 + _lTime.tv_usec << " us" <<  std::endl;
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << _vTime.tv_sec * 1000000 + _vTime.tv_usec << " us" << std::endl;

	/** to check the  */
	// _getTime(test);
	// std::sort(_initialList.begin(), _initialList.end());
	// _timeDiff(test);
	// std::cout << "Time to process a vector of " << _initialList.size() << " elements with std::sort : " << test.tv_sec * 1000000 + test.tv_usec << " us" <<  std::endl;

	// _getTime(test);
	// _initialList2.sort();
	// _timeDiff(test);
	// std::cout << "Time to process a list of " << _initialList.size() << " elements with std::sort : " << test.tv_sec * 1000000 + test.tv_usec << " us" <<  std::endl;

	_checkResult();
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
	_initialList = _vector;
	_initialList2 = _list;
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

void	PmergeMe::_getTime(timeval &startTime){
	gettimeofday(&startTime, NULL);
}

void	PmergeMe::_timeDiff(timeval &startTime){
	timeval endTime;
	gettimeofday(&endTime, NULL);

	startTime.tv_sec = endTime.tv_sec - startTime.tv_sec;
	startTime.tv_usec = endTime.tv_usec - startTime.tv_usec;
}

/****************** vector sort ******************/

// void	PmergeMe::_vectorMergeSort (std::vector<int> &v1)
// {
// 	std::vector<int>	v2;
// 	std::vector<int>	v3;

// 	if (v1.size() > VEC_MERGE_LIM_HIGH) {
// 		_splitVector(v1, v2, v3);
// 		_vectorMergeSort(v2);
// 		_vectorMergeSort(v3);

// 		// _vectorInsertSort(v1);
// 		_vectorInsertSort(v2);
// 		_vectorInsertSort(v3);
// 		_mergeVector(v1, v2, v3);
// 	}
// 	else
// 		_vectorInsertSort(v1);

// }

// void	PmergeMe::_splitVector(std::vector<int> &v1, std::vector<int> &v2, std::vector<int> &v3)
// {
// 	int	halfSize = v1.size() / 2;

// 	v2.assign(v1.begin() + halfSize, v1.end());
// 	v3.assign(v1.begin(), v1.begin() + halfSize);
// }

// void	PmergeMe::_mergeVector(std::vector<int> &v1, std::vector<int> &v2, std::vector<int> &v3)
// {
// 	unsigned long int i = 0, j = 0 , k = 0;

// 	for (; i < v1.size() && j < v2.size() && k < v3.size(); ++i) {
// 		if (v2[j] >= v3[k]) {
// 			v1[i] = v3[k++];
// 		}
// 		else if (v2[j] <= v3[k]) {
// 			v1[i] = v2[j++];
// 		}
// 	}
// 	if (i < v1.size()) {
// 		while (j < v2.size())
// 			v1[i++] = v2[j++];
// 		while (k < v3.size())
// 			v1[i++] = v3[k++];
// 	}
// }

// void	PmergeMe::_vectorInsertSort(std::vector<int> &v)
// {
// 	int	tmpVal;
// 	vIt	it1, insertPos;

// 	for (it1 = v.begin(); it1 != v.end(); it1++)
// 	{
// 		tmpVal = *it1;
// 		insertPos = std::upper_bound(v.begin(), it1, tmpVal);
// 		if (insertPos != it1 && it1 != v.end()) {
// 			v.erase(it1);
// 			v.insert(insertPos, tmpVal);
// 		}
// 	}
// }

// void	PmergeMe::_vectorMergeInsertSort ()
// {

// 	// std::vector<vIt>::iterator	start, end;

// 	if (_vector.size() > VEC_MERGE_LIM_HIGH){
// 		std::vector<vIt>	cuts;

// 		_splitVector(cuts, _vector.size());
// 		for (long long int i = 0, j = i + 1; j <= cuts.size(); ++i, ++j){
// 			_vectorInsertSort(cuts[i], cuts[j]);
// 		}
// 		_vectorMerge(cuts);
// 	}
// 	else
// 		_vectorInsertSort(_vector.begin(), _vector.end());
// }

void	PmergeMe::_vectorMergeInsertSort (vIt const & start, vIt const & end) {
	if (distance(start, end) > VEC_MERGE_LIM_HIGH){
		vIt	mid = start + distance(start, end) / 2;
		_vectorMergeInsertSort(start, mid);
		_vectorMergeInsertSort(mid, end);
		_vectorMerge(start, mid, end);
	}
	else {
		_vectorInsertSort(start, end);
	}
}

void	PmergeMe::_vectorMerge(vIt const &start, vIt const &mid, vIt const &end){
	int	tmpVal;
	vIt	insertPos = start, candidate = mid;
	for (int i = 0; i < distance(start, end); ++i){
		if (*insertPos > *candidate){
			std::cout << "distance = " << distance(start, end) << std::endl;
			tmpVal = *candidate;
			_vector.erase(candidate);
			_vector.insert(insertPos, tmpVal);
			++candidate;
		}
		else
			++insertPos;
	}
}

// void	PmergeMe::_splitVector(std::vector<vIt> & cuts, long long int const vSize)
// {
// 	for (long long int	i = 0; i < vSize / VEC_MERGE_LIM_HIGH; ++i)
// 		cuts[i] = _vector.begin() + VEC_MERGE_LIM_HIGH * i;
// 	if (vSize % VEC_MERGE_LIM_HIGH)
// 		cuts.push_back(_vector.end());
// 	cuts.insert(cuts.begin(), _vector.begin());
// }

void	PmergeMe::_vectorInsertSort(vIt const &start, vIt const &end)
{
	int	tmpVal;
	vIt	it1, insertPos;

	for (it1 = start; it1 != end; it1++)
	{
		tmpVal = *it1;
		insertPos = std::upper_bound(start, it1, tmpVal);
		if (insertPos != it1 && it1 != end) {
			_vector.erase(it1);
			_vector.insert(insertPos, tmpVal);
		}
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

	if (list1.size() > LIST_MERGE_LIM_HIGH) {
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


/******************* old version of vector MergeInsert ********************/

// void	PmergeMe::_vectorMergeSort (std::vector<int> &v1)
// {
// 	std::vector<int>	v2;

// 	if (v1.size() > VEC_MERGE_LIM_HIGH) {
// 		_splitVector(v1, v2);
// 		_vectorMergeSort(v1);
// 		_vectorMergeSort(v2);
// 	}
// 	_vectorInsertSort(v1);
// 	_vectorInsertSort(v2);
// 	_mergeVector(v1, v2);
// }

// void	PmergeMe::_splitVector(std::vector<int> &v1, std::vector<int> &v2)
// {
// 	int	halfSize = v1.size() / 2;

// 	v2.assign(v1.begin() + halfSize, v1.end());
// 	v1.erase(v1.begin() + halfSize, v1.end());
// }

// void	PmergeMe::_mergeVector(std::vector<int> &v1, std::vector<int> &v2)
// {
// 	vIt	it1 = v1.begin();
// 	for (long unsigned int i = 0; i < v2.size(); ++i) {
// 		while (it1 != v1.end() && v2[i] > *it1)
// 			it1++;
// 		v1.insert(it1, v2[i]);
// 	}
// }
