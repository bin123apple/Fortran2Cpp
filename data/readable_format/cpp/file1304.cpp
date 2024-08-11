#include <iostream>
// For file operations, include fstream
#include <fstream>
// For generating temporary files (if needed)
#include <cstdio>

int main() {
    for (int i = 1; i <= 30; ++i) {
        std::cout << i << std::endl;

        // For demonstration, let's assume you want to create a temporary file for each iteration.
        // This approach uses the C++ standard library to manage files.
        // Note: This is a simplification. Real-world usage might require more robust file naming or handling mechanism.
        std::ofstream tempFile("tempfile_" + std::to_string(100+i)); // Creates a uniquely named temp file for demonstration.
        if (tempFile.is_open()) {
            // Perform operations with the file here
            tempFile << "Temporary data for i = " << i << std::endl;
            tempFile.close(); // Remember to close the file
        } else {
            std::cerr << "Failed to create a temporary file for i = " << i << std::endl;
        }
        // Depending on the system and requirements, you might delete the file after use or use a more sophisticated temporary file mechanism.
    }
    return 0;
}