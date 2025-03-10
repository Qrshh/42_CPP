#include "Span.hpp"

#include <iostream>
#include "Span.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>

void basicTest() {
	std::cout << "===== BASIC TEST =====" << std::endl;
	Span sp(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Doit être 2 (5 - 3)
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;   // Doit être 14 (17 - 3)
}

void negativeNumbersTest() {
	std::cout << "===== NEGATIVE NUMBERS TEST =====" << std::endl;
	Span sp(5);
	sp.addNumber(-10);
	sp.addNumber(-20);
	sp.addNumber(0);
	sp.addNumber(10);
	sp.addNumber(5);

	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Doit être 5 (5 - 0)
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;   // Doit être 30 (10 - (-20))
}

void exceptionTest() {
	std::cout << "===== EXCEPTION TEST =====" << std::endl;
	Span sp(2);
	try {
		sp.shortestSpan();
	} catch (const std::exception &e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	sp.addNumber(42);
	try {
		sp.shortestSpan();
	} catch (const std::exception &e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}
}

void largeScaleTest() {
	std::cout << "===== LARGE SCALE TEST (10 000 numbers) =====" << std::endl;
	Span sp(10000);
	std::srand(std::time(0));

	for (int i = 0; i < 10000; ++i) {
		sp.addNumber(std::rand());
	}

	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}

void extremeValuesTest() {
	std::cout << "===== EXTREME VALUES TEST =====" << std::endl;
	Span sp(3);
	sp.addNumber(INT_MIN);
	sp.addNumber(INT_MAX);
	sp.addNumber(0);

	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // 0 à INT_MAX ou INT_MIN
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;   // Doit être INT_MAX - INT_MIN
}

int main() {
	basicTest();
	negativeNumbersTest();
	exceptionTest();
	largeScaleTest();
	extremeValuesTest();

	return 0;
}
