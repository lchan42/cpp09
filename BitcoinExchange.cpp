#include "BitcoinExchange.hpp"
#include "MyException.hpp"

/*****************************************************/
/********************** coplien **********************/
/*****************************************************/

BitEx::BitEx() : _fileFlag(false){
	std::cout << "BitEx constructor called" << std::endl;
}

BitEx::BitEx(std::string inputPath) : _fileFlag(false){
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
	if (_fileFlag == true) {
		_parse(_ifsData, ",");
		_parse(_ifsInput, " | ");
		std::cout << "ready to compute\n"
				  << std::endl;
	}
	else {
		std::cout << "error : missing files" << std::endl;
	}
}

void BitEx::_parse(std::ifstream &ifs, const std::string sep) // real compute function
{
	std::string line;

	try {
		_checkFirstLine(ifs, sep);
		_buildMap(ifs, sep);
	}
	catch (std::exception &e) {
		std::cout << "error: " << e.what() << std::endl;
	}
	std::getline(ifs, line);
	std::cout << "secondline line is : "<<  line << std::endl;
}


/* this function check if the first line of each file is correct or not */
void	BitEx::_checkFirstLine(std::ifstream &ifs, const std::string sep){

	std::string line;

	std::getline(ifs, line);
	if (&ifs == &_ifsData && line != "date" + sep + "exchange_rate"){
		throw MyException(_ERR_IMPUT_FIRSTLINE(".csv", line));
	}
	else if (&ifs == &_ifsInput && line != "date" + sep + "value") {
		throw MyException(_ERR_IMPUT_FIRSTLINE("input.txt", line));
	}
	else  {
		std::cout << "first line is correct: " << line << std::endl;
	}
}

void	BitEx::_buildMap(std::ifstream &ifs, const std::string sep){
	std::string line;


}

bool	bitEx::_checkString(std::string str){

}
// bool	BitEx::_checkFirstLine(){

// 	std::string line;

// 	std::getline(_ifsInput, line);
// 	if (line == "date | value") {
// 		std::cout << "fist line is correct" << std::endl;
// 		return true;
// 	} else {
// 		std::cout << "error: first line is incorrect" << std::endl;
// 		return false;
// 	}
//

