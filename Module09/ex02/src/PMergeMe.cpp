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


bool PMergeMe::parse(char **av){
	int i = 1;

	while(av[i] != NULL){
		char *endptr;
		long number = std::strtol(av[i], &endptr, 10);
		if(*endptr != '\0' || number <= 0 || number > std::numeric_limits<int>::max())
			return false;
		i++;
	}
	return true;
}

void PMergeMe::fillInContainers(char **av){
	int i = 1;

	while(av[i] != NULL){
		char *endptr;
		long number = std::strtol(av[i], &endptr, 10);
		if(*endptr != '\0' || number <= 0 || number > std::numeric_limits<int>::max())
			throw std::runtime_error("Invalid input");
		this->_vec.push_back(static_cast<int>(number));
		this->_list.push_back(static_cast<int>(number));
		i++;
	}
}

void PMergeMe::sort(){
	std::clock_t start;
	std::clock_t end;

	//sort vector
	start = std::clock();
	fordJohnsonSort(this->_vec);
	end = std::clock();
	_vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	//sort list
	start = std::clock();
	fordJohnsonSort(this->_list);
	end = std::clock();
	_listTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

void PMergeMe::displayVector(std::vector<int> &vec){
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";

}

void PMergeMe::Display(){
	//before sort
	std::cout << "Before : ";
	PMergeMe::displayVector(this->_vec);
	std::cout << std::endl;

	//sorting
	PMergeMe::sort();
	std::cout << "After : ";

	//after sort
	PMergeMe::displayVector(this->_vec);
	std::cout << std::endl;
	std::cout << "Time to process a range of " << this->_vec.size() << " elements with std::vector<int> : " << std::fixed <<std::setprecision(0) << this->_vecTime << "us" << std::endl;
	std::cout << "Time to process a range of " << this->_list.size() << " elements with std::list<int> : " << std::fixed <<std::setprecision(0) << this->_listTime << "us" << std::endl;
}

bool PMergeMe::isSorted(){
	for(size_t i = 0; i + 1 < this->_vec.size(); ++i){
		if(_vec[i] > _vec[i + 1])
			return false;
	}
	return true;
}

bool PMergeMe::hasDuplicate(){
	std::vector<int> copy = _vec;
	std::sort(copy.begin(), copy.end());
	return std::adjacent_find(copy.begin(), copy.end()) != copy.end();
}