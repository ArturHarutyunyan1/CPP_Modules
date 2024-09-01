#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void testConstructorsAndDestructors() {
    std::cout << "=== Test Constructors and Destructors ===" << std::endl;
    
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    

    delete animal;
    delete dog;
    delete cat;
    
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    delete wrongAnimal;
    delete wrongCat;
    
    std::cout << "========================================" << std::endl;
}

void testPolymorphism() {
    std::cout << "=== Test Polymorphism ===" << std::endl;
    
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << "Dog type: " << dog->getType() << std::endl;
    dog->makeSound(); // Should call Dog's makeSound
    
    std::cout << "Cat type: " << cat->getType() << std::endl;
    cat->makeSound(); // Should call Cat's makeSound
    
    delete dog;
    delete cat;
    
    std::cout << "=========================" << std::endl;
}

void testNonPolymorphicBehavior() {
    std::cout << "=== Test Non-Polymorphic Behavior ===" << std::endl;
    
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
    wrongCat->makeSound(); // Should call WrongAnimal's makeSound
    
    delete wrongCat;
    
    std::cout << "======================================" << std::endl;
}

void testMixedBehavior() {
    std::cout << "=== Test Mixed Behavior ===" << std::endl;
    
    const Animal* animals[3];
    animals[0] = new Animal();
    animals[1] = new Dog();
    animals[2] = new Cat();
    
    for (int i = 0; i < 3; ++i) {
        std::cout << "Animal type: " << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
    }
    
    for (int i = 0; i < 3; ++i) {
        delete animals[i];
    }
    
    const WrongAnimal* wrongAnimals[2];
    wrongAnimals[0] = new WrongAnimal();
    wrongAnimals[1] = new WrongCat();
    
    for (int i = 0; i < 2; ++i) {
        std::cout << "WrongAnimal type: " << wrongAnimals[i]->getType() << std::endl;
        wrongAnimals[i]->makeSound();
    }
    
    for (int i = 0; i < 2; ++i) {
        delete wrongAnimals[i];
    }
    
    std::cout << "============================" << std::endl;
}

int main() {
    testConstructorsAndDestructors();
    testPolymorphism();
    testNonPolymorphicBehavior();
    testMixedBehavior();
    return 0;
}