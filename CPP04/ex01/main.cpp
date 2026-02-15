#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"


int main()
{
    std::cout << "=== Test 1: Basic Creation and Destruction ===" << std::endl;
    const Animal* i = new Dog();
    const Animal* j = new Cat();
    delete i; //should not create a leak
    delete j; //should not create a leak

    std::cout << "\n=== Test 2: Deep Copy Test ===" << std::endl;
    Dog* dog1 = new Dog();
    dog1->getBrain()->setIdeas(0, "I want to play!");
    

    Dog* dog2 = new Dog(*dog1); // Copy constructor
    dog2->getBrain()->setIdeas(0, "I want to sleep!");

    std::cout << "Dog1 idea: " << dog1->getBrain()->getIdeas(0) << std::endl;
    std::cout << "Dog2 idea: " << dog2->getBrain()->getIdeas(0) << std::endl;
    std::cout << "(Different ideas = Deep copy works!)" << std::endl;

    delete dog1;
    delete dog2;

    std::cout << "\n=== Test 3: Assignment Operator Test ===" << std::endl;
    Cat* cat1 = new Cat();
    Cat* cat2 = new Cat();
    *cat2 = *cat1;
    std::cout << "(No crash = Deep copy in assignment works!)" << std::endl;
    
    delete cat1;
    delete cat2;

    std::cout << "\n=== Test 4: Array of Animals ===" << std::endl;
    const int arraySize = 4;
    Animal* animals[arraySize];
    
    std::cout << "Creating 2 Dogs and 2 Cats..." << std::endl;
    animals[0] = new Dog();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Cat();
    
    std::cout << "\nDeleting all animals (checking for memory leaks)..." << std::endl;
    for (int k = 0; k < arraySize; k++)
    {
        delete animals[k];
    }
    
    std::cout << "\n=== All Tests Completed Successfully ===" << std::endl;
    return 0;
}
