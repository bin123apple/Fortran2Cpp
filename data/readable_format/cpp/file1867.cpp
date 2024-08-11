#include <iostream>
#include <chrono>
#include <thread>

int main() {
    // Start timer
    auto start = std::chrono::high_resolution_clock::now();

    // Simulate work by sleeping for 2 seconds
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Stop timer
    auto finish = std::chrono::high_resolution_clock::now();

    // Calculate elapsed time in seconds
    std::chrono::duration<double> elapsed = finish - start;

    std::cout << "Elapsed time should be close to 2 seconds: " << elapsed.count() << " seconds." << std::endl;

    return 0;
}