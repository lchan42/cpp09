#include "PmergeMe.hpp"

int main (int ac, char *av[]){
	PmergeMe	p;

	// std::cout << "ac = " << ac << std::endl;
	if (ac >= 2)
		p.compute(av + 1);
	else
		std::cout << "programme needs at least 1 argument" << std::endl;
}

// shuf -i 1-100000 -n 3000
