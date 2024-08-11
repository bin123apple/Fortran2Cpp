#include <iostream>
#include <vector>

int main() {
    const int size = 32 * 32;
    std::vector<int> arr(size);
    int x;

    // Initialize array
    for (int i = 0; i < size; ++i) {
        arr[i] = i;
    }

    // Begin parallel region with GPU acceleration (assuming OpenACC support)
    #pragma acc kernels copy(arr[0:size])
    {
        // Divide work among 32 gangs
        #pragma acc loop gang(num_gangs:32) private(x)
        for (int i = 0; i < 32; ++i) {
            // Further divide work within gangs into 8 workers
            #pragma acc loop worker(num_workers:8) private(x)
            for (int j = 0; j < 32; ++j) {
                x = i ^ (j * 3); // ieor in Fortran is equivalent to XOR (^) in C++
                arr[i * 32 + j] += x;
            }
        }
    } // End parallel region

    // Verification
    std::cout << "Running verification test..." << std::endl;
    for (int i = 0; i < size; ++i) {
        if (arr[i] != i + ((i / 32) ^ ((i % 32) * 3))) {
            std::cerr << "Test failed at element " << i << std::endl;
            return 2; // Return error code 2
        }
    }
    std::cout << "All tests passed successfully." << std::endl;

    return 0; // Successful execution
}