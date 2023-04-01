// fstream::open / fstream::close

#include <iostream>
#include "MyException.hpp"
#include "BitcoinExchange.hpp"
#include <fstream>


// note : the use of exception is not really usefull here. It was just for practice.

int	main (int ac, char **av)
{
	BitEx			BitEx;

	if (ac >= 2){
		BitEx.tryOpenFile(av[1]);
		BitEx.compute();
	}
	else {
		std::cout << "try again with correct imput" << std::endl;
	}
}



	// BitEx.compute();
	// else {
	// 	std::cout << "try again with correct imput" << std::endl;
	// }
