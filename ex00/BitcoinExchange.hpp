#ifndef BITEX_HPP
# define BITEX_HPP

# define PRICE_HISTORY
# define PRICE_HISTORY

# include <iostream>
# include <map>
# include <fstream>
# include <string>
# include <sstream>
#include <limits.h>
#include <float.h>
#include <stdlib.h>
#include <iomanip>

// typedef std::map<std::string, unsigned int>	BitExMap;

enum e_date_limite
{
	BITCOIN_START_DATE = 2009,
	LIM_YEAR = 2023,
	LIM_MONTH = 12,
	LIM_DAY = 31
};

enum e_print_error
{
	ERR_EMPTY_LINE,
	ERR_SEPARATOR,
	ERR_INVALIDE_DATE,
	ERR_INVALIDE_VALUE,
	ERR_MAXENUMVAL
};

typedef std::map<int, double>		BitExMap;
typedef std::string::const_iterator	Itera;

class BitEx{
	public:
		BitEx();
		BitEx(BitEx const &cpy);
		~BitEx();

		BitEx & operator=(BitEx const &rhs);
		void	tryOpenFile(const char *path);
		void	compute();

	private:

		// Variables
		bool			_fileFlag;
		bool			_dataMapFlag;
		bool			_inputMapFlag;
		std::ifstream	_ifsData;
		std::ifstream	_ifsInput;
		BitExMap		_dataMap;

		// open/close
		void			_closeFiles();
		void			_openFile(const char *path, std::ifstream &fs);

		// add infiles into maps
		void			_checkFirstLine	(std::ifstream &ifs, const std::string sep);
		void			_buildMap		(std::ifstream &ifs, const std::string sep);
		void			_addInputTxt(const std::string &sep);
		void			_addDataCsv();

		// print
		void			_printResult(const std::string &sep);
		void			_printGoodResult(const std::string &date, const std::string &val);
		void			_printErrResult(const std::string &date, int errorCode);
		void			_printer(const std::string &date, const std::string &valS, const int valI, const double valD);

		// validity check
		bool			_checkLine(const std::string &str, const std::string sep);
		bool			_checkDate	(const std::string &date);
		unsigned int	_checkDateLimit(const std::string &date);
		bool			_checkVal	(const std::string &val, bool opt);
		bool			_AddInMapIfValid(const std::string &str, const std::string sep);

		// tools
		std::string		_ltoa(long int n);
		int				_dateToInt(const std::string &date);

		// debug function
		template <typename T, typename U>
		void	printMap(std::map<U, T> & mymap){
			for (typename std::map<U, T>::iterator it = mymap.begin(); it!=mymap.end(); ++it){
				std::cout << "key : " << "[" << it->first << "]" << " - " << "val : "<< "[" << it->second << "]" << std::endl;
			}
		}

		template <typename T, typename U>
		void	printNMap(std::map<U, T> & mymap, int n){
			typename std::map<U, T>::iterator it = mymap.begin();
			while (n--) {
				std::cout << "key : " << "[" << it->first << "]" << " - " << "val : "<< "[" << it->second << "]" << std::endl;
				it++;
			}
		}
};

#endif
