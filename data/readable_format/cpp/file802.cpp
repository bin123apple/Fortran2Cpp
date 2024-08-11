#include <vector>
#include <gtest/gtest.h>

// Define the DataCoarse class directly in this file
class DataCoarse {
public:
    int nc;
    int ns_ib;
    std::vector<int> iclev;
    std::vector<int> iclevc;

    DataCoarse() = default; 
    ~DataCoarse() = default; 
};

// Unit Tests
TEST(DataCoarseTest, PublicVariables) {
    DataCoarse data;
    data.nc = 5;
    data.ns_ib = 10;

    EXPECT_EQ(data.nc, 5);
    EXPECT_EQ(data.ns_ib, 10);
}

TEST(DataCoarseTest, DynamicArray) {
    DataCoarse data;
    data.iclev.resize(5);
    data.iclevc.resize(5);

    for (int i = 0; i < 5; ++i) {
        data.iclev[i] = i + 1;
        data.iclevc[i] = (i + 1) * 2;
    }

    EXPECT_EQ(data.iclev, std::vector<int>({1, 2, 3, 4, 5}));
    EXPECT_EQ(data.iclevc, std::vector<int>({2, 4, 6, 8, 10}));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}