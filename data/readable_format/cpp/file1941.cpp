#include <iostream>
#include <vector>
#include <string>
#include <cassert>

class BCAST_ALL_CH_ARRAY__genmod {
public:
    static void BCAST_ALL_CH_ARRAY(std::vector<std::string>& buffer, int NDIM, int COUNTVAL, const std::string& message) {
        buffer.clear(); // Make sure the buffer starts empty to match Fortran behavior
        buffer.resize(NDIM);
        
        for (auto& str : buffer) {
            // Fill each string with the message, truncated or padded as necessary
            str = message.substr(0, COUNTVAL);
        }
    }
};

// A simple function to print the contents of the buffer
void printBuffer(const std::vector<std::string>& buffer) {
    for (const auto& str : buffer) {
        std::cout << str << std::endl;
    }
}

int main() {
    std::vector<std::string> buffer;
    const int NDIM = 5;
    const int COUNTVAL = 12; // Adjusted to fit the actual message length
    const std::string message = "Hello, World!";

    BCAST_ALL_CH_ARRAY__genmod::BCAST_ALL_CH_ARRAY(buffer, NDIM, COUNTVAL, message);

    // Basic check to ensure correctness
    assert(buffer.size() == static_cast<size_t>(NDIM));
    for (const auto& str : buffer) {
        assert(str == message.substr(0, COUNTVAL));
    }

    std::cout << "All checks passed. Buffer content:" << std::endl;
    printBuffer(buffer);

    return 0;
}