#ifndef ARRAY_HPP
#define ARRAY_HPP

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

// Burada Array[] oluşturmamızı istiyor. Main içerisinde Array den istenilen tipte
// array oluşturulabilir ve sanırım [] operatörünü burada overload etmeme gerekiyor.
// İndex taşmasında kendim exception fırlatacağıma göre [] overload edicem.



#endif