#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "=== Test MutantStack ===" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	std::cout << "\nIteration avec iterateurs:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	std::cout << "\n=== Test avec std::list (comparaison) ===" << std::endl;
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << "Back: " << lst.back() << std::endl;

	lst.pop_back();

	std::cout << "Size: " << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();

	std::cout << "\nIteration avec list:" << std::endl;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	std::cout << "\n=== Test copie ===" << std::endl;
	MutantStack<int> copy(mstack);
	std::cout << "Copy top: " << copy.top() << std::endl;
	std::cout << "Copy size: " << copy.size() << std::endl;

	std::cout << "\n=== Test reverse iterator ===" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}

	return 0;
}
