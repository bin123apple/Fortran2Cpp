#include <iostream>
#include <vector>
#include <cstdlib>
#include <gtest/gtest.h>

class AstObs {
public:
    std::vector<float>* geopos = nullptr; // Using pointer to vector to mimic Fortran pointer behavior

    AstObs() : geopos(nullptr) {} // Default constructor

    explicit AstObs(std::vector<float>* vec) : geopos(vec) {} // Constructor initializing geopos

    void resetGeopos() {
        geopos = nullptr; // Reset geopos to simulate get_null_ast_obs behavior
    }
};

// Function simulating the Fortran subroutine behavior
void get_null_ast_obs(AstObs& obs) {
    obs.resetGeopos();
}

// Unit tests
TEST(AstObsTest, AssociationTest) {
    std::vector<float> rt(10); // Equivalent to Fortran 'rt' array
    AstObs my_ast_obs(&rt); // Initialize my_ast_obs with pointer to rt

    // Check if geopos is initially associated
    ASSERT_TRUE(my_ast_obs.geopos != nullptr);

    // Simulate the get_null_ast_obs call
    get_null_ast_obs(my_ast_obs);

    // Check if geopos is disassociated after the call
    ASSERT_TRUE(my_ast_obs.geopos == nullptr);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}