#include <gtest/gtest.h>
#include <vector>

// Assuming RP corresponds to float in C++.
// Assuming definitions for NCONS, and possibly NDIM if NAVIER_STOKES is considered.
// Replace these placeholders with actual values.
const int NCONS = 5;
#ifdef NAVIER_STOKES
const int NDIM = 3;
#endif

class Storage {
public:
    Storage() = default;
    void AllocateMemory(int totalPolynomialOrder) {
        Q.resize(NCONS * totalPolynomialOrder, 0.0f);
        QDot.resize(NCONS * totalPolynomialOrder, 0.0f);
#ifdef NAVIER_STOKES
        dQ.resize(NCONS * NDIM * totalPolynomialOrder, 0.0f);
#endif
    }

    std::vector<float> Q;    // Public for easy testing.
    std::vector<float> QDot; // Public for easy testing.
#ifdef NAVIER_STOKES
    std::vector<float> dQ;   // Public for easy testing.
#endif
};

// Unit Tests
TEST(StorageTest, MemoryIsAllocated) {
    Storage storage;
    const int totalPolynomialOrder = 10;
    storage.AllocateMemory(totalPolynomialOrder);
    EXPECT_EQ(storage.Q.size(), NCONS * totalPolynomialOrder);
    EXPECT_EQ(storage.QDot.size(), NCONS * totalPolynomialOrder);
#ifdef NAVIER_STOKES
    EXPECT_EQ(storage.dQ.size(), NCONS * NDIM * totalPolynomialOrder);
#endif
}

// Main function to run the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}