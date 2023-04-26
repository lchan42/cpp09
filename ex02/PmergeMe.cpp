#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _parseFlag(0) { std::cout << "constructor called" << std::endl; }

PmergeMe::PmergeMe(PmergeMe &rhs)
	:	_parseFlag(rhs._parseFlag), _initialList(rhs._initialList), _initialVector(rhs._initialVector),
		_list(rhs._list), _vector(rhs._vector),
		_lTime(rhs._lTime), _vTime(rhs._vTime)
		{ std::cout << "constructor called" << std::endl; }

PmergeMe::~PmergeMe() { std::cout << "destructor called" << std::endl; }

PmergeMe& PmergeMe::operator= (PmergeMe &rhs)
{
	std::cout << "operator = called" << std::endl;
	_parseFlag		= rhs._parseFlag;
	_initialList	= rhs._initialList;
	_initialVector	= rhs._initialVector;
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
		_getTime(_lTime);
		_listMergeSort(_list);
		_timeDiff(_lTime);
		_getTime(_vTime);
		_vectorMergeInsertSort(_vector, _vector.begin(), _vector.end() - 1);
		_timeDiff(_vTime);
		_printResult();
	}
}

void	PmergeMe::_printResult()
{
	timeval				compTime;
	std::list<int>		initialL;
	std::vector<int>	initialV;

	std::cout << "before : "; printStl(_initialList);
	std::cout << "after : "; printStl (_list);

	std::cout	<< "Time to process a range of " << _list.size()
				<< " elements with std::list : " << _lTime.tv_sec * 1000000 + _lTime.tv_usec
				<< " us" <<  std::endl;

	std::cout	<< "Time to process a range of " << _vector.size()
				<< " elements with std::vector : " << _vTime.tv_sec * 1000000 + _vTime.tv_usec
				<< " us" << std::endl;

	/** to compare with other sorting algo */
	std::cout << std::endl; std::cout << std::endl;
	std::cout << "this part is not asked by subject. It shows the sort time of the same list but with container 's methods" << std::endl;

	std::cout << std::endl;
	initialL = _initialList;
	_getTime(compTime);
	initialL.sort();
	_timeDiff(compTime);
	std::cout << "Sort list " << initialL.size() << " with std::sort : " << compTime.tv_sec * 1000000 + compTime.tv_usec << " us" <<  std::endl;

	// initialL = _initialList;
	// _getTime(compTime);
	// _listMergeSort(initialL);
	// _timeDiff(compTime);
	// std::cout << "Sort list " << initialL.size() << " with MyListSort : " << compTime.tv_sec * 1000000 + compTime.tv_usec << " us" <<  std::endl;

	initialV = _initialVector;
	_getTime(compTime);
	std::sort(initialV.begin(), initialV.end());
	_timeDiff(compTime);
	std::cout << "Sort vector " << initialV.size() << " with std::sort : " << compTime.tv_sec * 1000000 + compTime.tv_usec << " us" <<  std::endl;

	// initialV = _initialVector;
	// _getTime(compTime);
	// _vectorMergeInsertSort(initialV, initialV.begin(), initialV.end() - 1);
	// _timeDiff(compTime);
	// std::cout << "Sort vector " << initialV.size() << " with MyVectorSort : " << compTime.tv_sec * 1000000 + compTime.tv_usec << " us" <<  std::endl;

	// initialV = _initialVector;
	// _getTime(compTime);
	// _vectorMergeInsertSort2(initialV);
	// _timeDiff(compTime);
	// std::cout << "Sort vector " << initialV.size() << " with MyVectorSort2 : " << compTime.tv_sec * 1000000 + compTime.tv_usec << " us" <<  std::endl;

	/* check if sort is correct */
	// _checkResult();
}

