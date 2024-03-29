#ifndef MYEXCEPTION_HPP
#define MYEXCEPTION_HPP

#include <exception>
#include <iostream>

// note : throw() in "virtual ~MyException() throw()" means that the function will not throw expection
// note : virtual ~MyException is mandatory because of the ineritance of the class
// note : I respected the copien form even if it is completly useless here.
// note : there is no .cpp here. Everything is here.
// note : this class is a personalised exception class.
// note : std::exception what() prototype is "virtual const char* what() const throw();"

#define _RPL_OPENFILE(s1) "[" + std::string(s1) + "]" + " : open success"
#define _ERR_OPENFILE(s1) "[" + std::string(s1) + "]" + " : fail to open "
#define _ERR_IMPUT_FIRSTLINE(path, s1, s2) "on line 0 \"" + s1 + "\"" + " from [" + path + "] is incorrect. Expected : [" + s2 + "]"
#define _ERR_DATA_CORRUPTED(line, pos) "wrong input at line " + (pos) + ": \"" + (line) + "\""

class MyException : public std::exception {
	public:
		MyException(const char* error)	:_errorMessage(std::string(error))	{}
		MyException(std::string &error)	: _errorMessage(error)				{}
		MyException(std::string error)	: _errorMessage(error)				{}
		MyException(const MyException& cpy)									{ *this = cpy;}
		MyException& operator= (const MyException& cpy)						{ _errorMessage = cpy._errorMessage; return *this;}

		virtual ~MyException() throw()										{}

		virtual const char* what() const throw() 							{ return (_errorMessage.c_str()); }

	private :
		std::string	_errorMessage;
};

#endif
