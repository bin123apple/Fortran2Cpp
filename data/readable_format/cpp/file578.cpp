#include <iostream>
#include <chrono>

int main() {
    // Get the current time point at the start of the program
    auto start = std::chrono::high_resolution_clock::now();
    
    // Your code here (This is where you would perform tasks whose CPU time you want to measure)
    
    // Get the current time point again after the execution
    auto end = std::chrono::high_resolution_clock::now();
    
    // Calculate the elapsed time in seconds
    std::chrono::duration<double> elapsed = end - start;
    
    std::cout << "CPU Time: " << elapsed.count() << " seconds" << std::endl;
    
    return 0;
}