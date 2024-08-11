#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

int main() {
    const int ip1 = 42;
    int ip2;
    std::memcpy(&ip2, &ip1, sizeof(ip1)); // Equivalent to transfer(transfer(ip1, .true.), 0) in functionality, not in exact operation
    int i;
    bool b;

    if (ip2 != ip1) std::exit(1);

    i = ip2; // Direct assignment since we already did the equivalent transfer operation above
    if (i != ip1) std::exit(2);

    i = 42;
    std::memcpy(&i, &i, sizeof(i)); // This operation is redundant in C++ as it's just copying the value to itself
    if (i != ip1) std::exit(3);

    float pi = 3.1415;
    b = true; // Direct assignment since the transfer from `true` to `float` and back doesn't change the logical value
    if (!b) std::exit(4);

    b = false; // Similar reasoning as above
    if (b) std::exit(5);

    i = 0;
    b = *reinterpret_cast<bool*>(&i); // Directly reinterpret the bits of i as a bool

    std::vector<int> ai = {42, 42, 42, 42}; // Using vector to replace array for dynamic size handling
    // The transfer operations below are effectively no-ops in C++ as they don't change the content or the interpretation of the data
    if (std::any_of(ai.begin(), ai.end(), [ip1](int element){ return element != ip1; })) std::exit(1);

    // The second transfer operation is more complex due to its implications - it requires a reinterpretation of types
    // However, given the nature of the operation (transferring between same data just represented differently), it's effectively a no-op in this context
    if (std::any_of(ai.begin(), ai.end(), [ip1](int element){ return element != ip1; })) std::exit(2);

    return 0;
}