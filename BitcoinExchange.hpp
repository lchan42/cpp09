#ifndef BITEX_HPP
# define BITEX_HPP

# define PRICE_HISTORY

# include <iostream>
# include <map>
# include <fstream>

// typedef std::map<std::string, unsigned int>	BitExMap;

typedef struct s_date{
	unsigned int	year;
	unsigned int	month;
	unsigned int	day;
} t_date;

typedef struct s_lineStruct{
	std::string	test;
} t_lineStruct;

typedef std::map<int, int>	BitExMap;

class BitEx{
	public:
		BitEx();
		BitEx(std::string inputPath);
		// BitEx(BitEx const &cpy);
		~BitEx();

		// BitEx & operator=(BitEx const &rhs);
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
		BitExMap		_inputMap;

		// functions
		void			_closeFiles();
		void			_openFile(const char *path, std::ifstream &fs);

		void			_parse(std::ifstream &ifs, const std::string sep);
		void			_checkFirstLine(std::ifstream &ifs, const std::string sep);
		void			_buildMap(std::ifstream &ifs, const std::string sep);
		bool			_checkString(const char* str)
};

#endif
