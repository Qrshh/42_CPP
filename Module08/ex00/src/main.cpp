#include "../inc/easyfind.hpp"

int	main(int, char**)
{
	std::list<int>	my_arr;
	int		to_find = 2;

	my_arr.push_back(0);
	my_arr.push_back(1);
	my_arr.push_back(2);


	if (easyfind(my_arr, to_find) == -1)
		std::cerr << "NOOOOOOOOOOOOOOO" << std::endl;
	else
		std::cout << "Yeeeeeeeeeeeeeees" << std::endl;

}