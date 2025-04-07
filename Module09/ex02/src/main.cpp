#include "../inc/PMergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac > 2)
	{
		PMergeMe	obj;
		if (!obj.parse(av))
		{
			std::cout << "The sequence contains a negative value or 0" << std::endl;
			return -1;
		}
		obj.fillInContainers(av);
		if (!obj.isSorted() && !obj.hasDuplicate())
			obj.Display();		
		else
		{
			std::cout << "The sequence is already sorted or has duplicates! " << std::endl;
			return -1;
		}
	}
	else
	{
		std::cout << "Not enough args" << std::endl;
	}
	return 0;
}