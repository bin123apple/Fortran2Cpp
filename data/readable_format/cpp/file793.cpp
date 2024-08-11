#include <gtest/gtest.h>
#include <vector>

// Assuming the T structure and Z function are defined elsewhere,
// you might typically include the file where they're defined.
// For demonstration, I'll define them directly in this test file.

struct T {
  int I;
  float X;
};

void Z(std::vector<int>& Q) {
    for (size_t i = 0; i < Q.size(); i += 2) {
        Q[i] = 999;
    }
}

TEST(TranslatedCodeTests, TestZ) {
    std::vector<int> TestP = {1, 2, 3, 4};
    Z(TestP);
    EXPECT_EQ(TestP[0], 999);
    EXPECT_EQ(TestP[1], 2);
    EXPECT_EQ(TestP[2], 999);
    EXPECT_EQ(TestP[3], 4);
}

TEST(TranslatedCodeTests, TestConditions) {
    std::vector<T> T1(4);
    std::vector<float> SOURCE = {10.f, 20.f, 30.f, 40.f};
    
    for (size_t i = 0; i < T1.size(); ++i) {
        T1[i].I = i + 1; // Adjust for 0-based indexing
        T1[i].X = SOURCE[i];
    }

    std::vector<int> P;
    for (auto& element : T1) {
        P.push_back(element.I);
    }

    Z(P);

    // Reflect changes back to T1.I
    for (size_t i = 0; i < T1.size(); ++i) {
        T1[i].I = P[i];
    }

    bool conditionI = true, conditionX = true;
    std::vector<int> checkI = {999, 2, 999, 4};
    for (size_t i = 0; i < T1.size(); ++i) {
        if (T1[i].I != checkI[i]) conditionI = false;
        if (T1[i].X != SOURCE[i]) conditionX = false;
    }

    EXPECT_TRUE(conditionI);
    EXPECT_TRUE(conditionX);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}