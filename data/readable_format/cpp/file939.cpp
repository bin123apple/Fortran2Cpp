// dft_setting_params_combined.cpp
#include <iostream>
#include <string>
#include <gtest/gtest.h>

// Namespace that was previously in "dft_setting_params.hpp"
namespace dft_setting_params {

    constexpr int max_iter = 100;
    constexpr double conv_thresh = 1.0e-6;
    bool print_info = true;

#ifdef __LIBXC
    std::string xc_functional = "PBE";
#else
    std::string xc_functional = "LDA";
#endif

} // namespace dft_setting_params

// Unit Test Code
TEST(DFTSettingParamsTest, VariableInitializations) {
    EXPECT_EQ(dft_setting_params::max_iter, 100);
    EXPECT_DOUBLE_EQ(dft_setting_params::conv_thresh, 1.0e-6);
    EXPECT_TRUE(dft_setting_params::print_info);
}

TEST(DFTSettingParamsTest, ConditionalCompilation) {
#ifdef __LIBXC
    EXPECT_EQ(dft_setting_params::xc_functional, "PBE");
#else
    EXPECT_EQ(dft_setting_params::xc_functional, "LDA");
#endif
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}