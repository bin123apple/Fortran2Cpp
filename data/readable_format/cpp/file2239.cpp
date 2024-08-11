#include <gtest/gtest.h>
#include <vector>
#include <array>
#include <memory>

constexpr int NTDH_MAX = 10; // Define the value according to your model_defn

using SP = float;

struct RUNOFF {
    SP Q_INSTNT;
    SP Q_ROUTED;
    SP Q_ACCURATE;

    RUNOFF() : Q_INSTNT(0), Q_ROUTED(0), Q_ACCURATE(0) {}
    RUNOFF(SP instnt, SP routed, SP accurate) : Q_INSTNT(instnt), Q_ROUTED(routed), Q_ACCURATE(accurate) {}
};

std::array<SP, NTDH_MAX> FUTURE;
std::unique_ptr<std::vector<RUNOFF>> AROUTE;
std::unique_ptr<std::vector<std::vector<std::vector<RUNOFF>>>> AROUTE_3d;
RUNOFF MROUTE;

void initialize() {
    FUTURE.fill(0.0f);

    AROUTE = std::make_unique<std::vector<RUNOFF>>(10);
    for (int i = 0; i < 10; ++i) {
        (*AROUTE)[i] = RUNOFF(static_cast<SP>(i+1), static_cast<SP>(i+2), static_cast<SP>(i+3));
    }

    AROUTE_3d = std::make_unique<std::vector<std::vector<std::vector<RUNOFF>>>>(2, std::vector<std::vector<RUNOFF>>(2, std::vector<RUNOFF>(2)));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                (*AROUTE_3d)[i][j][k] = RUNOFF(static_cast<SP>((i+1)*(j+1)*(k+1)), static_cast<SP>((i+1)*(j+1)*(k+1) + 1), static_cast<SP>((i+1)*(j+1)*(k+1) + 2));
            }
        }
    }

    MROUTE = RUNOFF(1.0f, 2.0f, 3.0f);
}

TEST(MultirouteTest, Initialization) {
    initialize();

    for (const auto& value : FUTURE) {
        EXPECT_FLOAT_EQ(value, 0.0f);
    }

    for (size_t i = 0; i < AROUTE->size(); ++i) {
        EXPECT_FLOAT_EQ((*AROUTE)[i].Q_INSTNT, static_cast<SP>(i+1));
        EXPECT_FLOAT_EQ((*AROUTE)[i].Q_ROUTED, static_cast<SP>(i+2));
        EXPECT_FLOAT_EQ((*AROUTE)[i].Q_ACCURATE, static_cast<SP>(i+3));
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                EXPECT_FLOAT_EQ((*AROUTE_3d)[i][j][k].Q_INSTNT, static_cast<SP>((i+1)*(j+1)*(k+1)));
                EXPECT_FLOAT_EQ((*AROUTE_3d)[i][j][k].Q_ROUTED, static_cast<SP>((i+1)*(j+1)*(k+1) + 1));
                EXPECT_FLOAT_EQ((*AROUTE_3d)[i][j][k].Q_ACCURATE, static_cast<SP>((i+1)*(j+1)*(k+1) + 2));
            }
        }
    }

    EXPECT_FLOAT_EQ(MROUTE.Q_INSTNT, 1.0f);
    EXPECT_FLOAT_EQ(MROUTE.Q_ROUTED, 2.0f);
    EXPECT_FLOAT_EQ(MROUTE.Q_ACCURATE, 3.0f);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}