#include <iostream>
#include <array>

// Mock external functions.
void DARACH1(int size, std::array<double, 2>& arr, int& info) {
    std::cout << "Mock DARACH1 called." << std::endl;
    // Assuming the array passes some checks for simplicity.
    info = 0;
}

void UARERR(const char* file, int line, const char* message, int& info, int errorCode) {
    std::cout << "Mock UARERR called: " << message << " Error Code: " << errorCode << std::endl;
    // Just printing the error message for demonstration.
}

void DARCG22(double& a, double& b, double& c, double& d, double& nrm, int& info) {
    std::cout << "Mock DARCG22 called." << std::endl;
    // Assuming the operation always succeeds for simplicity.
    info = 0;
}

// Translated DARFGR function
void DARFGR(char JOB, std::array<double, 2>& Q1, std::array<double, 2>& Q2, int& INFO) {
    INFO = 0;
    double nrm;

    if (JOB == 'R') {
        nrm = Q1[0] * Q2[0] - Q1[1] * Q2[1];
        Q1[1] = Q1[1] * Q2[0] + Q1[0] * Q2[1];
        Q1[0] = nrm;
    } else if (JOB == 'L') {
        nrm = Q1[0] * Q2[0] - Q1[1] * Q2[1];
        Q2[1] = Q1[1] * Q2[0] + Q1[0] * Q2[1];
        Q2[0] = nrm;
    } else {
        INFO = -1;
        UARERR(__FILE__, __LINE__, "Invalid JOB character", INFO, -1);
    }
}

// Manual test routine
int main() {
    char JOB = 'R';  // Example JOB
    std::array<double, 2> Q1 = {1.0, 2.0};  // Example Q1
    std::array<double, 2> Q2 = {3.0, 4.0};  // Example Q2
    int INFO = 0;  // Initialize INFO

    std::cout << "Before DARFGR: Q1 = [" << Q1[0] << ", " << Q1[1] << "], Q2 = [" << Q2[0] << ", " << Q2[1] << "]" << std::endl;

    DARFGR(JOB, Q1, Q2, INFO);

    std::cout << "After DARFGR: Q1 = [" << Q1[0] << ", " << Q1[1] << "], Q2 = [" << Q2[0] << ", " << Q2[1] << "]" << std::endl;
    std::cout << "INFO: " << INFO << std::endl;

    return 0;
}