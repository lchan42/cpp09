#ifndef BITEX_HPP
# define BITEX_HPP

# define PRICE_HISTORY

# include <iostream>
# include <map>
# include <fstream>

typedef std::map<std::string, unsigned int>	BitExMap;

class BitEx{
	public:
		BitEx();
		BitEx(std::string inputPath);
		BitEx(std::fstream fs1, std::fstream fs2);
		BitEx(BitEx const &cpy);
		~BitEx();

		// BitEx & operator=(BitEx const &rhs);

		void	compute();
		void	setFstreams(std::fstream data, std::fstream infile);

	private:

		std::fstream	_fsData;
		std::fstream	_fsInFile;
		BitExMap		_dataMap;
		BitExMap		_imputMap;
		void			_closeFiles();
		// void			_setMap();

		// void			parse(std::string inputPath);
};

#endif
