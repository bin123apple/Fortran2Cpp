#include <iostream>
#include <vector>
#include <memory>

// Define the Block class
class Block {
public:
    std::vector<float> fields;

    Block() = default;

    Block(float value) {
        fields.push_back(value);
    }
};

// Define the List class
class List {
public:
    std::shared_ptr<Block> B;

    List() = default;

    List(const Block& block) {
        B = std::make_shared<Block>(block);
    }
};

// Define the Domain class
class Domain {
public:
    std::vector<List> L;

    Domain() : L(2) {}
};

int main() {
    // Create a domain instance
    Domain d;
    
    // Create a block instance and initialize its fields
    Block b1(5.0);

    // Allocate and initialize the block in the second list of the domain
    d.L[1].B = std::make_shared<Block>(b1);

    // Check if the value is as expected
    if (d.L[1].B->fields[0] != 5.0) {
        std::cerr << "STOP 1" << std::endl;
        return 1;
    }

    return 0;
}