#include <iostream>
#include <vector>

int main() {
    const int num_nodes = 4; // Simulating 4 processes/nodes
    const int N = 20;
    std::vector<std::vector<int>> a(N, std::vector<int>(num_nodes));

    // Simulate initializing array based on "process rank"
    for (int me = 0; me < num_nodes; ++me) {
        for (int i = 0; i < N; ++i) {
            a[i][me] = (i + 1) * (me + 1); // +1 to match Fortran 1-indexing in logic
        }
    }

    // Simulate fetching values as if from different "nodes"
    int n1 = a[9][0]; // Equivalent to a(10)[1] in Fortran
    int n2 = a[9][1]; // Equivalent to a(10)[2]
    int n3 = a[9][2]; // Equivalent to a(10)[3]

    // Output the simulated results
    for (int me = 0; me < num_nodes; ++me) {
        std::cout << "Simulated me,n1,n2,n3=" << (me + 1) << "," << n1 << "," << n2 << "," << n3 << std::endl;
    }

    return 0;
}