#include "PmergeMe.hpp"

int main (int ac, char *av[]){
	PmergeMe	p;

	if (ac >= 2)
		p.compute(av + 1);
	else
		std::cout << "programme needs at least 1 argument" << std::endl;
}

// make re && ./PmergeMe `shuf -i 1-100000 -n 5000 | tr "\n" " "`
// try algo with 3 2 9 8 7 10 4 5 5 1 does not work for the moment 
