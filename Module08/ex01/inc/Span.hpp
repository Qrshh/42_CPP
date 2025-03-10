#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Span{
	private:
		unsigned int _capacity;
		std::vector<int> _vector;

	public:
		Span();
		Span(unsigned int n);
		~Span();

		void addNumber(int number);
		int shortestSpan();
		int longestSpan();

	class MaxIntegerReachedException : public std::exception{
		public:
			virtual const char* what() const throw();
		};
	class NoSpanPossibleException : public std::exception{
		public:
			virtual const char* what() const throw();
	};
};


#endif
