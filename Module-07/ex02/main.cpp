#include "Array.hpp" // Include your Array class header

int main() {
    try {
        // Test 1: Default constructor (empty array)
        Array<int> emptyArray;
        std::cout << "Size of emptyArray: " << emptyArray.size() << std::endl;

        // Test 2: Constructor with parameter (array of n elements initialized by default)
        Array<int> arrayWithSize(5);
        std::cout << "Size of arrayWithSize: " << arrayWithSize.size() << std::endl;
        std::cout << "Elements of arrayWithSize (uninitialized values):" << std::endl;
        for (unsigned int i = 0; i < arrayWithSize.size(); ++i) {
            std::cout << arrayWithSize[i] << " ";
        }
        std::cout << std::endl;

        // Test 3: Copy constructor
        Array<int> copiedArray(arrayWithSize);
        std::cout << "Size of copiedArray: " << copiedArray.size() << std::endl;
        std::cout << "Elements of copiedArray after copy (should match arrayWithSize):" << std::endl;
        for (unsigned int i = 0; i < copiedArray.size(); ++i) {
            std::cout << copiedArray[i] << " ";
        }
        std::cout << std::endl;

        // Test 4: Modify the copied array and check independence from original
        copiedArray[0] = 10;
        std::cout << "After modifying copiedArray[0] to 10:" << std::endl;
        std::cout << "copiedArray[0]: " << copiedArray[0] << std::endl;
        std::cout << "arrayWithSize[0] (should remain unchanged): " << arrayWithSize[0] << std::endl;

        // Test 5: Assignment operator
        Array<int> assignedArray = arrayWithSize;
        std::cout << "Size of assignedArray: " << assignedArray.size() << std::endl;
        std::cout << "Elements of assignedArray after assignment (should match arrayWithSize):" << std::endl;
        for (unsigned int i = 0; i < assignedArray.size(); ++i) {
            std::cout << assignedArray[i] << " ";
        }
        std::cout << std::endl;

        // Test 6: Access out-of-bounds index
        std::cout << "Attempting to access out-of-bounds index in assignedArray..." << std::endl;
        std::cout << assignedArray[10] << std::endl; // This should throw an exception

        // Test 7: Memory Leak Simulation
        std::cout << "Testing memory leak simulation..." << std::endl;
        Array<int>* leakArray = new Array<int>(5); // Dynamically allocate an array
        // Intentionally not deleting leakArray to simulate a memory leak
        std::cout << "Created leakArray with size: " << leakArray->size() << std::endl;
        // You would normally need to delete leakArray; however, we're intentionally skipping that

        // The following line simulates the scope where you would typically delete the array
        // delete leakArray; // Uncomment this line to prevent the leak

        // Test 8: Another Memory Leak Simulation
        std::cout << "Creating another leak..." << std::endl;
        Array<int>* anotherLeak = new Array<int>(10); // Another leak
        std::cout << "Created anotherLeak with size: " << anotherLeak->size() << std::endl;

        // Remember to comment out or handle the delete to see the leak behavior
        // delete anotherLeak; // Uncomment this line to prevent the leak

    } 
    catch (const std::out_of_range &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}