#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <cstdlib>
#include <algorithm>

#define VALID_DIGIT "0123456789"


typedef std::vector<int>::iterator	vecIterator;
typedef std::list<int>::iterator	listIterator;

class PmergeMe {
	private :
		bool				_parseFlag;
		std::list<int>		_list;
		std::vector<int>	_vector;

		/* parsing */
		void				_parse( char *tab[]);
		void				_checkNumber( const char *s);
		void				_addNumber(int n);

		/* algo */

		// void				_vectorInsertSort(std::vector<int> &v);
		// void				_listInsertSort(std::list<int> &l);
		template <typename STL>
		void				_InsertSort(STL &stl);
		template <typename STL>
		void				_InsertSortList(STL &stl);


	public:
		PmergeMe();
		PmergeMe(PmergeMe &rhs);
		~PmergeMe();

		PmergeMe& operator= (PmergeMe &rhs);

		void	compute(char *tab[]);
};


//debug functions
// typedef std::list<int>::iterator itL;
// typedef std::vector<int>::iterator itV;

template<typename T>
void	printStl(T stl){
	try {
		typename T::iterator	begin = stl.begin();
		typename T::iterator	end = stl.end();
		for (; begin != end; begin++)
			std::cout << *begin << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "print error" << std::endl;
	}
}


#endif
