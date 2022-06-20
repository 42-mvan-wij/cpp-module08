#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template<typename T>
typename T::iterator easyfind(T container, int item) {
	typename T::iterator it = std::find(container.begin(), container.end(), item);
	if (it == container.end())
		throw std::exception();
	return it;
};

#endif
