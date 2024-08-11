#include <gtest/gtest.h>
#include <string>

// Define the GlobalPHMF class directly in this file
class GlobalPHMF {
public:
    static int ioutPHMF;
    static int iprecision;
    static int ndigits;
    static std::string outfile;

    static void initialize() {
        ioutPHMF = 0;
        iprecision = 2;
        ndigits = 7;
        outfile = "PreHeadsMF_output.txt";
    }
};

// Initialize static members outside the class definition
int GlobalPHMF::ioutPHMF = 0;
int GlobalPHMF::iprecision = 2;
int GlobalPHMF::ndigits = 7;
std::string GlobalPHMF::outfile = "PreHeadsMF_output.txt";

// Unit tests
TEST(GlobalPHMFTest, InitializationTest) {
    EXPECT_EQ(GlobalPHMF::ioutPHMF, 0);
    EXPECT_EQ(GlobalPHMF::iprecision, 2);
    EXPECT_EQ(GlobalPHMF::ndigits, 7);
    EXPECT_EQ(GlobalPHMF::outfile, "PreHeadsMF_output.txt");
}

TEST(GlobalPHMFTest, ModificationTest) {
    GlobalPHMF::ioutPHMF = 1;
    GlobalPHMF::iprecision = 3;
    GlobalPHMF::ndigits = 8;
    GlobalPHMF::outfile = "Modified_output.txt";

    EXPECT_EQ(GlobalPHMF::ioutPHMF, 1);
    EXPECT_EQ(GlobalPHMF::iprecision, 3);
    EXPECT_EQ(GlobalPHMF::ndigits, 8);
    EXPECT_EQ(GlobalPHMF::outfile, "Modified_output.txt");

    // Optionally reinitialize to default values if needed
    GlobalPHMF::initialize();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}