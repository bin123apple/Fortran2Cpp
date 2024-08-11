#include <iostream>
#include <vector>

class WorkType {
public:
    int ntotal_kernel;
    int ndimensions;
    int nvertices;
    std::vector<std::vector<double>> vertices;
    std::vector<std::vector<double>> kernel_values;

    WorkType() : ntotal_kernel(0), ndimensions(0), nvertices(0) {}

    void init(int nkern, int ndim, int nverts) {
        ntotal_kernel = nkern;
        nvertices = nverts;
        ndimensions = ndim;

        vertices.resize(ndimensions, std::vector<double>(nvertices, 0.0));
        kernel_values.resize(ntotal_kernel, std::vector<double>(nvertices, 0.0));
    }
};

int main() {
    WorkType wt;

    wt.init(10, 2, 5); // Example initialization

    std::cout << "ntotal_kernel: " << wt.ntotal_kernel << std::endl;
    std::cout << "ndimensions: " << wt.ndimensions << std::endl;
    std::cout << "nvertices: " << wt.nvertices << std::endl;

    // Optionally, add more detailed checks or output here as needed

    return 0;
}