#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span {
	private:
		Span();

	public:
		Span(unsigned int n);
		virtual ~Span();

		Span(Span const &src);
		Span &operator=(Span const &rhs);

		void addNumber(int num);
		unsigned int shortestSpan();
		unsigned int longestSpan();

		template<class Iterator>
		void addNumbers(Iterator begin, Iterator end) {
			while (begin != end) {
				addNumber(*begin);
				begin++;
			}
		};

		class SpanFull : public std::exception {
			virtual const char* what() const throw() { return "Span::SpanFull"; };
		};

		class SpanTooSmall : public std::exception {
			virtual const char* what() const throw() { return "Span::SpanTooSmall"; };
		};

	protected:
		std::vector<int> content;
		const unsigned int max_n;
};

#endif
