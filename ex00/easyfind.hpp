#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template<typename T>
typename T::iterator easyfind(T &container, int item) {
	return std::find(container.begin(), container.end(), item);
}

template<typename T>
typename T::const_iterator easyfind(T const &container, int item) {
	return std::find(container.begin(), container.end(), item);
}

#endif
