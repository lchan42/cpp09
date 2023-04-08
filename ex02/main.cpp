#include "PmergeMe.hpp"

int main (int ac, char *av[]){
	PmergeMe	p;

	// std::cout << "ac = " << ac << std::endl;
	if (ac >= 2)
	{
		if (ac != 2) {
			std::cout << "there is more than one argument. only the first argument will be taken into account" << std::endl;
		}
		p.compute(av);
	}
	else {
		std::cout << "programme needs at least 1 argument" << std::endl;
	}
}

// shuf -i 1-100000 -n 3000
