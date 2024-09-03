#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "Animal.hpp"

#define NUM_ANIMALS 4

int main() {
    // Test dynamic creation and deletion to ensure no memory leaks
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;  // should not create a memory leak
    delete i;

    std::cout << "\nCreating an array of Animals with interesting ideas:\n" << std::endl;

    // Create an array of Animals, half Dogs and half Cats
    Animal* animals[NUM_ANIMALS];
    for (int i = 0; i < NUM_ANIMALS / 2; ++i) {
        Dog* dog = new Dog();
        dog->setIdea(0, "Chase the mailman");
        dog->setIdea(1, "Dig a hole in the yard");
        dog->setIdea(2, "Chew on a bone");
        dog->setIdea(3, "Take a nap in the sun");
        animals[i] = dog;
    }
    for (int i = NUM_ANIMALS / 2; i < NUM_ANIMALS; ++i) {
        Cat* cat = new Cat();
        cat->setIdea(0, "Climb a tree");
        cat->setIdea(1, "Play with a ball of yarn");
        cat->setIdea(2, "Stalk a mouse");
        cat->setIdea(3, "Curl up in a cozy spot");
        animals[i] = cat;
    }

    std::cout << "\nTesting makeSound and Brain functionality:\n" << std::endl;

    // Test the makeSound and Brain functionality
    for (int i = 0; i < NUM_ANIMALS; ++i) {
        animals[i]->makeSound();

        Dog* dog = dynamic_cast<Dog*>(animals[i]);
        if (dog) {
            dog->getIdeas();  // Print all Dog's brain ideas
        }

        Cat* cat = dynamic_cast<Cat*>(animals[i]);
        if (cat) {
            cat->getIdeas();  // Assuming similar getIdeas() in Cat class
        }
    }

    std::cout << "\nDeep Copy Tests:\n" << std::endl;

    // Test deep copy for Dog
    Dog* originalDog = new Dog();
    originalDog->setIdea(0, "Fetch the newspaper");
    originalDog->setIdea(1, "Bark at the neighbor's cat");
    originalDog->setIdea(2, "Run around in circles");
    originalDog->setIdea(3, "Roll over for treats");
    Dog* copiedDog = new Dog(*originalDog);
    std::cout << "Original Dog Brain Ideas: " << std::endl;
    originalDog->getIdeas();
    std::cout << "Copied Dog Brain Ideas: " << std::endl;
    copiedDog->getIdeas();

    // Modifying the original dog's idea to check if the copied dog's idea remains unchanged
    originalDog->setIdea(0, "Sleep on the couch");
    std::cout << "Modified Original Dog Brain Ideas: " << std::endl;
    originalDog->getIdeas();
    std::cout << "Copied Dog Brain Ideas After Modification: " << std::endl;
    copiedDog->getIdeas();

    delete originalDog;
    delete copiedDog;

    // Test deep copy for Cat
    Cat* originalCat = new Cat();
    originalCat->setIdea(0, "Watch the birds outside");
    originalCat->setIdea(1, "Scratch the furniture");
    originalCat->setIdea(2, "Hide in a box");
    originalCat->setIdea(3, "Chase a laser pointer");
    Cat* copiedCat = new Cat(*originalCat);
    std::cout << "Original Cat Brain Ideas: " << std::endl;
    originalCat->getIdeas();  // Assuming similar getIdeas() in Cat class
    std::cout << "Copied Cat Brain Ideas: " << std::endl;
    copiedCat->getIdeas();

    // Modifying the original cat's idea to check if the copied cat's idea remains unchanged
    originalCat->setIdea(0, "Nap in a sunbeam");
    std::cout << "Modified Original Cat Brain Ideas: " << std::endl;
    originalCat->getIdeas();
    std::cout << "Copied Cat Brain Ideas After Modification: " << std::endl;
    copiedCat->getIdeas();

    delete originalCat;
    delete copiedCat;

    std::cout << "\nDeleting the array of Animals:\n" << std::endl;

    // Delete all animals in the array
    for (int i = 0; i < NUM_ANIMALS; ++i) {
        delete animals[i];
    }

    std::cout << "\nEnd of program execution. No memory leaks should occur.\n" << std::endl;

    return 0;
}