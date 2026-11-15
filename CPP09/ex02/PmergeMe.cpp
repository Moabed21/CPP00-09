#include "PmergeMe.hpp"

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <time.h>
#include <sstream>
#include <stdexcept>

/* ---------- comparators (compare values behind indices, count comparisons) ---------- */

namespace
{
	struct VectorLess
	{
		const std::vector<int>	*values;
		std::size_t				*count;

		VectorLess(const std::vector<int> *v, std::size_t *c) : values(v), count(c) {}
		bool operator()(std::size_t a, std::size_t b) const
		{
			++*count;
			return (*values)[a] < (*values)[b];
		}
	};

	struct DequeLess
	{
		const std::deque<int>	*values;
		std::size_t				*count;

		DequeLess(const std::deque<int> *v, std::size_t *c) : values(v), count(c) {}
		bool operator()(std::size_t a, std::size_t b) const
		{
			++*count;
			return (*values)[a] < (*values)[b];
		}
	};
}

static double nowMicroseconds()
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return static_cast<double>(ts.tv_sec) * 1000000.0 + static_cast<double>(ts.tv_nsec) / 1000.0;
}

/* ---------- canonical form ---------- */

PmergeMe::PmergeMe() : _vecComparisons(0), _deqComparisons(0) {}

PmergeMe::PmergeMe(const PmergeMe &other)
	: _input(other._input), _vec(other._vec), _deq(other._deq),
	  _vecComparisons(other._vecComparisons), _deqComparisons(other._deqComparisons) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_input = other._input;
		_vec = other._vec;
		_deq = other._deq;
		_vecComparisons = other._vecComparisons;
		_deqComparisons = other._deqComparisons;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

/* ---------- parsing ---------- */

// Digits only (no sign), value in [1, INT_MAX].
bool PmergeMe::parseToken(const std::string &token, int &out)
{
	if (token.empty() || token.size() > 10)
		return false;
	for (std::string::size_type i = 0; i < token.size(); ++i)
		if (token[i] < '0' || token[i] > '9')
			return false;
	long value = std::strtol(token.c_str(), NULL, 10);
	if (value < 1 || value > INT_MAX)
		return false;
	out = static_cast<int>(value);
	return true;
}

void PmergeMe::parse(int argc, char **argv)
{
	_input.clear();
	for (int i = 1; i < argc; ++i)
	{
		std::istringstream iss(argv[i]); // also accepts "3 5 9" as one argument
		std::string token;
		while (iss >> token)
		{
			int value;
			if (!parseToken(token, value))
				throw std::invalid_argument("invalid number: " + token);
			_input.push_back(value);
		}
	}
	if (_input.empty())
		throw std::invalid_argument("no input");
}

/* ---------- Ford-Johnson: std::vector ---------- */

std::vector<std::size_t> PmergeMe::fordJohnsonVector(const std::vector<std::size_t> &items)
{
	std::size_t n = items.size();
	if (n < 2)
		return items;

	VectorLess less(&_vec, &_vecComparisons);

	// 1. Pair up elements; the larger of each pair goes to `bigs`, remember its partner.
	std::vector<std::size_t> bigs;
	std::vector<std::size_t> partner(_vec.size());
	bigs.reserve(n / 2);
	for (std::size_t i = 0; i + 1 < n; i += 2)
	{
		std::size_t x = items[i];
		std::size_t y = items[i + 1];
		if (less(y, x))
		{
			bigs.push_back(x);
			partner[x] = y;
		}
		else
		{
			bigs.push_back(y);
			partner[y] = x;
		}
	}

	// 2. Recursively sort the larger elements: this is the main chain a1 <= a2 <= ...
	std::vector<std::size_t> sortedBigs = fordJohnsonVector(bigs);

	// 3. pend[j] = b(j+1), the partner of a(j+1); an odd leftover is the last pend, unbounded.
	std::vector<std::size_t> pend;
	pend.reserve(sortedBigs.size() + 1);
	for (std::size_t j = 0; j < sortedBigs.size(); ++j)
		pend.push_back(partner[sortedBigs[j]]);
	if (n % 2)
		pend.push_back(items[n - 1]);

	// 4. b1 <= a1, so it goes in front for free.
	std::vector<std::size_t> chain(sortedBigs);
	chain.insert(chain.begin(), pend[0]);

	// 5. Insert the rest in Jacobsthal groups (b3 b2, b5 b4, b11..b6, b21..b12, ...),
	//    each by binary search limited to the part of the chain before its partner.
	std::size_t prevJ = 1;
	std::size_t curJ = 3;
	std::size_t total = pend.size();
	while (prevJ < total)
	{
		std::size_t hi = std::min(curJ, total);
		for (std::size_t j = hi; j > prevJ; --j) // j is the 1-based b index
		{
			std::size_t elem = pend[j - 1];
			std::vector<std::size_t>::iterator bound = chain.end();
			if (j - 1 < sortedBigs.size())
				bound = std::find(chain.begin(), chain.end(), sortedBigs[j - 1]); // identity, not a value comparison
			std::vector<std::size_t>::iterator pos = std::upper_bound(chain.begin(), bound, elem, less);
			chain.insert(pos, elem);
		}
		std::size_t nextJ = curJ + 2 * prevJ;
		prevJ = curJ;
		curJ = nextJ;
	}
	return chain;
}

