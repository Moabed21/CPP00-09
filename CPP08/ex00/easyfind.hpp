#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <list>
#include <vector>
# include <iostream>
# include <algorithm>   // std::find
# include <stdexcept>   // std::runtime_error

template <typename T>
typename T::iterator easyfind(T& c, int n) {
    typename T::iterator it = std::find(c.begin(), c.end(), n);
    if (it == c.end())
        throw std::runtime_error("error not found");
    return it;
}

#endif
