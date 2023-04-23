#include "PmergeMe.hpp"

int main (int ac, char *av[]){
	PmergeMe	p;

	if (ac >= 2)
		p.compute(av + 1);
	else
		std::cout << "programme needs at least 1 argument" << std::endl;
	// for (int i = 1; av[i] != NULL; i++)
	// 	std::cout << av[i] << " ";
}

// make re && ./PmergeMe `shuf -i 1-100000 -n 5000 | tr "\n" " "`