double PmergeMe::sortVector()
{
	double start = nowMicroseconds();

	_vecComparisons = 0;
	_vec.assign(_input.begin(), _input.end());
	std::vector<std::size_t> indices(_vec.size());
	for (std::size_t i = 0; i < indices.size(); ++i)
		indices[i] = i;
	indices = fordJohnsonVector(indices);
	std::vector<int> sorted;
	sorted.reserve(_vec.size());
	for (std::size_t i = 0; i < indices.size(); ++i)
		sorted.push_back(_vec[indices[i]]);
	_vec.swap(sorted);

	return nowMicroseconds() - start;
}

/* ---------- Ford-Johnson: std::deque ---------- */

std::deque<std::size_t> PmergeMe::fordJohnsonDeque(const std::deque<std::size_t> &items)
{
	std::size_t n = items.size();
	if (n < 2)
		return items;

	DequeLess less(&_deq, &_deqComparisons);

	std::deque<std::size_t> bigs;
	std::deque<std::size_t> partner(_deq.size());
	for (std::size_t i = 0; i + 1 < n; i += 2)
	{
		std::size_t x = items[i];
		std::size_t y = items[i + 1];
		if (less(y, x))
		{
			bigs.push_back(x);
			partner[x] = y;
		}
		else
		{
			bigs.push_back(y);
			partner[y] = x;
		}
	}

	std::deque<std::size_t> sortedBigs = fordJohnsonDeque(bigs);

	std::deque<std::size_t> pend;
	for (std::size_t j = 0; j < sortedBigs.size(); ++j)
		pend.push_back(partner[sortedBigs[j]]);
	if (n % 2)
		pend.push_back(items[n - 1]);

	std::deque<std::size_t> chain(sortedBigs);
	chain.push_front(pend[0]);

	std::size_t prevJ = 1;
	std::size_t curJ = 3;
	std::size_t total = pend.size();
	while (prevJ < total)
	{
		std::size_t hi = std::min(curJ, total);
		for (std::size_t j = hi; j > prevJ; --j)
		{
			std::size_t elem = pend[j - 1];
			std::deque<std::size_t>::iterator bound = chain.end();
			if (j - 1 < sortedBigs.size())
				bound = std::find(chain.begin(), chain.end(), sortedBigs[j - 1]);
			std::deque<std::size_t>::iterator pos = std::upper_bound(chain.begin(), bound, elem, less);
			chain.insert(pos, elem);
		}
		std::size_t nextJ = curJ + 2 * prevJ;
		prevJ = curJ;
		curJ = nextJ;
	}
	return chain;
}

double PmergeMe::sortDeque()
{
	double start = nowMicroseconds();

	_deqComparisons = 0;
	_deq.assign(_input.begin(), _input.end());
	std::deque<std::size_t> indices;
	for (std::size_t i = 0; i < _deq.size(); ++i)
		indices.push_back(i);
	indices = fordJohnsonDeque(indices);
	std::deque<int> sorted;
	for (std::size_t i = 0; i < indices.size(); ++i)
		sorted.push_back(_deq[indices[i]]);
	_deq.swap(sorted);

	return nowMicroseconds() - start;
}

/* ---------- getters ---------- */

const std::vector<int> &PmergeMe::getInput() const { return _input; }
const std::vector<int> &PmergeMe::getVector() const { return _vec; }
const std::deque<int> &PmergeMe::getDeque() const { return _deq; }
std::size_t PmergeMe::getVectorComparisons() const { return _vecComparisons; }
std::size_t PmergeMe::getDequeComparisons() const { return _deqComparisons; }
