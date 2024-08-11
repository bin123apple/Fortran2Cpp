#include <iostream>
#include <string>
#include <algorithm>

// Assuming greet_mod functionality
namespace greet_mod {
    void greet(const std::string& name) {
        std::cout << "Hello, " << name << "!" << std::endl;
    }
}

// Assuming world_mod functionality
namespace world_mod {
    std::string world = " World ";
}

// A simple manual test function
void testGreetFunction() {
    std::cout << "Starting test..." << std::endl;
    
    // Test 1: Trim and greet
    std::string testWorld = " Test World ";
    testWorld.erase(0, testWorld.find_first_not_of(" "));
    testWorld.erase(testWorld.find_last_not_of(" ") + 1);
    
    std::cout << "Test 1 - Expected: Hello, Test World! | Got: ";
    greet_mod::greet(testWorld);
    
    // Additional tests can be added here following the same pattern
    std::cout << "Test completed." << std::endl;
}

int main() {
    // Main functionality
    std::string trimmedWorld = world_mod::world;
    trimmedWorld.erase(0, trimmedWorld.find_first_not_of(" "));
    trimmedWorld.erase(trimmedWorld.find_last_not_of(" ") + 1);
    greet_mod::greet(trimmedWorld);
    
    // Testing
    testGreetFunction();
    
    return 0;
}