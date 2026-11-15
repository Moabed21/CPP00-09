#include "RPN.hpp"

#include <climits>
#include <sstream>
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

// Pops b (top) then a, pushes a <op> b. Throws on missing operands, division by zero or overflow.
void RPN::applyOperator(char op)
{
	if (_stack.size() < 2)
		throw std::runtime_error("not enough operands");
	long b = _stack.top();
	_stack.pop();
	long a = _stack.top();
	_stack.pop();

	long result = 0;
	switch (op)
	{
	case '+':
		if ((b > 0 && a > LONG_MAX - b) || (b < 0 && a < LONG_MIN - b))
			throw std::overflow_error("overflow");
		result = a + b;
		break;
	case '-':
		if ((b < 0 && a > LONG_MAX + b) || (b > 0 && a < LONG_MIN + b))
			throw std::overflow_error("overflow");
		result = a - b;
		break;
	case '*':
		if (a != 0 && b != 0)
		{
			if ((a == -1 && b == LONG_MIN) || (b == -1 && a == LONG_MIN))
				throw std::overflow_error("overflow");
			if (a != -1 && b != -1)
			{
				long r = a * b; // checked below via division
				if (r / b != a)
					throw std::overflow_error("overflow");
			}
		}
		result = a * b;
		break;
	case '/':
		if (b == 0)
			throw std::runtime_error("division by zero");
		if (a == LONG_MIN && b == -1)
			throw std::overflow_error("overflow");
		result = a / b;
		break;
	}
	_stack.push(result);
}

long RPN::evaluate(const std::string &expression)
{
	while (!_stack.empty())
		_stack.pop();

	std::istringstream iss(expression);
	std::string token;
	while (iss >> token)
	{
		if (token.size() != 1)
			throw std::runtime_error("invalid token");
		char c = token[0];
		if (c >= '0' && c <= '9')
			_stack.push(c - '0');
		else if (c == '+' || c == '-' || c == '*' || c == '/')
			applyOperator(c);
		else
			throw std::runtime_error("invalid token");
	}
	if (_stack.size() != 1)
		throw std::runtime_error("invalid expression");
	return _stack.top();
}
