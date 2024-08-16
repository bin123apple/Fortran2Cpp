#include <vector>

// Assuming DATA_TYPE is double for this translation
using DATA_TYPE = double;

void init_array(int n, DATA_TYPE& alpha, DATA_TYPE& beta, 
               std::vector<std::vector<DATA_TYPE>>& a, 
               std::vector<DATA_TYPE>& u1, std::vector<DATA_TYPE>& u2, 
               std::vector<DATA_TYPE>& v1, std::vector<DATA_TYPE>& v2, 
               std::vector<DATA_TYPE>& w, std::vector<DATA_TYPE>& x, 
               std::vector<DATA_TYPE>& y, std::vector<DATA_TYPE>& z) {
    
    alpha = 43532.0;
    beta = 12313.0;
    
    for (int i = 0; i < n; ++i) {
        u1[i] = static_cast<DATA_TYPE>(i);
        u2[i] = static_cast<DATA_TYPE>(i) / n / 2.0;
        v1[i] = static_cast<DATA_TYPE>(i) / n / 4.0;
        v2[i] = static_cast<DATA_TYPE>(i) / n / 6.0;
        y[i] = static_cast<DATA_TYPE>(i) / n / 8.0;
        z[i] = static_cast<DATA_TYPE>(i) / n / 9.0;
        x[i] = 0.0;
        w[i] = 0.0;
        
        for (int j = 0; j < n; ++j) {
            a[j][i] = (static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j)) / n;
        }
    }
}

int main() {
    int n = 10; // Example size
    std::vector<std::vector<DATA_TYPE>> a(n, std::vector<DATA_TYPE>(n));
    std::vector<DATA_TYPE> u1(n), u2(n), v1(n), v2(n), w(n), x(n), y(n), z(n);
    DATA_TYPE alpha, beta;
    
    init_array(n, alpha, beta, a, u1, u2, v1, v2, w, x, y, z);
    
    // Example of printing some values to verify correctness
    std::cout << "alpha: " << alpha << ", beta: " << beta << std::endl;
    std::cout << "u1[0]: " << u1[0] << ", u2[0]: " << u2[0] << std::endl;
    std::cout << "a[0][0]: " << a[0][0] << ", a[n-1][n-1]: " << a[n-1][n-1] << std::endl;
    
    return 0;
}
