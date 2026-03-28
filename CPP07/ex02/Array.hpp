#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>

class Array
{
private:
	unsigned int _size;
	T* _elements;
	
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	~Array();
	
	Array& operator = (const Array& rhs);

	T& operator [] (unsigned int index);
	const T& operator [] (unsigned int index) const;

	unsigned int size() const;
};
#include "Array.tpp"

#endif