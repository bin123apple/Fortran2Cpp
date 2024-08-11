#include <iostream>
#include <vector>
#include <algorithm> // For std::fill
#include <climits> // For INT_MAX

int main() {
    int me = 1; // Simulating different process IDs, change this to simulate different processes
    int boss = 3; // Identifying the "boss" process
    int num_procs = 4; // Assuming a total of 4 processes

    std::vector<int> resc(3), tmp(3);

    // Initialize resc based on the condition
    if (me == boss) {
        std::fill(resc.begin(), resc.end(), 0);
    } else {
        std::fill(resc.begin(), resc.end(), -INT_MAX);
    }

    // Since we are simulating this, we'll just directly modify `resc` without actual MPI communication
    if (me != boss) {
        // Simulating receiving, modifying, and sending the array for non-boss processes
        for (int i = 0; i < 100; ++i) {
            // Normally we'd receive `resc` here
            tmp = resc;
            tmp[0] += 1;
            tmp[1] += 1;
            // Simulate sending the modified array back
            // Normally we'd send `tmp` here
            resc = tmp;
        }
    } else {
        // Simulating the boss process updating its array based on "received" updates
        for (int i = 0; i < 100 * (num_procs - 1); ++i) {
            resc[0] -= 1;
            resc[2] += 1;
        }
    }

    // Printing the results for this simulation
    std::cout << "Process " << me << ": ";
    for (const auto& val : resc) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}