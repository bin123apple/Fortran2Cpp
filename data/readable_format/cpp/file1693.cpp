#include <gtest/gtest.h>
#include <vector>
#include <string>

// AbsorberModule definition directly in this file
class AbsorberModule {
public:
    static const int max_absorbers = 10;
    static constexpr double pi = 3.141592653589793;
    std::vector<std::string> absorber_names;

    AbsorberModule() : absorber_names(max_absorbers) {}

    int find_absorber_index(const std::string& name) {
        for (int i = 0; i < max_absorbers; ++i) {
            if (absorber_names[i] == name) {
                return i;
            }
        }
        return -1; // Not found
    }
};

// Unit tests
TEST(AbsorberModuleTest, FindExistingAbsorber) {
    AbsorberModule absorbers;
    absorbers.absorber_names[0] = "Water";
    absorbers.absorber_names[1] = "CO2";

    EXPECT_EQ(0, absorbers.find_absorber_index("Water"));
}

TEST(AbsorberModuleTest, FindNonExistingAbsorber) {
    AbsorberModule absorbers;
    absorbers.absorber_names[0] = "Water";
    absorbers.absorber_names[1] = "CO2";

    EXPECT_EQ(-1, absorbers.find_absorber_index("Oxygen"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}