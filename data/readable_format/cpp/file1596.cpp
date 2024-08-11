#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

// Function declaration
void writeqnode(int myid, const double* qnode, int qnodesize) {
    // Constructing the filename based on myid
    std::string filename = std::to_string(1000 + myid) + ".txt";
    std::ofstream outFile(filename);

    // Check if the file was opened successfully
    if (!outFile.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    // Setting precision and scientific notation for the output
    outFile << std::scientific << std::setprecision(8);

    // Writing the qnode values to the file
    for (int i = 0; i < qnodesize; ++i) {
        outFile << " " << qnode[i] << std::endl; // Each value on a new line for simplicity
    }

    // Closing the file
    outFile.close();
}

// Main function for the test
int main() {
    int myid = 1; // Identifier for the output file
    int qnodesize = 5; // Size of the qnode array
    double qnode[] = {0.1, 0.2, 0.3, 0.4, 0.5}; // Example qnode array values

    // Calling the writeqnode function with the test data
    writeqnode(myid, qnode, qnodesize);

    // Informing the user that the test is complete
    std::cout << "Test completed. Check the file " << (1000 + myid) << ".txt for output." << std::endl;

    return 0;
}