#include <iostream>
#include <string>

class AuxiliaryRoutines {
public:
    static bool fft_consistent(int inc, int jump, int n, int lot) {
        int lcm = get_least_common_multiple(inc, jump);
        return !(lcm <= (n - 1) * inc && lcm <= (lot - 1) * jump);
    }

    static int get_least_common_multiple(int a, int b) {
        int i = a, j = b;
        while (j != 0) {
            int jnew = i % j;
            i = j;
            j = jnew;
        }
        return (a / i) * b; // Simplified to prevent overflow
    }

    static void fft_error_handler(int info, const std::string& subroutine_name) {
        std::cerr << "fftpack routine:: FATAL ERROR " << std::endl;
        switch (info) {
            case -1:
                std::cerr << "On entry to " << subroutine_name << 
                          " parameters lot, jump, n and inc are inconsistent." << std::endl;
                break;
            case -2:
                std::cerr << "On ntry to " << subroutine_name << 
                          " parameter l is greater than ldim." << std::endl;
                break;
            case -3:
                std::cerr << "On entry to " << subroutine_name <<
                          " parameter m is greater than mdim." << std::endl;
                break;
            case -5:
                std::cerr << "Within " << subroutine_name << 
                          " input error returned by lower level routine." << std::endl;
                break;
            case -6:
                std::cerr << "On entry to " << subroutine_name <<
                          " parameter ldim is less than 2*(l/2+1)." << std::endl;
                break;
            default:
                std::cerr << "On entry to " << subroutine_name <<
                          " parameter number " << info << " had an illegal value." << std::endl;
        }
    }
};

int main() {
    // Test get_least_common_multiple
    std::cout << "Testing get_least_common_multiple..." << std::endl;
    if (AuxiliaryRoutines::get_least_common_multiple(6, 8) == 24) {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "FAIL" << std::endl;
    }

    // Test fft_consistent
    std::cout << "Testing fft_consistent..." << std::endl;
    if (!AuxiliaryRoutines::fft_consistent(1, 1, 10, 10)) {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "FAIL" << std::endl;
    }

    // Test fft_error_handler by manually calling it with a test case
    std::cout << "Testing fft_error_handler with info = -1..." << std::endl;
    AuxiliaryRoutines::fft_error_handler(-1, "TestSubroutine");

    return 0;
}