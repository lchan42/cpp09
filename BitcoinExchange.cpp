#include "BitcoinExchange.hpp"
#include "MyException.hpp"

/*****************************************************/
/********************** coplien **********************/
/*****************************************************/

BitEx::BitEx() : _fileFlag(false)
{
	std::cout << "BitEx constructor called" << std::endl;
	// std::cout << "BitEx needs at least an entryFile " << std::endl;
}

BitEx::BitEx(std::string inputPath) : _fileFlag(false)
{
	(void)inputPath;
	// tryOpenFile(inputPath.c_str());
	std::cout << "BitEx constructor called" << std::endl;
}

// BitEx(BitEx const &cpy);

BitEx::~BitEx()
{
	_closeFiles();
	std::cout << "BitEx destructor called" << std::endl;
}

// BitEx & operator=(BitEx const &rhs);

/*****************************************************/
/********************* open files ********************/
/*****************************************************/

void BitEx::_closeFiles()
{
	if (_ifsData.is_open())
	{
		_ifsData.close();
	}
	if (_ifsInput.is_open())
	{
		_ifsInput.close();
	}
}

void BitEx::_openFile(const char *path, std::ifstream &fs)
{
	fs.open(path);
	if (fs.is_open())
	{
		std::cout << _RPL_OPENFILE(path) << std::endl;
	}
	else
	{
		throw MyException(_ERR_OPENFILE(path));
	}
}

void BitEx::tryOpenFile(const char *path)
{
	try
	{
		_openFile("data.csv", _ifsData);
		_openFile(path, _ifsInput);
		_fileFlag = true;
	}
	catch (std::exception &e)
	{
		std::cout << "error: " << e.what() << std::endl;
		_closeFiles();
	}
}

/*****************************************************/
/********************** coplien **********************/
/*****************************************************/

void BitEx::compute()
{
	if (_fileFlag == true)
	{
		_parse();
		std::cout << "ready to compute\n"
				  << std::endl;
	}
	else
	{
		std::cout << "error : missing files" << std::endl;
	}
}

void BitEx::_parse() // real compute function
{
	// std::string date;
	// std::string rate;
	std::string line;

	// std::getline(_ifsData, line);
	try {
		_checkFistLine();
	}
	catch (std::exception &e) {
		std::cout << "error: " << e.what() << std::endl;
	}
	std::getline(_ifsInput, line);
	std::cout << "secondline line is : "<<  line << std::endl;
}

void	BitEx::_checkFistLine(){

	std::string line;

	std::getline(_ifsInput, line);
	if (line != "date | value") {
		throw MyException(_ERR_IMPUT_FIRSTLINE(line));
	} else  {
		std::cout << "fist line is correct" << std::endl;
	}
 }

// bool	BitEx::_checkFistLine(){

// 	std::string line;

// 	std::getline(_ifsInput, line);
// 	if (line == "date | value") {
// 		std::cout << "fist line is correct" << std::endl;
// 		return true;
// 	} else {
// 		std::cout << "error: first line is incorrect" << std::endl;
// 		return false;
// 	}
//  }

