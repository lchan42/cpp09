#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <iterator>

#define VALID_DIGIT "0123456789"
#define MERGE_LIM_HIGH 5


typedef std::vector<int>::iterator	vIt;
typedef std::list<int>::iterator	listIter;

class PmergeMe {
	private :
		bool				_parseFlag;
		std::list<int>		_list;
		std::vector<int>	_vector;

		/* parsing */
		void		_parse( char *tab[]);
		void		_checkNumber( const char *s);
		void		_addNumber(int n);

		/* list sort */
		void		_listInsertSort(std::list<int> &lst);
		void		_listMergeSort(std::list<int> &list1);
		void		_splitList(std::list<int> &list1 , std::list<int> &list2);
		void		_mergeList(std::list<int> &list1 , std::list<int> &list2);

		/* list vector */
		void		_vectorInsertSort(std::vector<int> &v);
		void		_vectorMergeSort(std::vector<int> &v);
		void		_splitVector(std::vector<int> &v1, std::vector<int> &v2);
		void		_mergeVector(std::vector<int> &v1, std::vector<int> &v2);

		/* tool */
		listIter	_listIterPrev(listIter it);


		// template <typename STL>
		// void				_InsertSortList(STL &stl);





		// template <typename STL>
		// void				_InsertSort(STL &stl);



		/* vector sort */


	public:
		PmergeMe();
		PmergeMe(PmergeMe &rhs);
		~PmergeMe();

		PmergeMe& operator= (PmergeMe &rhs);

		void	compute(char *tab[]);
};


// cmd : make re && ./PmergeMe `shuf -i 1-100000 -n 5000 | tr "\n" " "`

//debug functions
// typedef std::list<int>::iterator itL;
// typedef std::vector<int>::iterator itV;

template<typename T>
void	printStl(T stl){
	try {
		typename T::iterator	begin = stl.begin(), end = stl.end();;

		for (; begin != end; begin++)
			std::cout << *begin << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "print error" << std::endl;
	}
}


#endif
