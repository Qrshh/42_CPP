#include "PMergeMe.hpp"

PMergeMe::PMergeMe(){}

PMergeMe::~PMergeMe(){}

PMergeMe::PMergeMe(const PMergeMe &other) : _vecTime(other._vecTime), _listTime(other._listTime) {}

PMergeMe& PMergeMe::operator=(const PMergeMe &other){
	if (this != &other){
		_vecTime = other._vecTime;
		_listTime = other._listTime;
	}
	return *this;
}