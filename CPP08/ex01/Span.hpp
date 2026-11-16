#pragma once
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iostream>

class Span
{
private:
	std::vector<int> v;
	unsigned int size;
public:
	Span(unsigned int N);
	Span( const Span &o);
	Span &operator=(const Span &n);
	void addNumber(int n);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;
	template <typename I>
	void addRange(I begin, I end);
	~Span();
};

