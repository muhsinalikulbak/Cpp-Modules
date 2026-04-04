#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class NumberNotFound : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Number Not Found";
		}
};

template <typename T>

typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw NumberNotFound();
	return it;
}



#endif