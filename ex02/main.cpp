#include <iostream>
#include <vector>
#include <cstdlib>
#include "MutantStack.hpp"

void check_leaks() {
	std::cout << std::endl;
	std::system("leaks -q mutant");
}

int main()
{
	std::atexit(&check_leaks);
	{
		std::cout << "MutantStack:" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << std::endl;

	{
		std::cout << "MutantStack:" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		const MutantStack<int> cmstack(mstack);

		{
			std::cout << "Mutable:" << std::endl;
			MutantStack<int>::iterator it = mstack.begin();
			MutantStack<int>::iterator ite = mstack.end();
			++it;
			--it;
			while (it != ite)
			{
				(*it) += 2;
				++it;
			}
			it = mstack.begin();
			ite = mstack.end();
			++it;
			--it;
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
		}

		{
			std::cout << "Immutable reverse:" << std::endl;
			MutantStack<int>::const_reverse_iterator it = cmstack.rbegin();
			MutantStack<int>::const_reverse_iterator ite = cmstack.rend();
			while (it != ite)
			{
				// (*it) += 2;
				++it;
			}
			it = cmstack.rbegin();
			ite = cmstack.rend();
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
		}

		std::stack<int> s(mstack);
	}

	std::cout << std::endl;

	{
		std::cout << "std::vector:" << std::endl;
		std::vector<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::vector<int>::iterator it = mstack.begin();
		std::vector<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return (EXIT_SUCCESS);
}
