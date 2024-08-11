#include <vector>
#include <gtest/gtest.h>

class IMFUD {
public:
    static std::vector<std::vector<std::vector<std::vector<int>>>> i_imfud0(
        const std::vector<std::vector<std::vector<std::vector<int>>>>& ida2, 
        std::size_t nds4, std::size_t nds3) {
        return manipulateArray(ida2, nds4, nds3);
    }

private:
    static std::vector<std::vector<std::vector<std::vector<int>>>> manipulateArray(
        const std::vector<std::vector<std::vector<std::vector<int>>>>& ida2, 
        std::size_t nds4, std::size_t nds3) {
        std::size_t dim1 = ida2.size();
        std::size_t dim2 = dim1 > 0 ? ida2[0].size() : 0;
        std::size_t dim3 = dim2 > 0 && ida2[0].size() > 0 ? ida2[0][0].size() : 0;
        std::size_t dim4 = dim3 > 0 && ida2[0][0].size() > 0 ? ida2[0][0][0].size() : 0;

        std::vector<std::vector<std::vector<std::vector<int>>>> result(dim1, std::vector<std::vector<std::vector<int>>>(dim2, std::vector<std::vector<int>>(dim3, std::vector<int>(dim4))));

        for (std::size_t i = 0; i < dim1; ++i) {
            for (std::size_t j = 0; j < dim2; ++j) {
                for (std::size_t k = 0; k < dim3; ++k) {
                    for (std::size_t l = 0; l < dim4; ++l) {
                        result[i][j][k][l] = 1 - ida2[i][j][k][l] - static_cast<int>(nds4 - nds3);
                    }
                }
            }
        }

        return result;
    }
};

TEST(IMFUDTest, ManipulateArray) {
    std::size_t nds4 = 2, nds3 = 2;
    std::vector<std::vector<std::vector<std::vector<int>>>> ida2(5, std::vector<std::vector<std::vector<int>>>(nds4, std::vector<std::vector<int>>(nds3, std::vector<int>(2))));

    // Initialize array with test data
    for (int i = 0; i < 5; ++i) {
        for (std::size_t j = 0; j < nds4; ++j) {
            for (std::size_t k = 0; k < nds3; ++k) {
                for (int l = 0; l < 2; ++l) {
                    ida2[i][j][k][l] = i + j + k + l + 4;  // Adjust for 0-based indexing and test data
                }
            }
        }
    }

    auto result = IMFUD::i_imfud0(ida2, nds4, nds3);

    // Verify the result (adjust according to the actual expected outcome)
    for (int i = 0; i < 5; ++i) {
        for (std::size_t j = 0; j < nds4; ++j) {
            for (std::size_t k = 0; k < nds3; ++k) {
                for (int l = 0; l < 2; ++l) {
                    EXPECT_EQ(1 - (i + j + k + l + 4 - (nds4 - nds3)), result[i][j][k][l]);
                }
            }
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}