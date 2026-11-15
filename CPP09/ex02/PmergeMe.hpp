#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <deque>
#include <string>
#include <vector>

class PmergeMe
{
private:
	std::vector<int>	_input;	// parsed arguments, original order
	std::vector<int>	_vec;	// sorted with the vector implementation
	std::deque<int>		_deq;	// sorted with the deque implementation
	std::size_t			_vecComparisons;
	std::size_t			_deqComparisons;

	static bool	parseToken(const std::string &token, int &out);

	// Ford-Johnson on indices into the container, so equal values keep
	// track of their own partner (duplicates are allowed).
	std::vector<std::size_t>	fordJohnsonVector(const std::vector<std::size_t> &items);
	std::deque<std::size_t>		fordJohnsonDeque(const std::deque<std::size_t> &items);

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void	parse(int argc, char **argv);	// throws on invalid input
	double	sortVector();					// returns elapsed microseconds
	double	sortDeque();					// returns elapsed microseconds

	const std::vector<int>	&getInput() const;
	const std::vector<int>	&getVector() const;
	const std::deque<int>	&getDeque() const;
	std::size_t				getVectorComparisons() const;
	std::size_t				getDequeComparisons() const;
};

#endif
