#include <gtest/gtest.h>

// Corrected EquivalenceGroup structure
class EquivalenceGroup {
public:
    // Using union for equivalence but not for static members
    union {
        float a;
        float b;
        float c;
    };

    // Static members to retain values across instances/calls
    static float d;
    static int f;

    // Functions to manipulate 'd' and 'f' to simulate Fortran's SAVE behavior
    static void setD(float newValue) {
        d = newValue;
    }

    static float getD() {
        return d;
    }

    static void setF(int newValue) {
        f = newValue;
    }

    static int getF() {
        return f;
    }
};

// Definition of static members
float EquivalenceGroup::d = 0;
int EquivalenceGroup::f = 0;

// Unit Tests
TEST(EquivalenceGroupTest, TestEquivalence) {
    EquivalenceGroup eq;
    eq.a = 1.0f; // This will affect a, b, c due to the union

    // Test equivalence of a, b, c
    EXPECT_FLOAT_EQ(eq.a, 1.0f);
    EXPECT_FLOAT_EQ(eq.b, 1.0f);
    EXPECT_FLOAT_EQ(eq.c, 1.0f);

    // Set and test static members (d and f)
    EquivalenceGroup::setD(2.0f);
    EquivalenceGroup::setF(3);

    EXPECT_FLOAT_EQ(EquivalenceGroup::getD(), 2.0f);
    EXPECT_EQ(EquivalenceGroup::getF(), 3);
}

TEST(EquivalenceGroupTest, TestSave) {
    // This test ensures that the static members retain their values
    EXPECT_FLOAT_EQ(EquivalenceGroup::getD(), 2.0f);
    EXPECT_EQ(EquivalenceGroup::getF(), 3);

    // Change values for the next test
    EquivalenceGroup::setD(4.0f);
    EquivalenceGroup::setF(5);

    EXPECT_FLOAT_EQ(EquivalenceGroup::getD(), 4.0f);
    EXPECT_EQ(EquivalenceGroup::getF(), 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}