#include <iostream>
#include <cstdlib>
#include <cassert>
#include "Span.hpp"

void check_leaks() {
	std::cout << std::endl;
	std::system("leaks -q span");
}

void printSpans(Span& s, unsigned int expect_short, unsigned int expect_long) {
	std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
	std::cout << "Longest span : " << s.longestSpan() << std::endl;
	assert(expect_short == s.shortestSpan());
	assert(expect_long == s.longestSpan());
}

int main() {
	std::atexit(&check_leaks);
	Span			 span1 = Span(10);
	std::vector<int> vec;
	std::cout << "\n\n--> Test with an overflow with iterator" << std::endl;
	for (int i = 0; i < 10; i++)
		vec.push_back(i * -20);
	try {
		span1.addNumber(10);
		span1.addNumber(10);
		span1.addNumber(10);
		span1.addNumber(10);
		span1.addNumber(10);
		std::cout << "now try iterator" << std::endl;
		span1.addNumbers(vec.begin(), vec.end());
	} catch (std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	printSpans(span1, 0, 90);

	Span span2 = Span(5);
	std::cout << "\n\n--> Test with an overflow with addNumber" << std::endl;
	try {
		span2.addNumber(5);
		span2.addNumber(3);
		span2.addNumber(17);
		span2.addNumber(9);
		span2.addNumber(11);
		span2.addNumber(999999);
	} catch (std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	printSpans(span2, 2, 14);
	std::cout << "\n\n--> Test with a short span object" << std::endl;
	Span tooShort = Span(1);
	tooShort.addNumber(42);

	try {
		std::cout << tooShort.shortestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try {
		std::cout << tooShort.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	Span span3(100000);
	std::vector<int> vec2;
	for (int i = 0; i < 100000; i++)
		vec2.push_back(i * 69);
	span3.addNumbers(vec2.begin(), vec2.end());
	printSpans(span3, 69, 99999 * 69);

	std::cout << "\n\n--> subject test" << std::endl;
	Span spb = Span(5);
	spb.addNumber(5);
	spb.addNumber(3);
	spb.addNumber(17);
	spb.addNumber(9);
	spb.addNumber(11);
	printSpans(spb, 2, 14);

	return (EXIT_SUCCESS);
}
