#include <iostream>
#include <openacc.h>

void redsub(int &s1, int &s2, const int n);

int main() {
    const int n = 10;
    int s1 = 0, s2 = 0;

    std::cout << "C++ Test Begins" << std::endl;

    #pragma acc parallel reduction(+:s1,s2) num_gangs(n)
    {
        s1 += 1;
        s2 += 1;
    }

    auto device_type = acc_get_device_type();

    // After the first parallel region
    if (device_type == acc_device_nvidia) {
        if (s1 != n || s2 != n) {
            std::cout << "Parallel Region Test (NVIDIA): Failed" << std::endl;
        } else {
            std::cout << "Parallel Region Test (NVIDIA): Passed" << std::endl;
        }
    } else {
        if (s1 != n || s2 != n) {
            std::cout << "Parallel Region Test (Non-NVIDIA): Failed" << std::endl;
        } else {
            std::cout << "Parallel Region Test (Non-NVIDIA): Passed" << std::endl;
        }
    }

    // Reset s1 and s2
    s1 = 0;
    s2 = 0;
    redsub(s1, s2, n);

    // After calling redsub
    if (device_type == acc_device_nvidia) {
        if (s1 != n || s2 != n) {
            std::cout << "Subroutine Test (NVIDIA): Failed" << std::endl;
        } else {
            std::cout << "Subroutine Test (NVIDIA): Passed" << std::endl;
        }
    } else {
        if (s1 != n || s2 != n) {
            std::cout << "Subroutine Test (Non-NVIDIA): Failed" << std::endl;
        } else {
            std::cout << "Subroutine Test (Non-NVIDIA): Passed" << std::endl;
        }
    }

    std::cout << "C++ Test Ends" << std::endl;

    return 0;
}

void redsub(int &s1, int &s2, const int n) {
    #pragma acc parallel reduction(+:s1,s2) num_gangs(n)
    {
        s1 += 1;
        s2 += 1;
    }
}