#include <iostream>
#include <fstream>
#include <iomanip>

// Define the writesta function
void writesta(int istep, int j, int icutb, int l, double ttime, double time, double dtime) {
    std::ofstream fileStream;
    
    // Open the file associated with unit number 8 in Fortran, in append mode
    // Assuming a file "unit8.txt" corresponds to unit number 8
    fileStream.open("unit8.txt", std::ios_base::app);
    
    if (!fileStream.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return;
    }

    // Setting the precision and fixed notation similar to Fortran's format statement
    fileStream << std::fixed << std::setprecision(6);

    // Writing formatted output to the file
    fileStream << std::setw(5) << istep << " "
               << std::setw(10) << j << " "
               << std::setw(5) << icutb + 1 << " "
               << std::setw(5) << l << " "
               << std::setw(13) << std::scientific << ttime + time << " "
               << std::setw(13) << std::scientific << time << " "
               << std::setw(13) << std::scientific << dtime << std::endl;

    // Flushing the stream to ensure all output is written
    fileStream.flush();

    // Closing the file
    fileStream.close();
}

// Main function to test writesta
int main() {
    // Test values
    int istep = 1, j = 2, icutb = 3, l = 4;
    double ttime = 5.0, time = 6.0, dtime = 0.5;

    // Call the function
    writesta(istep, j, icutb, l, ttime, time, dtime);

    return 0;
}