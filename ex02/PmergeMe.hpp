#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <sys/time.h>
#include <ctime>

#define VALID_DIGIT "0123456789"
#define LIST_MERGE_LIM_HIGH 30
#define VEC_MERGE_LIM_HIGH 1500



typedef std::vector<int>::iterator	vIt;
typedef std::list<int>::iterator	listIter;

class PmergeMe {
	private :
		/* variables */
		bool				_parseFlag;
		std::vector<int>	_initialList;
		std::list<int>		_initialList2;
		std::list<int>		_list;
		std::vector<int>	_vector;
		timeval				_lTime;
		timeval				_vTime;


		/* parsing */
		void		_parse( char *tab[]);
		void		_checkNumber( const char *s);
		void		_addNumber(int n);

		/* std::list sort */
		void		_listInsertSort(std::list<int> &lst);
		void		_listMergeSort(std::list<int> &list1);
		void		_splitList(std::list<int> &list1 , std::list<int> &list2);
		void		_mergeList(std::list<int> &list1 , std::list<int> &list2);

		/* std::vector sort */
		/* algo 3 single vector */
		void	_vectorMergeInsertSort (vIt const & start, vIt const & end);
		void	_splitVector(std::vector<vIt> & cuts, long long int const size);
		void	_vectorInsertSort(vIt const &start, vIt const &end);
		void	_vectorMerge(vIt const & start, vIt const & mid, vIt const & end);

		/* tools */
		listIter	_listIterPrev(listIter it);
		void	_getTime(timeval &startTime);
		void	_timeDiff(timeval &startTime);
		void	_printResult();

		/* checker*/
		void		_checkResult();

	public:
		PmergeMe();
		PmergeMe(PmergeMe &rhs);
		~PmergeMe();

		PmergeMe&	operator= (PmergeMe &rhs);
		void		compute(char *tab[]);
};

//debug functions
template<typename T>
void	printStl(T stl){
	try {
		typename T::iterator	begin = stl.begin(), end = stl.end();;
		if (!stl.size())
			std::cout << "empty stl";
		else
			for (; begin != end; begin++)
				std::cout << *begin << " ";
	}
	catch (std::exception &e) {
		std::cout << "print error" << std::endl;
	}
	std::cout << std::endl;
}

#endif


		/* algo 2 better split and merge vector */
		// void		_vectorInsertSort(std::vector<int> &v);
		// void		_vectorMergeSort(std::vector<int> &v);
		// void		_splitVector(std::vector<int> &v1, std::vector<int> &v2, std::vector<int> &v3);
		// void		_mergeVector(std::vector<int> &v1, std::vector<int> &v2, std::vector<int> &v3);

		/** algo 1 time for 3000 : */
		// void		_splitVector(std::vector<int> &v1, std::vector<int> &v2);
		// void		_mergeVector(std::vector<int> &v1, std::vector<int> &v2);