/****************** parsing ******************/
void	PmergeMe::_parse(char *tab[])
{
	int			i = 0;

	while (tab[i] != NULL)
	{
		_checkNumber(tab[i]);
		_addNumber(std::atoi(tab[i]));
		i++;
	}
	_initialVector = _vector;
	_initialList = _list;
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

void	printItRange(vIt const  start, vIt const  end){
	vIt it = start;

	while (it <= end) {
		std::cout << *it << " ";
		it ++;
	}
	std::cout << std::endl;
}

void	PmergeMe::_vectorMergeInsertSort (vecInt & v, vIt const & start, vIt const & end) {
	if (distance(start, end) > VEC_MERGE_LIM_HIGH){
		vIt	mid = start + (distance(start, end) )/ 2;
		_vectorMergeInsertSort(v, start, mid);
		_vectorMergeInsertSort(v, mid + 1, end);
		_vectorMerge(v, start, mid, end);
	}
	else {
		_vectorInsertSort(v, start, end);
	}
}

void	PmergeMe::_vectorMerge(vecInt & v, vIt const &start, vIt const & mid, vIt const &end){
	int	tmpVal;
	vIt	insertPos = start, candidate = mid + 1;

	while (candidate <= end && candidate !=insertPos) {
		if (*insertPos > *candidate){
			tmpVal = *candidate;
			v.erase(candidate++);
			v.insert(insertPos++, tmpVal);
		}
		else
			++insertPos;
	}
	/**note : using upper_bound function is supprisingly not faster than iterator++ */
	// int	tmpVal;
	// vIt	insertPos;

	// for (vIt it1 = mid + 1; it1 <= end; ++it1)
	// {
	// 	tmpVal = *it1;
	// 	insertPos = std::upper_bound(start, it1, tmpVal);
	// 	if (insertPos != it1) {
	// 		_vector.erase(it1);
	// 		_vector.insert(insertPos, tmpVal);
	// 	}
	// }
}

void	PmergeMe::_vectorInsertSort(vecInt & v ,vIt const &start, vIt const &end)
{
	int	tmpVal;
	vIt	it1, insertPos;

	for (it1 = start; it1 <= end; ++it1)
	{
		tmpVal = *it1;
		insertPos = std::upper_bound(start, it1, tmpVal);
		if (insertPos != it1) {
			v.erase(it1);
			v.insert(insertPos, tmpVal);
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
	if (flag == true && _list.size() == _vector.size()) {
		std::cout << "both list are sorted" << std::endl;
	}
}


/******************* version1 of vector MergeInsert ********************/

// void	PmergeMe::_vectorMergeSort (std::vector<int> &v1)
// {
// 	std::vector<int>	v2;

// 	if (v1.size() > VEC_MERGE_LIM_HIGH) {
// 		_splitVector(v1, v2);
// 		_vectorMergeSort(v1);
// 		_vectorMergeSort(v2);
// 	}
// 	_vectorInsertSort2(v1);
// 	_vectorInsertSort2(v2);
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

/******************* version2 of vector MergeInsert ********************/

// void	PmergeMe::_vectorMergeInsertSort2 (std::vector<int> &v1)
// {
// 	std::vector<int>	v2;
// 	std::vector<int>	v3;

// 	if (v1.size() > VEC_MERGE_LIM_HIGH) {
// 		_splitVector2(v1, v2, v3);
// 		_vectorMergeInsertSort2(v2);
// 		_vectorMergeInsertSort2(v3);

// 		// _vectorInsertSort(v1);
// 		_vectorInsertSort2(v2);
// 		_vectorInsertSort2(v3);
// 		_vectorMerge2(v1, v2, v3);
// 	}
// 	else
// 		_vectorInsertSort2(v1);

// }

// void	PmergeMe::_splitVector2(std::vector<int> &v1, std::vector<int> &v2, std::vector<int> &v3)
// {
// 	int	halfSize = v1.size() / 2;

// 	v2.assign(v1.begin() + halfSize, v1.end());
// 	v3.assign(v1.begin(), v1.begin() + halfSize);
// }

// void	PmergeMe::_vectorMerge2(std::vector<int> &v1, std::vector<int> &v2, std::vector<int> &v3)
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

// void	PmergeMe::_vectorInsertSort2(std::vector<int> &v)
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
