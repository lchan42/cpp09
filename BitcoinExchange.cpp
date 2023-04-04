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
/********************** compute **********************/
/*****************************************************/

void BitEx::compute()
{
	if (_fileFlag == true) {
		// _parse(_ifsData, ",");
		_parse(_ifsInput, " | ");
		std::cout << "ready to compute\n"
				  << std::endl;
	}
	else {
		std::cout << "error : missing files" << std::endl;
	}
}


/*****************************************************/
/******************  ********************/
/*****************************************************/
void BitEx::_parse (std::ifstream &ifs, const std::string sep) // real compute function
{
	std::string line;

	try {
		_checkFirstLine(ifs, sep);
		_buildMap(ifs, sep);
	}
	catch (std::exception &e) {
		std::cout << "error: " << e.what() << std::endl;
	}
}


/*****************************************************/
/****************** compute ifsDate  ********************/
/*****************************************************/
void	BitEx::_buildMap(std::ifstream &ifs, const std::string sep){

	std::string		line;
	unsigned int	n = 0;

	// std::getline(ifs, line);
	// if (_checkString(line, sep)){
	// 	_addValInMap(line, sep);
	// } else {
	// 	throw MyException(_ERR_DATA_CORRUPTED(line, _ltoa(n)));
	// }
	while (std::getline(ifs, line).good() && ++n){
		if (_checkString(line, sep)){
			_addValInMap(line, sep);
		} else {
			throw MyException(_ERR_DATA_CORRUPTED(line, _ltoa(n)));
		}
	}
}


/*****************************************************/
/****************** compute _ifsinput  ********************/
/*****************************************************/

/*****************************************************/
/****************** parsing tools ********************/
/*****************************************************/

/* this function check if the first line of each file is correct or not */
void	BitEx::_checkFirstLine(std::ifstream &ifs, const std::string sep){

	std::string line;

	std::getline(ifs, line);
	if (&ifs == &_ifsData && line != "date" + sep + "exchange_rate"){
		throw MyException(_ERR_IMPUT_FIRSTLINE(".csv", line, "date,exchange_rate"));
	}
	else if (&ifs == &_ifsInput && line != "date" + sep + "value") {
		throw MyException(_ERR_IMPUT_FIRSTLINE("input.txt", line, "date | value"));
	}
	// else  {
	// 	std::cout << "first line is correct: " << line << std::endl;
	// }
}

std::string	BitEx::_ltoa(long int n){
	std::stringstream	myStream;

	myStream << n;
	return (myStream.str());
}

template <typename T>
std::string	_ntoa(T number){

	std::stringstream	myStream;
	myStream << number;
	return (myStream.str());

}

// FAIRE UNE VERSION TEMPLATE QUI PREND INT, FLOAT, DOUBLE
// std::string	BitEx::_ltoa(double n){
// 	std::stringstream	myStream;

// 	myStream << n;
// 	return (myStream.str());
// }


bool	BitEx::_checkString(const std::string &str, const std::string sep){

	std::string 	date, val;
	std::size_t		sepPos;

	sepPos = str.find_first_of(sep);
	if (sepPos != std::string::npos)
	{
		date = str.substr(0, sepPos);
		val = str.substr(sepPos + sep.size());
		std::cout<<  "date = " << date << " val = " << val << std::endl;

		if (_checkDate(date) && _checkVal(val, false)){
			return true;
		}
	}
	return false;
}


typedef std::string::const_iterator Itera;
bool	BitEx::_checkDate(const std::string &date){

	unsigned int	hyphenCnt = 0;

	if (date.size() > 10) {
		return false;
	}	//invalide date (exceed 10 char)
	for (Itera it = date.begin(); it != date.end(); it++) {
		if (*it == '-') {hyphenCnt++; if (hyphenCnt > 2){return false;}}
	}	//invalide date form (more than 2 "-")
	if (date.find("--") != std::string::npos){
		return false;
	}	//invalide date form
	else if (date.find_first_not_of("0123456789-") != std::string::npos){
		return false;
	}	// unvalide char in date
	else if (_checkDateLimit(date) == false) {

		return false;
	}	//unvalide datelimite
	return true;
}

unsigned int	BitEx::_checkDateLimit(const std::string &date) {

	unsigned int	year, month, day, maxDayInMonth;
	unsigned int	tab[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	std::sscanf(date.c_str(), "%u - %u - %u", &year, &month, &day);
	if (year < BITCOIN_START_DATE || year > LIM_YEAR || month < 1  || month > LIM_MONTH){
		return false;
	}
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)){
		maxDayInMonth = 29;
	}
	else {
		maxDayInMonth = tab[month];
	}
	if (day <= 1 || day >= maxDayInMonth){
		return false;
	}
	return true;
}

/**
 * should this function set a limit to the size of val to 10 char ?
 * if opt is true, _check val will check if the convertion of val do not exceed 1000
 * as we exclude any char that are not either numbers or "." we do not need to check if val is < 0
 * */
bool	BitEx::_checkVal(const std::string &val, bool opt){
	unsigned int	dotCnt = 0;
	double			convertedVal, supLim;

	for (Itera it = val.begin(); it != val.end(); it++) {
		if (*it == '.') {dotCnt++; if (dotCnt > 1) {return false;}}
	}	//invalide date form (more than 1 ".")
	if (val.find_first_not_of("0123456789.") != std::string::npos){
		return false;
	}	//invalide char in val
	std::sscanf(val.c_str(), "%lf", &convertedVal);
	if (opt){ supLim = 1000; }
	else { supLim = INT_MAX; }
	if (convertedVal > supLim) {
		return false;
	}	//invalide converted vak : over limit
	return true;
}

void	BitEx::_addValInMap(const std::string &str, const std::string sep){

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

