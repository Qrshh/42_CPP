#include "../inc/BitcoinExchange.hpp"

int main(int ac, char **av){
	if(ac != 2){
		std::cerr << "Error\n Wrong number of arguments" << std::endl;
		return 1;
	}

	BitcoinExchange exchange;
	exchange.loadMap("data.csv");
	exchange.loadData(av[1]);
	return 0;
}