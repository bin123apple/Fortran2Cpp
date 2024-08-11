#include <iostream>
#include <vector>
#include <string>
#include <utility> // For std::pair

// Define a class to manage relationships
class GreatRelationships {
public:
    void great(const std::string& entity1, const std::string& entity2) {
        relationships.push_back(std::make_pair(entity1, entity2));
    }

    void printRelationships() const {
        for (const auto& relationship : relationships) {
            std::cout << relationship.first << " -> " << relationship.second << std::endl;
        }
    }

private:
    std::vector<std::pair<std::string, std::string>> relationships;
};

// A simple test function to demonstrate the class functionality
void testGreatRelationships() {
    GreatRelationships gr;

    // Add some relationships
    gr.great("Entity1", "Entity2");
    gr.great("Entity3", "Entity4");
    gr.great("Entity5", "Entity6");

    // Print relationships to verify
    std::cout << "Testing relationships:" << std::endl;
    gr.printRelationships();
}

int main() {
    // Run our simple test
    testGreatRelationships();

    return 0;
}