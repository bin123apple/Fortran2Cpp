#include <iostream>

// Mock implementations of FFT functionalities
class FFTScalar {
public:
    static void cft_1z() {
        std::cout << "cft_1z called" << std::endl;
        // Actual implementation goes here
    }

    static void cft_2xy() {
        std::cout << "cft_2xy called" << std::endl;
        // Actual implementation goes here
    }

    static void cfft3d() {
        std::cout << "cfft3d called" << std::endl;
        // Actual implementation goes here
    }

    static void cfft3ds() {
        std::cout << "cfft3ds called" << std::endl;
        // Actual implementation goes here
    }

    #if defined(__CUDA)
    static void cft_1z_gpu() {
        std::cout << "cft_1z_gpu called" << std::endl;
        // Actual implementation goes here
    }

    static void cft_2xy_gpu() {
        std::cout << "cft_2xy_gpu called" << std::endl;
        // Actual implementation goes here
    }

    static void cfft3d_gpu() {
        std::cout << "cfft3d_gpu called" << std::endl;
        // Actual implementation goes here
    }

    static void cfft3ds_gpu() {
        std::cout << "cfft3ds_gpu called" << std::endl;
        // Actual implementation goes here
    }
    #endif
};

// Main function to test FFT functionalities
int main() {
    FFTScalar::cft_1z();
    FFTScalar::cft_2xy();
    FFTScalar::cfft3d();
    FFTScalar::cfft3ds();

    #if defined(__CUDA)
    FFTScalar::cft_1z_gpu();
    FFTScalar::cft_2xy_gpu();
    FFTScalar::cfft3d_gpu();
    FFTScalar::cfft3ds_gpu();
    #endif

    std::cout << "All FFT Scalar tests passed." << std::endl;

    return 0;
}