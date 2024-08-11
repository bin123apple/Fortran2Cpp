#include <iostream>
#include <vector>

int main() {
    const int n = 100;
    
    // In C++, std::vector is often a good choice for a dynamically-sized array.
    // Here, we use it to represent both 'a' and 'temp'.
    std::vector<float> a(n); // Automatically initialized to 0.
    std::vector<float> temp(n);
    
    // Assuming 'a' has been filled with data here.
    // For demonstration, let's fill 'a' with some values.
    for (int i = 0; i < n; ++i) {
        a[i] = i; // Example: fill 'a' with sequential values.
    }
    
    // Copying the content of 'a' to 'temp'
    // This can be done efficiently using the assignment operator in C++, which copies all elements.
    temp = a;
    
    // Optionally, print the contents of 'temp' to verify the operation.
    // for (const auto& value : temp) {
    //     std::cout << value << ' ';
    // }
    // std::cout << std::endl;

    return 0;
}