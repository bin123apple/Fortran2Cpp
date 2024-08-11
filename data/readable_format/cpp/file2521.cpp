#include <iostream>
#include <stdexcept>
#include <cassert>

class VarSysParameter {
private:
    static constexpr const char* pp_kind = "NCPP";
    bool isRootRank;
    bool isTestRank;
    int testRank = 1;
    bool isParallelTest;

public:
    VarSysParameter() {
#ifdef _ParallelTest_
        isParallelTest = true;
#else
        isParallelTest = false;
#endif
    }

    void setDispSwitch(int myrank, int nprocs) {
        isRootRank = (myrank == 0);
        isTestRank = (myrank == testRank);
        if (isParallelTest && nprocs > 9) {
            throw std::runtime_error("nprocs > 9 is not suitable for parallel test");
        }
    }

    // Getters for testing purposes
    bool getIsRootRank() const { return isRootRank; }
    bool getIsTestRank() const { return isTestRank; }
    static const char* getPPKind() { return pp_kind; }
};

// Simple tests for the VarSysParameter class
void runTests() {
    VarSysParameter varSys;
    varSys.setDispSwitch(0, 5);
    assert(varSys.getIsRootRank() == true);
    assert(varSys.getIsTestRank() == false);
    std::cout << "Test 1 Passed: Root rank set correctly." << std::endl;

    varSys.setDispSwitch(1, 5);
    assert(varSys.getIsRootRank() == false);
    assert(varSys.getIsTestRank() == true);
    std::cout << "Test 2 Passed: Test rank set correctly." << std::endl;

    // Test for parallel test logic if applicable
    bool caughtException = false;
    try {
        varSys.setDispSwitch(0, 10);
    } catch (const std::runtime_error& e) {
        caughtException = true;
        std::cout << "Test 3 Passed: Exception caught for nprocs > 9 in parallel test." << std::endl;
    }
#ifdef _ParallelTest_
    assert(caughtException == true);
#else
    assert(caughtException == false);
#endif
}

int main() {
    runTests();
    return 0;
}