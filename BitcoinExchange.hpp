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
	std::string		
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

		bool			_fileFlag;
		std::ifstream	_ifsData;
		std::ifstream	_ifsInput;
		BitExMap		_dataMap;
		BitExMap		_imputMap;
		void			_closeFiles();
		void			_openFile(const char *path, std::ifstream &fs);

		// void			_setMap();

		void			_parse();
};

#endif
