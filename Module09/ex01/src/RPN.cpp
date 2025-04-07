#include "../inc/RPN.hpp"

RPN::RPN(){}
RPN::RPN(const RPN &other){this->stack = other.stack;}
RPN& RPN::operator=(const RPN &other){
	if(this != &other)
		*this = other;
	return *this;
}
RPN::~RPN(){}

static int toInt(const std::string& s) {
	std::istringstream iss(s);
	int n;
	if (!(iss >> n)) {
		throw std::runtime_error("Erreur : token invalide");
	}
	return n;
}


static bool isOperator(const std::string &token){
	return token == "+" || token == "-" || token == "/" || token == "*"; 
}

void RPN::applyOperation(const std::string &op){
	if(stack.size() < 2){
		throw std::runtime_error("Error\n Invalid expression");
	}
	int b = stack.top(); stack.pop();
	int a = stack.top(); stack.pop();

	if (a > 10 || b > 10){
		throw std::runtime_error("Error\n Number > 10");
	}

	if(op == "+") stack.push(a + b);
	else if (op == "-") stack.push(a - b);
	else if (op == "*") stack.push(a * b);
	else if (op == "/"){
		if(b == 0){
			throw std::runtime_error("Error\n Div by 0 is impossible");
		}
		else
			stack.push(a / b);
	}
}

int RPN::evaluate(const std::string &expr){
	std::istringstream iss(expr);
	std::string token;

	while(iss >> token){
		if(isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))){
			try {
                stack.push(toInt(token));
            } catch (const std::invalid_argument&) {
                throw std::runtime_error("Erreur : token invalide ");
			}
		} else if (isOperator(token)){
			applyOperation(token);
		}else {
			throw std::runtime_error("Error\n Invalid token");
		}
	}
	if(stack.size() != 1){
		throw std::runtime_error("Error\n Invalid expression");
	}
	return stack.top();
}
