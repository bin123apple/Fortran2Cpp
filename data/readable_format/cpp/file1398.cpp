#include <iostream>
#include <vector>
#include <string>
#include <gtest/gtest.h>

class BUFDCHR_mod {
public:
    static void BUFDCHR(std::string& STRING, const int& NOBS, const bool& CMPRES, const int& WIDTH, const bool& DSPLAY,
                        const std::string& NAME, const int& IBEFOR, std::vector<float>& VALUES, const int& IVAL,
                        const int& INAM, const std::string& NAMES, int& IRC) {
        // Example implementation, modify according to your actual needs
        std::cout << "BUFDCHR called with NAME: " << NAME << std::endl;
        IRC = 0; // Example output, modify according to the actual logic
    }
};

TEST(BUFDCHRTest, HandlesBasicInput) {
    std::string STRING = "TestString";
    const int NOBS = 1;
    const bool CMPRES = false;
    const int WIDTH = 10;
    const bool DSPLAY = true;
    const std::string NAME = "TestName";
    const int IBEFOR = 0;
    std::vector<float> VALUES = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    const int IVAL = 5;
    const int INAM = 1;
    std::string NAMES = "TestNames";
    int IRC = -1; // Initialized to a value that should be changed by BUFDCHR

    BUFDCHR_mod::BUFDCHR(STRING, NOBS, CMPRES, WIDTH, DSPLAY, NAME, IBEFOR, VALUES, IVAL, INAM, NAMES, IRC);

    EXPECT_EQ(0, IRC); // Assuming BUFDCHR sets IRC to 0
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}