#include <iostream>
#include <cassert>

// Declaration and implementation of the Clawpack46Block class in a single file
class Clawpack46Block {
public:
    // Function to set the block number
    static void setBlock(int blockno) {
        blockno_com = blockno;
    }

    // Function to get the block number
    static int getBlock() {
        return blockno_com;
    }

    // Function to unset the block number
    static void unsetBlock() {
        blockno_com = -1;
    }

private:
    // The block number shared across functions, mimicking the Fortran common block
    static int blockno_com;
};

// Definition of the static member variable
int Clawpack46Block::blockno_com = -1;

// Main function containing unit tests
int main() {
    // Test setting the block number
    Clawpack46Block::setBlock(10);
    assert(Clawpack46Block::getBlock() == 10);
    std::cout << "Test setBlock Passed!" << std::endl;

    // Test unsetting the block number
    Clawpack46Block::unsetBlock();
    assert(Clawpack46Block::getBlock() == -1);
    std::cout << "Test unsetBlock Passed!" << std::endl;

    std::cout << "All tests passed!" << std::endl;
    return 0;
}