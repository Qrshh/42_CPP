#ifndef RPN_HPP
#define RPN_HPP


#include <iostream>
#include <stack>
#include <string>
#include <sstream>


class RPN {
	private:
		std::stack<int> stack;
		void applyOperation(const std::string &op);
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
		int evaluate(const std::string &expr);
};

#endif