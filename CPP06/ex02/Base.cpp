#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>

Base::Base()
{

}

Base::~Base()
{

}

Base * generate(void)
{
    static bool seed = true;
    int selection = 0;
    Base* (*func[3]) (void);

    func[0] = createA;
    func[1] = createB;
    func[2] = createC;
    

    if (seed)
    {
        std::srand(static_cast<unsigned int>(std::time(0)));
        seed = false;
    }

    selection = std::rand() % 3;
    return func[selection]();
}

void  identify(Base* p)
{
    std::cout << "Type is ";

    if (p == NULL)
        std::cout << "null" << std::endl;
    else if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "unknown" << std::endl;
}

void  identify(Base& p)
{
    std::cout << "Type is ";

    try
    {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch(const std::bad_cast&)
    {
    }

    try
    {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch(const std::bad_cast&)
    {
    }

    try
    {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch(const std::bad_cast&)
    {
        std::cout << "unknown" << std::endl;
    }
}

// Burada cast işlemleri gerçek tür öğrenilecek


Base* createA()
{
    return new A();
}

Base* createB()
{
    return new B();
}

Base* createC()
{
    return new C();
}
