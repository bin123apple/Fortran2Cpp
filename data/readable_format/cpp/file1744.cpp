#include <iostream>
#include <fstream>
#include <iomanip>

// Define the writestadiv function directly in this file
void writestadiv(int istep, int j, int icutb, int l, double ttime, double time, double dtime) {
    // Assuming file8 is an ofstream object that has been opened for writing
    std::ofstream file8("output_cpp.txt", std::ios::out);

    // Make sure the file is open
    if (!file8.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return;
    }

    // Set output formatting for file
    file8 << std::setw(6) << istep
          << std::setw(11) << j
          << std::setw(6) << icutb + 1 << 'U'
          << std::setw(5) << l
          << std::setprecision(6) << std::scientific
          << std::setw(14) << ttime + time - dtime
          << std::setw(14) << time - dtime
          << std::setw(14) << dtime << std::endl;

    // Flush and close the file
    file8.flush();
    file8.close();
}

int main() {
    // Test values
    int istep = 1, j = 2, icutb = 3, l = 4;
    double ttime = 5.0, time = 6.0, dtime = 1.0;

    // Call the function with test values
    writestadiv(istep, j, icutb, l, ttime, time, dtime);

    return 0;
}