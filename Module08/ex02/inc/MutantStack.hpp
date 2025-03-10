#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack() {}
		MutantStack(const MutantStack &other) : std::stack<T>(other) {}
		MutantStack &operator=(const MutantStack &other){
			if (this != &other)
				std::stack<T>::operator=(other);
			return *this;
		}
		~MutantStack(){};

		//recuperation de l'iterateur de std::deque, sur lequel std::stack est base
		typedef typename std::stack<T>::container_type::iterator iterator;

		//on passe par this->c car stack stocke dans c, on a pas acces direct
		iterator begin(){return this->c.begin();}
		iterator end(){return this->c.end();}

};

#endif
