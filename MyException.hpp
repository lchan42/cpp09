#ifndef MYEXCEPTION_HPP
#define MYEXCEPTION_HPP

#include <exception>

// note : throw() in "virtual ~MyException() throw()" means that the function will not throw expection
// note : virtual ~MyException il mendatory because of the ineritance of the class
// note : this class il a expcetion. I respected the copien form even if it il completly useless here.
// note : there is no .cpp here. Everything is here.
// note : this class is a personnalised excetion class.
// note : std::exception what() prototype is "virtual const char* what() const throw();"

class MyException : public std::exception {
	public:
		MyException(const char* error) 					: _errorMessage(error) {}
		MyException(const MyException& cpy) 			{ *this = cpy;}
		MyException& operator= (const MyException& cpy)	{ _errorMessage = cpy._errorMessage; return *this;}

		virtual ~MyException() throw()					{}

		virtual const char* what() const throw() 		{ return (_errorMessage); }
		// virtual const char* what() const throw() 		{ return (("error: " + std::string(_errorMessage)).c_str()); }

	private :
		const char *_errorMessage;
};

#endif
