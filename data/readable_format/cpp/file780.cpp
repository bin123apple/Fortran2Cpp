#include <fstream>
#include <iostream>
#include <cstdio> // For std::remove

void testFileCreationAndDeletion(const std::string &filename) {
    // Test file creation
    {
        std::ofstream fileStream(filename);
        if (!fileStream) {
            std::cerr << "Failed to open " << filename << " for writing.";
            std::abort();
        }
        // File is closed automatically when fileStream goes out of scope
    }

    // Test file deletion
    if (std::remove(filename.c_str()) != 0) {
        std::cerr << "Failed to delete " << filename;
        std::abort();
    }

    // Attempt to open the deleted file to verify it was deleted
    {
        std::ifstream fileStream(filename);
        if (fileStream) {
            std::cerr << filename << " was not deleted as expected.";
            std::abort();
        }
    }

    std::cout << "File creation and deletion tests passed for " << filename << ".";
}

int main() {
    testFileCreationAndDeletion("test_file_cpp.txt");
    return 0;
}