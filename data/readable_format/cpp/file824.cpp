#include <iostream>
#include <algorithm> // For std::min

void MRE_DECOMP1D(int n, int numprocs, int myid, int& s, int& e) {
    int nlocal;
    int deficit;

    nlocal = n / numprocs;
    // Adjust for zero-based indexing by adding 1 to the final outputs
    s = myid * nlocal;
    deficit = n % numprocs;
    s = s + std::min(myid, deficit);
    if (myid < deficit) {
        nlocal = nlocal + 1;
    }
    e = s + nlocal - 1;
    if (e > n - 1 || myid == numprocs-1) e = n - 1;

    // Adjust for one-based indexing in outputs to match Fortran's output
    s += 1;
    e += 1;
}

void test(int n, int numprocs, int myid) {
    int s, e;
    MRE_DECOMP1D(n, numprocs, myid, s, e);
    std::cout << "n: " << n << " procs: " << numprocs << " id: " << myid
              << " start: " << s << " end: " << e << std::endl;
}

int main() {
    // Test cases
    test(100, 10, 0);
    test(100, 3, 0);
    test(100, 3, 2);
    test(100, 1, 0);
    test(5, 10, 0);
    test(5, 10, 6);
    return 0;
}