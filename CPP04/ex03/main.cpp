#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"


int main()
{
    std::cout << "=== Test 1: Cannot instantiate abstract class ===" << std::endl;
    std::cout << "// Animal* a = new Animal(); // Compilation ERROR!" << std::endl;
    std::cout << "// Because Animal::makeSound() is pure virtual\n" << std::endl;

    std::cout << "=== Test 2: Basic Animal Creation ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    std::cout << "\n=== Test 3: Deep Copy Test ===" << std::endl;
    Dog basic;
    {
        Dog tmp = basic;
        std::cout << "(tmp destroyed here)" << std::endl;
    }
    std::cout << "(basic still exists = Deep copy works!)\n" << std::endl;

    std::cout << "=== Test 4: Array of Animals ===" << std::endl;
    const int size = 4;
    Animal* animals[size];
    
    animals[0] = new Dog();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Cat();
    
    for (int k = 0; k < size; k++)
        delete animals[k];

    return 0;
}
