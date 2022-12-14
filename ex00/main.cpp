#include <iostream>
#include <vector>
#include <cstdlib>
#include "easyfind.hpp"

void check_leaks() {
	std::cout << std::endl;
	std::system("leaks -q easy-find");
}

int main() {
	std::atexit(&check_leaks);
	std::cout << std::boolalpha;

	std::vector<int> v;
	v.push_back(3);
	v.push_back(5);
	v.push_back(234);
	v.push_back(33);
	v.push_back(12);
	v.push_back(5);
	v.push_back(32);

	std::cout << "five = easyfind(v, 5)" << std::endl;
	std::vector<int>::iterator five = easyfind(v, 5);
	bool found = (five != v.end());
	std::cout << "five found: " << found << std::endl;
	if (found) {
		std::cout << "*five: " << *five << std::endl;
		std::cout << "after five: " << five[1] << std::endl;
		std::cout << "*five = 12" << std::endl;
		*five = 12;
	}

	std::cout << std::endl;

	std::cout << "five = easyfind(v, 5)" << std::endl;
	five = easyfind(v, 5);
	found = (five != v.end());
	std::cout << "five found: " << found << std::endl;
	if (found) {
		std::cout << "*five: " << *five << std::endl;
		std::cout << "after five: " << five[1] << std::endl;
		std::cout << "*five = 8374" << std::endl;
		*five = 8374;
	}

	std::cout << std::endl;

	std::cout << "five = easyfind(v, 5)" << std::endl;
	five = easyfind(v, 5);
	found = (five != v.end());
	std::cout << "five found: " << found << std::endl;
	if (found) {
		std::cout << "*five: " << *five << std::endl;
		std::cout << "after five: " << five[1] << std::endl;
	}

	std::cout << std::endl;

	{
		const std::vector<int> const_v = v;

		std::cout << "five = easyfind(const_v, 5)" << std::endl;
		std::vector<int>::const_iterator five = easyfind(const_v, 5);
		bool found = (five != const_v.end());
		std::cout << "five found: " << found << std::endl;
		if (found) {
			std::cout << "*five: " << *five << std::endl;
			std::cout << "after five: " << five[1] << std::endl;
		}

		std::cout << std::endl;

		std::cout << "uncontained = easyfind(const_v, 847294)" << std::endl;
		std::vector<int>::const_iterator uncontained = easyfind(const_v, 847294);
		found = (uncontained != const_v.end());
		std::cout << "uncontained found: " << found << std::endl;
		if (found) {
			std::cout << "*uncontained: " << *uncontained << std::endl;
			std::cout << "after uncontained: " << uncontained[1] << std::endl;
		}
	}
	return (0);
}
