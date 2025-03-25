#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <limits.h>


class BitcoinExchange {
	private:
		std::map<std::string, float> map;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void loadMap(const std::string &input);
		void loadData(const std::string &data);

};

#endif