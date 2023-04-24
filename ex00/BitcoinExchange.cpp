#include "BitcoinExchange.hpp"
#include "MyException.hpp"

/*****************************************************/
/********************** coplien **********************/
/*****************************************************/
BitEx::BitEx() : _fileFlag(false), _dataMapFlag(false), _inputMapFlag(false) { std::cout << "BitEx constructor called" << std::endl; }

BitEx::BitEx(BitEx const &cpy) : _fileFlag(cpy._fileFlag), _dataMapFlag(cpy._dataMapFlag), _inputMapFlag(cpy._inputMapFlag), _dataMap(cpy._dataMap){std::cout << "BitEx constructor called" << std::endl;}

BitEx::~BitEx(){ _closeFiles(); std::cout << "BitEx destructor called" << std::endl; }

BitEx & BitEx::operator=(BitEx const &rhs){

	_fileFlag 		= rhs._fileFlag;
	_dataMapFlag	= rhs._dataMapFlag;
	_inputMapFlag	= rhs._inputMapFlag;
	_dataMap		= rhs._dataMap;
	return *this;
}

/*****************************************************/
/********************* open files ********************/
/*****************************************************/
void BitEx::_closeFiles()
{
	if (_ifsData.is_open()) {
		_ifsData.close();
	}
	if (_ifsInput.is_open()) {
		_ifsInput.close();
	}
}

void BitEx::_openFile(const char *path, std::ifstream &fs)
{
	fs.open(path);
	if (fs.is_open()) {
		std::cout << _RPL_OPENFILE(path) << std::endl;
	}
	else {
		throw MyException(_ERR_OPENFILE(path));
	}
}

void BitEx::tryOpenFile(const char *path)
{
	try {
		_openFile("data.csv", _ifsData);
		_openFile(path, _ifsInput);
		_fileFlag = true;
	}
	catch (std::exception &e) {
		std::cout << "error: " << e.what() << std::endl;
		_closeFiles();
	}
}

/*****************************************************/
/********************** compute **********************/
/*****************************************************/
void	BitEx::compute() {
	_addDataCsv();
	_addInputTxt(" | ");
	_closeFiles();
}

void	BitEx::_buildMap(std::ifstream &ifs, const std::string sep){
	std::string		line;
	unsigned int	lineNumber = 0;

	while (std::getline(ifs, line).good() && ++lineNumber){
		if (_AddInMapIfValid(line, sep) == false){
			throw MyException(_ERR_DATA_CORRUPTED(line, _ltoa(lineNumber)));
		}
	}
}

bool	BitEx::_AddInMapIfValid(const std::string &str, const std::string sep){
	std::string 	date, val;
	std::size_t		sepPos;

	sepPos = str.find_first_of(sep);
	if (sepPos != std::string::npos)
	{
		date = str.substr(0, sepPos);
		val = str.substr(sepPos + sep.size());
		if (_checkDate(date) && _checkVal(val, false)){
			_dataMap[_dateToInt(date)] = strtod(val.c_str(), NULL);
			return true;
		}
	}
	return false;
}

void	BitEx::_addInputTxt(const std::string &sep) {

	if (_dataMapFlag == true) {
		try {
			_checkFirstLine(_ifsInput, sep);
		}
		catch (std::exception &e) {
			std::cout << "error: " << e.what() << std::endl;
			return ;
		}
		_printResult(sep);
	}
}

void BitEx::_addDataCsv() {
	if (_fileFlag == true) {
		try {
			_checkFirstLine(_ifsData, ",");
			_buildMap(_ifsData, ",");
			_dataMapFlag = true;
		}
		catch (std::exception &e) {
			std::cout << "error: " << e.what() << std::endl;
		}
	}
	else
		std::cout << "error : missing files" << std::endl;
}


/*****************************************************/
/********************** print ************************/
/*****************************************************/
void	BitEx::_printResult(const std::string &sep){
	std::string		line;
	std::string		date, val;
	std::size_t		sepPos;

	while (std::getline(_ifsInput, line).good()){
		sepPos = line.find_first_of(sep);
		if (sepPos != std::string::npos)
		{
			date = line.substr(0, sepPos);
			val = line.substr(sepPos + sep.size());
			if (!_checkDate(date))
				_printErrResult (date, ERR_INVALIDE_DATE);
			else if (!_checkVal(val, true))
				_printErrResult (val, ERR_INVALIDE_VALUE);
			else
				_printGoodResult(date, val);
		}
		else if (line.empty())
			_printErrResult (line, ERR_EMPTY_LINE);
		else
			_printErrResult (line, ERR_SEPARATOR);
	}
}

