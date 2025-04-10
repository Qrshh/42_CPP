#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <vector>
#include <list>
#include <ctime>
#include <algorithm>
#include <iomanip>


class PMergeMe{
	private:
		double _vecTime;
		double _listTime;
		std::vector<int> _vec;
		std::list<int> _list;

		template <typename Container>
		void mergeSortedAndSmaller(Container &sorted, const Container &smaller){
			for(typename Container::const_iterator it = smaller.begin(); it != smaller.end(); ++it){
				typename Container::iterator pos = sorted.begin();
				while(pos != sorted.end() && *pos < *it)
					++pos;
				sorted.insert(pos, *it);
			}
		}

		template <typename Container>
		Container recursiveSort(Container arr){
			if(arr.size() <= 1) return arr;
			Container smaller, larger;
			typename Container::iterator it = arr.begin();
			while(it != arr.end()){
				typename Container::iterator first = it++;
				if(it != arr.end()){
					typename Container::iterator second = it++;
					if(*first < *second){
						smaller.push_back(*first);
						larger.push_back(*second);
					} else {
						smaller.push_back(*second);
						larger.push_back(*first);
					}
				} else {
					larger.push_back(*first);
				}
			}
			Container sortedLarger = recursiveSort(larger);
			mergeSortedAndSmaller(sortedLarger, smaller);
			return sortedLarger;
		}

		template <typename Container>
		void fordJohnsonSort(Container &arr){
			arr = recursiveSort(arr);
		}

	public:
		PMergeMe();
		~PMergeMe();
		PMergeMe(const PMergeMe &other);
		PMergeMe &operator=(const PMergeMe &other);

		bool parse(char **av);
		void fillInContainers(char **av);
		void sort();
		void displayVector(std::vector<int> &vec);
		void Display();
		bool isSorted();
		bool hasDuplicate();
};



#endif