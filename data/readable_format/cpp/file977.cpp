#include <iostream>

double pr40421(int j, double** q, double*** r) {
    double sum_stu = 0.0;
    for(int i = 0; i < 2; i++) {
        for(int m = 0; m < j; m++) {
            for(int n = 0; n < 1; n++) {
                double s = q[n][m] * r[n][m][0];
                double t = q[n][m] * r[n][m][1];
                double u = q[n][m] * r[n][m][2];
                sum_stu += s + t + u;
            }
        }
    }
    return sum_stu;
}

int main() {
    int j = 1;
    double q[1][1] = {{2.0}};
    double r[1][1][3] = {{{1.0, 2.0, 3.0}}};
    
    // The proper way to create pointers for 2D and 3D arrays for the function.
    double* q_ptrs[1] = {q[0]};
    double** r_slice_ptrs[1];
    double* r_ptrs[1][3] = {{r[0][0], r[0][1], r[0][2]}};
    r_slice_ptrs[0] = r_ptrs[0];

    double sum_stu = pr40421(j, q_ptrs, r_slice_ptrs);

    std::cout << "Sum of s, t, and u: " << sum_stu << std::endl;

    if (sum_stu == 12.0) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }

    return 0;
}