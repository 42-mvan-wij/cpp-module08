#include <iostream>
#include "Span.hpp"

Span::Span() : max_n(0) {
	std::cout << "Span::Span() called" << std::endl;
}

Span::Span(unsigned int n) : max_n(n) {}

Span::Span(const Span &src) : max_n(src.max_n) {
	std::cout << "Span::Span(const Span &) called" << std::endl;
	*this = src;
}

Span::~Span() {
	std::cout << "Span destructor called" << std::endl;
}

Span &Span::operator=(Span const &rhs) {
	content = rhs.content;
	return *this;
}

void Span::addNumber(int num) {
	if (content.size() >= max_n) {
		throw Span::SpanFull();
	}
	content.push_back(num);
}

unsigned int Span::longestSpan() {
	if (content.size() < 2) {
		throw Span::SpanTooSmall();
	}
	std::sort(content.begin(), content.end());
	return (content[content.size() - 1] - content[0]);
}

unsigned int Span::shortestSpan() {
	if (content.size() < 2) {
		throw Span::SpanTooSmall();
	}
	std::sort(content.begin(), content.end());
	unsigned int min = content[1] - content[0];
	for (size_t i = 0; i < content.size() - 1; i++) {
		unsigned int dif = content[i + 1] - content[i];
		if (dif < min)
			min = dif;
	}
	return min;
}
