#include "Base.hpp"


Base::Base()
{

}

Base::~Base()
{

}

Base * Base::generate(void)
{
    // Burada random olarak A, B ya da C nesnesi oluşturulup döndürülecek
}

void Base::identify(Base* p)
{
    // Girilen pointer'ın hangi nesne olduğu (A, B, C) print edilicek.
}

void Base::identify(Base& p)
{
    // Girilen referansın hangi nesne olduğu (A, B, C) print edilecek
}

// Burada cast işlemleri gerçek tür öğrenilecek