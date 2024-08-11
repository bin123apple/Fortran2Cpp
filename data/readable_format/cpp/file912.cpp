#include <fstream>
#include <iostream>
#include <vector>
#include <cstdio> // For std::remove

// Function to write data to a file and then delete the file.
bool write_and_delete_file(const std::string& filename, const std::vector<float>& array) {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile.is_open()) {
        return false;
    }
    outFile.write(reinterpret_cast<const char*>(array.data()), array.size() * sizeof(float));
    if (!outFile.good()) {
        outFile.close();
        return false;
    }
    outFile.close();

    if (std::remove(filename.c_str()) != 0) {
        return false;
    }
    return true;
}

// A simple manual testing function
void test_write_and_delete_file() {
    std::vector<float> array = {5.4321f, 5.4321f, 5.4321f, 5.4321f, 5.4321f};
    std::string filename = "test_data.bin";

    if (write_and_delete_file(filename, array)) {
        std::cout << "Test passed: File operations performed correctly." << std::endl;
    } else {
        std::cerr << "Test failed: File operations not performed correctly." << std::endl;
    }
}

int main() {
    test_write_and_delete_file();
    return 0;
}