void	BitEx::_printGoodResult(const std::string &date, const std::string &val){
	int					convDate, convVal;
	double				result;
	BitExMap::iterator	it;

	convDate = _dateToInt(date);
	convVal = atoi(val.c_str());
	it = _dataMap.find(convDate);
	if (it == _dataMap.end()) {
		if (convDate < _dataMap.begin()->first){
			std::cout << date << " not in data base (prior starting date )" << std::endl;
			return ;
		}
		else if (convDate > _dataMap.rbegin()->first)
			result = convVal * (_dataMap.rbegin())->second;
		else {
			while (_dataMap.find(convDate) == _dataMap.end())
				convDate--;
			result = convVal * _dataMap[convDate];
		}
	}
	else
		result = convVal * _dataMap[convDate];
	_printer (date, val, convVal, result);
}

void	BitEx::_printErrResult(const std::string &str, int errorCode){
	std::string tab[ERR_MAXENUMVAL] = {
		" empty line.",
		" no separator.",
		" invalide date.",
		" invalide value.",
	};
	std::cout << "error: " << str << tab[errorCode] <<std::endl;
}

void	BitEx::_printer(const std::string &date, const std::string &valS, const int valI, const double valD) {
	double	result;
	int 	precision = 2;

	result = valI * valD;
	std::cout	<< date
				<< " => "
				<< valS
				<< " = "
				<< std::fixed << std::setprecision(precision) << result
				<< std::endl;
}

/*****************************************************/
/****************** validity check *******************/
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
}

bool	BitEx::_checkLine(const std::string &str, const std::string sep){
	std::string 	date, val;
	std::size_t		sepPos;

	sepPos = str.find_first_of(sep);
	if (sepPos != std::string::npos)
	{
		date = str.substr(0, sepPos);
		val = str.substr(sepPos + sep.size());
		if (_checkDate(date) && _checkVal(val, false))
			return true;
	}
	return false;
}

bool	BitEx::_checkDate(const std::string &date){
	unsigned int	hyphenCnt = 0;

	if (date.size() > 10) //invalide date (exceed 10 char)
		return false;
	for (Itera it = date.begin(); it != date.end(); it++) //invalide date form (more than 2 "-")
		if (*it == '-') {hyphenCnt++; if (hyphenCnt > 2){return false;}}
	if (date.find("--") != std::string::npos) //invalide date form
		return false;
	else if (date.find_first_not_of("0123456789-") != std::string::npos) // unvalide char in date
		return false;
	else if (_checkDateLimit(date) == false) //unvalide datelimite
		return false;

	return true;
}

unsigned int	BitEx::_checkDateLimit(const std::string &date) {
	unsigned int	year, month, day, maxDayInMonth;
	unsigned int	tab[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	std::sscanf(date.c_str(), "%u - %u - %u", &year, &month, &day);
	if (year < BITCOIN_START_DATE || year > LIM_YEAR || month < 1  || month > LIM_MONTH)
		return false;
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		maxDayInMonth = 29;
	else
		maxDayInMonth = tab[month - 1];
	if (day < 1 || day > maxDayInMonth)
		return false;
	return true;
}

/**
 * if opt is true, _check val will check if the convertion of val do not exceed 1000
 * should this function set a limit to the size of val to 10 char ?
 * as we excluded any char that are not either numbers or "." we do not need to check if val is < 0
 * */
bool	BitEx::_checkVal(const std::string &val, bool opt){
	unsigned int	dotCnt = 0;
	double			convertedVal, supLim;

	for (Itera it = val.begin(); it != val.end(); it++) {
		if (*it == '.'){dotCnt++; if (dotCnt > 1) {return false;}}
	}	//invalide date form (more than 1 ".")
	if (val.find_first_not_of("0123456789.") != std::string::npos){
		return false;
	}	//invalide char in val
	std::sscanf(val.c_str(), "%lf", &convertedVal);
	if (opt)	{ supLim = 1000; }
	else 		{ supLim = INT_MAX; }
	if (convertedVal > supLim) {
		return false;
	}	//invalide converted vak : over limit
	return true;
}

/************ type convertion function **************/
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

int	BitEx::_dateToInt(const std::string &date){
	std::string tmp;

	for (Itera it = date.begin(); it != date.end(); it++)
		if (*it != '-')
			tmp += *it;
	return atoi(tmp.c_str());
}
