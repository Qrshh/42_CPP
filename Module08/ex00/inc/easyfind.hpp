#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <list>
#include <algorithm> // pour std::find

template<typename T>

int easyfind(std::list<T> array, int number){
	std::list<int>::const_iterator it;

	it = std::find(array.begin(), array.end(), number);
	if(it != array.end())
		return(0);
	return (-1);
}


#endif
