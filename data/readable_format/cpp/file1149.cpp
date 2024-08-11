#include <gtest/gtest.h>
#include <array>

namespace m_phys_constants {

    constexpr int n_scalar = 1;
    constexpr int n_vector = 3;
    constexpr int n_sym_tensor = 6;
    constexpr int n_asym_tensor = 3;
    constexpr int n_solenoid = 2;

    constexpr std::array<std::array<int, 3>, 3> l_sim_t{{
        {{0, 1, 2}},
        {{1, 3, 4}},
        {{2, 4, 5}}
    }};

    // Corrected l_asim_t with proper dimensions
    constexpr std::array<std::array<std::array<int, 2>, 3>, 3> l_asim_t{{
        {{{{0, 0}}, {{0, 0}}, {{2, 1}}}},
        {{{{0, 1}}, {{-1, 0}}, {{1, -1}}}},
        {{{{2, 1}}, {{1, -1}}, {{0, 0}}}}
    }};

    constexpr std::array<int, 3> lst_sim_t{{0, 3, 5}};

} // namespace m_phys_constants

// Test cases for the constants
TEST(PhysConstantsTest, Constants) {
    EXPECT_EQ(m_phys_constants::n_scalar, 1);
    EXPECT_EQ(m_phys_constants::n_vector, 3);
    EXPECT_EQ(m_phys_constants::n_sym_tensor, 6);
    EXPECT_EQ(m_phys_constants::n_asym_tensor, 3);
    EXPECT_EQ(m_phys_constants::n_solenoid, 2);
}

// Test cases for l_sim_t
TEST(PhysConstantsTest, l_sim_t) {
    EXPECT_EQ(m_phys_constants::l_sim_t[0][0], 0);
    EXPECT_EQ(m_phys_constants::l_sim_t[1][2], 4);
    EXPECT_EQ(m_phys_constants::l_sim_t[2][1], 4);
}

// Test cases for l_asim_t, corrected according to the proper dimensions
TEST(PhysConstantsTest, l_asim_t) {
    EXPECT_EQ(m_phys_constants::l_asim_t[0][2][1], 1);
    EXPECT_EQ(m_phys_constants::l_asim_t[2][0][0], 2);
    EXPECT_EQ(m_phys_constants::l_asim_t[1][1][1], 0);
}

// Test cases for lst_sim_t
TEST(PhysConstantsTest, lst_sim_t) {
    EXPECT_EQ(m_phys_constants::lst_sim_t[0], 0);
    EXPECT_EQ(m_phys_constants::lst_sim_t[1], 3);
    EXPECT_EQ(m_phys_constants::lst_sim_t[2], 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}