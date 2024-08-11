#include <gtest/gtest.h>

// Assuming kint corresponds to the standard integer type.
// Adjust if a different size is intended for the precision.
using kint = int;

class m_quad_2_triangle {
public:
    static const kint ie_quad_2_tri[3][2]; // Declare the 2D array
};

// Initialize the 2D array with the specific values
const kint m_quad_2_triangle::ie_quad_2_tri[3][2] = {{1, 2}, {3, 1}, {3, 4}};

TEST(Quad2TriangleTest, CheckValues) {
    const kint expected_values[3][2] = {{1, 2}, {3, 1}, {3, 4}};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            EXPECT_EQ(m_quad_2_triangle::ie_quad_2_tri[i][j], expected_values[i][j])
                << "Element at (" << i << "," << j << ") is incorrect";
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}