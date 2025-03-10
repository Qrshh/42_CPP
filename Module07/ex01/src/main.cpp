#include "../inc/iter.hpp"

int main(void){

	std::cout << "Numbers :" << std::endl;
	int arr[3] = {2, 3 ,1};
	iter(arr, 3, print);

	std::cout << std::endl;

	std::cout << "Letters : " << std::endl;
	char arr2[3] = {'b', 'c', 'a'};
	iter(arr2, 3, print);

	std::cout << std::endl;
	std::cout << "Sentences : " << std::endl;

	std::string arr3[3] = {"one", "three", "two"};
	iter(arr3, 3, print);

	return 0;

}