#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <sstream> 
#include <limits.h>
#include <cerrno>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter& operator=(const ScalarConverter &sc);

	public:
		~ScalarConverter(void);
		static void convert(const std::string &literal);
};