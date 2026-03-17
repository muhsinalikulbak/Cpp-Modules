#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>


int main()
{
    std::cout << "[Test 1] generate() with pointer/ref identify" << std::endl;
    
    Base* base = generate();
    identify(base);

    if (base)
        identify(*base);
    delete base;

    std::cout << "\n[Test 2] explicit A/B/C objects" << std::endl;

    Base* a = new A();
    Base* b = new B();
    Base* c = new C();

    identify(a);
    identify(*a);

    identify(b);
    identify(*b);

    identify(c);
    identify(*c);

    delete a;
    delete b;
    delete c;

    std::cout << "\n[Test 3] null pointer" << std::endl;
    identify(NULL);

    std::cout << "\n[Test 4] multiple random generations" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        Base* sample = generate();
        identify(sample);
        delete sample;
    }
    
    return 0;
}
