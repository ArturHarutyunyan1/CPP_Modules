#include "Serializer.hpp"

int main() {
    // Create a Data instance
    Data data = {42, "Hello"};

    // Serialize the Data pointer
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value: " << raw << std::endl;

    // Deserialize back to a Data pointer
    Data* deserializedPtr = Serializer::deserialize(raw);
    std::cout << "Deserialized value - Number: " << deserializedPtr->number 
              << ", Text: " << deserializedPtr->text << std::endl;

    // Compare addresses
    if (deserializedPtr == &data) {
        std::cout << "Test passed: Deserialized pointer matches original." << std::endl;
    } else {
        std::cout << "Test failed: Deserialized pointer does not match original." << std::endl;
    }

    return 0;
}