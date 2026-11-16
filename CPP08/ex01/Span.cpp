#include "Span.hpp"

Span::Span( const Span &o):v(o.v), size(o.size){}

Span &Span::operator=(const Span &n)
{
	if(this != &n)
	{
		v = n.v;
		size = n.size;
	}
	return *this;
}

Span::Span(unsigned int N): size(N)
{
	if(N == 0)
		throw std::runtime_error("Out of Range");
}

void Span::addNumber( int n)
{
	if(v.size() >= this->size)
		throw std::runtime_error("Out of Range");
	else
		v.push_back(n);
	
}

unsigned int	Span::shortestSpan() const
{
	int value;
	if (this->v.size() <= 1)
		throw std::runtime_error("Out of Range");
	else
	{
		std::vector<int> tmp = this->v;
		std::sort(tmp.begin(), tmp.end());
		value = tmp[1] - tmp[0];
		for (int i = 0; i < static_cast<int>(v.size()) - 1; i++)
		{
			if (std::abs(tmp[i + 1] - tmp[i]) < value)
				value = std::abs(tmp[i + 1] - tmp[i]);
		}
	}
	return (static_cast<unsigned int>(value));
}

unsigned int	Span::longestSpan() const
{
	int value;
	if (this->v.size() <= 1)
		throw std::runtime_error("Out of Range");
	else
	{
		std::vector<int> tmp = this->v;
		std::sort(tmp.begin(), tmp.end());
		value = tmp[static_cast<int>(v.size()) - 1] - tmp[0];
	}
	return (static_cast<unsigned int>(value));
}

template <typename I>
void Span::addRange(I begin, I end) 
{
	if (std::distance(begin, end) > static_cast<long>(size - v.size()))
	    throw std::runtime_error("Out of Range");
	v.insert(v.end(), begin, end);
}

Span::~Span()
{
}