// test_ambervar.cpp
#include <gtest/gtest.h>
#include <string>

// Define the ambervar class directly here
class ambervar {
public:
    std::string mmdir;
    std::string qmdir;
    std::string qmbase;
    std::string mmbase;

    // Constructors, destructors, and other member functions can be defined here if necessary.
};

// Unit tests for ambervar
TEST(AmberVarTest, TestSetAndGet) {
    ambervar amberVariables;

    // Set values
    amberVariables.mmdir = "test_mmdir";
    amberVariables.qmdir = "test_qmdir";
    amberVariables.qmbase = "test_qmbase";
    amberVariables.mmbase = "test_mmbase";

    // Test values
    EXPECT_EQ(amberVariables.mmdir, "test_mmdir");
    EXPECT_EQ(amberVariables.qmdir, "test_qmdir");
    EXPECT_EQ(amberVariables.qmbase, "test_qmbase");
    EXPECT_EQ(amberVariables.mmbase, "test_mmbase");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}