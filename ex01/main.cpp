#include "RPN.hpp"

int main (int ac, char *av[]){
	rpn	myRpn;

	// std::cout << "ac = " << ac << std::endl;
	if (ac >= 2)
	{
		if (ac != 2) {
			std::cout << "there is more than one argument. only the first argument will be taken into account" << std::endl;
		}
		myRpn.compute(av[1]);
	}
	else {
		std::cout << "programme needs at least 1 argument" << std::endl;
	}
}
