#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
	std::vector<int> vec; // [10, 20, 30, 42]
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(42);

	std::list<int> lst; // [5, 15, 25]
	lst.push_back(5);
	lst.push_back(15);
	lst.push_back(20);
	lst.push_back(25);

	try {
		std::vector<int>::iterator it = easyfind(vec, 42);
		std::cout << "Found in vector: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator it = easyfind(vec, 100);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << "100 in vector: " << e.what() << std::endl;
	}

	try {
		std::list<int>::iterator it = easyfind(lst, 15);
		std::cout << "Found in list: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::list<int>::iterator it = easyfind(lst, 999);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << "999 in list: " << e.what() << std::endl;
	}

	return (0);
}
