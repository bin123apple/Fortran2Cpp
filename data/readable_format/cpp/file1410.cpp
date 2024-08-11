#include <iostream>
#include <vector>
#include <cmath> // For std::abs

// Our simplified GRVT_genmod class
class GRVT_genmod {
public:
    static void GRVT(int ISHP, int NDS, const std::vector<double>& R, double GWT,
                     double GCONST, int GRAVDIR, double DENSITY, std::vector<double>& FINTE) {
        for (size_t i = 0; i < ISHP; ++i) {
            for (size_t j = 0; j < NDS; ++j) {
                FINTE[i * NDS + j] = GWT * GCONST * DENSITY * R[i] * GRAVDIR;
            }
        }
    }
};

// A very simple test framework
class SimpleTest {
public:
    static void AssertEqual(double expected, double actual, const std::string& testName) {
        if (std::abs(expected - actual) > 1e-6) { // simple floating-point comparison
            std::cerr << "Test failed: " << testName << " - Expected: " << expected << ", Actual: " << actual << std::endl;
            failCount++;
        } else {
            std::cout << "Test passed: " << testName << std::endl;
        }
    }

    static void Report() {
        if (failCount > 0) {
            std::cerr << failCount << " test(s) failed." << std::endl;
        } else {
            std::cout << "All tests passed." << std::endl;
        }
    }

private:
    static int failCount;
};

int SimpleTest::failCount = 0;

// Writing a test for our GRVT_genmod::GRVT function
void TestGRVT() {
    int ISHP = 2;
    int NDS = 3;
    std::vector<double> R = {1.5, 2.0};
    double GWT = 9.81;
    double GCONST = 6.67430e-11;
    int GRAVDIR = 1;
    double DENSITY = 1000.0;
    std::vector<double> FINTE(ISHP * NDS, 0);

    GRVT_genmod::GRVT(ISHP, NDS, R, GWT, GCONST, GRAVDIR, DENSITY, FINTE);

    double expectedValue = GWT * GCONST * DENSITY * R[0] * GRAVDIR;
    for (int i = 0; i < ISHP * NDS; ++i) {
        SimpleTest::AssertEqual(expectedValue, FINTE[i], "TestGRVT_Element_" + std::to_string(i));
        if (i == NDS - 1) { // Update expected value for the next shape index
            expectedValue = GWT * GCONST * DENSITY * R[1] * GRAVDIR;
        }
    }
}

int main() {
    TestGRVT();
    SimpleTest::Report();
    return 0;
}