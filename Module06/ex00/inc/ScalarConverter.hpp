#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP


# include <iostream>
# include <string>
# include <climits>
# include <iomanip>
# include <algorithm>

class ScalarConverter {
	private:
		ScalarConverter();
	public:
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

		static void convert(const std::string &value);
};

#endif
