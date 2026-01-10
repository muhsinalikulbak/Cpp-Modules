
#include "Fixed.hpp"

int main()
{
    Fixed fixed = Fixed(0.1f) + Fixed(0.2f);
    std::cout << fixed.toFloat() << std::endl;
}
