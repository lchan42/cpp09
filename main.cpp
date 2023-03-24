// fstream::open / fstream::close
#include <fstream>      // std::fstream
#include <iostream>
#include "MyException.hpp"


// #define _RPL_OPENFILE (path) path + ": open success"
#define _RPL_OPENFILE(path) ("" + path + ": open success")
#define _ERR_OPENFILE (path) ("fail to open [" + path + "]")


// void	checkline () {

// }

// note : apparenylt we have to go through a string to use the define forme _RPL_OPENFILE(path)
void	openFile (const char *path) {

	std::fstream	fs(path);
	std::string		tmp(path);
	// const char*		msg2 = msg.c_str();

	if (fs.is_open()) {
		std::cout << _RPL_OPENFILE(tmp) << std::endl;
	// } else {
	// 	throw MyException((_ERR_OPENFILE(tmp)).c_str());
	// }
}

int	main (int ac, char **av) {
	try {
		openFile("data.csv");
	}
	catch (std::exception &e) {
		std::cout << "error: "<< e.what() << std::endl;
		return (false);
	}
	return (true);
}




// int main (int ac, char **av) {

// 	// std::fstream	fs(av[1]);
// 	std::fstream	fs("data.csv");
// 	std::string		line;

// 	// fs.open ("data.csv", std::fstream::in | std::fstream::out | std::fstream::app);
// 	if (fs.is_open()){
// 		// while(getline (file, line))
// 		std::cout << "open success" << std::endl;
// 		line << fs.rdbuf();
// 		fs.close();
// 	}
// 	else {
// 		std::cout << "open error" << std::endl;
// 	}
// 	return 0;
// }
