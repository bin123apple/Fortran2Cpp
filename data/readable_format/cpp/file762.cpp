#include <iostream>
#include <memory>
#include <gtest/gtest.h>

// Equivalent of DAT_MOD in Fortran
class DAT_MOD {
public:
    struct DAT {
        int NN;

        bool operator<(const DAT& other) const {
            return NN < other.NN;
        }
    };
};

// Equivalent of NODE_MOD in Fortran
class NODE_MOD {
public:
    struct NODE {
        int KEY;
        std::unique_ptr<DAT_MOD::DAT> PTR;

        bool operator<(const NODE& other) const {
            if (KEY != other.KEY) {
                return KEY < other.KEY;
            } else {
                // Assuming PTR is always valid for simplicity
                return *PTR < *(other.PTR);
            }
        }
    };
};

// Unit tests
TEST(DATNODETest, LessThanTest) {
    auto dat1 = std::make_unique<DAT_MOD::DAT>();
    dat1->NN = 10;
    auto dat2 = std::make_unique<DAT_MOD::DAT>();
    dat2->NN = 20;

    EXPECT_TRUE(*dat1 < *dat2) << "DAT less than comparison failed.";

    NODE_MOD::NODE node1, node2;
    node1.KEY = 1;
    node1.PTR = std::move(dat1);
    node2.KEY = 2;
    node2.PTR = std::move(dat2);

    EXPECT_TRUE(node1 < node2) << "NODE less than comparison failed.";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}