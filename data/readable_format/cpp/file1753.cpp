#include <vector>
#include <string>
#include <memory>
#include <gtest/gtest.h>

namespace dStar_crust_def {

    // Constants
    constexpr int crust_default_number_table_points = 2048;
    constexpr double crust_default_lgPmin = 22.0;
    constexpr double crust_default_lgPmax = 33.5;
    constexpr double crust_default_temperature = 1.0e8;

    // Crust table type
    struct crust_table_type {
        bool is_loaded = false;
        int nv = 0;
        int nisos = 0;
        std::vector<std::string> network;
        double lgP_min = 0.0, lgP_max = 0.0;
        double T = 0.0;
        std::vector<double> lgP;
        std::unique_ptr<std::vector<std::vector<double>>> Y = nullptr;
        std::unique_ptr<std::vector<double>> lgRho = nullptr;
        std::unique_ptr<std::vector<double>> lgEps = nullptr;

        crust_table_type() = default;
    };

    // Global variables
    crust_table_type crust_table;
    bool crust_is_initialized = false;
    std::string crust_datadir;

}

// Test case
TEST(dStarCrustDefTest, BasicOperations) {
    using namespace dStar_crust_def;
    crust_table_type crust_table;

    // Basic initializations
    crust_table.is_loaded = true;
    crust_table.nv = 10;
    crust_table.nisos = 5;
    crust_table.network = {"H-1", "He-4", "C-12", "O-16", "Fe-56"};
    crust_table.lgP.resize(crust_table.nv);
    for (int i = 0; i < crust_table.nv; ++i) {
        crust_table.lgP[i] = 22.0 + static_cast<double>(i);
    }

    // Check values
    EXPECT_TRUE(crust_table.is_loaded);
    EXPECT_EQ(crust_table.network.size(), 5);
    EXPECT_EQ(crust_table.nisos, 5);
    EXPECT_EQ(crust_table.network[0], "H-1");
    EXPECT_EQ(crust_table.network[4], "Fe-56");
    EXPECT_DOUBLE_EQ(crust_table.lgP[9], 31.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}