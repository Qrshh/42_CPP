#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}

bool isChar(const std::string &value){
	if(value.size() == 1 && std::isdigit(value[0]) == false && std::isprint(value[0]) != 0)
			return true;
	return false;
}

bool isFloat(const std::string &value){
	if(value[value.length() - 1] == 'f')
	{
		long unsigned int i = 0;
		while(i < value.length() - 1 && (std::isdigit(value[i]) || value[i] == '.'))
			i++;
		if(i == value.length() - 1)
			return true;
	}
	return false;
}

void convertChar(const std::string &value){
	std::cout << "char : " <<static_cast<char>(value[0]) << std::endl;
	std::cout << "int : " << static_cast<int>(value[0]) << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(value[0]) << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::Setprecision(1) << static_cast<double>(value[0]) << std::endl;
}

void convertFloat(const std::string &value){
	float number = atof(value.c_str());

	if(number < 0 || number > 127)
			std::cout << "char : impossible" << std::endl;
	else if (number < 32 || number == 127)
			std::cout << "char : non-displayable" << std::endl;
	else
		std::cout << "char : " << static_cast<char>(number) << std::endl;

	std::cout << "int : " << static_cast<int>(number) << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(2) << number << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(2) << static_cast<double>(number) << std::endl;
}

void ScalarConverter::convert(const std::string &value) {
	if(isFloat(value))
			convertFloat(value);
	else if (isChar(value))
			convertChar(value);

}

ScalarConverter::~ScalarConverter() {}