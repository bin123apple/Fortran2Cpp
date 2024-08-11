#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <cstring> // For std::memcpy

// The move function directly included in the same file
void move(
    std::vector<float>& p1, std::vector<float>& p2,
    std::vector<float>& wl1, std::vector<float>& wl2,
    std::vector<double>& disp1, std::vector<double>& disp2,
    int& np1, int& np2,
    std::string& ob1, std::string& ob2,
    std::string& fn1, std::string& fn2,
    std::string& xf1, std::string& xf2,
    std::string& xa1, std::string& xa2,
    std::string& type1, std::string& type2
) {
    const int array_size = 131072;
    const int disp_size = 9;

    // Directly copying the values
    xa2 = xa1;
    np2 = np1;
    ob2 = ob1;
    fn2 = fn1;
    xf2 = xf1;
    type2 = type1;

    // Copying the arrays
    std::memcpy(p2.data(), p1.data(), array_size * sizeof(float));
    std::memcpy(wl2.data(), wl1.data(), array_size * sizeof(float));
    std::memcpy(disp2.data(), disp1.data(), disp_size * sizeof(double));
}

// Test case for the move function
TEST(MoveFunctionTest, CorrectnessTest) {
    std::vector<float> p1(131072), p2(131072), wl1(131072), wl2(131072);
    std::vector<double> disp1(9), disp2(9);
    std::string xf1 = "ExtendedFilename1", xf2;
    std::string fn1 = "Filename1", fn2;
    std::string ob1 = "Object1", ob2;
    std::string type1 = "typ1", type2;
    std::string xa1 = "abc", xa2;
    int np1 = 100, np2;

    // Initialize some test data
    for (int i = 0; i < 131072; ++i) {
        p1[i] = static_cast<float>(i);
        wl1[i] = static_cast<float>(i) / 2.0f;
    }
    for (int i = 0; i < 9; ++i) {
        disp1[i] = static_cast<double>(i) * 100.0;
    }

    // Call the function
    move(p1, p2, wl1, wl2, disp1, disp2, np1, np2, ob1, ob2, fn1, fn2, xf1, xf2, xa1, xa2, type1, type2);

    // Assertions to verify the correctness
    EXPECT_EQ(np2, np1);
    EXPECT_EQ(xa2, xa1);
    EXPECT_EQ(ob2, ob1);
    EXPECT_EQ(fn2, fn1);
    EXPECT_EQ(xf2, xf1);
    EXPECT_EQ(type2, type1);
    EXPECT_TRUE(std::equal(p2.begin(), p2.end(), p1.begin()));
    EXPECT_TRUE(std::equal(wl2.begin(), wl2.end(), wl1.begin()));
    EXPECT_TRUE(std::equal(disp2.begin(), disp2.end(), disp1.begin()));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}