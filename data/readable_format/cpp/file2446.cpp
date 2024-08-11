#include <iostream>
#include <vector>

struct MyType {
    std::vector<int> indices;
};

void run_test() {
    MyType object;

    // Simulating a single "process" scenario.
    int me = 1; // This would normally be set to the rank of the process in a parallel code.

    // Fill the vector as if it was filled in a parallel environment.
    for (int i = 1; i <= me; ++i) {
        object.indices.push_back(i);
    }

    // Perform checks
    if (object.indices.size() != 1) {
        std::cerr << "Error: Size of indices is not 1." << std::endl;
        exit(1);
    }

    if (object.indices[0] != 1) {
        std::cerr << "Error: First element of indices is not 1." << std::endl;
        exit(1);
    }

    std::cout << "Test passed successfully." << std::endl;
}

int main() {
    run_test();
    return 0;
}