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

void BitEx::_parse()
{
	std::string line;
	std::string date;
	std::string rate;
j
	std::getline(_ifsData, line);

	std::cout << "first line is : "<<  line << std::endl;

}

void	BitEx::_
