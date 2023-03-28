// fstream::open / fstream::close

#include <iostream>
#include "MyException.hpp"
#include "BitcoinExchange.hpp"
#include <fstream>

#define _RPL_OPENFILE(path) std::string(path) + ": open success"
#define _ERR_OPENFILE(path) "fail to open " + std::string(path)

// note : the use of exception is not really usefull here. It was just for practice.

void	openFile (const char *path, std::ifstream &fs)
{
	fs.open(path);
	if (fs.is_open()) {
		std::cout << _RPL_OPENFILE(path) << std::endl;
	} else {
		throw MyException(_ERR_OPENFILE(path));
	}
}

void	closeFile(std::ifstream &fs)
{
	if (fs.is_open()){
		fs.close();
	}
}

bool	TryOpenFiles(const char *path, std::ifstream &fs1, std::ifstream &fs2)
{
	try {
		openFile("data.csv", fs1);
		openFile(path, fs2);
	}
	catch (std::exception &e) {
		std::cout << "error: "<< e.what() << std::endl;
		closeFile(fs1);
		closeFile(fs2);
		return (false);
	}
	return (true);
}

int	main (int ac, char **av)
{
	std::ifstream	fs1, fs2;

	if (ac >= 2 && TryOpenFiles(av[1], fs1, fs2)){
		std::cout << "try again with correct imput" << std::endl;

	}
}

	// // BitEx			BitEx;
	// BitEx.setFstreams(fs1, fs2);

	// BitEx.compute();
	// else {
	// 	std::cout << "try again with correct imput" << std::endl;
	// }
