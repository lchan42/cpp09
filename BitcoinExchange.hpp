#ifndef BITEX_HPP
#define BITEX_HPP

#define PRICE_HISTORY

#include <iostream>
#include <map>

typedef std::map<std::string, unsigned int>	BitExMap;

class BitEx{
	public:
		BitEx();
		BitEx(std::string inputPath);
		BitEx(BitEx const &cpy);
		~BitEx();

		BitEx & operator=(BitEx const &rhs);

	private:
		void	parse(std::string inputPath);
		void	
		BitExMap	_dataMap;
		BitExMap	_imputMap;
}

#endif
