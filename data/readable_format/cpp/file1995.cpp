#include <gtest/gtest.h>

// Define the KindType struct along with its static member definitions in the same file
struct KindType {
    static const int ip;
    static const int rp;
    static const int s_name;
    static const int s_file;
    static const int s_mess;
};

// Static member definitions
const int KindType::ip = 4;
const int KindType::rp = 8;
const int KindType::s_name = 250;
const int KindType::s_file = 250;
const int KindType::s_mess = 100;

// Unit tests for KindType
TEST(KindTypeTest, Constants) {
    EXPECT_EQ(KindType::ip, 4);
    EXPECT_EQ(KindType::rp, 8);
    EXPECT_EQ(KindType::s_name, 250);
    EXPECT_EQ(KindType::s_file, 250);
    EXPECT_EQ(KindType::s_mess, 100);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}