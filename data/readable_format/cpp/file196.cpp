#include <string>
#include <gtest/gtest.h>

// NEMOCK function definition
int NEMOCK(const std::string& NEMO) {
    const std::string CHRSET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_.";
    const int NCHR = 38;
    
    int LNEMO = 0;
    
    // Find the length of the string, ignoring trailing spaces
    for (int i = NEMO.length() - 1; i >= 0; --i) {
        if (NEMO[i] != ' ') {
            LNEMO = i + 1;
            break;
        }
    }
    
    // Check length constraints
    if(LNEMO < 1 || LNEMO > 8) {
        return -1;
    }
    
    // Check each character in NEMO
    for (int i = 0; i < LNEMO; ++i) {
        bool found = false;
        for (int j = 0; j < NCHR; ++j) {
            if (NEMO[i] == CHRSET[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            return -2; // Character not found in CHRSET
        }
    }
    
    return 0; // Success
}

// Unit tests
TEST(NEMOCKTest, ValidInput) {
    EXPECT_EQ(0, NEMOCK("ABC123"));
}

TEST(NEMOCKTest, InvalidLength) {
    EXPECT_EQ(-1, NEMOCK("TOOLONGINPUT"));
}

TEST(NEMOCKTest, InvalidCharacter) {
    EXPECT_EQ(-2, NEMOCK("AB@123"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}