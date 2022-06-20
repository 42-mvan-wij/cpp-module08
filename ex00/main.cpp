#include <iostream>
#include <vector>
#include "easyfind.hpp"

__attribute__((destructor))
void check_leaks() {
	std::cout << std::endl;
	system("leaks -q easy-find");
}

int main() {
	std::vector<int> v;
	v.push_back(3);
	v.push_back(5);
	v.push_back(234);
	v.push_back(33);
	v.push_back(12);
	v.push_back(5);
	v.push_back(32);

	std::cout << *easyfind(v, 5) << std::endl;
	return (0);
}
