# include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	v.push_back(6); v.push_back(7); v.push_back(1); v.push_back(66); v.push_back(2);

	std::list<int> l;
	l.push_back(6); l.push_back(7); l.push_back(1); l.push_back(66); l.push_back(2);
	
	try
	{
	std::vector<int>::iterator it = easyfind(v, 1);
        std::cout << "found: " << *it << std::endl;      // found: 43

        std::list<int>::iterator it2 = easyfind(l, 7);
        std::cout << "found: " << *it2 << std::endl;     // found: 20

        easyfind(v, 99);                                 // throws
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;              // error not found
    }
}