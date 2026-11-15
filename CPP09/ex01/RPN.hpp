#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <stack>
#include <string>

class RPN
{
private:
	// std::list as the underlying container instead of the default one,
	// which keeps ex02's containers unused here.
	std::stack<long, std::list<long> > _stack;

	void	applyOperator(char op);

public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	long	evaluate(const std::string &expression);
};

#endif
