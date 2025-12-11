#include "Base.hpp"

Base *genereate(void)
{
	std::srand(std::time(NULL));
	int random = std::rand() % 3;

	switch (random)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	case 2:
		return new C();
	default:
		return NULL;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A*>(&p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e) {}
	
	try
	{
		dynamic_cast<B*>(&p);
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e) {}

	try
	{
		dynamic_cast<C*>(&p);
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e) {}

	std::cout << "Unknown type" << std::endl;
}

int main(void)
{
	
}