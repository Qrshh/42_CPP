#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other){
	this->map = other.map;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other){
	if (this != &other){
		*this = other;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(){}


void BitcoinExchange::loadMap(const std::string &input){
	std::ifstream file(input);
	if(!file){
		std::cerr << "Error\n The program cannot open the data file" << std::endl;
		return ;
	}

	std::string line;
	getline(file, line);

	while(getline(file, line)){
		std::stringstream ss(line);
		std::string date, price;
		if(getline(ss, date, ',') && getline(ss, price)){
			try{
				map[date] = std::stof(price);
			} catch (const std::invalid_argument &){
				std::cerr << "Error\n Invalid price in the data file (NaN)" << std::endl;
			} catch (const std::out_of_range &){
				std::cerr << "Error\n Invalid price in the data file (Number too large)" << std::endl;
			}
		}
	}
}

static bool isBisextile(int year){
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static bool isDateValid(int day, int month, int year){
	int dayPerMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if(month == 2 && isBisextile(year)){
		dayPerMonths[2] = 29;
	}

	if(month < 1 || month > 12)
		return false;
	
	if(day < 1 || day > dayPerMonths[month])
		return false;

	return true;
}

static bool checkDateFormat(const std::string &date){
	for(int i = 0; i < 4; i++){
		if(!isdigit(date[i]))
			return false;
	}
	for(int i = 5; i < 7; i++){
		if(!isdigit(date[i]))
			return false;
	}
	for(int i = 8; i < 10; i++){
		if(!isdigit(date[i]))
			return false;
	}

	return true;
}

static bool checkDate(const std::string &date){
	if(!checkDateFormat(date)){
		std::cerr << "Error\n Date format is invalid" << std::endl;
		return false;
	}

	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

	if(date[4] != '-' || date[7] != '-'){
		std::cerr << "Error\n Invalid date format on this line" << std::endl;
		return false;
	}

	if(!isDateValid(day, month, year)){
		std::cerr << "Error\n This date " << date << "-" << month << "-" << year << " is invalid" << std::endl;
		return false;
	}
	return true;
}

static bool checkNumber(const std::string &price){
	if(price.empty()){
		std::cerr << "Error\n No value in the value part" << std::endl;
		return false;
	}

	bool hasDecimal = false;
	for(size_t i = 0; i < price.length(); i++){
		if(price[i] == '.'){
			if(hasDecimal){
				std::cerr << "Error\n Invalid number format " << price << std::endl;
				return false;
			}
			hasDecimal = true;
		}
		else if (!isdigit(price[i])){
			std::cerr << "Error\n Invalid character in number " << price << std::endl;
			return false;
		}
	}


	float number = atof(price.c_str());

	if(number < 0){
		std::cerr << "Error\n Not a positive number" << std::endl;
		return false;
	}

	if(number > INT_MAX){
		std::cerr << "Error\n Number too large" << std::endl;
		return false;
	}

	return true;
}

void BitcoinExchange::loadData(const std::string &data){
	std::ifstream file(data);
	if(!file){
		std::cerr << "Error\n The program cannot open the user data file" << std::endl;
		return ;
	}

	std::string line;
	getline(file, line);

	while(getline(file, line)){
		std::stringstream ss(line);
		std::string date, price;
		getline(ss, date, '|');
		if(!checkDate(date))
			continue;
		getline(ss, price);
		price.erase(0, price.find_first_not_of(" "));
		if(!checkNumber(price))
			continue ;
		float number = atof(price.c_str());

		std::map<std::string, float>::iterator it = map.lower_bound(date);

		if(it == map.begin()){
			std::cerr << "Error\n No data found for the requested date" << std::endl;
			continue;
		}
		--it;

		float rate = it->second;
		std::cout << date << " -> " << price << " = " << number * rate << std::endl;
	}
}