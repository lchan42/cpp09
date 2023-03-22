// fstream::open / fstream::close
#include <fstream>      // std::fstream
#include <iostream>

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


int main (int ac, char **av) {
	try {
		
	}
	catch (std::exception &e) {
		std::cout << "error: "<< e.what() << std::endl;
		return (false);
	}
	return (true);
}
