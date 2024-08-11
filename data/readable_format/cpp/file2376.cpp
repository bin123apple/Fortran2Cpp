#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <sstream>
#include <string>

// Performance functions
namespace performance {

    void perf_header(std::ostream& os) {
        os << std::endl;
        os << "        # Photons    CPU time (sec)    Photons/sec  " << std::endl;
        os << "      ----------------------------------------------" << std::endl;
    }

    void perf_footer(std::ostream& os) {
        os << "      ----------------------------------------------" << std::endl;
        os << std::endl;
    }

    void perf_numbers(std::ostream& os, int count, double time) {
        if (time < std::numeric_limits<double>::min()) {
            os << std::setw(1) << " "
               << std::setw(3) << " "
               << std::setw(12) << count
               << std::setw(3) << " "
               << std::setw(4) << " "
               << std::setw(10) << std::fixed << std::setprecision(1) << time
               << std::setw(4) << " "
               << "   ...   " << std::endl;
        } else {
            os << std::setw(1) << " "
               << std::setw(3) << " "
               << std::setw(12) << count
               << std::setw(3) << " "
               << std::setw(4) << " "
               << std::setw(10) << std::fixed << std::setprecision(1) << time
               << std::setw(4) << " "
               << std::setw(9) << std::fixed << std::setprecision(2) << static_cast<double>(count) / time
               << std::setw(4) << " " << std::endl;
        }
    }
}

// Manual Test Function
void test_performance() {
    std::ostringstream test_stream;
    performance::perf_header(test_stream);
    performance::perf_numbers(test_stream, 1000000, 123.4);
    performance::perf_numbers(test_stream, 500000, 0.0);
    performance::perf_footer(test_stream);

    // Print the test output for manual verification
    std::cout << test_stream.str() << std::endl;
}

int main() {
    // Run the test
    test_performance();

    // Add your application logic or further tests here

    return 0;
}