#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

Base *generate(void){
	Base *base;
	int random = rand() % 3;

	switch(random){
		case 0 :
			base = new A();
			break;
		case 1 :
			base = new B();
			break;
		case 2 :
			base = new C();
			break;
	}
	return base;
}

void identify(Base *p){
	if(dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base &p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (...) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (...) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (...) {}

	std::cout << "Unknown type" << std::endl;
}

int main(int, char **){
	srand(time(0));
	Base *base(generate());
	identify(base);
	identify(*base);
	identify(NULL);
	delete base;
	return 0;
}