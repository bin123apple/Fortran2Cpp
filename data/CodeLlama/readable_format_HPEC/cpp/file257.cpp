#include <vector>

void kernel_gesummv(int n, double alpha, double beta, 
                    const std::vector<std::vector<double>>& a, 
                    const std::vector<std::vector<double>>& b, 
                    std::vector<double>& tmp, 
                    const std::vector<double>& x, 
                    std::vector<double>& y) {
    // Initialize tmp and y to 0.0
    for (int i = 0; i < n; ++i) {
        tmp[i] = 0.0;
        y[i] = 0.0;
    }

    // Perform the computation
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            tmp[i] = a[j][i] * x[j] + tmp[i];
            y[i] = b[j][i] * x[j] + y[i];
        }
        y[i] = alpha * tmp[i] + beta * y[i];
    }
}

int main() {
    int n = 100; // Example size
    double alpha = 1.0;
    double beta = 1.0;

    // Initialize matrices a and b
    std::vector<std::vector<double>> a(n, std::vector<double>(n));
    std::vector<std::vector<double>> b(n, std::vector<double>(n));

    // Initialize vectors x, y, and tmp
    std::vector<double> x(n, 1.0); // Example initialization
    std::vector<double> y(n);
    std::vector<double> tmp(n);

    // Call the kernel
    kernel_gesummv(n, alpha, beta, a, b, tmp, x, y);

    // Output the results
    for (int i = 0; i < n; ++i) {
        std::cout << "y[" << i << "] = " << y[i] << std::endl;
    }

    return 0;
}
