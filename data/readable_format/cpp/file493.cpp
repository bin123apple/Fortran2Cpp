#include <iostream>
#include <vector>
#include <mutex>

int main() {
    std::vector<std::vector<float>> A;  // Dynamically resizable array of arrays (2D vector)
    std::mutex mtx;  // Mutex for critical section

    // Allocating memory for 10 vectors of floats
    A.resize(10);  // This resizes the outer vector to contain 10 elements

    // Entering critical section
    mtx.lock();
    try {
        A.clear();  // Deallocates the vector
        A.shrink_to_fit();  // Non-binding request to reduce capacity to fit size
    } catch (...) {
        mtx.unlock();  // Ensure we unlock before throwing the exception
        throw;  // Rethrow the current exception
    }
    mtx.unlock();
    // Exiting critical section

    return 0;
}