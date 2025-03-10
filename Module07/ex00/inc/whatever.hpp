#ifndef WHATEVER_HPP
#define WHATEVER_HPP


#include <iostream>

template<typename T>
void	ft_swap(T &a, T &b){
	T c;

	c = a;
	a = b;
	b = c;
}

template<typename T>
T	ft_min(T &a, T &b){
	if (a > b)
		return b;
	else if (b > a)
		return a;
	else
		return b;
}

template<typename T>

T ft_max(T &a, T &b){
	if(a > b)
		return a;
	else if (b > a)
		return b;
	else
		return b;
}




#endif