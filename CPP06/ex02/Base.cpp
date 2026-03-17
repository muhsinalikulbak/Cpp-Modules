#include "Base.hpp"
#include <cstdlib>
#include <ctime>

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
    // Girilen pointer'ın hangi nesne olduğu (A, B, C) print edilicek.
}

void  identify(Base& p)
{
    // Girilen referansın hangi nesne olduğu (A, B, C) print edilecek
}

// Burada cast işlemleri gerçek tür öğrenilecek


Base* createA()
{
    return new C();
}

Base* createB()
{
    return new B();
}

Base* createC()
{
    return new C();
}
