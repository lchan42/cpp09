#include "BitcoinExchange.hpp"
#include "MyException.hpp"

BitEx::BitEx() {
	std::cout << "BitEx constructor called" << std::endl;
	std::cout << "BitEx needs at least an entryFile " << std::endl;
}

BitEx::BitEx(std::string inputPath) {
	std::cout << "BitEx constructor called" << std::endl;
}

BitEx::BitEx(std::fstream fs1, std::fstream fs2) : _fsData(fs1), _fsInFile(fs2){
	std::cout << "BitEx constructor called" << std::endl;
}
		// BitEx(BitEx const &cpy);

BitEx::~BitEx() {
	_closeFiles();
	std::cout << "BitEx destructor called" << std::endl;
}

		// BitEx & operator=(BitEx const &rhs);

void	BitEx::_closeFiles()
{
	if (_fsData.is_open()){
		_fsData.close();
	}
	if (_fsInFile.is_open()){
		_fsInFile.close();
	}
}

// void	BitEx::openFile(){
// 		std::fstream	fs(path);

// 	if (fs.is_open()) {
// 		std::cout << _RPL_OPENFILE(path) << std::endl;
// 	} else {
// 		throw MyException(_ERR_OPENFILE(path));
// 	}
// 	return (fs);
// }


void	BitEx::setFstreams(std::fstream data, std::fstream infile){
	_fsData = data;
	_fsInFile = infile;
}

void	BitEx::compute(){
	return ();
}
