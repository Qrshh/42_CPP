#include "../inc/Span.hpp"

Span::Span() : _capacity(-1) {}

Span::Span(unsigned int n) : _capacity(n) {}

Span::~Span(){}

void Span::addNumber(int number){
	if(this->_vector.size() == this->_capacity)
		throw MaxIntegerReachedException();
	this->_vector.push_back(number);
}

int Span::longestSpan() {
	if(this->_vector.size() < 2)
		throw NoSpanPossibleException();

	int minVal = *std::min_element(this->_vector.begin(), this->_vector.end());
	int maxVal = *std::max_element(this->_vector.begin(), this->_vector.end());

	return maxVal - minVal;
}

int Span::shortestSpan() {
	if (this->_vector.size() < 2)
		throw NoSpanPossibleException();

	std::vector<int> sortedArr = this->_vector;
	std::sort(sortedArr.begin(), sortedArr.end());

	//etant donne qu'on trie notre vector, le plus petit ecart est forcement entre deux chiffres consecutifs
	int minSpan = INT_MAX;
	for (size_t i = 1; i < sortedArr.size(); i++) {
		minSpan = std::min(minSpan, sortedArr[i] - sortedArr[i - 1]);
		if (minSpan == 1) return 1; //1 est le plus petit écart possible
	}
	return minSpan;
}


const char* Span::NoSpanPossibleException::what() const throw(){
	return "Not enough  numbers in the vector to find a span";
}

const char* Span::MaxIntegerReachedException::what() const throw(){
	return "Max of integers possible to store has been reached";
}

