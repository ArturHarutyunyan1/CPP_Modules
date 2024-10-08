#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

bool testAMateria() {
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    bool result = true;

    // Test type
    if (ice->getType() != "ice") {
        std::cout << "testAMateria: Ice type test failed." << std::endl;
        result = false;
    }
    if (cure->getType() != "cure") {
        std::cout << "testAMateria: Cure type test failed." << std::endl;
        result = false;
    }

    // Test clone
    AMateria* iceClone = ice->clone();
    if (iceClone->getType() != "ice") {
        std::cout << "testAMateria: Ice clone test failed." << std::endl;
        result = false;
    }
    delete iceClone;

    AMateria* cureClone = cure->clone();
    if (cureClone->getType() != "cure") {
        std::cout << "testAMateria: Cure clone test failed." << std::endl;
        result = false;
    }
    delete cureClone;

    delete ice;
    delete cure;

    return result;
}

bool testMateriaSource() {
    IMateriaSource* source = new MateriaSource();
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    bool result = true;

    source->learnMateria(ice);
    source->learnMateria(cure);

    AMateria* iceCopy = source->createMateria("ice");
    AMateria* cureCopy = source->createMateria("cure");
    AMateria* unknownCopy = source->createMateria("unknown");

    if (iceCopy == nullptr) {
        std::cout << "testMateriaSource: Ice copy test failed." << std::endl;
        result = false;
    }
    if (cureCopy == nullptr) {
        std::cout << "testMateriaSource: Cure copy test failed." << std::endl;
        result = false;
    }
    if (unknownCopy != nullptr) {
        std::cout << "testMateriaSource: Unknown copy test failed." << std::endl;
        result = false;
    }

    if (iceCopy && iceCopy->getType() != "ice") {
        std::cout << "testMateriaSource: Ice copy type test failed." << std::endl;
        result = false;
    }
    if (cureCopy && cureCopy->getType() != "cure") {
        std::cout << "testMateriaSource: Cure copy type test failed." << std::endl;
        result = false;
    }

    delete iceCopy;
    delete cureCopy;
    delete source;

    return result;
}

bool testCharacter() {
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");
    IMateriaSource* source = new MateriaSource();
    bool result = true;

    AMateria* ice = new Ice();
    AMateria* cure = new Cure();

    source->learnMateria(ice);
    source->learnMateria(cure);

    me->equip(source->createMateria("ice"));
    me->equip(source->createMateria("cure"));

    // Capture output with redirection or mocking
    // Here we would ideally redirect the output to check if the expected strings are printed.
    // This requires additional setup and might be complex without a proper framework.

    // Using Materia on Bob
    me->use(0, *bob); // Should shoot ice bolt
    me->use(1, *bob); // Should heal wounds

    // Ideally, here we would verify the printed output using a mocking framework or redirecting output.

    delete bob;
    delete me;
    delete source;

    return result;
}

void runTests() {
    std::cout << "Running tests..." << std::endl;

    if (testAMateria()) {
        std::cout << "AMateria tests passed." << std::endl;
    } else {
        std::cout << "AMateria tests failed." << std::endl;
    }

    std::cout << "--------------------------" << std::endl; // Separator

    if (testMateriaSource()) {
        std::cout << "MateriaSource tests passed." << std::endl;
    } else {
        std::cout << "MateriaSource tests failed." << std::endl;
    }

    std::cout << "--------------------------" << std::endl; // Separator

    if (testCharacter()) {
        std::cout << "Character tests passed." << std::endl;
    } else {
        std::cout << "Character tests failed." << std::endl;
    }

    std::cout << "--------------------------" << std::endl; // Final separator
}

int main() {
    runTests();
    return 0;
}