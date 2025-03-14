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

bool isSpecial(const std::string &value){
	if(value == "-inf" || value == "+inf" || value == "-inff" || value == "+inff" || value == "nan" || value == "nanf")
		return true;
	return false;
}

bool isMinusInf(const std::string &value){
	if(value == "-inf" || value == "-inff")
		return true;
	return false;
}

bool isPlusInf(const std::string &value){
	if(value == "+inf" || value == "+inff")
		return true;
	return false;
}

bool isInt(const std::string &value){
	long unsigned int i = 0;
	while(std::isdigit(value[i]))
		i++;
	if(i == value.length())
		return true;
	return false;
}

bool isDouble(const std::string &value){
	if(value.find('.') != std::string::npos){
		long unsigned int	i = 0;
		while (i < value.length() - 1 && (std::isdigit(value[i]) || value[i] == '.'))
			i++;
		if (i == value.length() - 1)
			return (true);
	}
	return false;
}

void convertDouble(const std::string &value){
	double number = atof(value.c_str());

	if(number < 0 || number > 127)
		std::cout << "char : impossible" << std::endl;
	else if (number < 32 || number == 127)
		std::cout << "char : non-displayable" << std::endl;
	else
		std::cout << "char : " << static_cast<char>(number) << std::endl;

	std::cout << "int : " << static_cast<int>(number) << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(2) << static_cast<float>(number) << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(2) << number << std::endl;
}

void convertNan(const std::string &value){
	(void)value;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void convertPlusInf(const std::string &value){
	(void)value;
	std::cout << "char : impossible" << std::endl;
	std::cout << "int : " << INT_MAX << std::endl;
	std::cout << "float : " << __FLT_MAX__ << "f" << std::endl;
	std::cout << "double : " << __DBL_MAX__ << std::endl;
}

void convertMinusInf(const std::string &value){
	(void)value;
	std::cout << "char : impossible" << std::endl;
	std::cout << "int : " << INT_MIN << std::endl;
	std::cout << "float : " << __FLT_MIN__ << "f" << std::endl;
	std::cout << "double : " << __DBL_MIN__ << std::endl;
}

void convertChar(const std::string &value){
	std::cout << "char : " <<static_cast<char>(value[0]) << std::endl;
	std::cout << "int : " << static_cast<int>(value[0]) << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(value[0]) << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(value[0]) << std::endl;
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
	std::cout << "float : " << std::fixed << std::setprecision(1) << number << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(number) << std::endl;
}

void convertInt(const std::string &value){
	int number = atoi(value.c_str());

	if(number < 0 || number > 127)
		std::cout << "char : impossible" << std::endl;
	else if (number < 32 || number == 127)
		std::cout << "char : non-displayable " << std::endl;
	else
		std::cout << "char : " << static_cast<char>(number) << std::endl;
	std::cout << "int : " << (number) << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(2) << static_cast<float>(number) << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(2) << static_cast<double>(number) << std::endl;
}

void error(){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << 0 << std::endl;
	std::cout << "float: " << 0 << std::endl;
	std::cout << "double: " << 0 << std::endl;
}

void ScalarConverter::convert(const std::string &value) {
	//determination du type de value
	if(isFloat(value))
		convertFloat(value);
	else if (isChar(value))
		convertChar(value);
	else if (isSpecial(value)){
		if(isMinusInf(value))
			convertMinusInf(value);
		else if (isPlusInf(value))
			convertPlusInf(value);
		else
			convertNan(value);
	}
	else if (isInt(value))
		convertInt(value);
	else if (isDouble(value))
		convertDouble(value);
	else
		error();
}

ScalarConverter::~ScalarConverter() {}