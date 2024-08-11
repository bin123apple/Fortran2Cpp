#include <gtest/gtest.h>
#include <string>

class tableb_mod {
public:
    void TABLEB(int X, int Y, int VER, int& SCALE, int& REFVAL, int& WIDTH, std::string& IFORMAT, std::string& NAME, std::string& UNIT) {
        // Assuming simple logic for demonstration purposes
        SCALE = X + Y;
        REFVAL = X - Y;
        WIDTH = X * Y;
        IFORMAT = "Format-A";
        NAME = "TestName";
        UNIT = "Unit-X";
    }
};

// Unit tests
TEST(TablebModTest, HandlesOutputParameters) {
    tableb_mod obj;
    int X = 5, Y = 3, VER = 1, SCALE, REFVAL, WIDTH;
    std::string IFORMAT, NAME, UNIT;

    obj.TABLEB(X, Y, VER, SCALE, REFVAL, WIDTH, IFORMAT, NAME, UNIT);

    EXPECT_EQ(SCALE, 8);
    EXPECT_EQ(REFVAL, 2);
    EXPECT_EQ(WIDTH, 15);
    EXPECT_EQ(IFORMAT, "Format-A");
    EXPECT_EQ(NAME, "TestName");
    EXPECT_EQ(UNIT, "Unit-X");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}